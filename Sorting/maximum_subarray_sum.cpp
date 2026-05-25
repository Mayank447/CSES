#include <iostream>
#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int array[n];
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    int lptr, rptr = 0;
    ll sum = 0;
    ll max_sum = -10000000000000;

    while (rptr < n){
        sum += array[rptr++];
        if (sum > max_sum) max_sum = sum;

        if (sum < 0) {
            lptr = rptr;
            sum = 0;
        }
    }

    std::cout << max_sum << std::endl; 
    return 0;
}