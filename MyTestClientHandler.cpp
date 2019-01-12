
#include "MyTestClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

MyTestClientHandler:
MyTestClientHandler(Solver<Problem, Solution>
*solver,
CacheManger <Key, Value> *cm
){
this->
solver = solver;
this->
cm = cm;
}

void MyTestClientHandler::handleClient(istream inputStream, ostream outputStream) {
    string input;
    inputStream.getline(input);
    while (input != "end") {
        if (this->cm->doesExist) {
            this->cm->get(input);
        } else {
            this->cm->set(input, this->solver->solve(input));

        }
    }
}
