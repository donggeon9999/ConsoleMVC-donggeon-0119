#pragma once
#include <string>
#include <vector>
#include "Order.h"
#include "OrderStatus.h"

class OrderRepository
{
public:
    Order& Add(const std::string& sampleId, const std::string& customerName, int quantity);
    const std::vector<Order>& GetAll() const;
    Order* FindByOrderId(const std::string& orderId);
    std::vector<Order*> FindByStatus(OrderStatus status);

private:
    std::vector<Order> orders;
    int nextId = 1;
};
