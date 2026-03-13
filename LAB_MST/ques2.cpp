#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int val = 0, val2 = 0;
    for (auto x : nums) {
        val = (val ^ x) & ~val2;
        val2 = (val2 ^ x) & ~val;
    }
    cout << val;
}
