//
//  main.cpp
//  Reverse Linked List II
//
//  Created by liaogang on 16/3/21.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/**
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n > m )
        {
            ListNode *mPrev;
            ListNode *curr;
            const int headPos = 1;
            if (m == headPos)
            {
                mPrev = nullptr;
                curr = head;
            }
            else
            {
                mPrev = moveNext(head, m - headPos - 1);
                curr = mPrev->next;
            }
            
            
            ListNode *mNode = curr;
            ListNode *prev = nullptr;
            
            int count = n - m + 1;
            while( count > 0 )
            {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                
                count--;
            }
            
            
            if (mPrev)
                mPrev->next = prev;
            else
                head = prev;
            
            if (curr)
                mNode->next = curr;
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
//    ListNode *n = new ListNode(1);
//    n->addNode(2)->addNode(3)->addNode(4)->addNode(5);
//    
//    Solution a;
//    a.reverseBetween(n, 2, 4);
    
    
//    ListNode *n = new ListNode(5);
//    
//    Solution a;
//    a.reverseBetween(n, 1, 1);
    
    
//    ListNode *n = new ListNode(3);
//    n->addNode(5);
//    
//    Solution a;
//    a.reverseBetween(n, 1, 2);
 
    
    ListNode *n = new ListNode(1);
    n->addNode(2)->addNode(3);
    
    Solution a;
    a.reverseBetween(n, 1, 2);
    
    
    return 0;
}


