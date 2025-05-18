#include <bits/stdc++.h>
#define W first
#define V second
#define ENDL '\n'

using namespace std;

constexpr int MAX = 201;
constexpr int INF = 987654321;

int V, E;
vector<pair<int, int>> graph[MAX];  // { Weight, Value }
int dist[MAX];
int pre[MAX];

void input();
void solve();
void dijkstra(int st);
int find(int st, int en);

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
    cin >> V >> E;
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
    for(int st = 1; st <= V; st++)
    {
        dijkstra(st);
        for(int en = 1; en <= V; en++)
        {
            if(st == en) cout << "- ";
            else cout << find(st, en) << ' ';
        }
        cout << ENDL;
    }
}

void dijkstra(int st)
{
    fill(dist, dist + V + 1, INF);
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
            pre[nxt.V] = cur.V;
            pq.push({dist[nxt.V], nxt.V});
        }
    }
}   

int find(int st, int en)
{
    while(true)
    {
        if(pre[en] == st) return en;
        en = pre[en];
    }
}