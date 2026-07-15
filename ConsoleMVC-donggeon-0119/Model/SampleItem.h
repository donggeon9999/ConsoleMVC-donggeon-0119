#pragma once
#include <string>

class SampleItem
{
public:
    SampleItem(const std::string& id, const std::string& name, double avgProcessMinutes, double yieldRate, int stock);

    const std::string& GetId() const;
    const std::string& GetName() const;
    double GetAvgProcessMinutes() const;
    double GetYieldRate() const;
    int GetStock() const;

    void AddStock(int amount);
    bool RemoveStock(int amount);

private:
    std::string id;
    std::string name;
    double avgProcessMinutes;
    double yieldRate;
    int stock;
};
