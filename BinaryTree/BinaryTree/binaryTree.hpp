//
//  binaryTree.hpp
//  BinaryTree
//
//  Created by 孙艳东 on 2018/2/28.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp
#include<iostream>
#include <stdio.h>
using namespace std;
class BiNode {
public:
    char data;
    struct BiNode *lchild,*rchild;
};

class BiTree {
private:
    BiNode *root;
    int height;
    // 递归先序遍历
    void pre_Order(BiNode *t);
    // 非递归先序遍历
    void pre_Order_Nonrecursion(BiNode *t);
    // 递归中序遍历
    void in_Order(BiNode *t);
    // 非递归中序遍历
    void in_Order_Nonrecursion(BiNode *t);
    // 递归后序遍历
    void post_Order(BiNode *t);
    // 非递归后序遍历
    void post_Order_Nonrecursion(BiNode *t);
    BiNode* create(string &s, int &pos);
    void get_Height(BiNode *t, int h);
    
public:
    BiTree(){
        root = NULL;
        height = 0;
    }
    // 按照前序遍历序列创建二叉树
    void createBiTree(string s);
    // 递归先序遍历二叉树
    void preOrder();
    // 非递归先序遍历二叉树
    void preOrderNonrecursion();
    // 递归中序遍历二叉树
    void inOrder();
    // 非递归中序遍历二叉树
    void inOrderNonrecursion();
    // 后序遍历二叉树(递归方法)
    void postOrder();
    // 后序遍历二叉树(使用栈的非递归方法)
    void postOrderNonrecursion();
    // 层序遍历二叉树
    void levelOrder();
    // 二叉树镜像，递归做法
    void mirrorRecursively(BiNode *root);
    // 求树的高度
    int getHeight();
    // 求两个节点的最大公共祖先
    void ancestor(char A,char B);
};
#endif /* binaryTree_hpp */
