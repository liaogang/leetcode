//
//  main.cpp
//  Reverse Linked List
//
//  Created by liaogang on 16/3/21.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

///Reverse a singly linked list.

class Solution {
public:
    //循环
    ListNode* reverseList(ListNode* head) {
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        while( curr )
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
};

int main(int argc, const char * argv[]) {
    
    ListNode *n = new ListNode(1);
    n->addNode(2)->addNode(3)->addNode(4);
    
    
    Solution a;
    
    
    a.reverseList(n);
    
    return 0;
}
