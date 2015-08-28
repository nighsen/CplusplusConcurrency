// CplusplusConcurrency.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sorter.h"
#include "ThreadPool.h"
#include "MessageBus.h"
#include <stdio.h>

//for complex MessageBus below
/*MessageBus g_bus;
const std::string Topic = "Drive";
const std::string CallbackTopic = "DriveOk";

struct Subject
{
    Subject()
    {
        g_bus.Attach([this] {DriveOk();}, CallbackTopic);
    }
    void SendReq(const std::string& topic)
    {
        g_bus.SendReq<void, int>(50, topic);
    }
    void DriveOk()
    {
        std::cout << "drive ok" << std::endl;
    }
};

struct Car
{
    Car()
    {
        g_bus.Attach([this](int speed) { Drive(speed);}, Topic);
    }

    void Drive(int speed)
    {
        std::cout << "Car drive" << speed << std::endl;
        g_bus.SendReq<void>(CallbackTopic);
    }
};

struct Bus
{
    Bus()
    {
        g_bus.Attach([this](int speed) { Drive(speed);});
    }

    void Drive(int speed)
    {
        std::cout << "Bus drive" << speed << std::endl;
        g_bus.SendReq<void>(CallbackTopic);
    }
};

struct Truck
{
    Truck()
    {
        g_bus.Attach([this]() { Drive();});
    }

    void Drive()
    {
        std::cout << "Truck drive" << std::endl;
        g_bus.SendReq<void>(CallbackTopic);
    }
};
*/

int main()
{
    //for ThreadPool below
    /*
    ThreadPool pool(2);

    std::thread t1([&pool] {
        for (int i = 0; i < 10; i++)
        {
            auto id = std::this_thread::get_id();
            pool.AddTask([id] {
                std::cout << "sync thread1 id:" << id << std::endl;
            });
        }
    });

    std::thread t2([&pool] {
        for (int i = 0; i < 10; i++)
        {
            auto id = std::this_thread::get_id();
            pool.AddTask([id] {
                std::cout << "sync thread2 id:" << id << std::endl;
            });
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(2));
    getchar();
    pool.Stop();
    t1.join();
    t2.join();
    */

    //for MessageBus below
    /*
    MessageBus bus;
    bus.Attach([](int a) {std::cout << "no reference " << a << std::endl;});
    bus.Attach([](int& a) {std::cout << "lvalue reference " << a << std::endl;});
    bus.Attach([](int&& a) {std::cout << "rvalue reference " << a << std::endl;});
    bus.Attach([](const int& a) {std::cout << "const lvalue reference " << a << std::endl;});
    bus.Attach([](int a) { std::cout << "no reference has return value and key " << a << std::endl; return a;}, "a");

    int i = 2;
    bus.SendReq<void, int>(2);
    bus.SendReq<int, int>(2, "a");
    bus.SendReq<void, int&>(i);
    bus.SendReq<void, const int&>(2);
    bus.SendReq<void, int&&>(2);

    bus.Remove<void, int>();
    bus.Remove<int, int>("a");
    bus.Remove<void, int&>();
    bus.Remove<void, const int&>();
    bus.Remove<void, int&&>();

    bus.SendReq<void, int>(2);
    bus.SendReq<int, int>(2, "a");
    bus.SendReq<void, int&>(i);
    bus.SendReq<void, const int&>(2);
    bus.SendReq<void, int&&>(2);
    */

    //for complex MessageBus below
    /*
    Subject s;
    Car car;
    Bus bus;
    Truck truck;
    s.SendReq(Topic);
    s.SendReq("");
    */


    return 0;
}

