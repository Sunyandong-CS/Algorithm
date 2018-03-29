//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by 孙艳东 on 2018/3/19.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
using namespace std;

string longestPalindrome(string s) {
    
    string res;
    int len = s.size();
    if (len <= 1) return s;
    int start = 0;
    int end = 0;
    int maxLen = 1;
    int s_start = 0;
    for(int i = 1; i < len; i ++) {
        int count = 0;
        // 偶数回文的遍历
        start = i - 1;
        end = i;
        while (start >= 0 && end < len && s[start] == s[end]) {
            -- start;
            ++ end;
        }
        int strLen = (end - 1) - (start + 1) + 1;
        if ( strLen > maxLen) {
            maxLen = strLen;
            s_start = start + 1;
        }
        
        // 奇数回文的遍历
        start = i - 1;
        end = i + 1;
        while (start >= 0 && end < len && s[start] == s[end]) {
            -- start;
            ++ end;
        }
        strLen = (end - 1) - (start + 1) + 1;
        if ( strLen > maxLen) {
            maxLen = strLen;
            s_start = start + 1;
        }
    }
    
    res = s.substr(s_start, maxLen);
    return res;
}


int main(int argc, const char * argv[]) {
    string str;
    getline(cin,str);
    cout << longestPalindrome(str);
    return 0;
}
