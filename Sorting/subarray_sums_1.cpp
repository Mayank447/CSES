#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    ll sum = 0;
    int i=0, j=0;
    int count = 0;

    while(i < n){
        while (j < n && sum < x) sum += array[j++];

        if(sum == x) count++;
        sum -= array[i++];
    }

    std::cout << count << "\n";
    return 0;
}