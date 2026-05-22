#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int n = 0;

ll total(ll* A){
    ll sum = 0;
    for (int i=0; i<n; i++){
        sum += A[i];
    }
    return sum;
}

int main(){
    cin >> n;

    ll weights[n];
    for (int i=0; i<n; i++) {
        cin >> weights[i];
    }

    // Main logic starts here
    ll sum = total(weights);
    set<ll> validSum;
    
    for (int i=0; i<n; i++){
        set<ll> current_round_sums;
        for (const auto& element : validSum){
            current_round_sums.insert(element+weights[i]);
        }
        // Base case single element
        current_round_sums.insert(weights[i]);

        for (const auto& element : current_round_sums){
            validSum.insert(element);
        } 
    }

    set<ll> array;
    for (const auto& element : validSum){
        array.insert(abs(sum - 2*element));
    }

    ll min_sum = sum;
    for (const auto& element : array){
        if (element < min_sum) min_sum=element;
    }
    cout << min_sum << endl;
    return 0;
}
