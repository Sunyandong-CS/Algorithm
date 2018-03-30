//
//  main.cpp
//  sortList
//
//  Created by 孙艳东 on 2018/3/29.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//


/* Sort a linked list in O(n log n) time using constant space complexity. */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x) , next(NULL) {}
};

ListNode *mergeList(ListNode *h1, ListNode *h2) {
    if (h1 == NULL) {
        return h2;
    } else if(h2 == NULL) {
        return h1;
    } else {
        ListNode *tem =new ListNode(-1);
        ListNode *p = tem;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        if (h1) p->next = h1;
        if (h2) p->next = h2;
        
        return tem->next;
    }
}

ListNode *sortList(ListNode *head) {
    
    if(head == NULL || head->next == NULL) return head;
    
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // 后一半链表的开始
    fast = slow->next;
    slow->next = NULL;
    ListNode *head1 = sortList(head);
    ListNode *head2 = sortList(fast);
    return mergeList(head1, head2);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
