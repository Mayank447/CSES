#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> books(n);
    for (int i=0; i<n; i++) std::cin >> books[i];

    // Main logic
    std::vector<std::pair<int, int>> sorted_count;
    std::sort(books.begin(), books.end());

    int i=0, j=0;
    while (i < n) {
        while (j < n && books[i] == books[j]) j++;

        // book reading time, repeat count
        sorted_count.push_back(std::make_pair(books[i], j - i));
        i = j;
    }

    i = -1;
    j = sorted_count.size();
    ll left = 0;
    ll right = 0;

    // One book time (may be multiple count)
    if (j == 1){
        int count = 2;
        if (sorted_count[0].second != 1)
            count = sorted_count[0].second;

        std::cout << sorted_count[0].first * count << std::endl;
        return 0;
    }

    bool left_moved = false;
    while (i != j - 1){
        if (left < right){
            i += 1;
            left += sorted_count[i].first * sorted_count[i].second;
            left_moved = true;
        }

        else {
            j -= 1;
            right += sorted_count[j].first * sorted_count[j].second;
            left_moved = false;
        }
    }

    // This is obvious once you write a few test cases
    ll time = left + right;
    if (left_moved && left < right && sorted_count[j].second == 1){
        time = 2 * right;
    }
    else if (!left_moved && left > right && sorted_count[i].second == 1){
        time = 2 * left;
    }

    // std::cout << left << " " << right << "\n";
    std::cout << time << "\n";
    return 0;
}