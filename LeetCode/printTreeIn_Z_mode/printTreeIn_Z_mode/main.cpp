//
//  main.cpp
//  printTreeIn_Z_mode
//
//  Created by 孙艳东 on 2018/3/30.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
}TreeNode;

/**
 'Z' 字型打印二叉树

 @param pRoot 根节点
 @return 返回打印数组
 */
vector<vector<int> > Print(TreeNode* pRoot) {
    if(pRoot == NULL) return vector<vector<int> >();
        
    vector<vector<int> > res; // 返回结果
    stack<TreeNode *> double_stack; // 保存偶数行的栈
    stack<TreeNode *> single_stack; // 保存奇数行的栈
        
    double_stack.push(pRoot);
    int depths = 0; // 表示奇数行偶数行
   
    // 当两个栈都不为空的时候进行Z字型遍历,分奇数行和偶数行
    while(!double_stack.empty() || !single_stack.empty()) {
        vector<int> tem(0);
        if(depths % 2 == 0) { // 偶数层
            while(!double_stack.empty()) {
                TreeNode *top = double_stack.top();
                tem.push_back(top->val);
                if(top->left != NULL) {
                    single_stack.push(top->left);
                }
                if(top->right != NULL) {
                    single_stack.push(top->right);
                }
                double_stack.pop();
            }
            res.push_back(tem);
                
        } else { // 奇数层
            while(!single_stack.empty()) {
                TreeNode *top = single_stack.top();
                tem.push_back(top->val);
                if(top->right != NULL) {
                    double_stack.push(top->right);
                }
                if(top->left != NULL) {
                    double_stack.push(top->left);
                }
                single_stack.pop();
            }
            res.push_back(tem);
        }
        depths ++;
    }
        
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
