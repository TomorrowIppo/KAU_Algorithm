#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

constexpr bool DEBUG = false;

constexpr int row = 12;
constexpr int col = 6;

char board[row][col];
queue<pair<int, int>> boom;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[row][col];
bool flag;
int pop_cnt;

void input();
void solve();

void reset_vis();   
void puyo_check(pair<int, int> pos);
void puyo_pop();  
void puyo_down();
void print_board();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}

void input() {
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> board[i][j];
}

void solve() {
    while(true) {
        reset_vis();
        flag = false;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] != '.' && !vis[i][j]) {
                    puyo_check({i, j});
                }
            }
        }
        if(!flag) break;

        if(DEBUG) print_board();
        puyo_down();
        pop_cnt++;
        if(DEBUG) {
            cout << "puyo_down startup\n";
            print_board();
        }
    }
    cout << pop_cnt;
}

void reset_vis()
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            vis[i][j] = false;
}

void puyo_check(pair<int, int> pos)
{
    queue<pair<int, int>> q;
    char c = board[pos.X][pos.Y];
    q.push(pos);
    boom.push(pos);
    vis[pos.X][pos.Y] = true;

    int cnt = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(vis[nx][ny] || board[nx][ny] != c) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
            boom.push({nx, ny});
            cnt++;
        }
    }

    if(cnt >= 4) {
        puyo_pop();
        flag = true;
    } else while(!boom.empty()) boom.pop();
}

void puyo_pop() {
    while(!boom.empty()) {
        auto cur = boom.front(); boom.pop();
        board[cur.X][cur.Y] = '.';
    }
}

void puyo_down()
{
    for(int i = row - 2; i >= 0; i--) {
        for(int j = 0; j < col; j++) {
            if(board[i][j] == '.') continue;

            int cur_row = i;
            while(true) {
                if(cur_row == row - 1 || board[cur_row + 1][j] != '.') break;

                board[cur_row + 1][j] = board[cur_row][j];
                board[cur_row][j] = '.';
                cur_row++;
            }
        }
    }
}

void print_board() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}