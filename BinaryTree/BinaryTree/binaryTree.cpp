//
//  binaryTree.cpp
//  BinaryTree
//
//  Created by 孙艳东 on 2018/2/28.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include "binaryTree.hpp"
#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>

using namespace std;

// 递归创建二叉树
BiNode* BiTree::create(string &s, int &pos) {
    ++ pos;
    BiNode *t;
    if ((unsigned)pos >= s.size()) {
        return NULL;
    }else {
        if (s[pos] == '#') {
            t = NULL;
        } else {
            t = new BiNode;
            t->data = s[pos];
            t->lchild = create(s, pos);
            t->rchild = create(s, pos);
        }
    }
    return t;
}
// 按照前序遍历序列创建二叉树
void BiTree::createBiTree(string s){
    int pos = -1;
    root=create(s,pos);
}
// 递归版先序遍历
void BiTree::preOrder() {
    pre_Order(root);
    cout<<endl;
}
/**
 依次访问根节点、左子树、右子树，注意递归出口的结束。
 */
void BiTree::pre_Order(BiNode *t) {
    if (t != NULL) {
        cout<<t->data<<' ';
        pre_Order(t->lchild);
        pre_Order(t->rchild);
    }
}

// 非递归先序遍历
void BiTree::preOrderNonrecursion() {
    pre_Order_Nonrecursion(root);
    cout<<endl;
}

/**
 用栈模拟前序遍历，栈是先进先出的特点，
 则将无条件地入栈根节点，在弹出根节点之前依次将根节点的右孩子节点和左孩子节点入栈……
 */
void BiTree::pre_Order_Nonrecursion(BiNode *t) {
    stack<BiNode *> s;
    if (root == NULL) {
        return;
    }
    BiNode *curr = root;
    s.push(curr);
    while (!s.empty()) {
        curr = s.top();
        cout<<curr->data<<' ';
        s.pop();
        if (curr->rchild) {
            s.push(curr->rchild);
        }
        if (curr->lchild) {
            s.push(curr->lchild);
        }
    }
}

// 递归中序遍历
void BiTree::inOrder() {
    in_Order(root);
    cout<<endl;
}
/**
 依次访问左子树、根节点、右子树，注意递归出口的结束。
 */
void BiTree::in_Order(BiNode *t) {
    if (t != NULL) {
        in_Order(t->lchild);
        cout<<t->data<<' ';
        in_Order(t->rchild);
    }
}

// 非归中序遍历
void BiTree::inOrderNonrecursion() {
    in_Order_Nonrecursion(root);
    cout<<endl;
}
void BiTree::in_Order_Nonrecursion(BiNode *t) {
    if (root == NULL) {
        return;
    }
    stack<BiNode *> s;
    BiNode *curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->lchild;
        }
        curr = s.top();
        cout<< curr->data<<' ';
        s.pop();
        if (curr->rchild != NULL) {
            curr = curr->rchild;
        } else {
            curr = NULL;
        }
    }
}

// 非递归后序遍历
void BiTree::postOrder() {
    post_Order(root);
    cout<<endl;
}
/**
 依次访问左子树、右子树、根节点，注意递归出口的结束。
 */
void BiTree::post_Order(BiNode *t) {
    if (t != NULL) {
        post_Order(t->lchild);
        post_Order(t->rchild);
        cout<<t->data<<' ';
    }
}

// 递归后序遍历
void BiTree::postOrderNonrecursion() {
    post_Order_Nonrecursion(root);
    cout<<endl;
}

/**
 后序遍历先遍历左子树，再遍历右子树，最后遍历根节点
 对于一个节点而言，先一直遍历到最左节点
 然后用prev记录右子树是否遍历，如果没有遍历，则遍历右子树
 */
void BiTree::post_Order_Nonrecursion(BiNode *t) {
    if (root == NULL) {
        return;
    }
    stack<BiNode *> s;
    BiNode *prev = NULL;
    BiNode *curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->lchild;
        }
        curr = s.top();
        if (curr->rchild == NULL || curr->rchild == prev) {
            cout<< curr->data<<' ';
            s.pop();
            prev = curr;
            curr = NULL;
        } else {
            curr = curr->rchild;
        }
    }
}

// 层序遍历二叉树
void BiTree::levelOrder() {
    if (root == NULL) {
        return;
    }
    queue<BiNode *> q;
    q.push(root);
    while (!q.empty()) {
        BiNode *head;
        head = q.front();
        q.pop();
        cout<<head->data<<' ';
        if (head->lchild != NULL) {
            q.push(head->lchild);
        }
        if (head->rchild != NULL) {
            q.push(head->rchild);
        }
    }
    cout<<endl;
}

// 二叉树镜像的递归做法

void BiTree::mirrorRecursively(BiNode *root) {
    if(root == NULL) return;
    if (root->lchild == NULL && root->rchild == NULL) {
        return;
    }
    BiNode *tem = root->lchild;
    root->lchild = root->rchild;
    root->rchild = tem;
    
    if (root->lchild != NULL) {
        mirrorRecursively(root->lchild);
    }
    if (root->rchild != NULL) {
        mirrorRecursively(root->rchild);
    }
}




