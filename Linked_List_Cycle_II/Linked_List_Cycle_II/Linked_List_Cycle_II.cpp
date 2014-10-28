//
//  main.cpp
//  Linked_List_Cycle_II
//
//  Created by liaogang on 14/10/28.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//


/**
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Follow up:
 Can you solve it without using extra space?
 */



#include <iostream>




 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *flagNode = new ListNode(-1);
        
        if (head==NULL)
        {
            return NULL;
        }
        
        ListNode *last = NULL;
        ListNode *curr=head;
        
        while (curr->next)
        {
            if (curr->next == flagNode)
            {
                return curr;
            }
            
            last=curr;
            curr=curr->next;
            
            last->next=flagNode;
        }
        
        
        
        return NULL;
    }
};



int main(int argc, const char * argv[]) {
    ListNode *head=new ListNode(1);
    
    
    ListNode *n=new ListNode(2);
    
    head->next=n;
    n->next=head;
    
    Solution s;
    //s.hasCycle(NULL);
    s.detectCycle(head);
    
    
    
    return 0;
}
