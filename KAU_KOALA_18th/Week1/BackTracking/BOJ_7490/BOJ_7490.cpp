#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<string> ans, picked = { "1" };
vector<string> oper = { " ", "+", "-" };

void solve();
bool is_zero();
void find_combination(int num);
void print_answer();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        ans.clear();
        find_combination(2);
        print_answer();
        cout << '\n';   // 이거 하나 때문에 " 출력 형식이 잘못되었습니다 " 계속 받음 ;;;;;;;;
    }
}

bool is_zero() {
    // ' ' 때문에 재배치
    vector<string> arr;
    for(int i = 0; i < picked.size();) {
        if(picked[i] == " ") {
            string tmp = arr.back() + picked[i + 1];
            arr.pop_back();
            arr.push_back(tmp);
            i = i + 2;
        } else {
            arr.push_back(picked[i]);
            i++;
        }
    }
    
    // 계산
    int total = stoi(arr[0]);
    for(int i = 1; i < arr.size(); i += 2) {
        if(arr[i] == "+") {
            total += (stoi(arr[i + 1]));
        } else if(arr[i] == "-") {
            total -= (stoi(arr[i + 1]));
        }
    }
    return total == 0;
}

void find_combination(int num) {
    if(num == N + 1) {
        if(is_zero()){
            string tmp;
            for(auto item : picked) tmp += item;
            ans.push_back(tmp);
        }
    }
    else {
        for(auto o : oper) {
            picked.push_back(o);
            picked.push_back(to_string(num));
            find_combination(num + 1);
            picked.pop_back();
            picked.pop_back();
            
        }
    }
}

void print_answer() {
    for(auto nxt : ans)
        cout << nxt << '\n';
}
