#pragma once
#include <string>
#include "OrderStatus.h"

class Order
{
public:
    Order(const std::string& orderId, const std::string& sampleId, const std::string& customerName, int quantity);

    const std::string& GetOrderId() const;
    const std::string& GetSampleId() const;
    const std::string& GetCustomerName() const;
    int GetQuantity() const;

    OrderStatus GetStatus() const;
    void SetStatus(OrderStatus status);

private:
    std::string orderId;
    std::string sampleId;
    std::string customerName;
    int quantity;
    OrderStatus status;
};
