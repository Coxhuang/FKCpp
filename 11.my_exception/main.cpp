#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception
{
    const char * what () const throw ()
    {
        return "Cpp Exception";
    }
};

int main() {
    std::cout << "Hello, Exception!" << std::endl;

    try {
//        throw length_error("length_error异常");
        throw MyException(); // 主动抛出自定义异常
    } catch (logic_error e) {
        cout<<e.what()<<endl;
    }catch (MyException& e) { // 捕获自定义异常
        cout<<e.what()<<endl; // 打印异常信息
    }
    catch (exception e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
