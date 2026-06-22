#include <iostream>
#include <vector>

class FenwickTree {
private:
    int n;
    std::vector<int> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    int query(int idx){
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx)) {
            // idx & (-idx) fetches the lowest 1 bit and we recursively subtract that
            // 1011 -> 1010 -> 1000 -> 0
            sum += bit[idx];
        }
        return sum;
    }

    void add(int idx, int x) {
        for (; idx <= n; idx += idx & (-idx)) {
            // Update all the zeros above the first 1 bit take
            // e.g. 01011 -> 01100 -> 10000
            bit[idx] += x;
        }
    }

    // Binary lifting
    // To find the first index whose prefix sum meets a target value in O(log(n))
    int find_by_rank(int prefix_sum) {
        int idx = 0;
        for (int i = 1 << 18; i > 0; i >>= 1) {
            if (idx + i <= n && bit[idx + i] < prefix_sum) {
                idx += i;
                prefix_sum -= bit[idx];
            }
        }
        return idx + 1;
    }

    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    // Main logic
    FenwickTree f(n);
    for (int i=1; i<=n; i++){
        f.add(i, 1);
    }
    
    int curr_index = 0;
    for (int m=n; m>0; m--)
    {
        curr_index = (curr_index + k)%m;
        int actual_idx = f.find_by_rank(curr_index + 1);
        
        std::cout << actual_idx << " ";
        f.add(actual_idx, -1);
    }
    std::cout << "\n";
    return 0;
}