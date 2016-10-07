//
//  2251.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 26..
//  Copyright © 2016년 younghan. All rights reserved.
//
#if 0
#include <iostream>
#include <queue>
using namespace std;
bool visited[222][222][222];
int a,b,c;
class dat{
    public:
    int d1,d2,d3;
    dat() {};
    dat(int d1, int d2, int d3): d1(d1), d2(d2), d3(d3) {};
};
bool res[222];
queue<dat> q;
bool cache[222][222][222];
void routine(dat over)
{
    if(cache[over.d1][over.d2][over.d3]) return;
    cache[over.d1][over.d2][over.d3] = true;
    
    int tmp;
    if(over.d1 > a){
        tmp = over.d1 - a;
        routine(dat(a, over.d2+ tmp, over.d3));
        routine(dat(a, over.d2, over.d3 + tmp));
    }
    else if(over.d2 > b){
        tmp = over.d2 - b;
        routine(dat(over.d1+tmp, b, over.d3));
        routine(dat(over.d1, b, over.d3+tmp));
    }
    else if(over.d3 > c){
        tmp = over.d3 - c;
        routine(dat(over.d1+tmp, over.d2, c));
        routine(dat(over.d1, over.d2+tmp,c));
    }
    else{
        if(!visited[over.d1][over.d2][over.d3]){
            q.push(dat(over.d1,over.d2,over.d3));
            visited[over.d1][over.d2][over.d3] = true;
        }
    }
}

