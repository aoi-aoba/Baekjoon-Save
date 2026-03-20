// 피보나치 수의 합
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

const ll MOD = 1000000000;
typedef vector<vector<ll>> Matrix;

// if f(n) = f(n-1) + f(n-2), define g(n) as sum of f(1)~f(n)
// then g(n) = g(n-1) + g(n-2) + 1

ll A, B;
Matrix matrix = {
    {1, 1, 1},
    {1, 0, 0},
    {0, 0, 1}
};
// matrix^(n-2) * [g(2) g(1) 1]

Matrix matrixMult(Matrix x, Matrix y) {
    int R = x.size(), C = y[0].size();
    Matrix ret = Matrix(R, vector<ll>(C, 0));

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            for (int k = 0; k < y.size(); k++)
                ret[i][j] += (x[i][k] * y[k][j]) % MOD, ret[i][j] %= MOD;

    return ret;
}

// divide-and-conquer yeee
Matrix matrixPow(ll n) {
    if (n == 1) return matrix;
    
    Matrix half = matrixPow(n / 2);
    if (n % 2 == 0) return matrixMult(half, half);
    else return matrixMult(matrix, matrixMult(half, half));
}

ll psum(ll n) {
    if (n <= 2) return n;
    Matrix res = matrixPow(n - 2);
    return (2 * res[0][0] + res[0][1] + res[0][2]) % MOD;
}

int main() {
    fastio;
    cin >> A >> B;
    cout << (psum(B) - psum(A - 1) + MOD) % MOD;
}

