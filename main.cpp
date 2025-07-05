#include <iostream>
#include "SimpleClient.h"

int main() {
    SimpleClient cli{};
    // cli.udp("127.0.0.1", 1312);
    cli.tcp("127.0.0.1", 1313);
    return 0;
}