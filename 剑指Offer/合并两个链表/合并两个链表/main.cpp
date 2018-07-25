//
//  main.cpp
//
//  Created by sunyandong on 2018/7/16.
//  Copyright © 2018年 sunyandong. All rights reserved.
//

/*
    合并两个有序链表
 */


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *mergeTwoLinkList(ListNode *head1, ListNode *head2) {
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }
    if (head1->val < head2->val) {
        head1->next = mergeTwoLinkList(head1->next, head2);
        return head1;
    }
    head2->next = mergeTwoLinkList(head1, head2->next);
    return head2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
