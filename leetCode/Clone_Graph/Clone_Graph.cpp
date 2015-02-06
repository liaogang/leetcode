//
//  main.cpp
//  Clone_Graph
//
//  Created by liaogang on 14/11/10.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>


/**
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 OJ's undirected graph serialization:
 
 Nodes are labeled uniquely.
 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 
 First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 Second node is labeled as 1. Connect node 1 to node 2.
 Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 
 Visually, the graph looks like the following:
 
    1
   / \
  /   \
 0 --- 2
      / \
      \_/

 */


#include <vector>
#include <map>
using namespace std;

/// Definition for undirected graph.
struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


UndirectedGraphNode *cloneNode(UndirectedGraphNode *node)
{
    return new UndirectedGraphNode(node->label);
}

///clone node's neighbors to first
void cloneNeighborNodeReuse(UndirectedGraphNode *node,UndirectedGraphNode *first,map<int,UndirectedGraphNode*> &_map)
{

    ///copy it's neighbors.
    for_each(node->neighbors.begin(), node->neighbors.end(),
             [&first,&_map](UndirectedGraphNode *n)
             {
                 UndirectedGraphNode *m=nullptr;
                 auto find = _map.find(n->label);
                 
                 if ( find ==_map.end())
                 {
                     m = cloneNode(n);
                     _map[n->label]=m;
                     
                     first->neighbors.push_back( m );
                     cloneNeighborNodeReuse(n, m , _map);
                 }
                 else
                 {
                     m = find->second;
                     
                     first->neighbors.push_back( m );
                 }
                 
                 
             }
             );
}


class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node==NULL)
            return NULL;
        
        map<int,UndirectedGraphNode*> _map;
        
        UndirectedGraphNode *first=cloneNode(node);
        _map[first->label]=first;
        
        cloneNeighborNodeReuse(node,first,_map);
        
        return first;
    }
};


int main(int argc, const char * argv[])
{
   
    UndirectedGraphNode n0(0);
    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(2);
    
    n0.neighbors.push_back(&n1);
    n0.neighbors.push_back(&n2);
    
    
    n1.neighbors.push_back(&n2);
    
    
    n2.neighbors.push_back(&n2);
    
    
    Solution s;
    
    UndirectedGraphNode *cloned=s.cloneGraph(&n0);
    
    
    UndirectedGraphNode n3(0);
    UndirectedGraphNode *cloned2=s.cloneGraph(&n3);
    
    
    
    return 0;
}
