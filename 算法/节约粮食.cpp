#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 10;
const int MAX_M = 100;
const double INF = 1e20;
const double EPS = 1e-8;

struct Simplex {
    vector<double> b, c;
    vector<vector<double>> a;
    double z;
    int n, m;

    void initialize(int n_, int m_) {
        n = n_;
        m = m_;
        b.resize(m);
        a.resize(m);
        c.resize(n);
        for (auto& row : a)
            row.resize(n + 1), fill(row.begin(), row.end(), 0);
        fill(b.begin(), b.end(), 0);
        fill(c.begin(), c.end(), 0);
        z = 0;
    }

    void pivot(int k, int l) {
        b[l] /= a[l][k];
        for (int j = 0; j < n; j++)
            if (j != k)
                a[l][j] /= a[l][k];
        for (int i = 0; i < m; i++) {
            if (i != l && fabs(a[i][k]) > EPS) {
                b[i] -= a[i][k] * b[l];
                for (int j = 0; j < n; j++)
                    if (j != k)
                        a[i][j] -= a[i][k] * a[l][j];
                a[i][k] /= -a[l][k];
            }
        }
        z += c[k] * b[l];
        for (int j = 0; j < n; j++)
            if (j != k)
                c[j] -= c[k] * a[l][j];
        c[k] /= -a[l][k];
        a[l][k] = 1 / a[l][k];
    }

    double solve() {
        while (true) {
            int k = 0, l = 0;
            double minc = INF;
            for (int i = 0; i < n; i++)
                if (c[i] < minc)
                    minc = c[k = i];
            if (minc > -EPS)
                return z;
            double minba = INF;
            for (int i = 0; i < m; i++)
                if (a[i][k] > EPS && minba - b[i] / a[i][k] > EPS)
                    minba = b[i] / a[i][k], l = i;
            if (minba == INF)
                return INF;
            pivot(k, l);
        }
    }
};

int main() 
{
    int n, m;
    while (cin>>n>>m) {
        Simplex simplex;
        simplex.initialize(n + m, m);
        for (int i = 0; i < n; i++) {
            cin>>simplex.c[i];
            simplex.c[i] = -simplex.c[i];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin>>simplex.a[i][j];
            cin>>simplex.b[i];
            simplex.a[i][n + i] = 1;
        }
        printf("Nasa can spend %d taka.\n", static_cast<int>(ceil(-simplex.solve() * m)));
    }
    return 0;
}
