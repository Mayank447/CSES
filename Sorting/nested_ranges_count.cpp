#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

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

    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

bool comp(std::tuple<int, int, int> &p1, std::tuple<int, int, int> &p2){
    if (std::get<0>(p1) != std::get<0>(p2))
         return std::get<0>(p1) > std::get<0>(p2);

    return std::get<1>(p1) < std::get<1>(p2);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n;

    std::vector<std::tuple<int, int, int>> ranges;
    std::vector<int> end_points;

    for (int i=0; i<n; i++){
        std::cin >> a >> b;
        ranges.push_back(std::make_tuple(a, b, i));
        end_points.push_back(b);
    }

    std::sort(ranges.begin(), ranges.end(), comp);
    std::sort(end_points.begin(), end_points.end());

    auto it = std::unique(end_points.begin(), end_points.end());
    end_points.erase(it, end_points.end());
    int max_rank = end_points.size();

    std::vector<int> contains(n);
    std::vector<int> is_contained(n);

    // std::multiset<int> s;
    // for (int i=0; i<n; i++){
    //     auto [a, b, index] = ranges[i];
    //     auto it = s.upper_bound(b);

    //     contains[index] = std::distance(s.begin(), it);
    //     s.insert(b);
    // }

    // std::multiset<int> t;
    // for (int i=n-1; i>=0; i--){
    //     auto [a, b, index] = ranges[i];
    //     auto it = t.upper_bound(-b);
        
    //     is_contained[index] = std::distance(s.begin(), it);
    //     t.insert(-b);
    // }

    FenwickTree s(max_rank);  // mapping end points to [1, ..., n]
    for (int i=0; i<n; i++){
        auto [a, b, index] = ranges[i];
        b = std::distance(
            end_points.begin(),
            std::upper_bound(end_points.begin(), end_points.end(), b)
        );

        contains[index] = s.query(b);
        s.add(b, 1);
    }

    FenwickTree t(max_rank);
    for (int i=n-1; i>=0; i--){
        auto [a, b, index] = ranges[i];
        b = std::distance(
            end_points.begin(),
            std::upper_bound(end_points.begin(), end_points.end(), b)
        );

        is_contained[index] = t.rangeQuery(b, max_rank);
        t.add(b, 1);
    }

    for (int i=0; i<n; i++) std::cout << contains[i] << " ";
    std::cout << "\n";

    for (int i=0; i<n; i++) std::cout << is_contained[i] << " ";
    std::cout << "\n";
    return 0;
}