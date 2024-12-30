/**
 * 5            N<=10000
 * 3            M<=100
 * 1 2 3 4 5    
 * ----------
 * 1 2 4 5 3
 */

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n,m;
// 	cin>>n>>m;
// 	int ord[n+1];
// 	for(int i=1;i<=n;++i)	cin>>ord[i];
// 	for(int i=1;i<=m;++i)	next_permutation(ord+1,ord+1+n);
// 	for(int i=1;i<n;++i)	cout<<ord[i]<<' ';
// 	cout<<ord[n];
// }

#include <iostream>
using namespace std;

const int N=10010;

int n,m;
int arr[N];     //记录方案
int mars[N];    //记录火星人初始排列
bool st[N];     //记录每个数是否选过
int res=0;

void dfs(int x);

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&mars[i]);
    }
    dfs(1);

    return 0;
}

void dfs(int x){
    if(x>n){
        res++;
        if(res==m+1){
            for(int i = 1 ; i<=n;++i){
                printf("%d",arr[i]);
                if(i!=n){
                    printf(" ");
                }
            }
            exit(0);
        }
    }

    for(int i=1;i<=n;++i){
        if(!res){
            i=mars[x];
        }
        if(!st[i]){
            st[i]=true;
            arr[x]=i;
            dfs(x+1);
            st[i]=false;
            arr[x]=0;
        }
    }
}

 

/**

    //present
    int arr[10010];
    int mark[10010]={0};

    //int N;
    int n;
    int cnt=0;
    int goal;

    //dfs 第k位 共n个
    void dfs(int k);

    int main(){
        cin>>n;
        cin>>goal;
        for(int i=1;i<=n;++i){
            int tmp;
            cin>>tmp;
            arr[i]=tmp;
            mark[tmp]=1;
        }

        dfs(1);

        return 0;
    }

    void dfs(int k){
        if(k>n){
            cnt++;
            if(cnt==goal){
                for(int i=1;i<=n;++i){
                    printf("%d",arr[i]);
                    if (i!=n){
                        printf(" ");
                    }
                }
                cout<<endl;
            }
            return;
        }
        for(int i=1;i<=n;++i){
            if(mark[i]==0){
                mark[i]=1;
                arr[k]=i;
                dfs(k+1);
                mark[i]=0;
            }
        }
    }

*/