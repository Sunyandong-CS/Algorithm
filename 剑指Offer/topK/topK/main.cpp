//
//  main.cpp
//  topK
//
//  Created by 孙艳东 on 2018/3/26.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



/**
 第一种方式，使用快排里面的partion函数，找到前k个小的数
 */
int partition(int left, int right, vector<int> &input) {
    int baseNum = input[left];
    while(left < right) {
        while(input[right] >= baseNum && left < right) right --;
        swap(input[left],input[right]);
        while(input[left] <= baseNum && left < right) left ++;
        swap(input[left],input[right]);
    }
    baseNum = left;
    
    return baseNum;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res(k, 0);
    int len = input.size();
    if(k > len || k < 0 || len <= 0) return {};
    if(k == len) return input;
    int left = 0;
    int right = len - 1;
    int index = partition(left, right, input);
    while (index != k - 1) {
        if(index > k - 1) {
            right = index - 1;
            index = partition(left, right, input);
        }else {
            left = index + 1;
            index = partition(left, right, input);
        }
    }
    for(int i = 0; i < k; i ++) {
        res[i] = input[i];
    }
    return res;
}
/******************************************************/

vector<int> GetleastNumbers_SolutionWithMultiset(vector<int> input, int k) {
    int len = input.size();
    if (len <= 0 || k > len) return vector<int>();
    
    // 仿函数中的greater<T>模板，从小到大排序
    multiset<int, greater<int>> leastNums;
    vector<int>::iterator vec_it = input.begin();
    while(vec_it != input.end()) {
        // 将前k个数插入集合
        if (leastNums.size() < k) {
            leastNums.insert(*vec_it);
        }else {
            // 第一个元素是最大值
            multiset<int, greater<int>>::iterator greatest_it = leastNums.begin();
            // 如果后续元素<小于第一个元素，那么删掉第一个元素，并插入当前元素
            if (*greatest_it > *vec_it) {
                leastNums.erase(greatest_it);
                leastNums.insert(*vec_it);
            }
        }
        vec_it ++;
    }
    return vector<int>(leastNums.begin(), leastNums.end());
    
}


int main(int argc, const char * argv[]) {
    
    vector<int> input = {1 , 3, 5, 2, 4, 6};
    vector<int> res = GetLeastNumbers_Solution(input, 3);
    vector<int> res1 = GetleastNumbers_SolutionWithMultiset(input, 3);
    for(int i = 0;i < 3; i ++) {
        cout << res[i] << " \n";
        cout << res1[i] << " \n";
    }
    return 0;
}
