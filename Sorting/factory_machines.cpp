#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int 

ll produce(std::vector<std::pair<int, int>> &v, ll t){
    ll count = 0;
    for (auto it = v.begin(); it != v.end(); it++){
        count += ((t/(*it).first)) * ((*it).second);
    }
    return count;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, T;
    std::cin >> n >> T;

    std::vector<int> time(n);
    for (int i=0; i<n; i++) std::cin >> time[i];

    // Main logic
    std::sort(time.begin(), time.end());
    std::vector<std::pair<int, int>> sorted_count;

    int i=0, j=0;
    while (i < n) {
        while (j < n && time[i] == time[j]) j++;

        // time taken, repeat count
        sorted_count.push_back(std::make_pair(time[i], j - i));
        i = j;
    }

    ll l = 0, r = sorted_count[0].first * (ll)T;
    while (l < r){
        ll m = (l+r)/2;
        ll output = produce(sorted_count, (l+r)/2);

        if (output >= T) r = m;
        else l = m + 1;
    }

    std::cout << l << "\n";
    return 0;
}