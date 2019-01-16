#ifndef AP_MS2_THREADPOOL_H
#define AP_MS2_THREADPOOL_H

#define THREAD_POOL_SIZE 20

#include <thread>
#include <queue>
#include <atomic>
#include <mutex>
#include <string>
#include <iostream>
#include <condition_variable>
#include "IClientHandler.h"

/**
 * Task interface for ThreadPool.
 */
class Task {
public:

    /**
     * Used to adapt the object.
     */
    virtual void execute() = 0;
    virtual ~Task() {};
};

/**
  * Object Adapter finally utilized, this is used to take a ClientHandler, A TCPClient, and adapt
  * it to Task Interface, Perfect.
 */
class ClientHandlerTaskAdapter : public Task {
    server_side::IClientHandler *clientHandler;
    posix_sockets::TCPClient client;
public:
    /**
     * Object adapter for ClientHandler to Task.
     * @param clientHandler the clientHandler for handling requests.
     * @param client the client socket itself.
     */
    ClientHandlerTaskAdapter(server_side::IClientHandler *clientHandler, const posix_sockets::TCPClient &client);

    /**
     * Used to launch ClientHandler.
     */
    virtual void execute();

    virtual ~ClientHandlerTaskAdapter();
};

/**
 * TaskQueue used for queuing up tasks to a list of threads.
 */
class TasksQueue {
    std::atomic<bool> stop_queue;
    std::queue<Task*> tasks;
    mutable std::condition_variable queue_cond_var;
    mutable std::mutex mut;
public:
    TasksQueue() : stop_queue(false) {}

    /**
     * Used by threads to pop up the tasks.
     * @return
     */
    Task* pop();

    bool empty() const;

    /**
     * Add Tasks here.
     * @param task any class with Task implementation.
     */
    void push(Task* task);

    void wait() const;

    /**
     * Stop every thread and wait for them to finish.
     * @return true if successful.
     */
    bool stop() const;

    /**
     * Exit and kill TaskQueue.
     */
    void exit();
};

/**
 * ThreadPool design pattern, used to launch multiple functions on multiple ready made threads.
 */
class ThreadPool {
    /**
     * List of threads
     */
    std::queue<std::thread> workers;

    /**
     * Where all queues are set up.
     */
    TasksQueue tasks_queue;
    void worker();
public:
    ThreadPool();

    /**
     * Used to exit thread.
     */
    void exit();

    /**
     * Used to add queue to TaskQueue instance.
     * @param task
     */
    void addTask(Task* task);
};


#endif //AP_MS2_THREADPOOL_H
