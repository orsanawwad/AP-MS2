#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Base64Codec.h"
#include "StringReverser.h"
#include "BestFirstSearch.h"
#include "ISearchable.h"
#include "MazeDomain.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

//    StringReverser reverser;

//    std::string hello = "Hello, World!";

//    std::cout << reverser.solve(hello) << std::endl;

    server_side::Base64Codec codec;

//    std::cout << "------------" << std::endl;
//    std::cout << "Encoded: " << codec.encodeValue(hello) << std::endl;
//    std::cout << "Decoded: " << codec.decodeValue(codec.encodeValue(hello)) << std::endl;
//    std::cout << "------------" << std::endl;

//    server_side::IServer * server = new MySerialServer;
//    server_side::IClientHandler * clientHandler = new MyTestClientHandler;



//    server->open(5400,clientHandler);

    std::string values = "11\n"
                         "0,0\n"
                         "10,10\n"
                         " 4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\n"
                         " 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\n"
                         " 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7\n"
                         " 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7\n"
                         " 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1\n"
                         " 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9\n"
                         " 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8\n"
                         "10, 8, 0, 2, 3, 8, 0,10,10, 2, 7\n"
                         " 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1\n"
                         " 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1\n"
                         " 5,10, 1,10, 7, 7, 3,10, 8, 0, 6\n";

    std::string values2 = "3\n"
                         "0,0\n"
                         "2,2\n"
                         " 4, 2, 9\n"
                         " 4, 0,10\n"
                         " 4, 5, 2\n";


//    MyPriorityQueue<State<std::pair<int,int>,double>*, std::vector<State<std::pair<int,int>,double>*>,StateComparator<std::pair<int,int>,double>> pq;
//
//
//    auto asd = new State<std::pair<int,int>,double>({0,0},54);
//
//    pq.push(asd);
//    pq.push(new State<std::pair<int,int>,double>({1,1},4));
//    pq.push(new State<std::pair<int,int>,double>({2,2},6));
//    pq.push(new State<std::pair<int,int>,double>({3,3},23));
//    pq.push(new State<std::pair<int,int>,double>({4,4},25));
//    pq.push(new State<std::pair<int,int>,double>({5,5},65));
//
//    auto asdasd = pq.find(asd);
//
//    std::cout << ((*asdasd)->getCost()) << std::endl;
//    pq.remove(asd);
//    pq.push(new State<std::pair<int,int>,double>({0,0},30));
//
//    while(!pq.empty()) {
//        std::cout << pq.top()->getCost() << std::endl;
//        pq.pop();
//    }




//    std::cout << "------------" << std::endl;
//    std::cout << "Encoded: " << codec.encodeValue(values) << std::endl;
//    std::cout << "Decoded: " << codec.decodeValue(codec.encodeValue(values)) << std::endl;
//    std::cout << "------------" << std::endl;


//    std::pair<int,int> a1(-1,-1);
//    std::pair<int,int> a2(0,-1);
//
//    std::cout << (a1 == a2) << std::endl;

//    std::cout << a1 == a2 << std::endl;

    ISearchable<std::pair<int, int>, double> *searchable = new MazeDomain(values);

    BestFirstSearch<std::pair<int,int>,double> bfs;

    auto solution = bfs.search(searchable);

    std::cout << solution.getValues() << std::endl;

    return 0;
}

