#include <iostream>
#include <vector>

using namespace std;


int main() {

    vector<int> vec1_int; // 创建一个 int 类型容器
    vector<int> vec2_int(5); // 创建一个初始大小为5 的 int 类型容器
    vector<int> vec3_int(5,1); // 创建一个初始大小为5, 默认值为1的 int 类型容器
    vector<int> vec4_int(vec3_int); // 创建(拷贝)一个以vec3_int为原型的 int 类型容器

//    cout << vec3_int.size(); // size() 容器大小
//    vec3_int.resize(9); // 重新分配容器的元素个数，如果重新分配的元素个数比原来的小，将截断序列，后面的部分丢弃，如果大于原来的个数，后面的值是c的值，默认为0
//    cout << vec3_int.capacity(); // capacity() 返回vector的实际存储空间的大小，这个一般大于或等于vector元素个数
//    cout << vec1_int.empty(); // 1
//    cout << vec3_int.empty(); // 0

    for (int i : vec3_int){
        cout<<i << " ";
    }

    // 修改:
//    vec3_int.assign(3,99); // 将丢弃原来的所有元素然后重新赋值, 99 99 99
//    vec3_int.insert(vec3_int.begin()+1,7); // 1 7 1 1 1 1
    cout << endl;

    for (int i : vec3_int){
        cout<<i << " ";
    }

    return 0;
}
