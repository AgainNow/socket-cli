// 基于系统调用的简单socket服务端
#include <cstdint>

class SimpleClient {
public:
    void udp(const char* ip_addr = "127.0.0.1", uint16_t port = 1312);
    void tcp(const char* ip_addr = "127.0.0.1", uint16_t port = 1313);
};