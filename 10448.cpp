//
//  10448.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 5..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
bool ure[50];
int main()
{
    for(int i=1; i<=50; i++){
        ure[i*(i+1)/2] = true;
    }
    
    int t;
    cin >> t;
    while(t--)
    {
       int k;
       cin >> k;
        
        bool check = false;
        for(int i=1; i<=k-2; i++){
            for(int j=1; j<=k-i-1; j++){
                if(ure[i] && ure[j] && ure[k-i-j]){
                    check = true;
                    break;
                }
            }
        }
        if(check){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
        
    }
    
    return 0;
}
