给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环，边权可能为负数。

请你求出 $1$ 号点到 $n$ 号点的最短距离，如果无法从 $1$ 号点走到 $n$ 号点，则输出 `impossible`。

数据保证不存在负权回路。

### 输入格式

第一行包含整数 $n$ 和 $m$。

接下来 $m$ 行每行包含三个整数 $x, y, z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

### 输出格式

输出一个整数，表示 $1$ 号点到 $n$ 号点的最短距离。

如果路径不存在，则输出 `impossible`。

### 数据范围

$1 \le n, m \le 10^5$

图中涉及边长绝对值均不超过 $10000$。

### 输入样例：

Plaintext

```
3 3
1 2 5
2 3 -3
1 3 4
```

### 输出样例：

Plaintext

```
2
```

```
#include<bits/stdc++.h>
using namespace std;
deque<int>q;
const int N=1e5+10,M=2e5+10;
bool st[N];
int dist[N];
int h[N],e[M],ne[M],idx,w[M];
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

int main(){
    memset(dist, 0x3f, sizeof dist);
    memset(h,-1,sizeof h);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    dist[1]=0;
    st[1]=1;
    q.push_back(1);
    while(q.size()){
        auto t=q.front() ;
        q.pop_front();
        st[t]=0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>w[i]+dist[t]){
                dist[j]=w[i]+dist[t];
                if(!st[j]){
                q.push_back({j});
                st[j]=1;}
            }
            
        }
    }
    if(dist[n]!=0x3f3f3f3f)cout<<dist[n];
    else cout<<"impossible";
}
```

