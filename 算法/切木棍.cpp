#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() 
{
    long long n,k;
    cin >> n >> k;
    vector<double> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    double left = 0.0, right = *max_element(sticks.begin(), sticks.end());
    while (left + 0.000001 < right) {
        double mid = (left + right) / 2.0;

        int cuts = 0;
        for (int i = 0; i < n; i++) {
            cuts += ceil(sticks[i] / mid) - 1;
        }

        if (cuts > k) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << (long long)(ceil(right)) << endl;
    system("pause");
    return 0;
}
