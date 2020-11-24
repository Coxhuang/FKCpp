#include <iostream>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>

namespace sc = boost::statechart;


class event_working : public sc::event<event_working> {}; // 工作事件
class event_music : public sc::event<event_music> {}; // 娱乐事件
class event_sleeping : public sc::event<event_sleeping> {}; // 休息事件

class Recreation; // 娱乐状态
class Work; // 工作状态
class Sleep; // 休息状态


class Machine : public sc::state_machine<Machine, Recreation> {};
//这里定义了一个状态机类Machine。初始状态在Idle

class Recreation : public sc::simple_state<Recreation, Machine> { //这里定义一个了状态Recreation，属于Machine状态机。
public:

    typedef sc::transition<event_working, Work> reactions; // 在Recreation中触发event_working事件,跳转到Work状态

    Recreation(void) {
        std::cout << "当前状态: Recreation" << std::endl;
    }

    ~Recreation(void) {}

};

class Work : public sc::simple_state<Work, Machine> { //这里定义一个了状态Work，属于Machine状态机。
public:
    typedef sc::transition<event_music, Recreation> react_music; // 在Work中触发event_music事件,跳转到Recreation状态
    typedef sc::transition<event_sleeping, Sleep> react_sleeping; // 在Work中触发event_sleeping事件,跳转到Sleep状态
    typedef boost::mpl::list<react_music, react_sleeping> reactions; // 跳转表


    Work(void) {
        std::cout << "当前状态: Work" << std::endl;
    }

    ~Work(void) {}

};

class Sleep : public sc::simple_state<Sleep, Machine> { //这里定义一个了状态 Sleep，属于Machine状态机。
public:
    typedef sc::custom_reaction< event_working > reactions;

    sc::result react( const event_working &evt ){
        return transit< Work >(); // 跳转到 Work
    }

    Sleep(void) {
        std::cout << "当前状态: Sleep" << std::endl;
    }

    ~Sleep(void) {}

};


int main() {
    Machine mc;
    mc.initiate();
    mc.process_event(event_working()); // 触发工作事件
    mc.process_event(event_sleeping()); // 触发休息事件
    mc.process_event(event_working()); // 触发工作事件

    return 0;
}