void bfs(dat start)
{
    q.push(start);
    visited[start.d1][start.d2][start.d3] = true;
    
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        //cout << out.d1 << " " << out.d2 << " " << out.d3 <<endl;
        if(out.d1 == 0)
            res[out.d3] = true;
        
        int next_a = out.d1; int next_b = out.d2; int next_c = out.d3;
        if(out.d1 + out.d2 > b){ // 흘러넘치는 경우
            //next_b = b;
            //next_a = out.d1 + out.d2 - b;
            routine(dat(0,out.d1+out.d2,out.d3));
        }else{
            next_b = out.d1 + out.d2;
            next_a = 0;
        }
        if(!visited[next_a][next_b][next_c]){
            q.push(dat(next_a,next_b,next_c));
            visited[next_a][next_b][next_c] = true;
        }
        next_a = out.d1; next_b = out.d2; next_c = out.d3;
        if(out.d1 + out.d3 > c){
            //next_c = c;
            //next_a = out.d1 + out.d3 - c;
            routine(dat(0,out.d2, out.d1+out.d3));
        }else{
            next_c = out.d1 + out.d3;
            next_a = 0;
        }
        if(!visited[next_a][next_b][next_c]){
            q.push(dat(next_a,next_b,next_c));
            visited[next_a][next_b][next_c] = true;
        }
        ////////////////////////////////////////////////////////////
        next_a = out.d1; next_b = out.d2; next_c = out.d3;
        if(out.d2 + out.d1 > a){
            //next_a = a;
            //next_b = out.d2 + out.d1 - a;
            routine(dat(out.d2+out.d1,0,out.d3));
        }else{
            next_a = out.d2 + out.d1;
            next_b = 0;
        }
        if(!visited[next_a][next_b][next_c]){
            q.push(dat(next_a,next_b,next_c));
            visited[next_a][next_b][next_c] = true;
        }
        
        next_a = out.d1; next_b = out.d2; next_c = out.d3;
        if(out.d2 + out.d3 > c){
            //next_c = c;
            //next_b = out.d2 + out.d3 - c;
            routine(dat(out.d1,0,out.d2+out.d3));
        }else{
            next_c = out.d2 + out.d3;
            next_b = 0;
        }
        if(!visited[next_a][next_b][next_c]){
            q.push(dat(next_a,next_b,next_c));
            visited[next_a][next_b][next_c] = true;
        }
        ////////////////////////////////////////////////////////////
        next_a = out.d1; next_b = out.d2; next_c = out.d3;
        if(out.d3 + out.d2 > b){
            //next_b = b;
            //next_c = out.d3 + out.d2 - b;
            routine(dat(out.d1,out.d3+out.d2, 0));
        }else{
            next_b = out.d3 + out.d2;
            next_c = 0;
        }
        if(!visited[next_a][next_b][next_c]){
            q.push(dat(next_a,next_b,next_c));
            visited[next_a][next_b][next_c] = true;
        }
        next_a = out.d1; next_b = out.d2; next_c = out.d3;
        if(out.d3 + out.d1 > a){
            //next_a = a;
            //next_c = out.d3 + out.d1 - a;
            routine(dat(out.d3+out.d1,out.d2,0));
        }else{
            next_a = out.d3 + out.d1;
            next_c = 0;
        }
        if(!visited[next_a][next_b][next_c]){
            q.push(dat(next_a,next_b,next_c));
            visited[next_a][next_b][next_c] = true;
        }
    }
    
}
int main()
{
    cin >> a >> b >> c;
    
    bfs(dat(0,0,c));
    
    for(int i=1; i<222; i++){
        if(res[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}
#endif
#if 0
//
//  2251.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 26..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
bool visited[222][222][222];
int a,b,c;
class dat{
public:
    int d1,d2,d3;
    dat() {};
    dat(int d1, int d2, int d3): d1(d1), d2(d2), d3(d3) {};
};
bool res[222];
queue<dat> q;
bool cache[222][222][222];
void routine(dat over)
{
    if(cache[over.d1][over.d2][over.d3]) return;
    cache[over.d1][over.d2][over.d3] = true;
    
    int tmp;
    if(over.d1 > a){
        tmp = over.d1 - a;
        routine(dat(a, over.d2+ tmp, over.d3));
        routine(dat(a, over.d2, over.d3 + tmp));
    }
    else if(over.d2 > b){
        tmp = over.d2 - b;
        routine(dat(over.d1+tmp, b, over.d3));
        routine(dat(over.d1, b, over.d3+tmp));
    }
    else if(over.d3 > c){
        tmp = over.d3 - c;
        routine(dat(over.d1+tmp, over.d2, c));
        routine(dat(over.d1, over.d2+tmp,c));
    }
    else{
        routine(dat(0,over.d1+over.d2,over.d3));
        routine(dat(0,over.d2,over.d1+over.d3));
        ////////////////////////////////////////////////////////////
        routine(dat(over.d2+over.d1,0,over.d3));
        routine(dat(over.d1,0,over.d2+over.d3));
        ////////////////////////////////////////////////////////////
        routine(dat(over.d1,over.d3+over.d2, 0));
        routine(dat(over.d3+over.d1,over.d2,0));
        
        if(!visited[over.d1][over.d2][over.d3]){
            
            q.push(dat(over.d1,over.d2,over.d3));
            visited[over.d1][over.d2][over.d3] = true;
        }
    }
}

void bfs(dat start)
{
    q.push(start);
    visited[start.d1][start.d2][start.d3] = true;
    
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        
        //cout << out.d1 << " " << out.d2 << " " << out.d3 <<endl;
        
        if(out.d1 == 0)
            res[out.d3] = true;
        
        routine(dat(out.d1,out.d2,out.d3));
        /*
        routine(dat(0,out.d1+out.d2,out.d3));
        routine(dat(0,out.d2,out.d1+out.d3));
        ////////////////////////////////////////////////////////////
        routine(dat(out.d2+out.d1,0,out.d3));
        routine(dat(out.d1,0,out.d2+out.d3));
        ////////////////////////////////////////////////////////////
        routine(dat(out.d1,out.d3+out.d2, 0));
        routine(dat(out.d3+out.d1,out.d2,0));
         */
    }
    
}
int main()
{
    cin >> a >> b >> c;
    
    bfs(dat(0,0,c));
    
    for(int i=0; i<222; i++){
        if(res[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}
#endif

//
//  2251.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 26..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
using namespace std;
bool visited[222][222][222];
int a,b,c;
class dat{
public:
    int d1,d2,d3;
    dat() {};
    dat(int d1, int d2, int d3): d1(d1), d2(d2), d3(d3) {};
};
bool res[222];
bool cache[222][222][222];
void routine(dat over)
{
    if(cache[over.d1][over.d2][over.d3]) return;
    cache[over.d1][over.d2][over.d3] = true;
    
    int tmp;
    if(over.d1 > a){
        tmp = over.d1 - a;
        routine(dat(a, over.d2+ tmp, over.d3));
        routine(dat(a, over.d2, over.d3 + tmp));
    }
    else if(over.d2 > b){
        tmp = over.d2 - b;
        routine(dat(over.d1+tmp, b, over.d3));
        routine(dat(over.d1, b, over.d3+tmp));
    }
    else if(over.d3 > c){
        tmp = over.d3 - c;
        routine(dat(over.d1+tmp, over.d2, c));
        routine(dat(over.d1, over.d2+tmp,c));
    }
    else{
        routine(dat(0,over.d1+over.d2,over.d3));
        routine(dat(0,over.d2,over.d1+over.d3));
        ////////////////////////////////////////////////////////////
        routine(dat(over.d2+over.d1,0,over.d3));
        routine(dat(over.d1,0,over.d2+over.d3));
        ////////////////////////////////////////////////////////////
        routine(dat(over.d1,over.d3+over.d2, 0));
        routine(dat(over.d3+over.d1,over.d2,0));
        
        if(!visited[over.d1][over.d2][over.d3]){
            if(over.d1 == 0)
                res[over.d3] = true;
            visited[over.d1][over.d2][over.d3] = true;
        }
    }
}

int main()
{
    cin >> a >> b >> c;
    
    routine(dat(0,0,c));
    
    for(int i=0; i<222; i++){
        if(res[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}

