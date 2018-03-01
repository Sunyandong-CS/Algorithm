//
//  main.cpp
//  ReverseLinklist
//
//  Created by 孙艳东 on 2018/3/1.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x),next(NULL) {
    }
};
ListNode *ReverseList(ListNode* pHead) {
        ListNode* pReverseHead = NULL;
        ListNode* pNode = pHead;
        ListNode* pPrev = NULL;
        
        // 每次遍历前记录当前节点、当前节点的下一个节点、当前节点的前一个节点，保证链表不会断开
        while(pNode != NULL) {
            ListNode* pNext = pNode->next;
            if (pNext == NULL ) {
                pReverseHead = pNode;
            }
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        
        return pReverseHead;
}
    
// 结果测试
void Print(ListNode* head) {
        ListNode* pNode = head;
        
        while (pNode!=NULL)
        {
            cout<<pNode->val<<"->";
            pNode = pNode->next;
        }
}
int main(int argc, const char * argv[]) {
        // insert code here...
        
        ListNode* head  = new ListNode(1);
        ListNode* node1 = new ListNode(2);
        ListNode* node2 = new ListNode(3);
        ListNode* node3 = new ListNode(4);
        ListNode* node4 = new ListNode(5);
        
        head->next  = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = NULL;
        cout << "反转以前：";
        Print(head);
        ListNode* pNode = ReverseList(head);
        cout<<"反转以后"<<endl;
        Print(pNode);
        
        return 0;
    
}



