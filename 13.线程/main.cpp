#include <iostream>
#include <thread>
#include <mutex>
#include "ThreadPool.h"

int count = 10;
std::mutex lock;


void func1(){
    std::cout << "func1: " << std::this_thread::get_id() << " :func1"  << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // 休眠
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    while (count>0){
//        lock.lock();
//        count--;
//        std::cout << count << std::endl;
//        lock.unlock();
//    }
//    while (count>0){
//        std::lock_guard<std::mutex> lk(lock);
//        count--;
//        std::cout << count << std::endl;
//    }
}
void func2(){
    std::cout << "func2: " << std::this_thread::get_id() << " :func2" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // 休眠
//    while (count>0){
//        lock.lock();
//        count--;
//        std::cout << count << std::endl;
//        lock.unlock();
//    }
//    while (count>0){
//        std::lock_guard<std::mutex> lk(lock);
//        count--;
//        std::cout << count << std::endl;
//    }
}

class MyThread{
public:
    static void func_1(int a){
        std::cout << "func_1: " << a << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // 休眠

    }
    static void func_2(std::shared_ptr<std::string> &a){
        std::cout << "func_2: " << a << std::endl;
    }
};

int main() {
    std::cout << "Hello, Thread!" << std::endl;
//    std::thread t1(func1);
//    std::thread t2(func2);
//
//    t1.join();
//    t2.join();
//    ThreadPool pool(4);
//    pool.enqueue(func1);
//    pool.enqueue(func1);
//    pool.enqueue(func2);
//    pool.enqueue(func2);
//    pool.enqueue(func2);
//    MyThread::func_1(1);
    std::shared_ptr<std::string> pt = std::make_shared<std::string>("hello");
    std::thread t1(&MyThread::func_1,1);
    std::thread t2(&MyThread::func_2, std::ref(pt));
//    t1.detach();
    t1.join();
//    t2.detach();
    t2.join();
    std::cout << "aaaa";
    return 0;
}
