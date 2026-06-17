#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    ll prefix;
    std::vector<ll> prefix_sum;

    for (int i=0; i<n; i++) {
        std::cin >> prefix;

        if (i > 0) prefix += prefix_sum[i-1];
        prefix_sum.push_back(prefix);
    }

    // Main logic
    int mod;
    std::map<int, ll> freq;

    for (int i=0; i<n; i++) {
        mod = prefix_sum[i]%n; //-1
        mod += n; // -1+4
        mod %= n; //3

        if(freq.contains(mod)) freq[mod]++;
        else freq[mod] = 1;
    }

    ll count = freq[0];
    for (int i=0; i<n; i++){
        count += freq[i] * (freq[i]-1)/2;
    }

    std::cout << count << "\n";
    return 0;
}