#include <stdio.h>
#include <stdlib.h>


int n, i, j, a[30][30], q[30], visited[30], f=-1, r=-1;

void bfs(int v)
{
       int i;
       for (i=0;i<n;i++)
       {
            if(a[v][i] != 0 && visited[i] == 0)
              {
                r=r+1;
                q[r]=i;
                visited[i]=1;
                printf("%d  ",i);
              }
      }

      f=f+1;
      if(f<=r)
      bfs(q[f]);
}


void main()
{
    int v;
    printf("\n Enter the number of node: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        visited[i]=0;
    }

    printf("\n Enter graph data in matrix form:\n");
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
       scanf("%d",&a[i][j]);
    printf("\n Enter the starting node is: ");
    scanf("%d",&v);

    f=r=0;
    q[r]=v;
    printf("\n The BFS traversal is: ");
    visited[v]=1;
    printf("%d   ",v);

    bfs(v);
    if(r != n-1)
        printf("\n BFS is not possible");
}
