#include "AppController.h"
#include "../Model/OrderStatus.h"

AppController::AppController(SampleRepository& sampleRepository, OrderRepository& orderRepository, ConsoleView& view)
    : sampleRepository(sampleRepository), orderRepository(orderRepository), view(view)
{
}

void AppController::Run()
{
    bool running = true;
    while (running)
    {
        switch (view.ShowMainMenu())
        {
        case 1: HandleSampleMenu();    break;
        case 2: HandleOrderCreate();   break;
        case 3: HandleOrderApproval(); break;
        case 4: HandleMonitoring();    break;
        case 5: HandleRelease();       break;
        case 0: running = false;       break;
        default: view.ShowMessage("잘못된 입력입니다."); break;
        }
    }
}

void AppController::HandleSampleMenu()
{
    bool inSampleMenu = true;
    while (inSampleMenu)
    {
        switch (view.ShowSampleMenu())
        {
        case 1: HandleRegisterSample(); break;
        case 2: HandleListSample();     break;
        case 3: HandleSearchSample();   break;
        case 0: inSampleMenu = false;   break;
        default: view.ShowMessage("잘못된 입력입니다."); break;
        }
    }
}

void AppController::HandleRegisterSample()
{
    std::string name = view.InputText("시료 이름");
    double avgProcessMinutes = view.InputDouble("평균 생산시간(min)");
    double yieldRate = view.InputDouble("수율(0~1)");

    SampleItem& sample = sampleRepository.Add(name, avgProcessMinutes, yieldRate);
    view.ShowMessage("시료가 등록되었습니다. ID: " + sample.GetId());
}

void AppController::HandleListSample()
{
    view.ShowSampleList(sampleRepository.GetAll());
}

void AppController::HandleSearchSample()
{
    std::string keyword = view.InputText("검색어(이름)");
    std::vector<SampleItem*> found = sampleRepository.FindByNameKeyword(keyword);

    std::vector<SampleItem> copies;
    for (SampleItem* sample : found)
    {
        copies.push_back(*sample);
    }
    view.ShowSampleList(copies);
}

void AppController::HandleOrderCreate()
{
    std::string sampleId = view.InputText("시료 ID");
    if (sampleRepository.FindById(sampleId) == nullptr)
    {
        view.ShowMessage("존재하지 않는 시료 ID입니다.");
        return;
    }

    std::string customerName = view.InputText("고객명");
    int quantity = view.InputInt("주문 수량");

    Order& order = orderRepository.Add(sampleId, customerName, quantity);
    view.ShowMessage("주문이 접수되었습니다. 주문번호: " + order.GetOrderId() + " (RESERVED)");
}

void AppController::HandleOrderApproval()
{
    std::vector<Order*> reserved = orderRepository.FindByStatus(OrderStatus::RESERVED);
    view.ShowOrderList("승인 대기 중인 주문 (RESERVED)", reserved);

    int index = view.SelectIndex("승인/거절할 번호", static_cast<int>(reserved.size()));
    if (index < 0)
    {
        return;
    }

    Order* order = reserved[index];
    if (!view.InputYesNo("이 주문을 승인하시겠습니까?"))
    {
        order->SetStatus(OrderStatus::REJECTED);
        view.ShowMessage("주문이 거절되었습니다.");
        return;
    }

    SampleItem* sample = sampleRepository.FindById(order->GetSampleId());
    if (sample != nullptr && sample->RemoveStock(order->GetQuantity()))
    {
        order->SetStatus(OrderStatus::CONFIRMED);
        view.ShowMessage("재고가 충분하여 CONFIRMED 상태로 전환되었습니다.");
    }
    else
    {
        order->SetStatus(OrderStatus::PRODUCING);
        view.ShowMessage("재고가 부족하여 PRODUCING 상태로 전환되었습니다. (생산 큐 연동은 별도 PoC에서 처리)");
    }
}

void AppController::HandleMonitoring()
{
    std::vector<int> counts = {
        static_cast<int>(orderRepository.FindByStatus(OrderStatus::RESERVED).size()),
        static_cast<int>(orderRepository.FindByStatus(OrderStatus::CONFIRMED).size()),
        static_cast<int>(orderRepository.FindByStatus(OrderStatus::PRODUCING).size()),
        static_cast<int>(orderRepository.FindByStatus(OrderStatus::RELEASED).size())
    };
    std::vector<std::string> labels = { "RESERVED", "CONFIRMED", "PRODUCING", "RELEASED" };

    view.ShowStatusSummary(counts, labels);
    view.ShowSampleList(sampleRepository.GetAll());
}

void AppController::HandleRelease()
{
    std::vector<Order*> confirmed = orderRepository.FindByStatus(OrderStatus::CONFIRMED);
    view.ShowOrderList("출고 가능 주문 (CONFIRMED)", confirmed);

    int index = view.SelectIndex("출고할 번호", static_cast<int>(confirmed.size()));
    if (index < 0)
    {
        return;
    }

    confirmed[index]->SetStatus(OrderStatus::RELEASED);
    view.ShowMessage("출고 처리가 완료되었습니다. (RELEASED)");
}
