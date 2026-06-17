#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    std::vector<ll> prefix_sum(n);
    std::vector<std::pair<ll, int>> sorted;
    std::map<ll, int> freq;

    for (int i=0; i<n; i++){
        if (i > 0) prefix_sum[i] = prefix_sum[i-1] + array[i];
        else prefix_sum[0] = array[0];

        if (freq.contains(prefix_sum[i])) freq[prefix_sum[i]]++;
        else freq[prefix_sum[i]] = 1;

        sorted.push_back(std::make_pair(prefix_sum[i], i));
    }

    std::sort(sorted.begin(), sorted.end());

    ll count = 0;
    int i=0, j=0;

    while (i < n){
        ll value = x + sorted[i].first;
        if (sorted[i].first == x) count++;

        while (j<n && sorted[j].first < value) j++;

        if (j<n && sorted[j].first == value){
            int size = freq[sorted[j].first];
            count += std::distance(
                std::lower_bound(
                    std::next(sorted.begin(), j),
                    std::next(sorted.begin(), j+size),
                    std::make_pair(value, sorted[i].second+1)
                ),
                std::next(sorted.begin(), j+size)
            );
        }
        i++;
    }
    
    std::cout << count << "\n";
    return 0;
}