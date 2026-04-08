<<<<<<< HEAD
## 多重背包问题 (Multiple Knapsack Problem)

这道题目是经典的**多重背包问题**。与 01 背包（每种 1 件）和完全背包（每种无限件）不同，多重背包对每种物品的数量有限制。

### 题目描述

有 $N$ 种物品和一个容量为 $V$ 的背包。 第 $i$ 种物品最多有 $s_i$ 件，每件体积是 $v_i$，价值是 $w_i$。 求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。



```
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int g[N],f[N],q[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(g,f,sizeof g);
        for(int j=0;j<v;j++){
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v){
                if(hh<=tt&&q[hh]<k-s*v)hh++;
                while(hh<=tt&&g[q[tt]]-(q[tt]-j)/v*w<=g[k]-(k-j)/v*w)tt--;
                q[++tt]=k;
                f[k]=g[q[hh]]+(k-q[hh])/v*w;
            }
        }
    }
    cout<<f[m];
    return 0;
}
```

=======
## 多重背包问题 (Multiple Knapsack Problem)

这道题目是经典的**多重背包问题**。与 01 背包（每种 1 件）和完全背包（每种无限件）不同，多重背包对每种物品的数量有限制。

### 题目描述

有 $N$ 种物品和一个容量为 $V$ 的背包。 第 $i$ 种物品最多有 $s_i$ 件，每件体积是 $v_i$，价值是 $w_i$。 求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。



```
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int g[N],f[N],q[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(g,f,sizeof g);
        for(int j=0;j<v;j++){
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v){
                if(hh<=tt&&q[hh]<k-s*v)hh++;
                while(hh<=tt&&g[q[tt]]-(q[tt]-j)/v*w<=g[k]-(k-j)/v*w)tt--;
                q[++tt]=k;
                f[k]=g[q[hh]]+(k-q[hh])/v*w;
            }
        }
    }
    cout<<f[m];
    return 0;
}
```

>>>>>>> 72bd28a3d2a7be7368f1697833d6d6caa357466a
