// 基于系统调用的并发socket客户端
#include <cstdint>

class ConcurrentClient {
public:
    void udp(const char* ip_addr = "127.0.0.1", uint16_t port = 1312);
    void tcp(const char* ip_addr = "127.0.0.1", uint16_t port = 1313);
};