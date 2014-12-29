//
//  main.cpp
//  Reverse Nodes in k-Group
//
//  Created by liaogang on 14/11/17.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Reverse Nodes in k-Group
 
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 
 You may not alter the values in the nodes, only nodes itself may be changed.
 
 Only constant memory is allowed.
 
 For example,
 Given this linked list: 1->2->3->4->5
 
 For k = 2, you should return: 2->1->4->3->5
 
 For k = 3, you should return: 3->2->1->4->5
 */

#include <assert.h>

#include "../../leetcode.h"


///return reversed head
ListNode* reverseGroup(ListNode *head,ListNode *end,int k)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    for (int i = 0; i < k; i++)
    {
        ListNode *next = curr->next;
        if(prev)
            curr->next=prev;
        
        prev=curr;
        
        curr=next;
    }
    
    
    
    return end;
}

ListNode *getGroupTail(ListNode *groupHead,int k)
{
    for (int count = k -1 ;
         count> 0 && groupHead;
         groupHead = groupHead->next,count--)
        ;
    
    return groupHead;
}
using namespace std;
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    
    ListNode *groupHead = head;
    ListNode *groupTail;
    ListNode *prevGroupTail= NULL;
    
    ListNode *reverseGroupTail = NULL;
    
    bool bFirst = true;
    ListNode *result = head;
    while (groupHead && (groupTail = getGroupTail(groupHead,k)))
    {
       // cout<<"~~"<<groupHead->val<<endl;
        
        ListNode* nextGroupHead = groupTail->next;
        
        reverseGroupTail = groupHead;
        
        ListNode *reverseGroupHead = reverseGroup(groupHead, groupTail, k);
        if (bFirst == true) {
        bFirst=false;
            result = reverseGroupHead;
        }

        
        
        assert(reverseGroupHead == groupTail);
        
        if (prevGroupTail) {
            prevGroupTail->next=reverseGroupHead;
        }
        
        prevGroupTail = reverseGroupTail;
        
        ///move next
        groupHead=nextGroupHead;
    }
    
   if(prevGroupTail)
       prevGroupTail->next = groupHead;

    return result;
}


void printNodes(ListNode *head)
{
    while (head)
    {
        printf("%d\n",head->val);
        
        head=head->next;
    }
}


int main(int argc, const char * argv[])
{
    ListNode head(1);
    
    //head.addNode(2)->addNode(3)->addNode(4)->addNode(5);
    
    printNodes(&head);
    
    printNodes(    reverseKGroup(&head, 2) );
    

//    printNodes(    reverseKGroup(&head, 3) );
    
    
    
    
    
    return 0;
}
