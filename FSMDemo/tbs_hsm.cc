/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/6 9:57 上午
 */
#include "tbs_hsm.h"

// TbsHsm
TbsHsm::TbsHsm() : signal_lock(false) {
    state_machine_.Initialize<TbsHsmStates::Idle>(this); // 初始状态: Idle
    std::cout << "当前状态: " << current_state << std::endl;
    state_machine_.SetDebugInfo("TbsHsmDemo", TraceLevel::Basic);
}

void TbsHsm::update() {
    state_machine_.ProcessStateTransitions();
    state_machine_.UpdateStates();
}

std::string TbsHsm::get_state() const {
    std::cout << "当前状态: " << current_state << std::endl;
    return current_state;
}

void TbsHsm::set_task_event() {
    signal_set_task = true; // 设置任务
    std::cout << "触发任务事件 ";
    update(); // 更新
    signal_set_task = false;
}

void TbsHsm::cancel_task_event() {
    signal_cancel_task = true; // 取消任务
    std::cout << "触发取消事件 ";
    update(); // 更新
    signal_cancel_task = false;
}

void TbsHsm::truck_lock_event() {
    signal_lock = true; // 加锁
    std::cout << "触发锁车事件 ";
    update(); // 更新
}

void TbsHsm::truck_unlock_event() {
    signal_lock = false; // 解锁
    std::cout << "触发解锁事件 ";
    update(); // 更新
}

void TbsHsm::truck_run_event() {
    signal_run = true;
    std::cout << "触发开始事件 ";
    update(); // 更新
    signal_run = false;
}

void TbsHsm::truck_stop_event() {
    signal_stop = true; // 停车
    std::cout << "触发停车事件 ";
    update(); // 更新
}

void TbsHsm::truck_guide_stop_event() {
    signal_guide_stop = true; // 引导停车
    std::cout << "触发引导停车事件 ";
    update(); // 更新
    signal_guide_stop = false;
}

void TbsHsm::truck_calibrate_event() {
    signal_calibrate = true; // 对位
    std::cout << "触发对位事件 ";
    update(); // 更新
    signal_calibrate = false;
}

void TbsHsm::truck_arrived_event() {
    signal_arrived = true; // 到达
    std::cout << "触发到达事件 ";
    update(); // 更新
    signal_arrived = false;
}

Transition TbsHsm::goto_inner_state() {

    if( current_inner_state == "TargetSet" ){
        return InnerEntryTransition<TbsHsmStates::TargetSet>();
    }
    else if( current_inner_state == "Driving" ){
        return InnerEntryTransition<TbsHsmStates::Driving>();
    }
    else if( current_inner_state == "Stop" ){
        return InnerEntryTransition<TbsHsmStates::Stop>();
    }
    else if( current_inner_state == "GuideStop" ){
        return InnerEntryTransition<TbsHsmStates::GuideStop>();
    }
    else if( current_inner_state == "Calibrate" ){
        return InnerEntryTransition<TbsHsmStates::Calibrate>();
    }
    else if( current_inner_state == "Arrived" ){
        return InnerEntryTransition<TbsHsmStates::Arrived>();
    }
    else{
        std::cout << "强制跳转 异常" << std::endl;
        return InnerEntryTransition<TbsHsmStates::TargetSet>();
    }

}



