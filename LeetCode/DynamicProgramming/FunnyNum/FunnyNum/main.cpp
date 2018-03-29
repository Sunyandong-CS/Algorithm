//
//  main.cpp
//  FunnyNum
//
//  Created by 孙艳东 on 2018/3/5.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(int argc, const char * argv[]) {
    
    int n = 0;
    while(scanf("%d",&n)) {
        vector<int> num;
        int min = 0;
        int max = 0;
        int maxCount = 0;
        int minCount = 0;
        for (int i = 0; i < n; i++) {
            int tem;
            cin>> tem;
            num.push_back(tem);
        }
        sort(num.begin(),num.end());
        int len = num.size();
        max = num[len - 1] - num[0];
        min = max;
        for (int i = 0; i < len; i ++) {
            for(int j = i + 1;j < len; j ++) {
                if (num[j] - num[i] == max) {
                    maxCount ++;
                }
                if (num[j] - num[i] < min) {
                    min = num[j] - num[i];
                }
            }
        }
        for (int i = 0; i < len; i ++) {
            for(int j = i + 1;j < len; j ++) {
                if (num[j] - num[i] == min) {
                    minCount ++;
                }
            }
        }
        printf("%d %d",minCount,maxCount);
    }
    
    return 0;
}
