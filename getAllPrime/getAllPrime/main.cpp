//
//  main.cpp
//  getAllPrime
//
//  Created by 孙艳东 on 2018/3/31.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

/* 素数筛选法 */

#include <iostream>
#include <vector>
using namespace std;

/**
 获取2-n中所有的素数

 @param n n
 @return 返回所有的素数
 */
vector<int> getAllPrime(int n) {
    if (n < 2) {
        return vector<int>();
    }
    vector<int> res;
    vector<bool> check(n + 1,true); // 标记筛选的素数
    check[1] = false;
    check[0] = false;
    for (int i = 2; i * i <= n; i ++) {
        if (check[i]) {
            for (int j = i * 2 ; j <= n; j += i) {
                check[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i ++) {
        if (check[i] == true) {
            res.push_back(i);
            cout<< i << " ";
        }
    }
    
    return  res;
}


int main(int argc, const char * argv[]) {
    int n; // 表明要输出的范围
    cin >> n;
    vector<int> res = getAllPrime(n);
    
    return 0;
}
