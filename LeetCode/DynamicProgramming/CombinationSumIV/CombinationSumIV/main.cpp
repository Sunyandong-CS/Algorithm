//
//  main.cpp
//  CombinationSumIV
//
//  Created by 孙艳东 on 2018/3/5.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//


/**
 Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
 
 Example:
 
 nums = [1, 2, 3]
 target = 4
 
 The possible combination ways are:
 (1, 1, 1, 1)
 (1, 1, 2)
 (1, 2, 1)
 (1, 3)
 (2, 1, 1)
 (2, 2)
 (3, 1)
 
 Note that different sequences are counted as different combinations.
 
 Therefore the output is 7.
 
 题目大意:给定一个无重复的正整数数组，和一个目标值，求所有能组成目标整数的组合，（每个数字可以无限使用）（类似于组成钱数）
 
 解法:超时解法====递归和迭代
 动态规划解决比较合适  dp[i]表示组成值为i的组合有多少种，dp[i] = dp[i] + dp[i - j];
 
*/

#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int> &nums, int target) {
    
    int len = nums.size();
    vector<int> dp(target + 1,0); //dp[i]表示组成值为i的组合有多少种
    dp[0] = 1;
    
    for (int i = 0; i < target ; i ++) {
        for(int j = 0; j < len ; j ++) {
            if(nums[j] <= i){
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    
    return dp[target];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
