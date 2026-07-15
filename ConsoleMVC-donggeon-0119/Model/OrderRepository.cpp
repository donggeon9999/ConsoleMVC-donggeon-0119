#include "OrderRepository.h"
#include <sstream>
#include <iomanip>

Order& OrderRepository::Add(const std::string& sampleId, const std::string& customerName, int quantity)
{
    std::ostringstream oss;
    oss << "ORD-" << std::setw(4) << std::setfill('0') << nextId++;

    orders.emplace_back(oss.str(), sampleId, customerName, quantity);
    return orders.back();
}

const std::vector<Order>& OrderRepository::GetAll() const
{
    return orders;
}

Order* OrderRepository::FindByOrderId(const std::string& orderId)
{
    for (Order& order : orders)
    {
        if (order.GetOrderId() == orderId)
        {
            return &order;
        }
    }
    return nullptr;
}

std::vector<Order*> OrderRepository::FindByStatus(OrderStatus status)
{
    std::vector<Order*> result;
    for (Order& order : orders)
    {
        if (order.GetStatus() == status)
        {
            result.push_back(&order);
        }
    }
    return result;
}
