#include "SampleItem.h"

SampleItem::SampleItem(const std::string& id, const std::string& name, double avgProcessMinutes, double yieldRate, int stock)
    : id(id), name(name), avgProcessMinutes(avgProcessMinutes), yieldRate(yieldRate), stock(stock)
{
}

const std::string& SampleItem::GetId() const
{
    return id;
}

const std::string& SampleItem::GetName() const
{
    return name;
}

double SampleItem::GetAvgProcessMinutes() const
{
    return avgProcessMinutes;
}

double SampleItem::GetYieldRate() const
{
    return yieldRate;
}

int SampleItem::GetStock() const
{
    return stock;
}

void SampleItem::AddStock(int amount)
{
    stock += amount;
}

bool SampleItem::RemoveStock(int amount)
{
    if (stock < amount)
    {
        return false;
    }

    stock -= amount;
    return true;
}
