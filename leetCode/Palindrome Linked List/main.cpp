//
//  main.cpp
//  Palindrome Linked List
//
//  Created by liaogang on 16/3/31.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/**
 Given a singly linked list, determine if it is a palindrome.
 
 Follow up:
 Could you do it in O(n) time and O(1) space?
 

 */

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

bool isPalindrome(ListNode* head) {
    
    int count = getCount(head);
    
    if (count == 0 || count == 1) {
        return true;
    }


    
    ListNode *midPrev = moveNext(head, (count + 1) / 2 - 1);
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    
    ListNode *end = reverseList(mid);
    
    
    while (head && end) {
        
        if (head->val != end->val) {
            return false;
        }
        
        head = head->next;
        end = end->next;
    }
    
    
    
    return true;
}

int main(int argc, const char * argv[]) {
    ListNode *h = new ListNode(1);
    h->addNode(2)->addNode(2)->addNode(1);
    
    
    printf("%d\n", isPalindrome(h));
    
    return 0;
}
