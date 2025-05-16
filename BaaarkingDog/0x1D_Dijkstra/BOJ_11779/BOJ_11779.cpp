#include <bits/stdc++.h>
#define ENDL '\n'
#define W first
#define V second

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX = 1001;

int N, M, st, en;
vector<pair<int, int>> graph[MAX];  // Weight, Vertex
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
    cin >> N >> M;
    fill(dist, dist + N + 1, INF);

    while(M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    cin >> st >> en;

}

void solve()
{
    // 최소비용 구하기 (역추적 기능 제외)
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

    for(int i = 1; i <= N; i++)
    {
        cout << "Vertex : " << i << ", min_dist : ";

        if(dist[i] == INF) cout << "INF" << ENDL;
        else cout << dist[i] << ENDL;
    }
}