#include <bits/stdc++.h>
#define MAX 51
#define X first
#define Y second
#define INF 987654321

using namespace std;

int N, M, ans = INF;
bool chicken_vis[MAX][MAX];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> comb;

void solve();
void find_min_chicken_dist(int idx);
void get_chicken_comb(int idx, int level);
int get_chicken_dist();
int get_distance(pair<int, int> x, pair<int, int> y);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            
            if(input == 1)
                house.push_back({i, j});
            else if(input == 2)
                chicken.push_back({i, j});
        }
    }
    
    // find chicken combination and answer
    get_chicken_comb(0, 0);
    cout << ans << '\n';
}

void get_chicken_comb(int idx, int level) {
    if(level == M) {
        int chicken_dist = get_chicken_dist();
        ans = min(ans, chicken_dist);
    }
    else {
        for(int i = idx; i < chicken.size(); i++) {
            pair<int, int> nxt = chicken[i];
            
            if(!chicken_vis[nxt.X][nxt.Y]) {
                chicken_vis[nxt.X][nxt.Y] = true;
                comb.push_back(nxt);
                
                // 바보같이 i가 아니라 idx + 1을 넣어서 중복된 경우의 수 만들었음
                get_chicken_comb(i, level + 1);
                
                chicken_vis[nxt.X][nxt.Y] = false;
                comb.pop_back();
            }
        }
    }
}

int get_chicken_dist() {
    int ret = 0;
    
    for(auto from : house) {
        int min_dist = INF;
        
        for(auto to : comb) {
            int dist = get_distance(from ,to);
            min_dist = min(min_dist, dist);
        }
        ret += min_dist;
    }
    return ret;
}

int get_distance(pair<int, int> x, pair<int, int> y) {
    return abs(x.X - y.X) + abs(x.Y - y.Y);
}
