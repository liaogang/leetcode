//
//  main.cpp
//  Evaluate_Reverse_Polish_Notation
//
//  Created by liaogang on 14/11/11.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>





/**
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Some examples:
 
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 
 
 */



/**
 逆波兰表达式简介
 逆波兰表达式(Reverse Polish Notation)[1] ，简称为RPN，由J. Lukasiewicz（12/21/1878 – 02/13/1956）发展而来，在避免使用括号的情况下，完成表达式的有优先级的运算。RPN表达式由操作数（operand）和运算符（operator）构成，不使用括号，即可表示带优先级的运算关系，但是须使用元字符，如空格。一般在计算机中，使用栈操作进行RPN表达式的计算。遇到操作数就入栈，遇到运算符，就对当前栈顶元素进行相应的一元或者二元运算。
 
 */

#include <vector>
#include <stack>
using namespace std;



const char charOperator[] = {'?','+','-','*','/','%'};
enum enumOperator
{
    not_operator=0,
    operator_plus,
    operator_sub,
    operator_mul,
    operator_divide,
    operator_mod
};


string calc(string &a,string &b,enumOperator op)
{
    int ia;
    int ib;
    
    ia=atoi(a.c_str());
    
    ib=atoi(b.c_str());
    
    int ret;
    
    if (op == operator_plus)
    {
        ret = ia + ib;
    }
    else if (op == operator_sub)
    {
        ret = ia - ib;
    }
    else if (op == operator_mul)
    {
        ret = ia * ib;
    }
    else if (op == operator_divide)
    {
        ret = ia / ib;
    }
    else if (op == operator_mod)
    {
        ret = ia % ib;
    }
    
    char sRet[20];
    sprintf(sRet, "%d\0",ret);
    return     string(sRet);
}


///是运算符?
enumOperator isOperator(char c)
{
    enumOperator o = not_operator;
    for (int i = 0; i < sizeof(charOperator)/sizeof(charOperator[0]); i++)
    {
        if (c == charOperator[i])
        {
            o = (enumOperator)i;
        }
    }
    
    return o;
}

///是操作数?
bool isOperand(char c)
{
    return !isOperator(c);
}



class myRPNstack
{
private:
    stack<string> stackRPN;
public:
    
    int getValue()
    {
        string a= stackRPN.top();
        return atoi(a.c_str());
    }
    
    
    void push(string s)
    {
        enumOperator o  = not_operator;
        
        if (s.size()==1)
            o = isOperator( s[0]) ;
        
        if( o != not_operator)
        {
            string a,b;
            a=popTop();
            b=popTop();
            
            string value =  calc(b, a, o);
            
            stackRPN.push( value );
        }
        else
        {
            stackRPN.push(s);
        }
        
        
    }
    
    string popTop()
    {
        string a = top();
        pop();
        return a;
    }
    
    void pop()
    {
       stackRPN.pop();
    }
    
    string top()
    {
        return stackRPN.top();
    }
    
    bool empty()
    {
        return stackRPN.empty();
    }
};


int evalRPN(vector<string> &tokens)
{
    myRPNstack stackRPN;
    
    auto end=tokens.end();
    for (auto i = tokens.begin(); i != end; i++)
    {
        stackRPN.push(*i);
    }
    
    
    return stackRPN.getValue();
}


int main(int argc, const char * argv[])
{
    /// = 9
    vector<string> tokens({"2", "1", "+", "3", "*"});
    //cout<<evalRPN(tokens)<<endl;
    
    ///=6
    vector<string> tokens2({"4", "13", "5", "/", "+"});
//    cout<<evalRPN(tokens2)<<endl;
    
    
   // 	["3","-4","+"]
    vector<string> tokens3({"3","-4","+"});
    cout<<evalRPN(tokens3)<<endl;
    
    return 0;
}



