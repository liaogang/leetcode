//
//  main.cpp
//  Maximum Depth of Binary Tree
//
//  Created by liaogang on 16/2/16.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"


/**
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

int deepth = 0;

void markTree(TreeNode* root,int val) {
    
    if (root) {
        
        val += 1;
        
        if (root->left) {
            markTree(root->left, val);
        }
        
        if(root->right){
            markTree(root->right, val);
        }
        
        
        if (val> deepth) {
            deepth = val;
        }
    }

}


int maxDepth(TreeNode* root) {
    
    markTree(root,0);
    
    return deepth;
}


int main(int argc, const char * argv[]) {
    
    
//    vector<int> v ({1,2,3,4,5,5,6,});
//    vector<int> v ({0});
    vector<int> v ({1,2});
    
    TreeNode *r ;
    
//    r=nullptr;
//    maxDepth(r);
    
    r = generateTree(v);
    maxDepth(r);
    
    
    
    
    
    
    
    return 0;
}

