#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int dp[11][11][11][11];

/*
 * luogo - P1004 - NOIP 2000 方格取数
 * Type : DP
 */

void run() {
    int a, b, c, N;
    cin >> N;
    vector<vector<int> > vvi = vector<vector<int> >(N, vector<int>(N, 0));
    while (cin >> a >> b >> c, a || b ||c)
        vvi[a - 1][b - 1] = c;
    for (int x1 = 1; x1 <= N; ++x1)
    for (int y1 = 1; y1 <= N; ++y1)
    for (int x2 = 1; x2 <= N; ++x2)
    for (int y2 = 1; y2 <= N; ++y2) {
        int tmp1 = max(dp[x1 - 1][y1][x2 - 1][y2], dp[x1 - 1][y1][x2][y2 - 1]);
        int tmp2 = max(dp[x1][y1 - 1][x2 - 1][y2], dp[x1][y1 - 1][x2][y2 - 1]);
        if (x1 == x2 && y1 == y2)
            dp[x1][y1][x2][y2] = max(tmp1, tmp2) + vvi[x1 - 1][y1 - 1];
        else
            dp[x1][y1][x2][y2] = max(tmp1, tmp2) + vvi[x1 - 1][y1 - 1] + vvi[x2 - 1][y2 - 1];
    }
    cout << dp[N][N][N][N] << endl;
}

int main() {
    run();
    return 0;
}
