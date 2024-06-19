#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int collatz_cycle_length(int n, map<int, int>& memo) {
    if (n == 1) return 1;
    if (memo.find(n) != memo.end()) return memo[n];
    //偶數
    if (n % 2 == 0) {
        memo[n] = 1 + collatz_cycle_length(n / 2, memo);
    } else {
        memo[n] = 1 + collatz_cycle_length(3 * n + 1, memo);
    }
    return memo[n];
}

int main() {
    int i, j;
    map<int, int> memo;
    
    while (cin >> i >> j) {
        int start = min(i, j);
        int end = max(i, j);
        int max_cycle_length = 0;
        
        for (int n = start; n <= end; ++n) {
            int cycle_length = collatz_cycle_length(n, memo);
            if (cycle_length > max_cycle_length) {
                max_cycle_length = cycle_length;
            }
        }
        
        cout << i << " " << j << " " << max_cycle_length << endl;
    }
    
    return 0;
}
