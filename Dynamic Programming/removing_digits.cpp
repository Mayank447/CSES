#include <iostream>

int max_digit(int num){
    int max_digit = 0;
    while (num > 0) {
        max_digit = std::max(max_digit, num % 10);
        num /= 10;
    }
    return max_digit;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Main logic
    // My guess we can prove the greedy logic by proving instead
    // that count(num) is a non-decreasing function.
    // Edit: Yes dp[n] = 1 + dp[n-d], where d is between 1 and 9
    
    int count = 0;
    while (n != 0){
        n -= max_digit(n);
        count++;
    }

    std::cout << count << "\n";
    return 0;
}