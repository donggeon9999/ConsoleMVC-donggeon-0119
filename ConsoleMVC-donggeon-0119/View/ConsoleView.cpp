#include "ConsoleView.h"
#include "../Model/OrderStatus.h"
#include <iostream>

int ConsoleView::ShowMainMenu()
{
    std::cout << "\n===== 반도체 시료 생산주문관리 시스템 (PoC) =====\n";
    std::cout << "1. 시료 관리\n";
    std::cout << "2. 시료 주문\n";
    std::cout << "3. 주문 승인/거절\n";
    std::cout << "4. 모니터링\n";
    std::cout << "5. 출고 처리\n";
    std::cout << "0. 종료\n";
    return InputInt("선택");
}

int ConsoleView::ShowSampleMenu()
{
    std::cout << "\n----- 시료 관리 -----\n";
    std::cout << "1. 시료 등록\n";
    std::cout << "2. 시료 목록\n";
    std::cout << "3. 시료 검색\n";
    std::cout << "0. 뒤로\n";
    return InputInt("선택");
}

void ConsoleView::ShowMessage(const std::string& message)
{
    std::cout << message << "\n";
}

std::string ConsoleView::InputText(const std::string& prompt)
{
    std::cout << prompt << ": ";
    std::string value;
    std::getline(std::cin, value);
    return value;
}

double ConsoleView::InputDouble(const std::string& prompt)
{
    std::cout << prompt << ": ";
    double value = 0.0;
    std::cin >> value;
    std::cin.ignore();
    return value;
}

int ConsoleView::InputInt(const std::string& prompt)
{
    std::cout << prompt << " > ";
    int value = 0;
    std::cin >> value;
    std::cin.ignore();
    return value;
}

void ConsoleView::ShowSampleList(const std::vector<SampleItem>& samples)
{
    if (samples.empty())
    {
        std::cout << "등록된 시료가 없습니다.\n";
        return;
    }

    std::cout << "ID\t이름\t\t평균생산시간\t수율\t재고\n";
    for (const SampleItem& sample : samples)
    {
        std::cout << sample.GetId() << "\t" << sample.GetName() << "\t\t"
                   << sample.GetAvgProcessMinutes() << " min\t" << sample.GetYieldRate()
                   << "\t" << sample.GetStock() << " ea\n";
    }
}

void ConsoleView::ShowOrderList(const std::string& title, const std::vector<Order*>& orders)
{
    std::cout << "\n----- " << title << " -----\n";
    if (orders.empty())
    {
        std::cout << "해당하는 주문이 없습니다.\n";
        return;
    }

    for (size_t i = 0; i < orders.size(); ++i)
    {
        const Order* order = orders[i];
        std::cout << "[" << (i + 1) << "] " << order->GetOrderId()
                   << " | 고객: " << order->GetCustomerName()
                   << " | 시료: " << order->GetSampleId()
                   << " | 수량: " << order->GetQuantity()
                   << " | 상태: " << ToString(order->GetStatus()) << "\n";
    }
}

void ConsoleView::ShowStatusSummary(const std::vector<int>& counts, const std::vector<std::string>& labels)
{
    std::cout << "\n----- 상태별 주문 현황 -----\n";
    for (size_t i = 0; i < counts.size() && i < labels.size(); ++i)
    {
        std::cout << labels[i] << ": " << counts[i] << "건\n";
    }
}

int ConsoleView::SelectIndex(const std::string& prompt, int itemCount)
{
    if (itemCount <= 0)
    {
        return -1;
    }

    int index = InputInt(prompt);
    if (index < 1 || index > itemCount)
    {
        return -1;
    }
    return index - 1;
}

bool ConsoleView::InputYesNo(const std::string& prompt)
{
    std::string answer = InputText(prompt + " (Y/N)");
    return !answer.empty() && (answer[0] == 'Y' || answer[0] == 'y');
}
