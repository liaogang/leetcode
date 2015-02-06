//
//  main.cpp
//  Linked_List_Cycle
//
//  Created by liaogang on 14/10/28.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

/**
 Given a linked list, determine if it has a cycle in it.
 
 Follow up:
 Can you solve it without using extra space?
 */

/**
 不用额外的空间，即空间复杂度为1即可。
 */


#include <iostream>






//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL)
        {
            return false;
        }
        
        ListNode *last = NULL;
        ListNode *curr=head;
        
        while (curr->next)
        {
            if (curr->next == head)
            {
                return true;
            }
            
            last=curr;
            curr=curr->next;
            
            last->next=head;
        }
        
        
        
        return false;
    }
};




int main(int argc, const char * argv[])
{
    ListNode *head=new ListNode(1);
    head->next=NULL;
    
    
    Solution s;
    s.hasCycle(NULL);
    s.hasCycle(head);
    
    
    
    return 0;
}
