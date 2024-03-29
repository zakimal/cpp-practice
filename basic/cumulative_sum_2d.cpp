#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> s(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
        }
    }

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] +s[x1][y1] << endl;
    }
    return 0;
}