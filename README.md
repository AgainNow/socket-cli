# socket-cli
socket客户端开发模板，基于系统调用、muduo等。

## 需求

1. 基于系统调用实现经典socket客户端
2. 基于muduo实现经典socket客户端
3. 基于boost::asio实现经典socket客户端
4. 基于C++20网络模块的socket客户端（C++20后，内嵌了asio模块）

## 经典服务

1. 回显客户端/服务端：客户端发什么数据，服务端就回什么数据
2. daytime服务
3. 登录服务

## 协议

1. UDP
2. TCP

## 客户端设计

1. 单线程单次请求 Simple Client
2. 单线程循环请求 Iterative Client
3. todo 多线程并发请求 Concurrent Client
