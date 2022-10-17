//
// Created by rim on 11/23/22.
//

#include <functional>
#include "ThreadPool.h"
#include <mutex>
#include <condition_variable>
ThreadPool::ThreadPool(){
    m = new std::mutex();
    cond = new std::condition_variable();
}
void ThreadPool::addThread(std::thread* t){threads.push_back(t);}
void ThreadPool::joinThreads(){for(std::thread* t : threads){t->join();}}
void ThreadPool::killThreads(){

    for(std::thread *t : threads){
        t->~thread();}

}
void ThreadPool::exec(){
    while (true)
    {
        std::unique_lock<std::mutex> u_lock(*m);
        cond->wait(u_lock, [this]{return !this->threads.empty();});

        std::thread* task = threads.front();
        threads.pop_back();

        m->unlock();
        cond->notify_one();

        task->join();
    }
}