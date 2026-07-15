#pragma once
#include "../Model/SampleRepository.h"
#include "../Model/OrderRepository.h"
#include "../View/ConsoleView.h"

class AppController
{
public:
    AppController(SampleRepository& sampleRepository, OrderRepository& orderRepository, ConsoleView& view);

    void Run();

private:
    void HandleSampleMenu();
    void HandleRegisterSample();
    void HandleListSample();
    void HandleSearchSample();

    void HandleOrderCreate();
    void HandleOrderApproval();
    void HandleMonitoring();
    void HandleRelease();

    SampleRepository& sampleRepository;
    OrderRepository& orderRepository;
    ConsoleView& view;
};
