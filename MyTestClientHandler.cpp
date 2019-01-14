#include <cstdlib>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <strings.h>
#include "MyTestClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

template<typename Problem, typename Solution>
void MyTestClientHandler<Problem, Solution>::handleClient(int socketIdentity) {

//    string input;
//    inputStream.getline(input);
//    while (input != "end") {
//        if (this->cm->doesExist) {
//            this->cm->get(input);
//        } else {
//            this->cm->set(input, this->solver->solve(input));
//
//<<<<<<< Updated upstream
//        }
//    }
//=======
    char buffer[256];
    int n;

    /* If connection is established then start communicating */
    bzero(buffer, 256);
    n = read(socketIdentity, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);
    close(socketIdentity);
//>>>>>>> Stashed changes
}

template<typename Problem, typename Solution>
MyTestClientHandler<Problem, Solution>::MyTestClientHandler(server_side::ISolver<Problem, Solution> *solver,
                                                            server_side::ICacheManager<Problem, Solution> *cm):solver(
        solver), cm(cm) {}
