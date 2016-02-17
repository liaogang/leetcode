//
//  main.cpp
//  Reorder List
//
//  Created by liaogang on 16/2/17.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"


/**
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 
 You must do this in-place without altering the nodes' values.
 
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */


// return new head
ListNode* reverseList(ListNode *start,ListNode *end = nullptr)
{
    
    ListNode *curr = start;
    ListNode *next = curr->next;
    curr->next = nullptr;
    
    while (next) {
        ListNode *nnext = next->next;
        next->next = curr;
        
        //step
        curr = next;
        next = nnext;
    }
    
    
    return curr;
}

void reorderList(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return;
    
    
    // get count and tail node
    int count = 0;
    ListNode *tail = head;
    for (; tail->next != nullptr; tail=tail->next,count++)
    {
    }
    count++;
    
    
    
    
    int move = count % 2 == 0 ? count / 2  : (count + 1) / 2;
    
    ListNode *upHead = head;
    ListNode *upEnd = moveNext(head, move-1);
    
    ListNode *downEnd = upEnd->next;
    upEnd->next = nullptr;
    reverseList(downEnd);
    ListNode *downHead = tail;
    
    
    ListNode *up = upHead;
    ListNode *down = downHead;
    for ( ; up != nullptr && down != nullptr;  ) {
        ListNode *upNext = up->next;
        ListNode *downNext = down->next;
        
        up->next = down;
        down->next = upNext;
        
        up=upNext;
        down=downNext;
    }
    
    
    
}

int main(int argc, const char * argv[]) {
    
    ListNode *n = new ListNode(1);
    
//    n->addNode(2)->addNode(3)->addNode(4)->addNode(5)->addNode(6)->addNode(7);
//    n->addNode(2)->addNode(3)->addNode(4);
    n->addNode(2)->addNode(3);
    
    printList(n);
    
    
    /*
    ListNode *newHead = reverseList(n);
    printList(newHead);
    */
    
    
    
    
    reorderList(n);
    printList(n);
    
    return 0;
}
