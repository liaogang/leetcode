//
//  main.cpp
//  Copy List with Random Pointer
//
//  Created by liaogang on 15/1/20.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
    Copy List with Random Pointer
 
    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
    Return a deep copy of the list.
 */

#include <map>
using namespace std;

RandomListNode *copyRandomList(RandomListNode *head)
{
    map<RandomListNode*, RandomListNode*> _map;

    RandomListNode *head2 = nullptr;
    RandomListNode *tail2 = nullptr;
    
    for (; head != nullptr; head=head->next)
    {
       RandomListNode *node = new RandomListNode(head->label);
        node->random = head->random;
        
        if(tail2)
        {
            tail2->next=node;
        }
        else
            head2=node;
        
        
        tail2=node;
        
        _map[head]=node;
    }
    
    
    tail2=head2;
    for (; tail2; tail2=tail2->next)
    {
        tail2->random=_map[tail2->random];
    }
    
    
    return head2;
}


int main(int argc, const char * argv[])
{
    RandomListNode t(-1);
    
    t.random=&t;
    
    
    RandomListNode *n = copyRandomList(&t);
    
    
    
    return 0;

}


