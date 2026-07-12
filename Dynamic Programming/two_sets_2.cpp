#include <iostream>
#include <vector>
#define MOD 1000000007

typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Main logic
    if ((n*(n+1)/2) % 2 == 1){
        std::cout << 0 << "\n";
        return 0;
    }

    int upper_limit = n*(n+1)/4;
    std::vector<ll> knapsack(upper_limit + 1, 0);
    knapsack[0] = 1;

    // Not including n forces set with n to be the other one.
    // Other we can divide by 2.
    for (int i=1; i<n; i++){
        for (int j=upper_limit; j>=0; j--){
            if (knapsack[j] && j+i<=upper_limit) {
                knapsack[i+j] += knapsack[j];
                knapsack[i+j] %= MOD;
            }
        }
    }

    std::cout << knapsack[upper_limit] << "\n";
    return 0;
}