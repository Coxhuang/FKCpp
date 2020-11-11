#include <iostream>
//#include <Python.h>
#include <python/python.h>



int main(int argc, char *argv[]) {
    std::cout << "Hello, Cpp 调用 Python程序!" << std::endl;

//    Py_SetProgramName(argv[0]);

    Py_Initialize();

    PyRun_SimpleString("print 'Hello Python!'\n");

    Py_Finalize();

    return 0;
}
