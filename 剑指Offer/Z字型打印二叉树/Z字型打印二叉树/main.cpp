//
//  main.cpp
//  Z字型打印二叉树
//
//  Created by sunyandong on 2018/7/24.
//  Copyright © 2018年 sunyandong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int >> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int >> res;
    if (root == NULL) {
        return res;
    }
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int flag = 1; // 奇数层还是偶数层
    while (!nodeQueue.empty()) {
        size_t size = nodeQueue.size();
        vector<int> level;
        while (size --) {
            TreeNode *top = nodeQueue.front();
            nodeQueue.pop();
            if (flag == 0) { // 偶数层
                level.insert(level.begin(), top->val);
            } else {
                level.push_back(top->val);
            }
            if (top->left) {
                nodeQueue.push(top->left);
            }
            if (top->right) {
                nodeQueue.push(top->right);
            }
        }
        res.push_back(level);
        flag ^= 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
