//
//  main.c
//  内存对齐
//
//  Created by 孙艳东 on 2018/3/16.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <stdio.h>

typedef struct stu {
    int a;
    char b;
    int  c;
}STU;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d!\n",sizeof(STU));
    return 0;
}
