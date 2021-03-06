//
//  main.cpp
//  Intersection of Two Linked Lists
//
//  Created by liaogang on 14/12/29.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//


/**
    LeetCode
    LeetCode OJ is a platform for preparing technical coding interviews.
 
    @link https://leetcode.com
 */


#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};




/// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
    ListNode* addNode(int value)
    {
        ListNode *n=new ListNode(value);
        next=n;
        return n;
    }
    
};



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
    int len = (int) a.size();
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



void printInterval(Interval i)
{
    printf("[%d,%d]\n",i.start,i.end);
}

void printfIntervals(vector<Interval> &itvs)
{
    for_each(itvs.begin(), itvs.end(), printInterval);
}


int getCount(ListNode *head)
{
    int i = 0;
    for (; head != NULL; head=head->next,i++);
    return i;
}

ListNode *moveNext(ListNode *head , int n)
{
    for (; head != NULL && n > 0; head=head->next,n--);
    
    return head;
}


void printList(ListNode *head)
{
    printf("print list: %p:\n",head);
    for (; head != NULL; head=head->next)
        printf("%d\n",head->val);
    printf( "print list end \n");
}

template<class T>
void printContainer(T c)
{
    for ( auto a : c)
        cout<<a<<endl;
}

void printVecVec(vector<vector<int> > &A)
{
    printf("~~~~~~~size: %lu~~~~~~>>>\n",A.size());
    for (auto i = A.begin(); i != A.end(); i++)
    {
        vector<int> row = *i;
        
        printContainer(row);
        //printContainer(row);
        
        for (auto j = row.begin(); j != row.end(); j++) {
            int k = *j;
            printf("%d  ",k);
        }
        
        printf("\n");
    }
    printf("\n<<<~~~~~~~~~~~~~\n");
}


typedef vector<int> MatrixRow;
typedef vector<MatrixRow> Matrix;



/// Definition for a point.
struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};



struct Line
{
    Point a;
    Point b;
    Line();
    Line(Point aa, Point bb):a(aa),b(bb){}
};


///Definition for singly-linked list with a random pointer.
struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/// 全排列
long A(int m,int n)
{
    if (n == 0)
        return 1;
    //else if(n ==1 )
    //    return m;
    
    long total = 1;
    for (int i = 0; i < n; i++)
    {
        total *= (m - i);
    }
    
    return total;
}


/// 组合
long C(int m,int n)
{
    if (n == 0)
        return 1;
    else if(n ==1)
        return m;
    
    return A(m,n)/A(n,n);
}
