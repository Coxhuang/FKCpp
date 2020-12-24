#include <iostream>
#include "network.hpp"

#define WAIT_SECOND 3	//暂停时间，单位为“秒”


int main() {
    long int start_download_rates;	//保存开始时的流量计数
    long int end_download_rates;	//保存结果时的流量计数
    getCurrentDownloadRates(&start_download_rates);//获取当前流量，并保存在start_download_rates里

//    while(1){
//        getCurrentDownloadRates(&start_download_rates);//获取当前流量，并保存在start_download_rates里
//        sleep(WAIT_SECOND);	//休眠多少秒，这个值根据宏定义中的WAIT_SECOND的值来确定 //sleep的头文件在unistd.h
//        getCurrentDownloadRates(&end_download_rates);//获取当前流量，并保存在end_download_rates里
//        printf("download is : %.2lf Bytes/s\n", (float)(end_download_rates-start_download_rates)/WAIT_SECOND );//打印结果
//    }
    exit(EXIT_SUCCESS);
}
