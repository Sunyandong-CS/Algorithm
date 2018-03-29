//
//  main.cpp
//  setValue
//
//  Created by 孙艳东 on 2018/3/25.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>

int i = 1;
int main(int argc, const char * argv[]) {
    
    // 这段代码并不会报错，但i的值是未定义的，可能是0，与外面的i无关
    int i = i;
    
    return 0;
}
