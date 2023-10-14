#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
typedef vector<int> BigBinary;

void check(BigBinary &x) {
    while (!x.empty() && x.back() == 0)
        x.pop_back();
    int cur = 0;
    for (int i = 0; i < x.size(); i++) {
        x[i] += cur;
        cur = x[i] >> 1;
        x[i] &= 1;
    }
    for (; cur; cur >>= 1)
        x.push_back(cur & 1);
}

void Print(const BigBinary &x) {
    BigBinary temp(x);
    check(temp);
    for (int i = temp.size() - 1; i >= 0; i--)
        printf("%d", temp[i]);
    if (temp.empty())
        printf("0");
    printf("\n");
}

BigBinary Add(const BigBinary &a, const BigBinary &b, int negFlag = 1) {
    BigBinary c(a);
    for (int i = 0; i < b.size(); i++)
        c[i] += b[i] * negFlag;
    return c;
}

BigBinary Minus(const BigBinary &a, const BigBinary &b) {
    return Add(a, b, -1);
}

BigBinary Mul(const BigBinary &a, const BigBinary &b) {
    BigBinary c;
    c.resize(a.size() * b.size() + 1);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}

void MulN2(BigBinary &a, int n_2) {
    int isize = a.size();
    a.resize(isize + n_2);
    for (int i = a.size() - 1, j = isize - 1; j >= 0; i--, j--)
        a[i] = a[j];
    for (int i = n_2 - 1; i >= 0; i--)
        a[i] = 0;
}

BigBinary FasterMul(const BigBinary &a, const BigBinary &b) {
    if (a.size() < 32)
        return Mul(a, b);
    int n_2 = a.size() >> 1;
    BigBinary A(a.begin() + n_2, a.end());
    BigBinary B(a.begin(), a.begin() + n_2);
    BigBinary C(b.begin() + n_2, b.end());
    BigBinary D(b.begin(), b.begin() + n_2);
    BigBinary A_C = FasterMul(A, C);
    BigBinary B_D = FasterMul(B, D);
    BigBinary ADpBC = Minus(Minus(FasterMul(Add(A, B), Add(C, D)), A_C), B_D);
    MulN2(A_C, n_2 << 1);
    MulN2(ADpBC, n_2);
    return Add(Add(A_C, ADpBC), B_D);
}

const int maxn = 1e5 + 10;
char buf[maxn];
BigBinary a, b;

int main() {
    while (scanf("%s", buf) != EOF) {
        a.clear();
        b.clear();
        for (int i = strlen(buf) - 1; i >= 0; i--)
            a.push_back(buf[i] == '1');
        scanf("%s", buf);
        for (int i = strlen(buf) - 1; i >= 0; i--)
            b.push_back(buf[i] == '1');
        if (a.size() < b.size())
            a.resize(b.size(), 0);
        else
            b.resize(a.size(), 0);
        BigBinary res = FasterMul(a, b);
        Print(res);
    }
    return 0;
}
