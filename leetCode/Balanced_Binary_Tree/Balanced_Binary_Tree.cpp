//
//  main.cpp
//  Balanced_Binary_Tree
//
//  Created by liaogang on 14/10/29.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>
#include <vector>


/**
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */


using namespace std;



//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution
{
private:
    int depthMin,depthMax;
public:
    bool isLeaf(TreeNode *n , int depthCurr)
    {
        if (!n->left && !n->right )
        {
            if (depthCurr > depthMax)
                depthMax = depthCurr;
            
            if (depthCurr < depthMin)
                depthMin = depthCurr;
            
            return true;
        }
        
        return false;
    }
    
    void walkoverTree(TreeNode *n , int depthCurr)
    {
        if (!n)
            return;
   
        if (!isLeaf(n, depthCurr))
        {
            walkoverTree(n->left, depthCurr +1);
            walkoverTree(n->right, depthCurr +1);
        }
        
    }
    
    
    //root
    bool isBalanced(TreeNode *root)
    {
        
        depthMin=0;
        depthMax=0;
        
        if(root)
        {
            depthMin=1;
            depthMax=1;
            walkoverTree(root,1);
        }
            
        
        return depthMax - depthMin <= 1;
    }
    
    
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





int main(int argc, const char * argv[])
{
    
    Solution s;
    
 
    
    
    
   //{1,2,2,3,#,#,3,4,#,#,4}  false
    //cout<<"is balance? :"<<s.isBalanced(generateTree({1,2,2,3,flagEmpty,flagEmpty,3,4,flagEmpty,flagEmpty,4}))<<endl;
    
    // 	{1,2} true
    //cout<<"is balance? :"<<s.isBalanced(generateTree({1,2,flagEmpty}))<<endl;
    
    
   //{1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5} true
    bool result = s.isBalanced(generateTree({1,2,2,3,3,3,3,4,4,4,4,4,4,flagEmpty,flagEmpty,5,5}));
    cout<<"is balance? :"<< result <<endl;
    
    return 0;
}
