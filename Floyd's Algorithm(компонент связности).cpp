// Алгоритм Флойда

#include <iostream>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
 
const int SIZE = 1e3 + 10;
int adj[SIZE][SIZE];
bool usd[SIZE];
 
int n,m,f,s; // n - вершины, m - ребра

void input() {
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;++i) {
        scanf("%d %d", &f, &s);
        adj[f][s] = adj[s][f] = 1;
    }
}

int floyd() {
    for (int k=1;k<=n;++k){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                if (adj[i][k] + adj[k][j] == 2)         
                    adj[i][j] = 1;
            }
        }
    }
    int kol = 0;
    for (int i=1;i<=n;++i) {
        if (!usd[i]) {
            ++kol;
            usd[i] = true;
            for (int j=1;j<=n;++j) {
                if (adj[i][j] && !usd[j])
                    usd[j] = true;
            }
        }
    }
    return kol;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    cout<<floyd();
    return 0;
}