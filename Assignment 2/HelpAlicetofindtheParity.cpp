#include <bits/stdc++.h>
using namespace std;

// function to compute XOR from 0 to n
int xor_upto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R;
    cin >> L >> R;

    int X = xor_upto(R) ^ xor_upto(L - 1);

    if (X % 2 == 0)
        cout << "even\n";
    else
        cout << "odd\n";

    return 0;
}