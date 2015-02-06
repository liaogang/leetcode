//
//  main.cpp
//  generate_DeBruijnBit
//
//  Created by liaogang on 14/10/29.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

/**
 @see http://www.matrix67.com/blog/archives/3985
 00000111011111001011010100110001
  这个 01 串有一个无比牛 B 的地方：如果把它看作是循环的，它正好包含了全部 32 种可能的 5 位 01 串，既无重复，又无遗漏！其实，这样的 01 串并不稀奇，因为构造这样的 01 串完全等价于寻找一个有向图中的 Euler 回路。如下图，构造一个包含 16 个顶点的图，顶点分别命名为 0000, 0001, 0010, …, 1111 。如果某个点的后 3 位，正好等于另一个点的前 3 位，就画一条从前者出发指向后者的箭头。也就是说，只要两个顶点上的数满足 abcd 和 bcde 的关系（ a 、 b 、 c 、 d 、 e 可能代表相同的数字），就从 abcd 出发，连一条到 bcde 的路，这条路就记作 abcde 。注意，有些点之间是可以相互到达的（比如 1010 和 0101 ），有些点甚至有一条到达自己的路（比如 0000 ）。
 
 
 
 De Bruijn 序列在这里究竟有什么用呢？它的用途其实很简单，就是为 32 种不同的情况提供了一个唯一索引。比方说， 1000000 后面有 6 个 0 ，将 1000000 乘以 0x077CB531 ，就得到
 */





/**
 *  Binary Circles
 *  @see https://projecteuler.net/index.php?section=problems&id=265
 *
 
 2N binary digits can be placed in a circle so that all the N-digit clockwise subsequences are distinct.
 
 For N=3, two such circular arrangements are possible, ignoring rotations:
 
 For the first arrangement, the 3-digit subsequences, in clockwise order, are:
 000, 001, 010, 101, 011, 111, 110 and 100.
 
 Each circular arrangement can be encoded as a number by concatenating the binary digits starting with the subsequence of all zeros as the most significant bits and proceeding clockwise. The two arrangements for N=3 are thus represented as 23 and 29:
 00010111 2 = 23
 00011101 2 = 29
 
 Calling S(N) the sum of the unique numeric representations, we can see that S(3) = 23 + 29 = 52.
 
 Find S(5).

 */







#include <iostream>
#include <map>

using namespace std;

void printHex(unsigned int hex)
{
    cout<<"hex: 0x";
    for (int i= sizeof(unsigned int) *8 -1 ; i >= 0 ; i--)
    {
        if (i == 2) {
            cout<<" ";
        }
        if (hex & (1 << i) ) {
            cout<<"1";
        }
        else
            cout<<"0";
    }
    
    cout<<endl;
}
// 2^5 = 32.
// 6位子串需要2^6个位数
void generate_DeBruijnArray(int* arr , int arrLen = 32)
{
    const int arrFive[5] ={0};
    
}


unsigned int generate_DeBruijnBit()
{
    return 0;
}


map<unsigned int,bool> _map;

void pick(int *arr,int len,int begins)
{
    //cout<<"[";
    for (int i = begins ; i < len; i++)
    {
        int *arrTmp = new int[len];
        memccpy(arrTmp, arr, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]));
        arrTmp[i]=1;
        
        unsigned int key = 0;
        
        //print it
        for (int j = 0; j < len; j ++)
        {
            if (arrTmp[j] == 1) {
                key |= 1<<j;
            }
            //cout<<arrTmp[j]<<",";
        }
        
        
        
        
        cout<<endl<<key<<endl;
        _map[key]=true;
        cout<<"added to map"<<endl;
        printHex(key);
        
        
        //cout<< "{child, ";
        pick(arrTmp, len, i+1);
        //cout<< "}";
        
        delete arrTmp;
    }
    
   //cout<<"]";
    
}



unsigned int generate_BiraryCircles3()
{
    int arrThree[3] ={0};
  
    
    unsigned int birary_array_bit = 0;
    unsigned int begin = 0x000;
    _map[begin]=false;
    
    pick(arrThree, 3, 0);
    
    cout<<endl;
    
    
    
    

    //生成　birary tree.
    
    //取最后二位
    for (int i = 0 ; i < /*2^3*/ 8; i++)
    {
        unsigned int last2bit = birary_array_bit & 3;

        //末位置0,或置1
        bool added = false;
        unsigned int addedend = 0x1; //末位要加的bit
        while (!added)
        {
            unsigned int last3bit = ( last2bit << 1) | addedend;
            auto finded = _map.find( last3bit);
            if ( finded != _map.end())
            {
                if (finded->second == true)
                {
                    birary_array_bit = (birary_array_bit <<1) | addedend;
                    _map[last3bit]=false;
                    added = true;
                }
            }
            
            if (addedend == 0x1)
                addedend = 0x0;
            else if (addedend == 0)
                break;
        }
        
    }
    
    
    
    
    
    
    cout<<"result ";
    printHex(birary_array_bit);
    
    
    return 0;
}




int main(int argc, const char * argv[])
{
    generate_BiraryCircles3();
    
    
    
    //testBirayCircle3();
    
    
    
    
    
    return 0;
}




