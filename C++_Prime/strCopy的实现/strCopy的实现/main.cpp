//
//  main.cpp
//  strCopy的实现
//
//  Created by sunyandong on 2018/7/15.
//  Copyright © 2018年 sunyandong. All rights reserved.
//

/*
    不使用库函数实现strcpy
 */

#include <iostream>
using namespace std;


char * str_cpy(char *str_dest, const char *str_src) {
    if (str_src == NULL || str_dest == NULL) {
        return NULL;
    }
    char *str_dest_copy = str_dest;
    while (*str_src != '\0') {
        *str_dest = *str_src;
        str_dest ++;
        str_src ++;
    }
    return str_dest_copy;
}

int main(int argc, const char * argv[]) {
    char str_src[]="Sample string";
    char str_dest[40];
    str_cpy(str_dest, str_src);
    
    cout << str_dest;
    return 0;
}
