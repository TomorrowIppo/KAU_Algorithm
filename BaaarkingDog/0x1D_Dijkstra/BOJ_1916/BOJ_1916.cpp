#include <bits/stdc++.h>
#define W first
#define V second

using namespace std;

constexpr int MAX = 1001;
constexpr int INF = 987654321;

int V, E, st, en;
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
    fill(dist, dist + V + 1, INF);
    
    while(E--) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    cin >> st >> en;
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

    cout << dist[en] << '\n';
}