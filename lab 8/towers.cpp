//Program to find the maximum possible blocks in tower 1.
#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
    int test;
    cin >> test;

    while (test--) {
        solve();
    }
    return 0;
}
// Function to compute the maximum possible height of Tower 1
void solve() {
    int num;
    cin >> num;

    vector<long long> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    long long height = arr[0];

    for (int i = 1; i < num; i++) {
        if (arr[i] > height) {
            long long excess = arr[i] - height;
            height += (excess + 1) / 2;
        }
    }

    cout << height << endl;
}
