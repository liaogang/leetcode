//
//  main.cpp
//  Rotate List
//
//  Created by liaogang on 14/12/29.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
    Rotate List
 
 Given a list, rotate the list to the right by k places, where k is non-negative.
 
 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 */


class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        
        if (k == 0 )
            return head;
        
        
        ListNode *end = head;
        ListNode *last = nullptr;
        /// get count
        int count =0;
        for (; end != NULL; end=end->next,count++)
            last = end;
        
        end = last;
       
        if(count == 1)
            return head;
        
        k = k % count;
        if (k == count )
            return head;
        
        ///
        end->next=head;
        k = count - k;
        while (k-- > 0) {
            last = head;
            head=head->next;
        }
        
        last->next=nullptr;
        
        return head;
    }
};

int main(int argc, const char * argv[])
{
    
    ListNode test(1);
    test.addNode(2);
    int k = 1;
    
    Solution s;
    
    printList(  s.rotateRight(&test, k) );
    
    return 0;
}


