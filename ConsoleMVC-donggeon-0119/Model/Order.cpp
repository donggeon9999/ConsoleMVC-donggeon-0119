#include "Order.h"

Order::Order(const std::string& orderId, const std::string& sampleId, const std::string& customerName, int quantity)
    : orderId(orderId), sampleId(sampleId), customerName(customerName), quantity(quantity), status(OrderStatus::RESERVED)
{
}

const std::string& Order::GetOrderId() const
{
    return orderId;
}

const std::string& Order::GetSampleId() const
{
    return sampleId;
}

const std::string& Order::GetCustomerName() const
{
    return customerName;
}

int Order::GetQuantity() const
{
    return quantity;
}

OrderStatus Order::GetStatus() const
{
    return status;
}

void Order::SetStatus(OrderStatus status)
{
    this->status = status;
}
