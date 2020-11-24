/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/23 5:31 下午
 */
#include <iostream>
#include "person.h"

int main() {
    Person p;
    p.SetPerson("Alan", 18);
    p.SetBook("Effective C++", 51.8);
    p.Print();
    return 0;
}
 