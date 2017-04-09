/*
*Dijkstra 纯手写
*
*2017-4-9 调试完成
*
*By veizi
*/
#include <bits/stdc++.h>
#define INF 0x0FFFFFFF
using namespace std;

int w[6][6]=
{
    0,2,INF,4,INF,INF,
    2,0,8,INF,1,INF,
    INF,8,0,4,3,8,
    4,INF,4,0,5,INF,
    INF,1,3,5,0,10,
    INF,INF,8,INF,10,0
};

int main()
{
    int start;
    cin>>start;
    bool know[6]= {false}; //判断是否可以确定该点的Path
    int cost[6]= {INF,INF,INF,INF,INF,INF}; //起点到该点的费用
    int path[6]= {-1}; //当前点的前一个出发点
    know[start]=true;
    cost[start]=0;
    path[start]=-1;

    for(int i=0; i<6; i++)
    {
        cost[i] = w[start][i];
        if(i!=start && cost[i]!=INF)
            path[i] = start;
    }

    int min_node=start;//当前未访问节点中最近的节点

    int unknown=4;//还不能确定路径的节点个数
    while(unknown>0)
    {
        int min_cost=INF;//从起点到达 当前未访问最近点 的消耗
        for(int j = 0; j < 6; j++)
        {
            if( !know[j] && (cost[j]<min_cost) )
            {
                min_cost = cost[j];
                min_node = j;
            }
        }

        know[min_node] = true;//标记 查找到的最近点k 为可以确定路径
        unknown--;

        for(int j = 0; j < 6; j++)
        {
            if(!know[j] && min_cost+w[min_node][j] < cost[j])
            {
                cost[j] = min_cost+w[min_node][j];
                path[j] = min_node;
            }
        }
    }

    //Path print out
    for(int i=0; i<6; i++)
    {
        int temp=i;
        cout<<"path: "<<temp;
        while(temp!=start)
        {
            cout<<" "<<path[temp];
            temp=path[temp];
        }
        cout<<"\t\tcost: "<<cost[i]<<endl;
    }
    return 0;
}
