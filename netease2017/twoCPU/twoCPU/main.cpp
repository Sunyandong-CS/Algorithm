//
//  main.cpp
//  twoCPU
//
//  Created by 孙艳东 on 2018/3/27.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int count = 0;
    int sum = 0;
    int l,r;
    cin>>l>>r;
    if (l % 3 != 0) {
        count = ((r - l) / 3 ) * 2;
        count = count + (r - l + 1) % 3;
    }else if(l % 3 == 0 && (l + 1) % 3 == 0 ) {
        count = ((r - l + 1) / 3 ) * 2;
        count = count + (r - l + 1) % 3;
    } else {
        count = ((r - l + 1) / 3 ) * 2;
        count = count + (r - l) % 3;
    }
    cout << count;
    return 0;
}
