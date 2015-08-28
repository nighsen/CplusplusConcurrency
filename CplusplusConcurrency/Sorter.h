#pragma once
#include <list>
#include <future>
#include <vector>
#include <thread>
#include "ThreadSafeStack.h"

template<typename T>
struct sorter
{
    struct chunk_to_sorter
    {
        std::list<T> data;
        std::promise<std::list<T>> promise;
    };

    threadsafe_stack<chunk_to_sorter> chunks;
    std::vector<std::thread> threads;
};