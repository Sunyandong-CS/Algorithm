//
//  main.cpp
//  power
//
//  Created by 孙艳东 on 2018/3/27.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0,m = 0;
    int power[10000];
    int diff[100000000];
    int pay[100000000];
    cin>>n>>m;
    vector<int> paym(m,0);
    for(int i = 0; i < n; i ++ ) {
        scanf("%d%d\n",&diff[i],&pay[i]);
    }
    for(int i = 0; i < m; i ++ ) {
        scanf("%d",&power[i]);
    }
    for(int i = 0; i < m; i ++ ) {
        int pw = power[i];
        int maxP = 0;
        for(int j = 0;j < n;j ++) {
            if (pw > diff[j] ) {
                maxP = maxP > pay[j] ? maxP:pay[j];
            }
        }
        paym.push_back(maxP);
    }
    
    for(int i = 0; i < m; i++) {
        printf("%d\n",paym[i]);
    }
    
    
    return 0;
}
