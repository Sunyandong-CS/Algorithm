//
//  main.cpp
//  DecodeWays
//
//  Created by 孙艳东 on 2018/3/19.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numDecodings(string s) {
    if (s.size() == 0 || s[0] == '0') {
        return 0;
    }
    
    vector<int> dp(s.size() + 1, 0);// dp[i]表示前i个数字有多少种转换方式
    dp[1] = 1;
    dp[0] = 1;
    
    for (int i = 2; i <= s.size(); i ++) {
        
        if(s[i - 1] - '2' < 0 && s[i] != '0') {
            dp[i] = dp[i - 1] + dp[i - 2];
        } else if(s[i - 1] - '2' < 0 && s[i] == '0') {
            dp[i] = dp[i - 2];
        } else {
            dp[i] = dp[i - 1];
        }
    }
    
    return dp[s.size()];
}
int main(int argc, const char * argv[]) {
    
    
    return 0;
}
