#include <iostream>
#include <vector>

class A{
public:
    A(){
        std::cout << "A 构造函数" << std::endl;
    };
    explicit A(int t){
        std::cout << "A 一个参数 构造函数:" << t << std::endl;
        a_m = t;
    };
    A(const A& C){
        std::cout << "A 拷贝构造函数" << std::endl;
    };
    void get_a(){
        std::cout << "A get_a " << "a_m:" << a_m << std::endl;
    };
private:
    int a_m = 0;
};

class B{
public:
    B(){
        std::cout << "B 构造函数" << std::endl;
    };
    explicit B(int t){
        std::cout << "B 一个参数 构造函数:" << t << std::endl;
    };
    void get_b(){
        _a.get_a();
    };
private:
    A _a;
};


int const FRAME_SIZE = 87;


int main( int argc, char * argv[] ){

    std::vector<char> __buffer{'1','2','3','4','5','6','7','8'};
    std::vector<char> frame;
    std::vector<char>::iterator a;

//    __buffer.erase(__buffer.begin(),__buffer.begin()+2);
//    std::vector<char>::const_iterator first1 = __buffer.begin()+1;
//    std::vector<char>::const_iterator first4 = __buffer.begin()+4;
//    std::vector<char> cut1_vector;
//
//    for(auto el : cut1_vector) {
//        std::cout << el << " ";
//    }
//    std::cout << *(a+1) << std::endl;
//    int buffe_len = __buffer.size();

//    for (int i = 0; i < buffe_len; ++i){
//        std::cout << __buffer[i] << std::endl;
//    }
//    for(auto el : __buffer) {
//        std::cout << ": " <<el << " ";
//    }
    for (auto it = __buffer.begin(); it != __buffer.end(); ++it){
        if (*it == '2') {
//            std::cout << ": " << " ";
            frame.assign(it,__buffer.end());
            std::cout<<frame.size();
            for (auto el : frame) {
                std::cout << " " << el << " ";
            }
            std::cout << " " << std::endl;
            frame.assign(it,it+2);
//            std::cout<<frame.size();
            for (auto el : frame) {
                std::cout << " " << el << " ";
            }
        } else{

        }
    }

    return 0;
}
