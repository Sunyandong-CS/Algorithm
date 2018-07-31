//
//  main.cpp
//  addWithoutArithmetic
//
//  Created by sunyandong on 2018/7/31.
//  Copyright © 2018年 sunyandong. All rights reserved.
//

#include <iostream>

using namespace std;

int addWithLoop(int num1, int num2) {
    int sum = 0;
    int carry = 0;
    while (num2 != 0) {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    
    return num1;
}

int addWithRecursion(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    return addWithRecursion(sum, carry);
}

int main(int argc, const char * argv[]) {
    int num1 = 0;
    int num2 = 0;
    cin >> num1 >> num2;
    
    cout << addWithLoop(num1, num2) << endl;
    cout << addWithRecursion(num1, num2) << endl;
    return 0;
}
