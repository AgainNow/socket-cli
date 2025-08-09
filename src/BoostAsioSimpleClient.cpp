#include "BoostAsioSimpleClient.h"

#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

void BoostAsioSimpleClient::tcp(const char* ip_addr, uint16_t port) {
    try {
        boost::asio::io_context io;
        tcp::resolver resolver(io);
        // endpoint: 端点，连接地址
        tcp::resolver::results_type endpoints = resolver.resolve(ip_addr, std::to_string(port).c_str());

        tcp::socket socket(io);
        boost::asio::connect(socket, endpoints);

        std::string msg = "Hello from client\n";
        boost::asio::write(socket, boost::asio::buffer(msg));

        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, '\n');

        std::istream input(&buffer);
        std::string reply;
        std::getline(input, reply);

        std::cout << "Server replied: " << reply << "\n";
    } catch (std::exception& e) {
        std::cerr << "Client error: " << e.what() << "\n";
    }
}
