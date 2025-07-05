#include "ItervativeClient.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

void IterativeClient::udp(const char* ip_addr, uint16_t port) {
    int sd = socket(PF_INET, SOCK_DGRAM, 0);
    std::cout << "sd: " << sd << std::endl;
    
    sockaddr_in servaddr;
    socklen_t servaddr_len = sizeof(servaddr);
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = htons(1312);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    char request[1024] = {"Hello, I'm UDP Client."};
    char response[1024];

    for (int i = 0; i < 10; ++i) {
        sendto(sd, request, strlen(request), 0, (sockaddr*)&servaddr, servaddr_len);
        
        size_t len = recvfrom(sd, response, 1024, 0, (sockaddr*)&servaddr, &servaddr_len);
        printf("Response: %.*s\n", (int)len, response);
    }
    
    close(sd);
}

void IterativeClient::tcp(const char* ip_addr, uint16_t port) {
    for (int i = 0; i < 10; ++i) {
        // 创建socket
        int sd = socket(PF_INET, SOCK_STREAM, 0);
        std::cout << "sd: " << sd << std::endl;
        
        // 连接服务器
        struct sockaddr_in servaddr;
        servaddr.sin_family = PF_INET;
        servaddr.sin_port = ntohs(1314);
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        if (connect(sd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
            std::cout << "Connect failed!\n";
        }
        
        // 发送请求包
        char request[] = {"Hello, I'm Client."};
        send(sd, request, strlen(request), 0);
        
        // 读取服务器响应包
        char response[1024];
        auto len = recv(sd, response, 1024, 0);
        printf("Response: %.*s\n", (int)len, response);
        
        // 关闭socket
        close(sd);
    }
}