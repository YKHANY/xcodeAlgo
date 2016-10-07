//
//  10430.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    
    printf("%d\n",(a+b)%c);
    printf("%d\n",(a%c + b%c)%c);
    printf("%d\n",(a*b)%c);
    printf("%d\n",((a%c)*(b%c))%c);
    
    return 0;
}