#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

#define MIN_SUM -1000000000000000

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    std::vector<ll> prefix_sum(n);

    prefix_sum[0] = array[0];
    for (int i=1; i<n; i++)
        prefix_sum[i] = prefix_sum[i-1] + array[i];

    std::multiset<ll> s;
    for (int i=a-1; i<b; i++) s.insert(prefix_sum[i]);
    
    ll max_diff = MIN_SUM;
    for (int i=0; i<=n-a; i++)
    {
        ll diff = *std::prev(s.end());
        if (i > 0)
            diff -= prefix_sum[i-1];
        
        if (diff > max_diff)
            max_diff = diff;

        if (i+b < n)
            s.insert(prefix_sum[i+b]);

        s.erase(s.find(prefix_sum[i+a-1]));
    }

    std::cout << max_diff << "\n";
    return 0;
}