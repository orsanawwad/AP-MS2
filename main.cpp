#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Base64Codec.h"
#include "StringReverser.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    StringReverser reverser;

    std::string hello = "Hello, World!";

    std::cout << reverser.solve(hello) << std::endl;

//    server_side::Base64Codec codec;
//
//    std::cout << "------------" << std::endl;
//    std::cout << "Encoded: " << codec.encodeValue(hello) << std::endl;
//    std::cout << "Decoded: " << codec.decodeValue(codec.encodeValue(hello)) << std::endl;
//    std::cout << "------------" << std::endl;

//    server_side::IServer * server = new MySerialServer;
//    server_side::IClientHandler * clientHandler = new MyTestClientHandler;



//    server->open(5400,clientHandler);

    return 0;
}