//
//  main.cpp
//  Symmetric Tree
//
//  Created by liaogang on 14/12/4.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
   Symmetric Tree
 
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree is symmetric:
 
 
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 
 But the following is not:
 
   1
  / \
 2   2
  \   \
  3    3

 
 
 OJ's Binary Tree Serialization:
 
 The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 
 Here's an example:
 
   1
  / \
 2   3
    /
   4
    \
     5
 
 The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */

#include <vector>
using namespace std;


#include "../../leetcode.h"




///result: Memory Limit Exceeded
class Solution2
{

public:
    bool isSymmetricInLevel(vector<TreeNode*> nodes,int level)
    {
        if (level == 1 )
            return true;
        
        int left = 0;
        int right = level-1;
        
        while (left <= right)
        {
            TreeNode *nLeft = nodes[left];
            TreeNode *nRight = nodes[right];
            
            bool b = false;
            
            if ( nLeft == NULL && nRight == NULL)
            {
                b = true;
            }
            else if( nLeft && nRight && nLeft->val == nRight->val)
            {
                b = true;
            }
            
            if (b == false)
                return false;
            
            left++;
            right--;
        }
        
        
        
        return true;
    }
    
    
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        
        
        bool result = true;
        
        vector<TreeNode*> nodes;
        
        nodes.push_back(root);
        
        int currLevel = 1;
        ///next

        int levelEmpty = false;
        int currLevelSymmetric = true;
        while (levelEmpty == false && currLevelSymmetric == true)
        {
            currLevel++;
            levelEmpty=true;
            vector<TreeNode*> nodes2;
            for (auto i = nodes.begin(); i != nodes.end(); i++)
            {
                TreeNode *n = *i;
                if (!n )
                {
                    nodes2.push_back(NULL);
                    nodes2.push_back(NULL);
                }
                else
                {
                    nodes2.push_back(n->left);
                    nodes2.push_back(n->right);
                }
                
                if ( n &&  (n->left || n->right) )
                    levelEmpty = false;
            }
            
            
            if (levelEmpty)
                break;
            
            currLevelSymmetric = isSymmetricInLevel(nodes2, nodes2.size());
            
            result &= currLevelSymmetric;
            
            nodes=nodes2;
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{
//    TreeNode *root = generateTree(vector<int>({1,2,2,3,4,4,3}) );
//    TreeNode *root = generateTree(vector<int>({1,2,flagEmpty}) );
    TreeNode *root = generateTree(vector<int>({1,2,2,flagEmpty,3,3,flagEmpty}) );
    
    Solution2 s;
    bool r = s.isSymmetric(root);
    cout<<r<<endl;
    
    return 0;
}
