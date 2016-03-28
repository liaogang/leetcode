//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by liaogang on 16/3/28.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 */

#include "../leetcode.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    int count = getCount(head);
   
    if ( n == count ) {
        return head->next;
    }
    else
    {
        ListNode *prev;
        ListNode *curr;
        ListNode *next;
        
        prev = moveNext(head, count - 1 - (n - 1) - 1);
        curr = prev->next;
        next = curr->next;
        
        prev->next = next;
    }
    
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    ListNode *n = new ListNode(1);
    n->addNode(2)->addNode(3)->addNode(4)->addNode(5);
    
    ListNode *head = removeNthFromEnd(n, 2);
    
    return 0;
}
