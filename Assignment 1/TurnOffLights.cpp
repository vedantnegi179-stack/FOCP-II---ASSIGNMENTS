#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string bulbs;
    cin >> bulbs;
    
    // Function to count operations needed for a given k
    // Returns number of operations needed, or n+1 if impossible
    auto check = [&](int k) -> int {
        // Make a copy to simulate
        string temp = bulbs;
        int ops = 0;
        
        for(int i = 0; i < n; i++){
            if(temp[i] == '1'){
                // Must perform operation starting at i
                ops++;
                if(ops > m) return m + 1; // Early exit
                
                // Turn off bulbs from i to i+k-1
                for(int j = i; j < min(n, i + k); j++){
                    temp[j] = '0';
                }
            }
        }
        return ops;
    };
    
    // Binary search on k (minimum k from 1 to n)
    int lo = 1, hi = n, ans = n;
    
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        
        if(check(mid) <= m){
            ans = mid;    // mid works, try smaller
            hi = mid - 1;
        } else {
            lo = mid + 1; // mid doesn't work, try larger
        }
    }
    
    cout << ans << endl;
    
    return 0;
}