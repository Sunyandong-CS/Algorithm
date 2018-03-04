//
//  main.cpp
//  BestTimeToBuyAndSellStock
//
//  Created by 孙艳东 on 2018/3/4.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

/*
 LeetCode: 121. Best Time to Buy and Sell Stock https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 Example 1:
 Input: [7, 1, 5, 3, 6, 4]
 Output: 5
 
 max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 Example 2:
 Input: [7, 6, 4, 3, 1]
 Output: 0
 
 In this case, no transaction is done, i.e. max profit = 0.

 题目大意: 简单的来说就是给定一个商品价格变动的数组(num[])，假定第i天的价格是num[i],你可以在任意一天买入在其后卖出，计算你能获得的最大收益:
 **/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxCount = 0; // 最大收益
    int len = prices.size();
    if(len == 0) return 0;
    int minNum = prices[0]; // 记录当前最低价格
    
    vector<int> dp(len, 0); // dp[i] 记录第i天可以获得的最大收益
    dp[0] = 0;
    for(int i = 1;i < len; i ++) {
        minNum = min(prices[i],minNum);
        
        // 第i天的最大收益
        dp[i] = max(dp[i-1],prices[i] - minNum);
    }
    return dp[len -1];
}

int main(int argc, const char * argv[]) {
    return 0;
}
