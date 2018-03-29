//
//  main.cpp
//  MergeSort
//
//  Created by 孙艳东 on 2018/3/29.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void myMerge(vector<int> &num, int l1, int r1, int l2, int r2) {
    
    int i = l1;
    int j = l2;
    int len = (r1 - l1 + 1) + (r2 - l2 + 1);
    vector<int> tem(len);
    int k = 0;
    // 合并有序数组
    while (i <= r1 && j <= r2) {
        if (num[i] < num[j]) {
            tem[k ++] = num[i ++];
        } else {
            tem[k ++] = num[j ++];
        }
    }
    while (i <= r1 ) {
        tem[k ++] = num[i ++];
    }
    while (j <= r2 ) {
        tem[k ++] = num[j ++];
    }
    
    // 更新原始数组
    for (int i = 0; i < len; i ++) {
        num[l1 + i] = tem[i];
    }
}

void mergeSort(vector<int> &num, int start, int end) {
    if(start < end) {
        int mid = (end + start) >> 1;
        mergeSort(num, start, mid);
        mergeSort(num, mid + 1, end);
        myMerge(num, start, mid, mid + 1, end);
    }
}



int main(int argc, const char * argv[]) {
    vector<int> tem = {3, 5, 2, 1, 6, 7, 4, 9};
    mergeSort(tem, 0, 7);
    for (int i = 0; i < 8; i ++) {
        cout<<tem[i]<<" ";
    }
    return 0;
}
