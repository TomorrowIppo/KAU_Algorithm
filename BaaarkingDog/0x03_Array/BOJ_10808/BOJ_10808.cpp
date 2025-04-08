#include <bits/stdc++.h>

using namespace std;

int freq[26];

// ASCII 코드를 활용하면 freq[c - 'a'] 방식으로 입력한 문자를 자동으로 해당 위치에 배치할 수 있다.
// a가 입력되면 당연히 0이 되므로 첫번째 위치에 배치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for(auto c : s)
        freq[c - 'a']++;

    for(int i = 0; i < 26; i++)
        cout << freq[i] << ' ';

    return 0;
}

