/*
get_clocknum()을 통해 시계수를 구한 후, 4중 반복문
clocknum은 러프하게 arr[0 ~ 3]에서 각각 시작하는 숫자들 중 최소를 리턴하도록 했음
1112와 1121의 경우 1121의 clocknum연산 결과가 1112가 나오므로 해당 연산 결과를
vis 배열로 방문여부를 따져 중복을 걸렀다.
 */

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<int> ls;
bool vis[10000];

void solve();
int get_clockNum(vector<int> arr);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    for(int i = 0; i < 4; i++) {
        int inp;
        cin >> inp;
        ls.push_back(inp);
    }
    int end_clocknum = get_clockNum(ls);
    
    vector<int> arr;
    vector<int> tmp;
    for(int i = 1; i <= 9; i++) {
        arr.push_back(i);
        for(int j = 1; j <= 9; j++) {
            arr.push_back(j);
            for(int k = 1; k <= 9; k++) {
                arr.push_back(k);
                for(int h = 1; h <= 9; h++) {
                    arr.push_back(h);
                    int c_num = get_clockNum(arr);
                    if(c_num == end_clocknum) {
                        cout << cnt + 1 << '\n';
                        //for(auto item : tmp) cout << item << ' ';
                        return ;
                    }
                    
                    if(!vis[c_num]) { vis[c_num] = true; cnt++; tmp.push_back(c_num); }
                    
                    arr.pop_back();
                }
                arr.pop_back();
            }
            arr.pop_back();
        }
        arr.pop_back();
    }
}

int get_clockNum(vector<int> arr) {
    int ret = 10000;
    for(int i = 0; i < arr.size(); i++) {
        int idx = i;
        int tmp = 0;
        for(int j = 3; j >= 0; j--) {
            tmp += arr[idx] * pow(10, j);
            
            if(idx == arr.size() - 1) idx = 0;
            else idx++;
        }
        ret = min(ret, tmp);
    }
    
    return ret;
}

