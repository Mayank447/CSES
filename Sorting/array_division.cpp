#include <iostream>
#include <vector>

typedef long long ll;

bool isValid(std::vector<int>& array, int k, ll max_sum){
    int subarrays = 1;
    ll current_sum = 0;

    for (int num: array){
        if (num > max_sum) return false;

        if (current_sum + num > max_sum) {
            subarrays++;
            current_sum = num;
        }
        else current_sum += num;
    }

    return subarrays <= k;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k; 

    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    ll sum=0, max_element=0;
    for (int i=0; i<n; i++) {
        sum += array[i];
        if (array[i] > max_element) max_element = array[i]; 
    }

    ll l=max_element, r=sum;
    while (l<r){
        ll mid = (l+r)/2;

        if (isValid(array, k, mid)) r=mid;
        else l = mid+1;
    }

    std::cout << l << "\n"; 
    return 0;
}