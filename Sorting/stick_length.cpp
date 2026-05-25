#include <iostream>
#include <algorithm>
#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int array[n];
    for (int i=0; i<n; i++) std::cin >> array[i];
    std::sort(array, array + n);

    int median;
    if (n%2 == 0) median = (array[n/2 - 1] + array[n/2])/2;
    else median = array[(n+1)/2 - 1]; // -1 since its 0 indexed

    ll residual_sum = 0;
    for (int i=0; i<n; i++) residual_sum += abs(median - array[i]);
    std::cout << residual_sum << std::endl;

    return 0;
}