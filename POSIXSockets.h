#ifndef AP_MS2_POSIXSOCKETS_H
#define AP_MS2_POSIXSOCKETS_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <iostream>
#include <string>
#include "string.h"
#include <system_error>
#include <stdexcept>

/**
 * OOP POSIX api implementation.
 */
namespace posix_sockets
{
    /**
     * Custom timeout exception.
     */
    class timeout_exception : public std::runtime_error {
    public:
        timeout_exception(const char *msg);
        timeout_exception(const std::string msg);
    };

    /**
     * Custom illegal exception
     */
    class illegal_state_exception : public std::logic_error {
    public:
        illegal_state_exception(const std::string msg);
    };


    // struct defining general socket, with general operations (open and close)
    // opening is done in the constructor.
    // the socket is not automatically closed in the destructor so that the object
    // can be passed as a parameter (possibly to another thread)
    struct TCPSocket {
        int sock_fd;
        TCPSocket();
        TCPSocket(int open_sock_fd);
        void close();
        void setTimeout(int sec, int usec = 0);
    };

    /**
     * TCPClient implementation.
     */
    class TCPClient {
        TCPSocket sock;
    public:
        // It makes sense to creates another constructor that
        // will create a client from scratch
        TCPClient(const TCPSocket sock);

        /**
         * Used to read line by line from socket, not as per standard, but enough for the job.
         * @param bufferLine the next line read from user.
         * @return status code.
         */
        long readLine(std::string &bufferLine);

        /**
         * Send message to client.
         * @param message the message to send.
         * @return status code.
         */
        long sendMessage(std::string &message);

        /**
         * Dynamicly set the timout of the sockets on the fly.
         * @param sec
         * @param usec
         */
        void setTimeout(int sec, int usec = 0);

        /**
         * Closes socket.
         */
        void close();
    };

    /**
     * TCP Server implementation.
     */
    class TCPServer {
        TCPSocket sock;
    public:
        /**
         * Set up a server with port
         */
        TCPServer(int port);

        /**
         * Listen with a max of X people.
         */
        void listen(int maxAllowedListens);

        /**
         * Set timeout for server.
         * @param sec seconds.
         * @param usec microseconds.
         */
        void setTimeout(int sec, int usec = 0);

        /**
         * Accept new client.
         * @return new client socket.
         */
        TCPClient accept();

        /**
         * Close socket.
         */
        void close();
    };
}

#endif //AP_MS2_POSIXSOCKETS_H
