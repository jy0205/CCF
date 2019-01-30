#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include<stack>
#include <string.h>
#include <vector>
using namespace std;
const int maxn=(int)41;
const unsigned long long maxm=400;
int a[maxn][5];
int n;
int f[401][401][401];
int p[5][3]={{2,2,2},{0,1,0}, {1,0,0},{0,3,3},{3,0,3}};
//对于每个任务其选择方式有三种，单C，单C单G，双C单G（与双C取最小值）
//对于单C，可选择CPU0或CPU1
//对于单C单G，同上
//对于双C单G，则都选
//如此枚举每个任务的选择方式，则不需要考虑任务的执行顺序，直接累加时间即可。枚举每个任务的执行方式，并且标记其各处理器占用时间的状态f（x,y,z）=i，表示执行完前i个任务各处理器占用时间
//f（x,y,z）不为0，则完成前f(x,y,z)个任务需要的最少时间为max（x,y,z）
struct nod{
    int idx,x,y,z;
    nod(){}
    nod(int idx,int x,int y,int z):idx(idx),x(x),y(y),z(z){}
    void out(){printf("id:%d %d %d %d\n",idx,x,y,z);}
};
nod s[200];
int dfs(){
    int h=0;
    s[h++]=nod(0,0,0,0);
    f[0][0][0]=-1;
    int i,x,y,z;
    int ans=23333333;
    while(h!=0){
        nod t=s[--h];
        i=t.idx,x=t.x,y=t.y,z=t.z;
        if(f[x][y][z]>=i)continue;  //如果该状态可以执行的任务数不少于接下来要枚举的任务数就放弃该次枚举
            f[x][y][z]=i;
        
        i++;
        int v=max(x,max(y,z));
        if(v>ans)continue;
        if(i==n+1) {ans=min(ans,v);continue;}
        for(int j=0;j<5;j++){
            s[h++]=nod(i,x+a[i][p[j][0]],y+a[i][p[j][1]],z+a[i][p[j][2]]);
        
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);//交上去你会发现30分。但证明并没有什么问题
    memset(f,0,sizeof 0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=4;j++)
        scanf("%d",&a[i][j]);
        if(a[i][2]>a[i][4])a[i][2]=a[i][4];
        a[i][0]=0;
    }
    printf("%d\n",dfs());

    return 0;
}
