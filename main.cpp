#include <iostream>
#include "MySerialServer.h"
#include "Base64Codec.h"
#include "StringReverser.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "AstarAlgo.h"
#include "DFS.h"
#include "ISearchable.h"
#include "MazeDomain.h"
#include "ICacheManager.h"
#include "FileCacheManager.h"
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "SearchableSolverAdapter.h"
#include "MyClientHandler.h"

int main(int argc, char* argv[]) {

    server_side::IServer * server = new MyParallelServer();
    server_side::ICacheManager<std::string, std::string> * cm = new FileCacheManager;
    server_side::ISolver<ISearchable<std::pair<int,int>,double>*,std::string>* solver = new SearchableSolverAdapter();
    server_side::IClientHandler * clientHandler = new MyClientHandler(solver,cm);

    server->open(stoi(argv[1]),clientHandler);

    delete server;
    server = NULL;
    delete solver;
    solver = NULL;
    delete cm;
    cm = NULL;
    delete clientHandler;
    clientHandler = NULL;

    return 0;
}

