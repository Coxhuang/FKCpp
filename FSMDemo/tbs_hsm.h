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
    Transition goto_inner_state(); // 跳转到Work内部指定状态

public: // event
    void set_task_event();
    void cancel_task_event();
    void truck_lock_event();
    void truck_unlock_event();
    void truck_run_event();
    void truck_stop_event();
    void truck_guide_stop_event();
    void truck_calibrate_event();
    void truck_arrived_event();

private:
    friend struct TBSHSMStates;
    StateMachine state_machine_;

public:
    std::string current_state = "Idle"; // 当前状态机的状态
    std::string current_inner_state = "TargetSet"; // 当前状态机内部的状态

public:
    bool signal_set_task; // 任务: true:下发任务 false: _
    bool signal_cancel_task; // 取消: true:取消任务 false: _
    bool signal_lock; // 锁: true:加锁 false:解锁
    bool signal_run; //
    bool signal_stop; //
    bool signal_guide_stop; //
    bool signal_calibrate; //
    bool signal_arrived; //
};


struct TbsHsmStates {

    struct BaseState : StateWithOwner<TbsHsm> {
    };

    struct Idle : BaseState {

        virtual void OnEnter() {
            Owner().current_state = "Idle";
        }

        virtual void OnExit() {

        }

        virtual Transition GetTransition() {
            if (Owner().signal_set_task){ // 下发任务
                return SiblingTransition<Work>();
            } else{
                return NoTransition();
            }

        }
    };

    struct Work : BaseState {

        virtual void OnEnter() {
            Owner().current_state = "Work";
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_cancel_task){ // 取消任务
                return SiblingTransition<Idle>(); // 取消任务-> 空闲状态
            } else{
                if (Owner().signal_lock){ // 锁车
                    return SiblingTransition<Locked>(); // 加锁-> 锁车状态
                } else{
                    return Owner().goto_inner_state();
                }
            }
        }
    };

    struct TargetSet : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "TargetSet";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_run){
                return InnerTransition<Driving>();
            } else{
                return NoTransition();
            }
        }
    };

    struct Driving : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "Driving";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_stop) {  // 停车
                return InnerTransition<Stop>();
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
            if (Owner().signal_guide_stop){ // 引导停车
                return InnerTransition<GuideStop>();
            } else if (Owner().signal_calibrate){ // 对位
                return InnerTransition<Calibrate>();
            } else if (Owner().signal_arrived){ // 到达
                return InnerTransition<Arrived>();
            } else{
                return NoTransition();
            }
        }
    };

    struct GuideStop : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "GuideStop";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_calibrate){ // 对位
                return InnerTransition<Calibrate>();
            } else{
                return NoTransition();
            }
        }
    };

    struct Calibrate : BaseState {

        virtual void OnEnter() {
            Owner().current_inner_state = "Calibrate";
            std::cout << "当前内部状态: Work_" << Owner().current_inner_state << std::endl;
        }
        virtual void Update(){
        }

        virtual Transition GetTransition() {
            if (Owner().signal_arrived){ // 到达
                return InnerTransition<Arrived>();
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
            return NoTransition();
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
            if (!Owner().signal_lock){  // 解锁
                return SiblingTransition<Work>();
            } else{
                return NoTransition();
            }
        }
    };
};

#endif //FSMDEMO_TBS_HSM_H
