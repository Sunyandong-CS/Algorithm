//
//  main.cpp
//  PartionEqualSubsetSum
//
//  Created by 孙艳东 on 2018/3/7.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartition(vector<int> &nums) {
    // 计算所有数字的和
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // 如果为奇数则不可能分为两部分
    if (sum & 1) {
        return false;
    }
    // 获取和的一半
    int halfSum = sum >> 1;
    
    vector<int> dp(halfSum + 1, 0); // dp[i] 表示和为i的组合是否存在
    dp[0] = true;
    
    for (auto num:nums) {
        // 对于每个数字判断它与 其他数字和为任意数的组合存在否
        for(int i = halfSum; i >= num; i --) {
            if(dp[i - num] == true) {
                dp[i] = true;
            }
        }
    }
    return dp[halfSum];

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
