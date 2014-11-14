//
//  main.cpp
//  Path_Sum
//
//  Created by liaogang on 14/11/11.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Path Sum
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 For example:
 Given the below binary tree and sum = 22,
 
       5
      / \
     4   8
    /   / \
   11  13  4
  /  \      \
 7    2      1
 
 
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 */




 /// Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void walkoverChild(TreeNode *n)
{
    
}

bool hasPathSum(TreeNode *root, int sum)
{
    
}

int main(int argc, const char * argv[])
{
    return 0;
}
