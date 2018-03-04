//
//  main.cpp
//  HouseBobber
//
//  Created by 孙艳东 on 2018/3/4.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

/*
 
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 
 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 题目大意:
 给定一串非负数字代表每一家拥有的金额数量，求出在不惊动警察的条件下你能抢走的最大金额数量（你不能抢夺连续两家的金钱）：
 
 **/


#include <iostream>
#include <vector>
using namespace std;

int maxNum(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}
int rob(vector<int> &num) {
    int len = num.size();
    if (len == 0) return 0;
    if (len == 1) return num[0];
    if (len == 2) return maxNum(num[0], num[1]);
    
    vector<int> dp(len, 0); // dp[i] 表示前i家人可以抢到的最大金额
    dp[0] = num[0];
    dp[1] = maxNum(num[0], num[1]);
    for(int i = 2;i < len; i++) {
        
        // 由于不能抢相邻的家庭,所以到第i家时，此时最大的金额应该为第i-2家的钱加上当前的钱与前i-1家得到的最大金额dp[i -1]相比较中大的那一个
        dp[i] = maxNum(dp[i - 2] + num[i], dp[i - 1]);
    }
    return dp[len - 1];
}

int main(int argc, const char * argv[]) {
    
    vector<int> num;
    
    return 0;
}
