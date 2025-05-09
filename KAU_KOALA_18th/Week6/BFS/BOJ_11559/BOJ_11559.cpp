#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

char board[12][6];
queue<pair<int, int>> boom;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[12][6];

void input();
void solve();

void reset_vis();   
void puyo_check(pair<int, int> pos);
void puyo_pop();    // complete
void puyo_down();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}

void input() {
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 6; j++)
            cin >> board[i][j];
}

void solve() {
    while(true) {
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(board[i][j] != '.' && !vis[i][j]) {
                    boom.push({i, j});
                    puyo_check({i, j});
                }
            }
        }
    }
    
    puyo_down();
}

void puyo_check(pair<int, int> pos) {
    queue<pair<int, int>> q;
    q.push(pos);
    int cnt = 0;

    while(!q.empty()) {
        
        for(int dir = 0; dir < 4; dir++) {
            
        }
    }

    if(cnt >= 4) puyo_pop();
}

void puyo_pop() {
    while(!boom.empty()) {
        auto cur = boom.front(); boom.pop();
        board[cur.X][cur.Y] = '.';
    }
}

void puyo_down()
{
}
