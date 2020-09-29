//
// Created by Cox on 2020/9/27.
//

#ifndef INC_5__PAT_H
#define INC_5__PAT_H

class MyPat{
public:
    char name{};
    MyPat(void);
    MyPat(int a);
    MyPat(char a);
    MyPat(char *a);
private:
    int age{};
    char *str1;
};

#endif //INC_5__PAT_H
