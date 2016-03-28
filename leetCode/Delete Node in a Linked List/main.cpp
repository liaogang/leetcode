//
//  main.cpp
//  Delete Node in a Linked List
//
//  Created by liaogang on 16/3/25.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 
 Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 */

#include "../leetcode.h"

void deleteNode(ListNode* node) {
    ListNode *last = nullptr;
    while (node) {
        ListNode *next = node->next;
        if (next) {
         
            node->val = next->val;
            
            last = node;
            node = next;
        }
        else
        {
            last->next = nullptr;
            
            break;
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}
