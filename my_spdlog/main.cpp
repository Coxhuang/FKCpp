#include <iostream>
#include "tlog/src/tlog.h"
#include "tlog/src/log.hpp"
#include <vector>

int main() {
    int a = 1;
    int b = 2;
    std::vector<int> v(10,1);
    log->info("**************************************************");
    log->info("****************** Process Init {} {}******************",v,b);
    return 0;
}
