//
//  main.cpp
//  Same Tree
//
//  Created by liaogang on 14/11/17.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Same Tree
 
 Given two binary trees, write a function to check if they are equal or not.
 
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */


/**
 * Definition for binary tree
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <assert.h>

bool isSameTree(TreeNode *p, TreeNode *q)
{
    bool r = true;
    if(p == NULL && q == NULL)
    {
        return true;
    }
    else if(p == NULL || q == NULL )
        return  false;
    else{
        if(p->val == q->val)
        {
            r = isSameTree(p->left, q->left);
            
            if (r == true)
                r = isSameTree(p->right, q->right);
            
        }
        else
            r = false;
    }
    return r;
}

int main(int argc, const char * argv[])
{
    return 0;
}
