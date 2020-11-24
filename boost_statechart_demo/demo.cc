#include <iostream>
#include <ctime>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>

namespace sc = boost::statechart;


class event_set_target : public sc::event<event_set_target> {}; // 下发任务
class event_lock : public sc::event<event_lock> {}; // 锁车
class event_error : public sc::event<event_error> {}; // 错误
class event_recover : public sc::event<event_recover> {}; // 恢复
class event_to_work : public sc::event<event_to_work> {}; // Work

class Idle; // 空闲
class Work; // 工作
class Locked; // 锁车
class Error; // 锁车
class Runing; // 运行

class Machine : public sc::state_machine<Machine, Idle> {
public:
    void go_to_inner_state(){
        std::cout << "go_to_inner_state" << std::endl;
    }
};
//这里定义了一个状态机类Machine。初始状态在Idle

class Idle : public sc::simple_state<Idle, Machine> { //这里定义一个了状态Idle，属于Machine状态机。
public:

//    typedef sc::transition<event_set_target, Work> reactions; // 在Idel中触发event_set_target事件,跳转到Work状态
    typedef sc::custom_reaction< event_set_target > reactions;
    sc::result react( const event_set_target & ){
        return transit<Work>(); // 跳转 Work
    }

    Idle(void) {
        std::cout << "当前状态: Idle" << std::endl;
    }

    ~Idle(void) {
        post_event(event_lock()); //允许从构造函数中发放消息
    }

};

class Work : public sc::simple_state<Work, Machine> { //这里定义一个了状态Work，属于Machine状态机。
public:
    typedef sc::transition<event_lock, Locked> react_lock; // 在Idel中触发event_lock事件,跳转到Locked状态
    typedef sc::transition<event_error, Error> react_error; // 在Idel中触发event_lock事件,跳转到Locked状态
    typedef boost::mpl::list<react_lock, react_error> reactions; // 跳转表


    Work(void) {
        std::cout << "当前状态: Work" << std::endl;
    }

    ~Work(void) {
    }

};

class Runing : public sc::simple_state<Runing, Machine> {
public:

    Runing(void) {
        std::cout << "当前状态: Runing" << std::endl;
    }

    ~Runing(void) {}

};


class Locked : public sc::simple_state<Locked, Machine> { //这里定义一个了状态 Locked，属于Machine状态机。
public:
    typedef sc::transition<event_recover, Work> react_recover; // 在Idel中触发event_recover事件,跳转到Work状态
    typedef boost::mpl::list<react_recover> reactions; // 跳转表

    Locked(void) {
        std::cout << "当前状态: Locked" << std::endl;
    }

    ~Locked(void) {}

};

class Error : public sc::simple_state<Error, Machine> { //这里定义一个了状态 Error，属于Machine状态机。
public:
    typedef sc::transition<event_recover, Idle> react_recover; // 在Idel中触发event_recover事件,跳转到Idle状态
    typedef boost::mpl::list<react_recover> reactions; // 跳转表

    Error(void) {
        std::cout << "当前状态: Error" << std::endl;
    }

    ~Error(void) {}

};

//int main() {
//    Machine mc;
//    mc.initiate();
//
//    mc.process_event(event_set_target()); // 触发set_taregte事件
////    mc.process_event(event_lock()); // 触发lock事件
////    mc.process_event(event_error()); // 触发lock事件
////    mc.process_event(event_recover()); // 触发recover事件
//
//    return 0;
//}

