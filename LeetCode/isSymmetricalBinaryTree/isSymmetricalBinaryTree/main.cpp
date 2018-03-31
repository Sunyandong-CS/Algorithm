//
//  main.cpp
//  isSymmetricalBinaryTree
//
//  Created by 孙艳东 on 2018/3/31.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

bool isSymmetrical(TreeNode* pRoot) {
    if(pRoot == NULL) return true; // 空树默认true
    return isMirrorTree(pRoot->left,pRoot->right);
}
bool isMirrorTree(TreeNode* left, TreeNode* right) {
    if(left == NULL && right == NULL) { //左右节点都为空，则为真
        return true;
    }else if(left == NULL && right != NULL || left != NULL && right == NULL) { // 只有一个为空，明显部队称
        return false;
    } else {
        if(left->val != right->val) { // 左右对称的节点值不一样为false
            return false;
        } else { // 递归判断下一层
            return isMirrorTree(left->left, right->right) && isMirrorTree(left->right, right->left);
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
