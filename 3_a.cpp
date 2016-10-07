//
//  3_a.cpp
//  Algo
//
//  Created by younghan on 2016. 1. 10..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int t;
int main()
{
    scanf("%d",&t);
    int a,b;
    for(int i=0; i<t; i++){
        scanf("%d %d",&a,&b);
        int val=0;
        int res=0;
        while(1)
        {
            int rem = b%a;
            if(rem > 0){
                val = b/a + 1;
            }else if(rem == 0){
                res = b/a;
                break;
            }
            int tmp = a*val - b;
            if(tmp > 0){
                a = tmp;
                b = b*val;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}