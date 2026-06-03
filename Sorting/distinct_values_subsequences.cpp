#include <iostream>
#include <vector>
#include <map>
#include <set>

#define MOD 1000000007
#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i=0; i<n; i++) std::cin >> x[i];

    // Main logic
    std::map<int, int> frequency;
    std::set<int> collected;

    for (int i=0; i<n; i++){
        collected.insert(x[i]);
        if (frequency.count(x[i])) frequency[x[i]]++;
        else frequency[x[i]] = 1; 
    }

    ll subsequences = 1;
    for (auto it = collected.begin(); it != collected.end(); it++){
        subsequences *= frequency[*it] + 1;
        subsequences %= MOD;
    }

    std::cout << subsequences - 1 << "\n";
    return 0;
}