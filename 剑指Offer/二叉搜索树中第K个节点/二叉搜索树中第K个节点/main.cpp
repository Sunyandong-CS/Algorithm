//
//  main.cpp
//  二叉搜索树中第K个节点
//
//  Created by sunyandong on 2018/7/16.
//  Copyright © 2018年 sunyandong. All rights reserved.
//

/* 中序遍历二叉树即为排序的，找到第K个就行 */

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

int countNode = 0;
TreeNode *res = NULL;

TreeNode* KthNode(TreeNode* pRoot, int k) {
    if (pRoot == NULL) {
        return NULL;
    }
    KthNode(pRoot->left,k);
     countNode ++;
    if (countNode == k) {
        res = pRoot;
    }
    KthNode(pRoot->right, k);
    return res;
}





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
