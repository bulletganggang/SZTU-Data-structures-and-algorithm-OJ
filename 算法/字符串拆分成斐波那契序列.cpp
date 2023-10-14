#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>

using namespace std;

bool backtrack(vector<int>& list, string num, int length, int index, long long sum, int prev) {
    if (index == length) {
        return list.size() >= 3;
    }

    long long curr = 0;
    for (int i = index; i < length; i++) {
        if (i > index && num[index] == '0') {
            break;
        }

        curr = curr * 10 + num[i] - '0';
        if (curr > INT_MAX) {
            break;
        }

        if (list.size() >= 2) {
            if (curr < sum) {
                continue;
            }
            else if (curr > sum) {
                break;
            }
        }

        list.push_back(curr);
        if (backtrack(list, num, length, i + 1, prev + curr, curr)) {
            return true;
        }
        list.pop_back();
    }

    return false;
}

void print(vector<int> v) {
    if (v.size() == 0) {
        cout << "None" << endl;
        return;
    }

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    string s;
    while (cin >> s) {
        vector<int> list;
        backtrack(list, s, s.length(), 0, 0, 0);
        print(list);
    }

    return 0;
}
