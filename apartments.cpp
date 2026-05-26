#include <iostream>
#include <set>

using namespace std;

auto comp(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.second < p2.second;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int applicants[n];
    for (int i=0; i<n; i++) cin >> applicants[i];

    int apartments[m];
    for (int i=0; i<m; i++) cin >> apartments[i];
    sort(apartments, apartments + m);
    
    // Setting up the data structures
    set<int> possible_apartments[n];
    set<int> possible_applicants[m];
    set<pair<int, int>, decltype(comp)> apartment_set; // (apartment id, number of applicants) 
    set<pair<int, int>, decltype(comp)> student_set; // (student id, number of apartments) 

    for (int i=0; i<n; i++){
        auto l = lower_bound(apartments, apartments + m, applicants[i]-k);
        auto u = upper_bound(apartments, apartments + m, applicants[i]+k);
        
        for (auto it=l; it!=u; it++){
            auto index = distance(apartments, it);
            possible_apartments[i].insert(index);
            possible_applicants[index].insert(i);
        }
    }
    for (int i=0; i<m; i++) apartment_set.insert(pair<int, int>(i, possible_applicants[i].size()));
    for (int i=0; i<n; i++) student_set.insert(pair<int, int>(i, possible_apartments[i].size()));

    // Main logic
    while(apartment_set.size())
    {
        // If an apartment has no suitor, delete that from list
        auto top = apartment_set.begin();
        if (top->second == 0) apartment_set.erase(top);

        // If an student has no possible apartment, delete them from the list
        auto front = student_set.begin();
        if (top->second == 0) student_set.erase(front);

        // If an apartment has only one suitor, allot that
        else if (top->second == 1){
            int index = top->first;
            int student = *(possible_applicants[index].begin());

            // Remove that allotted student from all the other available apartments
            for (auto it=possible_apartments[student].begin(); it!=possible_apartments[student].end(); it++){
                apartment_set.erase(make_pair(*it, possible_applicants[*it].size()));
                possible_applicants[*it].erase(student);
                apartment_set.insert(make_pair(*it, possible_applicants[*it].size()));
            }
            apartment_set.erase(top);

            // Remove that apartment from all other students  -> Not possible size == 1
        }

        // If a student has only one possible apartment, allot that
        else if (front->second == 1){
            int student = front->first;
            int apartment_idx = *(possible_apartments[student].begin()); // only one element

            for (auto it=possible_applicants[apartment_idx].begin(); it!=possible_applicants[apartment_idx].end(); it++){
                student_set.erase(make_pair(*it, possible_applicants[*it].size()));
                possible_apartments[*it].erase(apartment_idx);
                student_set.insert(make_pair(*it, possible_applicants[*it].size()));
            }

            student_set.erase(front);
        }

        else {
            
        }
    }

    return 0;
}