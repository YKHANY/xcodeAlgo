//
//  vector_test.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 23..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    // v = vector<int>(10);
    /*
    v.push_back(3);
    v.push_back(4);
    
    v.pop_back();
    cout << v.back();
    cout << v.size();
    cout << v.front();
    */
    
    //v.resize(20);
    //v.push_back(3);
    //cout << v[0];
   
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    
    sort(v.begin(), v.end());
    v.erase(v.begin()+2);
    cout << v[2];
    v.insert(v.begin()+2,3);
    cout << v[2];
    
    
    return 0;
}
