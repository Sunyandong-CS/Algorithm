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
using namespace std;
int main(int argc, const char * argv[]) {
    int n = 0;
    int k = 0;
    vector<int> num;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        int tem = 0;
        cin >> tem;
        num.push_back(tem);
    }
    for(int j = 0; j < k; j ++) {
        for (int i = 0; i < n; i ++) {
            if(i == n - 1) {
                num[i] = (num[i] + num[0]) % 100;
            } else {
                num[i] = (num[i] + num[i + 1]) % 100;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        if(i == n - 1) {
            cout<<num[i];
        } else {
            cout<<num[i]<<" ";
        }
        
    }
    return 0;
}
