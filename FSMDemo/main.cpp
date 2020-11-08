#include "tbs_hsm.h"

int main() {
    TbsHsm tbshsm_instance;
    tbshsm_instance.set_task_event();
    tbshsm_instance.truck_run_event();
    tbshsm_instance.truck_lock_event();
    tbshsm_instance.truck_unlock_event();
    tbshsm_instance.truck_stop_event();
    tbshsm_instance.truck_lock_event();
    tbshsm_instance.truck_unlock_event();
    tbshsm_instance.truck_guide_stop_event();
    tbshsm_instance.truck_calibrate_event();
    tbshsm_instance.truck_arrived_event();
}

