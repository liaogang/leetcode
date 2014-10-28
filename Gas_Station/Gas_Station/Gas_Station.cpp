//
//  main.cpp
//  Gas_Station
//
//  Created by liaogang on 14/10/28.
//  Copyright (c) 2014年 gang.liao. All rights reserved.

/**
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        auto distance = cost;
        int size = gas.size();
        int distanceFromBegin =0;
        int gasCostFromBegin=0;
        
        int result = -1;
        
        for (int endIndex = 0 ; endIndex < size  ; endIndex++)
        {
            for (int beginIndex = endIndex -1 ; beginIndex < size; beginIndex--)
            {
                int _beginIndex = beginIndex;
                if (_beginIndex < 0)
                    _beginIndex += size;
                
                
                
                int currGas = gas[_beginIndex];
                int nextDistance = distance[_beginIndex];
                
                
                distanceFromBegin += nextDistance;
                gasCostFromBegin += currGas;
                
                if (distanceFromBegin > gasCostFromBegin)
                {
                }
                else
                {
                    result = _beginIndex;
                    break;
                }
                
                
            }

        }
        
        
        return result;
    }
};



int main(int argc, const char * argv[]) {

    
    Solution s;
    
    vector<int> gas={4};
    vector<int> cost={5};
   int index = s.canCompleteCircuit(gas, cost);
    
    cout<<index<<endl;
    
    return 0;
}
