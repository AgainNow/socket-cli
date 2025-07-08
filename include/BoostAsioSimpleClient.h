#pragma once

#include <cstdint>

class BoostAsioSimpleClient {
public:
    void tcp(const char* ip_addr, uint16_t port);
};
