//
//  main.cpp
//  Intersection of Two Linked Lists
//
//  Created by liaogang on 14/12/29.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
/**
    Intersection of Two Linked Lists
 
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 For example, the following two linked lists:
 
 A:          a1 → a2
                     ↘
                     c1 → c2 → c3
                     ↗
 B:     b1 → b2 → b3
 
 begin to intersect at node c1.
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.

 */

#include "../../leetcode.h"

int cmp(ListNode *nA,ListNode *nB)
{
    return nA->val - nB->val;
}

bool cmp2(ListNode *nA,ListNode *nB)
{
    return nA == nB;
}



class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        
        /// @method 1:
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        
        int aLen = getCount(headA);
        int bLen = getCount(headB);
        
        int offset = aLen - bLen;
        if (offset > 0) {
            headA = moveNext(headA,offset);
        }else if (offset < 0)
        {
            headB = moveNext(headB, offset);
        }
        
        
        
        for (; headA != nullptr && headB != nullptr; headA=headA->next,headB=headB->next)
        {
            if (cmp(headA, headB) == 0)
            {
                return headA;
            }
        }
        
        
        return nullptr;
    }
};


int main(int argc, const char * argv[])
{
    ListNode test1(2);
    test1.addNode(3);//->addNode(3)->addNode(3)->addNode(173)->addNode(19)->addNode(31);
    
    ListNode test2(3);
    
    Solution s;
    ListNode *n = s.getIntersectionNode(&test1, &test2);
    
    if (n) {
        printf("%d\n",n->val);
    }
    else
        printf("null\n");
    
    
    
    
    
    return 0;
}
