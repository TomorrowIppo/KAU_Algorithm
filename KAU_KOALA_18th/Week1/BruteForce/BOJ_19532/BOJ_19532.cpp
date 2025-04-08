/*
 
 Cramer's Rule을 이용하여 접근하였습니다. O(1)
 
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int y;
    int z;
} Matrix;

void solve() {
    Matrix matrix[2];
    cin >> matrix[0].x >> matrix[0].y >> matrix[0].z >> matrix[1].x >> matrix[1].y >> matrix[1].z;
    
    int det = (matrix[0].x * matrix[1].y) - (matrix[0].y * matrix[1].x);
    int det1 = (matrix[0].z * matrix[1].y) - (matrix[0].y * matrix[1].z);
    int det2 = (matrix[0].x * matrix[1].z) - (matrix[0].z * matrix[1].x);
    
    int x = det1 / det;
    int y = det2 / det;
    
    cout << x << ' ' << y << '\n';
}

void test() {
    int t = 2;
    while(t--) {
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //test();
    solve();
    
    return 0;
}
