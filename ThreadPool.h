//
// Created by rim on 11/23/22.
//

#ifndef PROJET_TETRAVEX_THREADPOOL_H
#define PROJET_TETRAVEX_THREADPOOL_H

#include <vector>
#include <stack>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadPool{

    std::vector<std::thread*> threads;

public:
    std::mutex * m;
    std::condition_variable * cond;
    ThreadPool();
    void addThread(std::thread* t);
    void joinThreads();
    void exec();
    void killThreads();
};


#endif //PROJET_TETRAVEX_THREADPOOL_H
