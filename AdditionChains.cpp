/**
 * https://www.luogu.com.cn/problem/UVA529
 * Addition Chains：
 *      5       1 2 4 5
 *      7       1 2 4 6 7
 *      12      1 2 4 8 12 
 *      15      1 2 4 5 10 15           
 *      77      1 2 4 8 9 17 34 68 77
 */

#include <iostream>
using namespace std;

int n,d;            //d为搜索深度
int a[10005]={1};   //存储加成序列

bool dfs(int u);    //搜索第u层

int main(){
    while(scanf("%d",&n),n){    //取到n，且n不为零
        d=1;
        while(!dfs(1)){d++;}    //失败就加一层
        for(int i=0;i<d;++i){printf("%d ",a[i]);}
        puts(" ");
    }
    
    return 0;
}

bool dfs(int u){
    if(u==d){                   //达到搜索深度时，判断该序列是否成立
        return a[u-1]==n;
    }
    //剪枝
    for (int i = u-1; i >= 0; --i){ //cut1：优化搜索顺序
        int t=a[u-1]+a[i];          //t是该层新确定的值,遍历得到
        if(t>n) continue;           //cut2: 越界剪枝
        a[u]=t;                     //cut3；估价未来
        for(int j=u+1;j<=d;++j){
            t*=2;
        }
        if(t<n) return false;       
        if(dfs(u+1)) return true;
    }
    return false; 
}