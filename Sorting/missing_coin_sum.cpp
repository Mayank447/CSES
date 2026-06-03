#include <iostream>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int coins[n];
    for (int i=0; i<n; i++) std::cin >> coins[i];

    // Main logic
    std::sort(coins, coins + n);

    long long int max_num = 0;
    for (int i=0; i<n; i++){
        if (coins[i] <= max_num + 1) max_num += coins[i];
        else break;
    }

    std::cout << max_num + 1 << std::endl;
    return 0;
}