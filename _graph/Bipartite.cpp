#include<bits/stdc++.h>
using namespace std;
#define MaxN 100

bool bipartite = true;
int a[MaxN][MaxN], color[MaxN];
bool mark[100];
int vertex,edge;
void dfs(int v, int cur)
{
    mark[v] = true;
    color[v] = cur; // color this vertex as cur
    for (int i = 0; i < vertex; i++)
        if (a[v][i] == 1)  // if there is edge between v and i
        {
            if (color[i] == cur)   // if color of vertex i is equal to color of v, that is cur
            {
                bipartite = false; // graph is definitely not bipartite, so return
                return;
            }
            if (!mark[i]) dfs(v, cur==1?2:1); // continue dfs
        }
};

int main()
{

    int i,u,v;
    cin>>vertex>>edge;
    for(i=1; i<=edge; i++)
    {
        cin>>u>>v;
        a[u][v] = 1;
        a[v][u]= 1;
    }
    dfs(0, 1);
    cout << bipartite;
}
