//
//  main.cpp
//  Subsets
//
//  Created by liaogang on 14/12/19.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>


/**
   Given a set of distinct integers, S, return all possible subsets.
 Note:
 
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 
 For example,
 If S = [1,2,3], a solution is:
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]

 @see

 */


#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

void sortarray(vector<int> &t)
{
    sort(t.begin(), t.end(), myfunction );
}

#include <assert.h>


/**
 　　除开空集不算,
   　若用1代表只有一个元素的集合,
     a代表一个或多个元素的集合
    [1,a] 的合集　等于　1 + a子集 + [1xa](1与a各子集的结合)
    即: 1 + a 合上　1xa
 */

typedef  vector<int> mSet;
typedef vector<mSet> mSubset;


void printSet (mSet &s)
{
    if (s.size() == 0) {
        printf("empty");
    }
    
    for (auto i = s.begin(); i!= s.end(); i++) {
        int ii = *i;
        printf("%d,",ii);
    }
    
    printf("\n");
}

void printSubSet (mSubset &s)
{
    for (auto i = s.begin(); i!= s.end(); i++) {
        mSet ii = *i;
        printSet(ii);
    }
    printf("\n");
}

/// allow duplicate
mSubset add(int one ,mSubset a)
{
    vector<int> f;
    f.push_back(one);
    a.insert(a.begin(), f);
    return  a;
}



mSubset add(mSubset a , mSubset b)
{
    for (auto i = b.begin(); i != b.end(); i++) {
        mSet temp = *i;
        a.push_back(temp);
    }
    
    return  a;
}

mSubset mul( int one , mSubset a)
{
    vector<vector<int>> result;
    
    auto end= a.end();
    for (auto i  = a.begin(); i!= end; i ++) {
        vector<int> atemp = *i;
        atemp.insert(atemp.begin(), one);
        result.push_back(atemp);
    }
    
    return result;
}



/// get the rest behind the first object.
mSet getRest(mSet s)
{
    s.erase(s.begin());
    return s;
}

/** 获得一个元素集合的子集
 * get a set's value. subsets
 */
mSubset getSubsets(mSet a)
{
    assert(a.size() != 0 );
    
    if (a.size() > 1)
    {
        int one = a.front();
        
        mSet rest = getRest(a);
        
        mSubset restSubset = getSubsets(rest);
        
        return add( add(one,  restSubset ) , mul(one, restSubset));
    }
    else // size = 1
    {
        mSubset r;
        r.push_back(a);
        return r;
    }
    
}












mSubset subsets(mSet &S)
{
    sortarray(S);
    mSubset emptySubset;
    mSet empty;
    emptySubset.push_back(empty);
    
    mSubset ret2 =  getSubsets(S);
    
    mSubset ret = add(emptySubset , ret2);
    
    printSubSet(ret);
    
    return ret;
}

void test1()
{
    vector<int> test({1,2,3,4,5});
    subsets( test );
}



int main(int argc, const char * argv[])
{
    test1();
    return 0;
}
