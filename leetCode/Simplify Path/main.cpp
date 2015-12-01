//
//  main.cpp
//  Simplify Path
//
//  Created by liaogang on 15/3/12.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/*
 Simplify Path
 
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 
 */

string simplifyPath(string path)
{
    if (path == "/..")
        return "/";
    
    if (path == "/.")
        return "/";
    
     if (path == "/")
        return "/";
    
    
    cout<<path<<endl;
    
    int super = 0 ;
    
    while( 1 )
    {
        auto cur = path.find("/" , super + 1);
        
        if (cur == string::npos)
            break;
        else
        {
            if (cur == super + 1) {
                path.erase( cur  , 1);
                super = 0;
                cout<<path<<endl;
                continue;
            }
            
            if( path[cur+1] == '.')
            {
                if( path[cur +2] == '.' )
                {
                    if( path[cur + 3] == '/' || cur + 3 == path.length() )
                    {
                        auto len = cur + 3 - super;
                        path.erase( super + 1 , len );
                        
                        super = 0;
                        cout<<path<<endl;
                        continue;
                    }
                }
                else if( path[cur + 2] == '/' || cur + 2 == path.length() )
                {
                    path.erase(cur+1,2);
                    super = 0;
                    cout<<path<<endl;
                    continue;
                }
                
            }
            else if (path [cur + 1] == '/')
            {
                path.erase( cur + 1 , 1);
                super = 0;
                cout<<path<<endl;
                continue;
            }
            
            super = cur ;
        }
        
    }
    
    
    cout<<path<<endl;
    if (path.length() > 1) {
    auto end = path.end() -1 ;
    if ( end != path.begin() && *end  == '/')
    {
        path.erase( end );
    }
        

    }
    
    cout<<path<<endl;

    
    if (path == "/..")
        return "/";
    
    if (path == "/.")
        return "/";
   
    if ( strncmp(path.c_str(), "/../", 4) == 0)
        path.erase( 0 , 3);
    

    if ( strncmp(path.c_str(), "/./", 3) == 0)
        path.erase( 0 , 2);
    
    return path;
}

int main(int argc, const char * argv[])
{
   
//    cout<< simplifyPath("///TJbrd/owxdG")<<endl;
    
//    cout<< simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///")<<endl;
    
//    cout<< simplifyPath("/home/foo/./.././bar")<<endl;
//    cout<< simplifyPath("/home/../../..")<<endl;
    
    cout<< simplifyPath("///")<<endl;
    
//    cout<< simplifyPath("/../")<<endl;
    
//    cout<< simplifyPath("/a/./b/../../c/")<<endl;
    
    return 0;
}
