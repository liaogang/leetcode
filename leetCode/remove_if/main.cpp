//
//  main.cpp
//  remove_if
//
//  Created by liaogang on 15/2/11.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

typedef bool (*remove_fn) (ListNode *node);

bool remove_fn_e(ListNode *node)
{
    if (node->val % 2 == 0) {
        return true;
    }
    return false;
}

// Remove all nodes from the supplied list for which the
// supplied remove function returns true.
// Returns the new head of the list.
ListNode *removeIf(ListNode *head,remove_fn rm)
{
    /// find new head.
    for ( ;head && rm (head); head=head->next)
    {}
    
    /// others.
    for ( ListNode *prev = head , *curr = head->next ; curr  ; curr = curr->next )
    {
        if ( rm(curr))
                prev->next = curr->next;
    }
    
    
    return head;
}

ListNode *removeIf2(ListNode *head,remove_fn rm)
{
    ListNode **phead = &head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    
    for ( ; curr != nullptr ; curr=curr->next)
    {
        if ( rm(curr))
        {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;
        }
        else
            prev = curr;
    }
    
    
    
    return head;
}

void remove_if_Linus(ListNode ** head, remove_fn rm)
{
    for (ListNode** curr = head; *curr; )
    {
        ListNode * entry = *curr;
        if (rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}

int main(int argc, const char * argv[])
{
    ListNode h (2);
    h.addNode(3)->addNode(4)->addNode(5)->addNode(7)->addNode(9);
    
    ListNode *nh = removeIf( &h , remove_fn_e );
    
    printList(nh);
    
    return 0;
}
