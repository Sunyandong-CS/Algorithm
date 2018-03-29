//
//  main.cpp
//  CountingBits
//
//  Created by 孙艳东 on 2018/3/12.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

/*
 *题目描述:
 Given a non negative integer number num. For every numbers i in the
 range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 
 Example:
 For num = 5 you should return [0,1,1,2,1,2].
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num) {
    vector<int> count(num + 1, 0);
    
    for (int i = 0; i <= num; i ++) {
        int n = i;
        while (n > 0) {
            n &= (n - 1);
            count[i] ++;
        }
    }
    return count;
}


int main(int argc, const char * argv[]) {
    
    int num;
    vector<int> res;
    cin >> num;
    res = countBits(num);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    return 0;
}
