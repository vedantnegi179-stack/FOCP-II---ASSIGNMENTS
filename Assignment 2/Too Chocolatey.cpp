#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to determine the winner of the game
string solve(int N, vector<int>& A) {
    // Sort the array in descending order to simulate the greedy strategy
    sort(A.begin(), A.end(), greater<int>());
    
    long long alex_score = 0;
    long long bob_score = 0;
    bool alex_turn = true;
    
    int last_val = -1;
    int count_val = 0;
    
    for (int x : A) {
        // Track the frequency of the current chocolate quantity
        if (x == last_val) {
            count_val++;
        } else {
            last_val = x;
            count_val = 1;
        }
        
        // A quantity can only be consumed at most twice (once per player)
        if (count_val <= 2) {
            if (alex_turn) {
                alex_score += x;
            } else {
                bob_score += x;
            }
            alex_turn = !alex_turn; // Toggle turn after a valid consumption
        }
    }
    
    // Alex must consume strictly more than Bob to win
    if (alex_score > bob_score) {
        return "Alex";
    } else {
        return "Bob";
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            int N;
            cin >> N;
            vector<int> A(N);
            for (int i = 0; i < N; ++i) {
                cin >> A[i];
            }
            
            // Output the winner
            cout << solve(N, A) << "\n";
        }
    }
    return 0;
}