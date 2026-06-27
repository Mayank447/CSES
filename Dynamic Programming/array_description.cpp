#include <iostream>
#include <vector>
#include <list>
#include <numeric>

#define MOD 1000000007
typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> array(n);
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(m+2, 0));
    for (int i=0; i<n; i++) {
        std::cin >> array[i];
        if (array[i]) dp[i][array[i]] = 1;
    }

    // Main logic
    ll count = 1;

    for (int i=0; i<n; i++){
        // Current element if non-zero within 1 range of the previous element 
        if (array[i]) {
            if (i > 0 && array[i-1] && std::abs(array[i]-array[i-1])>1){
                std::cout << 0 << "\n";
                return 0;
            }
            continue;
        }
        
        std::list<int> s;
        int j = i;

        if (j>0) s.push_back(array[j-1]);
        else {
            for (int k=1; k<=m; k++) {
                s.push_back(k);
                dp[0][k] = 1;
            }
            j++;
        }
        
        while (j<n && !array[j]){
            for (auto it=s.begin(); it!=s.end(); it++){
                int element = *it;

                dp[j][element] += dp[j-1][element];
                dp[j][element] %= MOD;

                if (element>1) {
                    dp[j][element-1] += dp[j-1][element];
                    dp[j][element-1] %= MOD;
                }
                if (element<m) {
                    dp[j][element+1] += dp[j-1][element];
                    dp[j][element+1] %= MOD;
                }
            }
            if (s.front() > 1) s.push_front(s.front()-1);
            if (s.back() < m) s.push_back(s.back()+1);
            j++;
        }

        i = j;
        if (i < n){
            ll local_count = dp[i-1][array[i]];
            local_count += dp[i-1][array[i]-1];
            local_count += dp[i-1][array[i]+1];
            local_count %= MOD;

            if (!local_count){
                std::cout << 0 << "\n";
                return 0;
            }
            count *= local_count;
            count %= MOD;
        }
    }

    if (!array[n-1]){
        count *= (std::accumulate(dp[n-1].begin(), dp[n-1].end(), 0LL) % MOD);
        count %= MOD;
    }

    std::cout << count << "\n";
    return 0;
}