/*
 
 Filter의 크기는 3x3 고정이므로 1x9로 표현 후 sort했을 때 index기준 [4] 위치가 중앙값 고정임은 자명하다.
 RxV 행렬이 주어질 때, 실행하는 필터 횟수는 (R-2)x(V-2)이며, 필터링 과정은 O(1)로 볼 수 있으므로
 시간복잡도는 O(RV) (3 <= R <= 40, 3 <= V <= 40)이다.
 
 T를 통해 비교, Matrix 입력하는 것 또한 O(RV)이기에, Brute-Force를 사용해도 시간 제한 조건을 충족할 수 있습니다.
 
 */

#include <bits/stdc++.h>
#define R_MAX 40
#define V_MAX 40

using namespace std;

int matrix[R_MAX][V_MAX];
vector<int> filtered_matrix;
int T;

void solve();
void filter(int r, int v);
int count(int t);
void test();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //test();
    solve();
    
    return 0;
}

void solve() {
    // input
    int R, V;
    cin >> R >> V;
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < V; j++)
            cin >> matrix[i][j];
    
    int T;
    cin >> T;
    
    // filter
    for(int i = 0; i < R - 2; i++)
        for(int j = 0; j < V - 2; j++)
            filter(i, j);
    
    // result
    int res = count(T);
    cout << res << '\n';
}

void filter(int r, int v) {
    vector<int> tmp;
    
    for(int i = r; i <= r + 2; i++)
        for(int j = v; j <= v + 2; j++)
            tmp.push_back(matrix[i][j]);
    
    sort(tmp.begin(), tmp.end());
    filtered_matrix.push_back(tmp[4]);
}

int count(int t) {
    int ret = 0;
    
    for(auto e : filtered_matrix) {
        //cout << e << ' ';
        
        if(e >= t) ret++;
    }
    //cout << '\n';
    
    return ret;
}

void test() {
    int t = 2;
    
    while(t--) {
        filtered_matrix.clear();
        solve();
    }
}
