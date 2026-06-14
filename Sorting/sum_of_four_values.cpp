#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<std::pair<int, int>> array(n);
    for (int i=0; i<n; i++) {
        std::cin >> array[i].first;
        array[i].second = i+1;
    }

    // Main logic
    std::sort(array.begin(), array.end());

    for (int i=0; i<n; i++){
        if ((ll)array[i].first + array[i+1].first + array[i+2].first + array[i+3].first > x)
            break;
 
        if ((ll)array[i].first + array[n-3].first + array[n-2].first + array[n-1].first < x)
            continue;
        
        auto upper = std::upper_bound(array.begin(), array.end(), std::make_pair(x - array[i].first, 0));

        int l = n;
        if (upper != array.end()) l = std::distance(array.begin(), upper);
        if (l <= i) break;

        for (int j=l-1; j>i; j--){
            int a=i+1, b=j-1;

            while(a < b){
                ll sum = (ll)array[i].first + array[j].first + array[a].first + array[b].first;

                if(sum == x) {
                    std::cout << array[i].second << " "<< array[j].second << " " << array[a].second << " " << array[b].second << "\n";
                    return 0;
                }
                else if (sum > x) b--;
                else a++;
            }
        }
    }

    std::cout << "IMPOSSIBLE" << "\n";
    return 0;
}