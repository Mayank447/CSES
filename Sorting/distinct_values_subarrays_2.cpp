#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long ll; 

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    int i=0, j=0;
    int distinct = 0;
    std::unordered_map<int, int> freq;

    ll count=0;
    while (i<n){
        while(j<n && distinct<k) {
            freq[array[j]]++;
            if (freq[array[j++]] == 1) distinct++;
        }

        // distinct ==k
        while(j<n && freq.contains(array[j])) freq[array[j++]]++;

        count += j-i;
        freq[array[i]]--;

        if (freq[array[i]] == 0){
            freq.erase(array[i]);
            distinct--;
        }
        i++;
    }

    std::cout << count << "\n";
    return 0;
}