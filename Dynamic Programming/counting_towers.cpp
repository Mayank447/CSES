#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007
typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    std::vector<int> queries(t);
    for (int i=0; i<t; i++) std::cin >> queries[i];

    // Main logic
    // For a one width colum of height n, the number of ways to do it is 2^n-1.
    // Easy to prove by induction, make the recently added block (in induction step)
    // go from 1 combined, 2 combined, ..., n combined

    int n = *std::max_element(queries.begin(), queries.end());

    // Not horizontal bars
    // The number of ways to do it = [h_w1(n)]^2 = 2^(2n-2)

    // This method does not generalize for width 2, so instead
    // we use the recursion, there are 2 cases, unified or split for the
    // top row, total ways = split[n] + unified[n]
    std::vector<ll> split(n+1, 0);
    std::vector<ll> unified(n+1, 0);
    
    split[1] = 1;
    unified[1] = 1;

    for (int i=2; i<=n; i++){
        unified[i] = 2*unified[i-1] + split[i-1];
        split[i] = unified[i-1] + 4*split[i-1];
        // 4 cases are both split, left joined, right joined, both vertically joined
    
        unified[i] %= MOD;
        split[i] %= MOD;
    }

    for (int i=0; i<t; i++){
        std::cout << (split[queries[i]] + unified[queries[i]])%MOD << "\n";
    }
    return 0;
}