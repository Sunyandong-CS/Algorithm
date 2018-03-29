//
//  main.cpp
//  LinkList
//
//  Created by 孙艳东 on 2018/3/26.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
using namespace std;

// 链表节点结构体
typedef struct node {
    int val;
    struct node *next;
}node;

// 链表的创建
node *creat() {
    node *head, *p , *s;
    int x = 0, cycle = 1;
    head = (node *)malloc(sizeof(node));
    p = head;
    while (cycle) {
        printf("请输入下一个节点数据:");
        cin>>x;
        if (x != 0) {
            s = (node*)malloc(sizeof(node));
            s->val = x;
            cout<<s->val<<"\n";
            p->next = s;
            p = s;
        }else {
            cycle = 0;
        }
    }
    head = head->next;
    p->next = NULL;
    return (head);
}
// 打印单链表
void print(node *head) {
    if (head == NULL) return;
    node *p;
    p = head;
    while (p != NULL) {
        cout<<p->val<<"->";
        p = p->next;
    }
    free(p);
}
// 链表的删除
node* del(node *head, int num) {
    node* p1, *p2;
    p1 = head;
    while (p1->val != num && p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->val == num) {
        if(p1 == head) {
            head = p1->next;
        } else {
            p2->next = p1->next;
        }
    } else {
        printf("%d\n could not been found", num);
    }
    return (head);
}

// 链表的插入


int main(int argc, const char * argv[]) {
    
    node *head = creat();
    print(head);
    return 0;
}
