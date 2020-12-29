#include <glog/logging.h>

int main(int argc,char* argv[]) {

    google::InitGoogleLogging(argv[0]);

//    FLAGS_log_dir = "./log";

//    LOG(INFO) << "hello world";
    google::ShutdownGoogleLogging(); // 当要结束glog时必须关闭库，否则会内存溢出
    return 0;
}
