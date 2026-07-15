#pragma once
#include <string>
#include <vector>
#include "../Model/SampleItem.h"
#include "../Model/Order.h"

class ConsoleView
{
public:
    int ShowMainMenu();
    int ShowSampleMenu();

    void ShowMessage(const std::string& message);

    std::string InputText(const std::string& prompt);
    double InputDouble(const std::string& prompt);
    int InputInt(const std::string& prompt);

    void ShowSampleList(const std::vector<SampleItem>& samples);
    void ShowOrderList(const std::string& title, const std::vector<Order*>& orders);
    void ShowStatusSummary(const std::vector<int>& counts, const std::vector<std::string>& labels);

    int SelectIndex(const std::string& prompt, int itemCount);
    bool InputYesNo(const std::string& prompt);
};
