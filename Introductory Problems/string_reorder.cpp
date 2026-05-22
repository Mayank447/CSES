#include <iostream>
#include <string>
using namespace std;

int max_element(int* A){
    int max_id = -1, max_element=-1;
    for (int i=0; i<26; i++){
        if(A[i] > max_element){
            max_element = A[i];
            max_id = i;
        }
    }
    return max_id;
}

int total (int* A){
    int sum = 0;
    for (int i=0; i<26; i++){
        sum += A[i];
    }
    return sum;
}

bool possible(int* A){
    int max_id = max_element(A);
    int sum = total(A);

    // When adding last character
    if (sum == 0) return true;

    // Odd sum
    else if ((sum%2==1) && ((sum+1)/2 >= A[max_id])) return true;
    
    // Even sum
    else if ((sum%2==0) && (sum/2 >= A[max_id])) return true;

    return false;
}

int lowest_lexographically(int* A, int start){
    for (int i=start; i<26; i++){
        if (A[i] > 0) return i;
    }
    return -1;
}

int main(){
    string input_string;
    cin >> input_string;

    int n = input_string.length();
    int freq[26] = {0};
    for (int i=0; i<n; i++){
        freq[input_string[i]-'A']++;
    }

    // Not possible case
    if (!possible(freq)){
        cout << -1 << endl;
        return 0;
    }

    string output_string(n, '0');
    int l=-1, c=0;

    while(l<n-1) {
        int start = 0;
        while(true){
            c = lowest_lexographically(freq, start);
            freq[c] = freq[c] - 1;

            if (l==-1 && possible(freq)) break;
            else if (possible(freq) && (output_string[l]-'A' != c)){
                break;
            }
            freq[c] = freq[c] + 1;
            start = c+1;
        }
        
        output_string[++l] = 'A'+c;
    }
    
    cout << output_string << endl;
    return 0;
}