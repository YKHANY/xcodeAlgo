//
//  1_b.cpp
//  Algo
//
//  Created by younghan on 2015. 11. 30..
//  Copyright © 2015년 younghan. All rights reserved.
//

#include<stdio.h>

int arr[9];
int main()
{
    int i,j;
    int tmp=0, res;
    for(i=0; i<9; i++){
        scanf("%d",arr+i);
        tmp += arr[i];
    }
    res = tmp - 100;
    
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++){
            if(i!= j && arr[i]!= 0 && arr[j] != 0 && res == arr[i]+arr[j]){
                arr[i] = 0;
                arr[j] = 0;
                break;
            }
        }
    }
    
    for(i=0; i<9; i++)
    {
        if(arr[i] != 0)
            printf("%d\n",arr[i]);
    }
    return 0;
}