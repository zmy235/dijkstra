#include <bits/stdc++.h>
using namespace std;
#define SIZE 9
#define INF 0x0FFFFFFF

int main(){

    int w[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=i;j<SIZE;j++)
        {
            if(i==j) w[i][j]=0;
            else
            {
                int t=rand()%50;
                w[i][j]=(t>10) ? INF:t;
                w[j][i]=w[i][j];
            }
        }
    }

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            cout<<(w[i][j]==INF ? -1:w[i][j])<<"\t";
        }
        cout<<endl;
    }
    while(true){
        int start;
        cin>>start;

        bool know[SIZE];
        int cost[SIZE];
        int path[SIZE];

        for(int i=0;i<SIZE;i++)
        {
            know[i]=false;
            cost[i]=w[start][i];
            path[i]=(w[start][i]==INF) ? start : -1;
        }

        know[start]=true;
        path[start]=-1;

        int min_node=start;
        for(int j=SIZE;j>=1;j--)
        {
            int min_cost=INF;
            for(int i=0;i<SIZE;i++)
            {
                if(!know[i] && min_cost>cost[i])
                {
                    min_cost=cost[i];
                    min_node=i;
                }
            }

            know[min_node]=true;

            for(int i=0;i<SIZE;i++)
            {
                if(!know[i] && min_cost+w[min_node][i]<cost[i])
                {
                    cost[i]=min_cost+w[min_node][i];
                    path[i]=min_node;
                }
            }
        }

        for(int i=0;i<SIZE;i++)
        {
            if(cost[i]>=INF) cout<<i<<": "<<"Can not touch."<<endl;
            else
            {
                cout<<i<<": "<<i<<" ";
                int t=i;
                while(path[t]!=-1)
                {
                    t=path[t];
                    cout<<t<<" ";
                }
                cout<<start<<"\t\tcost: "<<cost[i]<<endl;
            }
        }
    }
    return 0;
}
