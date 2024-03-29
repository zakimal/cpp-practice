#include <bits/stdc++.h>
using namespace std;

#define N 4
#define N2 16
static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};
int MDT[N2][N2];
struct Puzzle {
    int f[N2], space, MD;
    int cost;
    bool operator < (const Puzzle &p) const {
        for (int i = 0; i < N2; i++) {
            if (f[i] == p.f[i]) continue;
            return f[i] < p.f[i];
        }
        return false;
    }
};
struct State {
    Puzzle puzzle;
    int estimated;
    bool operator < (const State &s) const {
        return s.estimated < estimated;
    }
};
int get_all_md(Puzzle pz) {
    int sum = 0;
    for (int i = 0; i < N2; i++) {
        if (pz.f[i] == N2) continue;
        sum += MDT[i][pz.f[i] - 1];
    }
    return sum;
}
int astar(Puzzle s) {
    priority_queue<State> PQ;
    s.MD = get_all_md(s);
    s.cost = 0;
    map<Puzzle, bool> V;
    Puzzle u, v;
    State initial;
    initial.puzzle = s;
    initial.estimated = get_all_md(s);
    PQ.push(initial);

    while (!PQ.empty()) {
        State st = PQ.top(); PQ.pop();
        u = st.puzzle;
        if (u.MD == 0) return u.cost;
        V[u] = true;
        int sx = u.space / N;
        int sy = u.space % N;
        for (int r = 0; r < 4; r++) {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if (tx < 0 || N <= tx || ty < 0 || N <= ty) continue;
            v = u;
            v.MD -= MDT[tx*N + ty][v.f[tx*N + ty] - 1];
            v.MD += MDT[sx*N + sy][v.f[tx*N + ty] - 1];
            swap(v.f[sx*N + sy], v.f[tx*N + ty]);
            v.space = tx*N + ty;
            if (!V[v]) {
                v.cost++;
                State news;
                news.puzzle = v;
                news.estimated = v.cost + v.MD;
                PQ.push(news);
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            MDT[i][j] = abs(i/N - j/N) + abs(i%N - j%N);
        }
    }
    Puzzle in;
    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }
    cout << astar(in) << endl;
    return 0;
}