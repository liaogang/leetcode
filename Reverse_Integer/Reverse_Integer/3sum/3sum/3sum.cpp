/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/


#include <iostream>
#include <map>
#include <vector>

using namespace std;

//struct pos_num
//{
//    int pos,num;
//    pos_num(int p,int n):pos(p),num(n)
//    {
//        
//    }
//};


vector<int> sortThree(int a,int b,int c)
{
    vector<int> result;
    
    if (a > b) {
        swap(a, b);
    }

    if (b > c) {
        swap( b, c);
    }
    
    if (a > b) {
        swap(a, b);
    }
    

    result.push_back(a);
    result.push_back(b);
    result.push_back(c);
   
    cout<<a<<","<<b<<","<<c<<endl;
    
    return result;
}


struct pos_num2
{
    int pos,pos2;
    int num;
    int num2;
    bool marked;
    pos_num2()
    {
    }
    
    pos_num2(int n,int n2,int p,int p2):
        num(n),num2(n2),marked(false),pos(p),pos2(p2)
    {
        
    }
};

vector<vector<int> > threeSum(vector<int> &num) {

    
    
    map<int,pos_num2> _map;
    
    
    
    vector<vector<int>> result;
    
    auto begin = num.begin();
    auto end = num.end();
   
    for ( auto beg = begin ; beg!=end; beg++)
    {
        for (auto beg2 = beg + 1; beg2!=end; beg2++)
        {
            int value2 = *beg2;
            int pos2 = beg2 - begin;
            
            auto finded = _map.find(value2);
            if ( finded != _map.end())
            {
                pos_num2 pn = finded->second;
                if (  pn.marked == false && pn.pos != pos2 && pn.pos2 != pos2)
                {
                    result.push_back( sortThree(pn.num, pn.num2, value2 ) );
                    
                    pn.marked = true;
                    
                    _map[value2] = pn; //mark it's added.
                }
                
                
            }
            else
            {
                int pos = beg - begin;
                //not found
                int value = *beg;
                pos_num2 pn(value,value2,pos,pos2);
                
                int index = 0 - value - value2;
                _map[index]=pn;
            }
            
        }
        
        
    }
    
    
    
    return result;
}



int main(int argc, const char * argv[])
{
  //  vector<int> test( {-1 ,0 ,1, 2, -1 ,-4} );
    //vector<int> test( { -40 , 32 , 20} );
    //vector<int> test( { -40 , 8 , 0 , -8 , -8,32 , 20} );
    vector<int> test( { -20 , -20 , -20 , -20 , 40 , 40} );
    
    threeSum( test );
    
    
    vector<int> test2( {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6});
    
    threeSum( test2 );
    
    return 0;
}
