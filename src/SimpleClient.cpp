#include "SimpleClient.h"

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>  // mac不用添加；linux需要添加


void SimpleClient::udp(const char* ip_addr, uint16_t port) {
    int sd = socket(PF_INET, SOCK_DGRAM, 0);
    std::cout << "sd: " << sd << std::endl;
    
    sockaddr_in servaddr;
    socklen_t servaddr_len = sizeof(servaddr);
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ip_addr);
    
    char request[1024] = {"Hello, I'm UDP Client.\n"};
    sendto(sd, request, strlen(request), 0, (sockaddr*)&servaddr, servaddr_len);
    
    char response[1024];
    size_t len = recvfrom(sd, response, 1024, 0, (sockaddr*)&servaddr, &servaddr_len);
    printf("Response: %.*s\n", (int)len, response);
    
    close(sd);
}

void SimpleClient::tcp(const char* ip_addr, uint16_t port) {
    // 创建socket
    int sd = socket(PF_INET, SOCK_STREAM, 0);
    std::cout << "sd: " << sd << std::endl;
    
    // 连接服务器
    struct sockaddr_in servaddr;
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = ntohs(port);  // 端口号
    servaddr.sin_addr.s_addr = inet_addr(ip_addr);  // ip地址
    if (connect(sd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        std::cout << "Connect failed!\n";
    }
    
    // 读取服务器响应包
    char buffer[1024];
    recv(sd, buffer, 1024, 0);
    std::cout << buffer << std::endl;
    
    // 关闭socket
    close(sd);
}