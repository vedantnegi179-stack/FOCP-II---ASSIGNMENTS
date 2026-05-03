#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

int spf[MAXN + 1];  // smallest prime factor

// Precompute SPF using sieve
void compute_spf() {
    for (int i = 1; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // prime
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Count distinct prime factors
int count_distinct_primes(int n) {
    int count = 0;
    int last = -1;

    while (n > 1) {
        if (spf[n] != last) {
            count++;
            last = spf[n];
        }
        n /= spf[n];
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    compute_spf();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = count_distinct_primes(n);

        // result = 2^k
        cout << (1 << k) << '\n';
    }

    return 0;
}