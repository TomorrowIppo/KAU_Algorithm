#include <bits/stdc++.h>

using namespace std;

int r, c, k;
size_t R_size, C_size;
vector<vector<int>> arr(100, vector<int>(100, 0));

bool comp(const vector<int>& a, const vector<int>& b) {
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
void solve();
void R_calc();
void C_calc();
void print_vec();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

void solve() {
    // input & init
    cin >> r >> c >> k;
    R_size = 3; C_size = 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];

    // solving
    int time = 0;
    while(time <= 100) {
        if(arr[r - 1][c - 1] == k) { cout << time << '\n'; return ; }
        if(R_size >= C_size) R_calc();
        else C_calc();
        //print_vec();
        time++;
    }
    cout << -1 << '\n';
}

void R_calc() {
    C_size = 0;
    for(auto& row : arr) {
        // Map을 이용하여 중복 개수 확인
        unordered_map<int, int> countMap;
        for(auto& item : row)
            if(item != 0) countMap[item]++;
        
        vector<vector<int>> tmp_row;
        for(const auto& pair : countMap) {
            vector<int> tmp = { pair.first, pair.second };
            tmp_row.push_back(tmp);
        }
        sort(tmp_row.begin(), tmp_row.end(), comp);

        // pair 묶음을 flat하게 만들기
        vector<int> flat;
        for(const auto& pair : tmp_row)
            for(auto item : pair)
                flat.push_back(item);
        
        // 빈 부분 0으로 채우기
        size_t size = (flat.size() > 100) ? 100 : flat.size();
        C_size = max(C_size, size); // flat_row 중 가장 긴 사이즈 찾기
        
        for(size_t i = 0; i < 100; i++) {
            if(i >= size) row[i] = 0;
            else row[i] = flat[i];
        }
    }
}

void C_calc() {
    R_size = 0;
    for(size_t i = 0; i < arr[0].size(); i++) {
        // Map을 이용하여 중복 개수 확인
        unordered_map<int, int> countMap;
        for(size_t j = 0; j < arr.size(); j++)
            if(arr[j][i] != 0) countMap[arr[j][i]]++;
        
        vector<vector<int>> tmp_col;
        for(const auto& pair : countMap) {
            vector<int> tmp = { pair.first, pair.second };
            tmp_col.push_back(tmp);
        }
        sort(tmp_col.begin(), tmp_col.end(), comp);

        // pair 묶음을 flat하게 만들기
        vector<int> flat;
        for(const auto& pair : tmp_col)
            for(auto item : pair)
                flat.push_back(item);
        
        // 빈 부분 0으로 채우기
        size_t size = (flat.size() > 100) ? 100 : flat.size();
        R_size = max(R_size, size); // flat_row 중 가장 긴 사이즈 찾기
        
        for(size_t j = 0; j < 100; j++) {
            if(j >= size) arr[j][i] = 0;
            else arr[j][i] = flat[j];
        }
    }
}

void print_vec() {
    cout << '\n';
    for(size_t i = 0; i < R_size; i++) {
        for(size_t j = 0; j < C_size; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}
