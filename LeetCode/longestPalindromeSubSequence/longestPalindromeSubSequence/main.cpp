//
//  main.cpp
//  longestPalindromeSubSequence
//
//  Created by 孙艳东 on 2018/3/21.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

int main() {
    string str;
    
    while(getline(cin,str)) {
        int len = str.length();
        vector<vector<int>> dp(len, vector<int>(len,0)); // dp[i][j]表示前i~j中元素最长的回文子序列
        for(int j = 0;j < len ; j ++) {
            dp[j][j] = 1;
            for(int i = j - 1;i >= 0 ; i --) {
                
                if(str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
                }
            }
        }
        cout<< len - dp[0][len - 1] - 1;
    }
    return 0;
}
