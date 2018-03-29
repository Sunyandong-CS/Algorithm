//
//  main.cpp
//  LetterCombinationsOfAPhoneNumber
//
//  Created by 孙艳东 on 2018/3/19.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

/*
 *题目描述Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 
 Input:Digit string "23" ----->(2  'abc'  3 'def ')
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 
 题目大意：输入九宫格上的数字组合，求出所有可能出现的单词
 
 */


#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<string> &res, string digitsToChar[], string digits, string tem, int level) {
    if(level == digits.size()) {
        res.push_back(tem);
        
    } else {
        string str = digitsToChar[digits[level] - '2'];
        for (int i = 0; i < str.size(); i ++) {
            tem.push_back(str[i]);
            dfs(res, digitsToChar, digits, tem, level + 1);
            tem.pop_back();
        }
    }
    
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    int len = digits.size();
    if(len == 0) return res;
    string digitsToChar[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};;
    string tem = "";
    dfs(res, digitsToChar, digits, tem, 0);
    
    return res;
}



int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    vector<string> res;
    res = letterCombinations(str);
    for(int i = 0;i < res.size();i ++ ) {
        std::cout << res[i] <<"\n" ;
    }
    
    return 0;
}
