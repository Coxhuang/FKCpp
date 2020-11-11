#include "tbs_hsm.h"

int main() {
    TbsHsm tbshsm_instance;
    tbshsm_instance.event_set_task();
    tbshsm_instance.event_lock();
    tbshsm_instance.event_lock_recover();
    tbshsm_instance.event_error();
    tbshsm_instance.event_error_recover();
    tbshsm_instance.event_set_task();
    tbshsm_instance.event_start_up();
    tbshsm_instance.event_stop();
    tbshsm_instance.event_lock();
    tbshsm_instance.event_lock_recover();
}

