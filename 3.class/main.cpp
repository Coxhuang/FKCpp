#include "point.h"


//class Point{
//
//    public:
//        void set_point(int x, int y) {
//            xPos = x;
//            yPos = y;
//        }
//
//        void print_point() const {
//            cout<< "x = " << xPos << endl;
//            cout<< "y = " << yPos << endl;
//        }
//
//    private:
//        int xPos;
//        int yPos;
//};

//class Point {
//
//public:
//    void set_point(int x, int y); // 声明
//    void print_point() const ; // 声明
//
//private:
//    int xPos;
//    int yPos;
//};
//
//void Point::set_point(int x, int y) { // 定义
//    xPos = x;
//    yPos = y;
//}
//
//void Point::print_point() const { // 定义
//    cout<< "x = " << xPos << endl;
//    cout<< "y = " << yPos << endl;
//}

int main()
{

    Point point_obj{}; //  Point 对象名; 实例化
    point_obj.set_point(10, 20);
    point_obj.print_point();

    // 输出> x = 10 y = 20

    const Point const_point_obj{}; // 常量对象
//    point_obj.set_point(10, 20); // const对象只能调用const成员函数。
    const_point_obj.print_point(); // print_point是const函数, 所以允许调用

    // 输出> x = 0 y = 0


    return 0;
}