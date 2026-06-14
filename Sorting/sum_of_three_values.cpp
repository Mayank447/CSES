#include <iostream>
#include <algorithm>
#include <vector>

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
        int a=i+1, b=n-1;

        while(a < b){
            while (array[i].first + array[a].first + array[b].first > x) b--;

            if (a >= b) break;
            else if (array[i].first + array[a].first + array[b].first == x) {
                std::cout << array[i].second << " " << array[a].second << " " << array[b].second << "\n";
                return 0;
            }
            a++;
        }
    }

    std::cout << "IMPOSSIBLE" << "\n";
    return 0;
}