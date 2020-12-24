/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/14 4:47 下午
 */

#ifndef SPEEDTEST_NETWORK_HPP
#define SPEEDTEST_NETWORK_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

long int getCurrentDownloadRates(long int *save_rate) {
    FILE * net_dev_file;	// 文件指针
    char buffer[1024];	// 文件中的内容暂存在字符缓冲区里
    size_t bytes_read;	// 实际读取的内容大小
    char * match;	 // 用以保存所匹配字符串及之后的内容
    if ( (net_dev_file=fopen("/proc/net/dev", "r")) == NULL ){ //打开文件/pro/net/dev/，我们要读取的数据就是它啦
        printf("open file /proc/net/dev/ error!\n");
        exit(EXIT_FAILURE);
    }
    bytes_read = fread(buffer, 1, sizeof(buffer), net_dev_file);//将文件中的1024个字符大小的数据保存到buffer里
    fclose(net_dev_file); //关闭文件
    if ( bytes_read == 0 ) {//如果文件内容大小为０，没有数据则退出
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0';
    match = strstr(buffer, "e*:"); // 匹配ens33第一次出现的位置，返回值为第一次出现的位置的地址
    if ( match == NULL ){
        printf("no ens33 keyword to find!\n");
        exit(EXIT_FAILURE);
    }
    long int temp;
    long int temp2;
    long int temp3;
    long int temp4;
    long int temp5;
    long int temp6;
    long int temp7;
    long int temp8;
    long int temp9;
    sscanf(match, "e*:%ld%ld%ld%ld%ld%ld%ld%ld%ld", &temp,&temp2,&temp3,&temp4,&temp5,&temp6,&temp7,&temp8,&temp9); // 从字符缓冲里读取数据，这个值就是当前的流量啦。呵呵。
//    sscanf(match, "ens33:%ld{7}%ld", &temp,&temp9); // 从字符缓冲里读取数据，这个值就是当前的流量啦。呵呵。
//    sscanf(match, "ens33:%ld", save_rate); // 从字符缓冲里读取数据，这个值就是当前的流量啦。呵呵。
//    sscanf(match, "ens33:%ld", save_rate); // 从字符缓冲里读取数据，这个值就是当前的流量啦。呵呵。
//    printf("---------:%s%ld \n",match, *save_rate);
    printf("----temp-----:%ld \n",temp9);
    printf("---------:%s \n",match);
//    printf("---------:%ld \n", *temp);
    return *save_rate;
}


#endif //SPEEDTEST_NETWORK_HPP
