#include <bits/stdc++.h>
#define W first
#define V second

using namespace std;

constexpr int MAX = 50001;
constexpr int INF = 987654321;

int V, E, st;
vector<pair<int, int>> graph[MAX];  // { Weight, Value }
int dist[MAX];

void input();
void solve();

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}

void input() 
{
    // input & init dist
    cin >> V >> E;
    st = 1;
    fill(dist, dist + V + 1, INF);
    
    while(E--) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
}

void solve()
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(dist[cur.V] != cur.W) continue;

        for(auto nxt : graph[cur.V])
        {
            if(dist[nxt.V] <= dist[cur.V] + nxt.W) continue;

            dist[nxt.V] = dist[cur.V] + nxt.W;
            pq.push({dist[nxt.V], nxt.V});
        }
    }

    // for(int i = 1; i <= V; i++)
    // {
    //     if(dist[i] == INF) continue;
    //     else cout << i << " : " << dist[i] << '\n';
    // }
    cout << dist[V] << '\n';
}