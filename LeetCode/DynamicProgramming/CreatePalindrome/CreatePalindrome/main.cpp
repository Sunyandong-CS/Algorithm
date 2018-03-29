//
//  main.cpp
//  CreatePalindrome
//
//  Created by 孙艳东 on 2018/3/5.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int createPalindrome(string s) {
    long long len = s.length();
    vector<vector<int>> dp(len, vector<int>(len,0));
    for (int i = 0; i < len; i ++) {
        dp[i][i] = 1;
        for (int j = i - 1;j >= 0; j --) {
            if(s[i] == s[j])
                dp[j][i] = dp[j + 1][i - 1] + 2;
            else {
                dp[j][i] = max(dp[j + 1][i],dp[j][i - 1]);
            }
        }
    }
    
    return len - dp[0][len-1];
}

int main(int argc, const char * argv[]) {
    string s;
    int length;
    while(cin>>s){
        length = createPalindrome(s);
        cout<<length<<endl;
    }
    return 0;
}
