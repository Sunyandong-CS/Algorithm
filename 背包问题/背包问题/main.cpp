//
//  main.cpp
//  背包问题
//
//  Created by sunyandong on 2018/7/25.
//  Copyright © 2018年 sunyandong. All rights reserved.
//

/*
 有n个重量和价值分别为 wi,vi 的物品。
 从这些物品中挑选出总重量不超过 W 的物品，
 求所有挑选方案中价值总和的最大值
 */

#include <iostream>
#include <vector>

using namespace std;


/*
 0-1背包 每件物品只有一件，可以选择放或不放
 */
int back_pack01(int totalWeight, vector<int> weight, vector<int> value) {
    int len = weight.size();
    vector<vector<int>> dp(len + 1, vector<int>(totalWeight + 1, 0)); // dp[i][j] 表示前i件物品放入价值为j的背包，能取到的最大值
    for (int i = 1; i <= len; i ++) {
        for (int j = 0; j <= totalWeight; j ++) {
            if ( weight[i - 1] > j) { // 第i件物品放不下
                dp[i][j] = dp[i-1][j];
            } else { // 能放下第i件物品,可以选择放或者不放
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]] + value[i-1]);
            }
        }
    }
    
    return dp[len][totalWeight];
}

int main(int argc, const char * argv[]) {
    int n = 0;
    int totalWight;
    cin >> n >> totalWight;
    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> weight[i] >> value[i];
    }
    
    cout << back_pack01(totalWight, weight, value);
    
    return 0;
}
