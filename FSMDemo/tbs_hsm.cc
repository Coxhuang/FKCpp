/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/6 9:57 上午
 */
#include "tbs_hsm.h"

TbsHsm::TbsHsm() {
    state_machine_.Initialize<TbsHsmStates::Idle>(this); // 初始状态: Idle
    std::cout << "当前状态: " << current_state << std::endl;
    state_machine_.SetDebugInfo("TbsHsmDemo", TraceLevel::Basic);
}

// TbsHsm

void TbsHsm::update() {
    state_machine_.ProcessStateTransitions();
    state_machine_.UpdateStates();
}

std::string TbsHsm::get_state() const {
    std::cout << "当前状态: " << current_state << std::endl;
    return current_state;
}

Transition TbsHsm::goto_inner_state() const {

    if( current_inner_state == "Runing" ){
        return InnerEntryTransition<TbsHsmStates::Runing>();
    } else if( current_inner_state == "Stop" ){
        return InnerEntryTransition<TbsHsmStates::Stop>();
    } else if( current_inner_state == "Arrived" ){
        return InnerEntryTransition<TbsHsmStates::Arrived>();
    } else{
        return NoTransition();
    }
}

void TbsHsm::event_set_task() {
    signal_set_task = true;
    update();
    signal_set_task = false;
}

void TbsHsm::event_lock() {
    signal_lock = true;
    update();
    signal_lock = false;
}

void TbsHsm::event_lock_recover() {
    signal_lock_recover = true;
    update();
    signal_lock_recover = false;
}

void TbsHsm::event_error() {
    signal_error = true;
    update();
    signal_error = false;
}

void TbsHsm::event_error_recover() {
    signal_error_recover = true;
    update();
    signal_error_recover = false;
}

void TbsHsm::event_start_up() {
    signal_start_up = true;
    update();
    signal_start_up = false;
}

void TbsHsm::event_stop() {
    signal_stop = true;
    update();
    signal_stop = false;
}

void TbsHsm::event_stop_recover() {
    signal_stop_recover = true;
    update();
    signal_stop_recover = false;
}

void TbsHsm::event_arrived() {
    signal_arrived = true;
    update();
    signal_arrived = false;
}

void TbsHsm::event_run() {
    signal_run = true;
    update();
    signal_run = false;
}






