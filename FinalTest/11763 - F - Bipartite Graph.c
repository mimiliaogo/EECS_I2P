#include <stdio.h>
int n;
int edge[1010][1010];
void dfs(int vertice, int depth)
{
    int i;

    if (edge[0][vertice]==0) {
        edge[0][vertice] = depth;
        for (i=1; i<=n; i++) {
            if (edge[i][vertice]) {
                dfs(i, depth+1);
            }
        }
    }
}

int judge()
{
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=i+1; j<=n; j++) {
            if (edge[i][j]) {
                if ((edge[0][i]+edge[0][j])%2==0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int t, m, i;
    int is_bip;
    int vertice_1,vertice_2;
    scanf("%d", &t);
    while (t>0) {
        t--;
        scanf("%d%d", &n, &m);
        memset(edge, 0, sizeof(edge));
        for (i=0; i<m; i++) {
            scanf("%d%d", &vertice_1, &vertice_2);
            edge[vertice_1][vertice_2] = 1;
            edge[vertice_2][vertice_1] = 1;
        }

        for (i=1; i<n; i++) {
            if (edge[0][i]==0) {
                dfs(i, 1);
            }
        }

        is_bip = judge();
        if (is_bip) printf("YES\n");
        else printf("NO\n");
    }
}
