//
//  binary_seaerch.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 22..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int arr[7] = {1,2,3,4,5,6,7};
int l,r,p,val;
int main()
{
    r= sizeof(arr) / sizeof(int) -1;
    
    scanf("%d",&val);
    bool res = false;
    while(l <= r)
    {
        p = (l+r)/2;
        printf("(%d %d %d)\n",l,r,p);
        
        if(val > arr[p]){
            l = p+1;
        }else if(val < arr[p]){
            r = p-1;
        }else{
            res = true;
            break;
        }
    }
    
    printf("(%d %d %d)\n",l,r,p);
    if(res){
        printf("%d\n",p);
    }else{
        printf("no result\n");
    }
    return 0;
}