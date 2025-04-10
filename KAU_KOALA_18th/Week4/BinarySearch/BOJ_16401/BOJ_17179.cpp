#include <bits/stdc++.h>

using namespace std;

int N, M, L;
vector<int> cutting_point;
vector<int> query;

void solve();
void input();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}

void solve() {
    // Parametric Search
    for(int i = 0; i < N; i++) {
        int left = 0, right = L;
        while(left <= right) {
            int prev = 0;
            int cut = 0;
            int mid = (left + right) / 2;

            for(auto point : cutting_point) {
                if(point - prev >= mid) {
                    prev = point;
                    cut++;
                }
            }

            if(query[i] == cut && L - prev < mid) right = mid - 1;
            else if(query[i] > cut) right = mid - 1;
            else left = mid + 1;
        }
        cout << right << '\n';
    }
    
}

void input() {
    cin >> N >> M >> L;

    for(int i = 0; i < M; i++) {
        int inp; cin >> inp;
        cutting_point.push_back(inp);
    }
    for(int i = 0; i < N; i++) {
        int inp; cin >> inp;
        query.push_back(inp);
    }
}