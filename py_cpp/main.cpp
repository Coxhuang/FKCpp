#include <iostream>
#include <boost/python.hpp>
using namespace std;
using namespace boost::python;


int main()
{
//    Py_Initialize();
////    PyRun_SimpleString("import sys");
////    int argc = 1;
////    wchar_t argv[1]; //python2使用char,与python3有区别
////    if (PyRun_SimpleString("exec(open('/home/trunk/huang/test/py_cpp/call.py').read())")){
////        cout << "Fail 2" <<endl;
////        return -1;
////    }
////    Py_Finalize();
//
//    PyRun_SimpleString("print('----------Python Start')");
//
//
//    //引入当前路径,否则下面模块不能正常导入
//    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("sys.path.append('./')");
//
//    PyObject *pModule = PyImport_ImportModule("call"); // 导入py文件
//
//    PyObject *pDict = PyModule_GetDict(pModule); // 获取py文件内容(字典格式)
//
//
//    PyObject *pFunc = PyObject_GetAttrString(pModule, "haha"); // 获取函数
//
//    pFunc = PyDict_GetItemString(pDict, "haha");
//
//    PyObject *pArg = Py_BuildValue("(s)", "Hello Charity");
//
//
//    PyObject *result = PyEval_CallObject(pFunc,pArg);
//
//    //c用来保存c/c++类型的返回值
//    int c;
//    //将python类型的返回值转换为c/c++类型
//    PyArg_Parse(result, "i", &c);
//    //输出返回值
//    printf("a+b=%d\n", c);
//
//
//
//
//
//    pFunc = PyDict_GetItemString(pDict, "haha"); // 从字典属性中获取函数
//
//
//    Py_Finalize(); // 释放python
//    getchar();
//
//
//
//    return 0;

    Py_Initialize();//使用python之前，要调用Py_Initialize();这个函数进行初始化
    if (!Py_IsInitialized())
    {
        printf("初始化失败！");
        return 0;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/trunk/huang/test/py_cpp')");//这一步很重要，修改Python路径


    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    pModule = PyImport_ImportModule("sub_system");
    if (pModule==NULL) {
        cout << "没找到" << endl;
    }
    pFunc = PyObject_GetAttrString(pModule, "get");//这里是要调用的函数名
//    PyObject* args = Py_BuildValue("(ii)", 1, 2);//给python函数参数赋值

    PyObject* pRet = PyObject_CallObject(pFunc, nullptr);

    int res1 = 0;
//    int res2 = 0;
//    int res3 = 0;
//    int res4 = 0;
//    int res5 = 0;
//    PyArg_Parse(pRet,"iiiii",&res1,&res2,&res3,&res4,&res5);// 转换返回类型
    PyArg_Parse(pRet,"i",&res1);// 转换返回类型

    cout << "res1:" << res1 << endl;// 输出结果
//    cout << "res2:" << res2 << endl;// 输出结果
//    cout << "res3:" << res3 << endl;// 输出结果
//    cout << "res4:" << res4 << endl;// 输出结果
//    cout << "res5:" << res5 << endl;// 输出结果

    Py_Finalize();//调用Py_Finalize，这个根Py_Initialize相对应的。

    return 0;

}
