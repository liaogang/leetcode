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
        
        
        int count ;
        
        /// head ~~ end : head2 ~~ end2.
        ///       f             k
        /// after rotate.
        /// head2 ~~ end2 : head ~~ end.
        
        ListNode *end2 = head;
        ListNode *last;
        int i = 0;
        for (; end2 != NULL; end2=end2->next,i++)
            last = end2;
        
        end2 = last;
        count = i;
        
        if (k == count || count == 1)
            return head;
        
        
        while (k-- > 0)
        {
                
        }
        
        
        
        int f = count - k;
        ListNode *end = head;
        int n = f;
        for (; end != NULL && n > 0; end=end->next,n--);
        
        ListNode *head2=end->next;
        
        
        
        end2->next = head;
        end->next = nullptr;
        
        return head2;
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


