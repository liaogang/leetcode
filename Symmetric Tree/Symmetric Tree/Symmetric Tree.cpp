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


/// Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


const int flagEmpty = -203984;
TreeNode * generateTree(vector<int> a)
{
    int len = a.size();
    if (len==0)
        return NULL;
    
    cout<<"len:"<<len<<endl;
    
    unsigned int len2=len;
    
    TreeNode **nodes = new TreeNode*[len];
    for (int i =0; i < len; i++)
    {
        TreeNode *n = NULL;
        if (a[i] != flagEmpty)
        {
            n =new TreeNode(a[i]);
        }
        
        nodes[i]=n;
        cout<<i<<","<<a[i]<<endl;
    }
    
    
    int cSum = 1;
    int louNumber = 1;
    int lou = 1;
    len2>>=1;
    
    while (len2)
    {
        int currLouNumber = 2 * louNumber;
        cout<<endl<<"-----------curr lou:"<<lou<<"-----------"<<currLouNumber<<endl;
        
        
        for (int i = cSum ,j = cSum - louNumber ; i < cSum + currLouNumber && i < len && j < cSum ; i+=2 , j++)
        {
            TreeNode *left = nodes[i] ;
            TreeNode *right = nodes[i + 1];
            
            while (j < cSum)
            {
                if (nodes[j])
                {
                    cout<<"set parent"<< i  << " ," << i + 1<< "-->"<< j<< endl;
                    nodes[j]->left=left;
                    nodes[j]->right=right;
                    break;
                }
                j++;
            }
            
        }
        
        
        //move next
        louNumber=currLouNumber;
        cSum += louNumber;
        cout<<"total"<<cSum<<endl;
        len2>>=1;
        lou++;
    }
    
    
    
    
    return nodes[0];
}


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
