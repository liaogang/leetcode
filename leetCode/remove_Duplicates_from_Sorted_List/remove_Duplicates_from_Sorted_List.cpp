//
//  main.cpp
//  remove_Duplicates_from_Sorted_List
//
//  Created by liaogang on 14/11/6.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//






#include <iostream>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

///unlink nodes.  (beg,end)
void unlink(ListNode *beg,ListNode *end)
{
    beg->next=end;
}


///unlink nodes.  (beg,end)
void unlink2(ListNode *beg,ListNode *end)
{
    beg->next=end;
}


void addNode(ListNode **pHead,ListNode **pEnd,ListNode *n)
{
    n->next=NULL;
    
    if ((*pEnd) == NULL)
    {
        *pEnd = n;
        *pHead = n;
    }
    else
    {
        (*pEnd)->next=n;
        (*pEnd)=n;
    }
    
}


class Solution
{
public:
    /**
     Given a sorted linked list, delete all duplicates such that each element appear only once.
     
     For example,
     Given 1->1->2, return 1->2.
     Given 1->1->2->3->3, return 1->2->3.
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head==NULL)
            return NULL;
        
        
        ListNode *beg=head;
        ListNode *end=beg->next;
        
        while (1)
        {
            
            if ( end == NULL || beg->val != end->val)
            {
                unlink( beg , end);
                beg=end;
            }
            
            
            if (end == NULL)
                break;
            
            end=end->next;
            
        }
        
        return head;
    }
    
    
    
    /**
     Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
     
     For example,
     Given 1->2->3->3->4->4->5, return 1->2->5.
     Given 1->1->1->2->3, return 2->3.
     */
    ListNode *deleteDuplicates2(ListNode *head)
    {
        if (head==NULL)
            return NULL;
        
        
        ListNode *dup=NULL;
        
        ListNode *head2=NULL;
        ListNode *end2=NULL;
        

        ListNode *last=head;
        ListNode *curr=head->next;
        
        while (curr || last)
        {
            if (!curr || curr->val != last->val)
            {
                if (dup == NULL || last->val != dup->val)
                {
                    addNode(&head2, &end2, last);
                }
            }
            else
            {
                dup=last;
                ///skip to add
            }
           
            
            
            last=curr;
            if (curr)
                curr=curr->next;
        }
        
        
        return head2;
    }
    
};


int main(int argc, const char * argv[])
{
    /**
     Input: 	{1,1}
     Output: 	{1,1}
     Expected: 	{1}
     */
    ListNode head(1);
    ListNode n(1);
    head.next=&n;
    
    Solution s;
    s.deleteDuplicates(&head);
    
   ///II
    
    /**
Input: 	{1,2}
Output: 	{1}
Expected: 	{1,2}
    */
    
    ListNode head2(1);
    ListNode n2(2);
    head2.next=&n2;
    ListNode n3(2);
    n2.next=&n3;
    
    
    Solution s2;
    ListNode *result =  s2.deleteDuplicates2(&head2);
    
    
    
    
    return 0;
}
