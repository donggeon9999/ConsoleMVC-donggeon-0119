#pragma once

enum class OrderStatus
{
    RESERVED,
    REJECTED,
    PRODUCING,
    CONFIRMED,
    RELEASED
};

const char* ToString(OrderStatus status);
