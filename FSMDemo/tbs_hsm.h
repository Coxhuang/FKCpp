/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/6 9:57 上午
 */

#ifndef FSMDEMO_TBS_HSM_H
#define FSMDEMO_TBS_HSM_H
//https://github.com/amaiorano/hsm/wiki
#include "hsm/include/hsm.h"
#include <cstdio>
#include <iostream>

using namespace hsm;


class TbsHsm {
public:
    TbsHsm();

public:
    void update();
    std::string get_state() const;
    Transition goto_inner_state() const; // 跳转到Work内部指定状态

public: // event
    void event_set_task();
    void event_lock();
    void event_lock_recover();
    void event_error();
    void event_error_recover();
    void event_start_up();
    void event_stop();
    void event_stop_recover();
    void event_arrived();
    void event_run();

private:
    friend struct TBSHSMStates;
    StateMachine state_machine_;

public:
    std::string current_state = "Idle"; // 当前状态机的状态
    std::string current_inner_state = "Work"; // 当前状态机内部的状态

public:
    bool signal_set_task{false}; // 任务: true:下发任务 false: _

    bool signal_lock{false}; // 锁车: true:锁车 false: _
    bool signal_lock_recover{false}; // 锁车恢复: true:锁车恢复 false: _

    bool signal_error{false}; // 错误: true:错误 false: _
    bool signal_error_recover{false}; // 错误恢复: true:错误恢复 false: _

    bool signal_start_up{false}; // 开始: true:开始 false: _

    bool signal_stop{false}; // 停车: true:停车 false: _
    bool signal_stop_recover{false}; // 停车恢复: true:恢复 false: _

    bool signal_arrived{false}; // 到达终点: true:到达 false: _

    bool signal_run{false}; // 继续运行: true:运行 false: _

};


struct TbsHsmStates {

    struct BaseState : StateWithOwner<TbsHsm> {
    };

    struct Idle : BaseState {

        virtual void OnEnter() {
            Owner().current_state = "Idle"; // 初始值
            Owner().current_inner_state = "Work"; // 初始值
            std::cout << "当前状态: " << Owner().current_state << std::endl;
        }

        virtual void OnExit() {

        }

        virtual Transition GetTransition() {
            if (Owner().signal_set_task){
                return SiblingTransition<Work>();
            } else{
                return NoTransition();
            }
        }
    };

    struct Work : BaseState {

        virtual void OnEnter() {
            Owner().current_state = "Work";
            std::cout << "当前状态: " << Owner().current_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_set_task){ // 工作状态接收新的任务
                Owner().current_inner_state = "Work"; // 内部状态跳到 Work
                return NoTransition();
            } else if (Owner().signal_lock){
                return SiblingTransition<Locked>();
            } else if (Owner().signal_error){
                return SiblingTransition<Error>();
            } else if (Owner().signal_start_up){
                return InnerEntryTransition<Runing>(); // 外层状态跳转至内层状态: InnerEntryTransition
            } else{
                return Owner().goto_inner_state();
            }
        }
    };

    struct Runing : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "Runing";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_stop){
                return InnerTransition<Stop>(); // 内层状态跳转: InnerTransition
            } else if (Owner().signal_arrived){
                return InnerTransition<Arrived>(); // 内层状态跳转: InnerTransition
            } else{
                return NoTransition();
            }
        }
    };

    struct Stop : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "Stop";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_stop_recover){
                return InnerTransition<Runing>(); // 内层状态跳转: InnerTransition
            } else{
                return NoTransition();
            }
        }
    };

    struct Arrived : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "Arrived";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_run){
                return InnerTransition<Runing>(); // 内层状态跳转: InnerTransition
            } else{
                return NoTransition();
            }
        }
    };

    struct Locked : BaseState {
        virtual void OnEnter() {
            Owner().current_state = "Locked";
            std::cout << "当前状态: " << Owner().current_state << std::endl;
        }
        virtual void Update(){
        }
        virtual Transition GetTransition() {
            if (Owner().signal_lock_recover){ // 解锁
                return SiblingTransition<Work>();
            } else{
                return NoTransition();
            }
        }
    };

    struct Error : BaseState {

        virtual void OnEnter() {
            Owner().current_state = "Error";
            std::cout << "当前状态: " << Owner().current_state << std::endl;
        }

        virtual Transition GetTransition() {
            if (Owner().signal_error_recover){ // 退出error
                return SiblingTransition<Idle>();
            } else{
                return NoTransition();
            }
        }
    };
};

#endif //FSMDEMO_TBS_HSM_H
