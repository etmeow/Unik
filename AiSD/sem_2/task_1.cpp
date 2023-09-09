#include <iostream>
#include <vector>
#include "fstream"

using namespace std;

int bin_search(const vector<int> &a, int x, int l, int r) {

    if (l > r) return 0;

    else if (l == r) return a[l] == x ? 1 : 0;
    
    else {

        int mid = (l + r) / 2;

        if (a[mid] == x) {

            return bin_search(a, x, l, mid - 1) + bin_search(a, x, mid + 1, r) + 1;
        }

        else if (a[mid] > x) {

            return bin_search(a, x, l, mid - 1);
        }

        else {

            return bin_search(a, x, mid + 1, r);
        }

    }    
}

int linear_search(const vector<int> &a, int x) {

    int n = a.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {

        if (a[i] == x) cnt += 1;
    }

    return cnt;
}

int main() {

    ifstream file;
    vector<int> a;
    int tmp, x;

    file.open("data.txt");


    while (!file.eof()) {

        file >> tmp;
        a.push_back(tmp);
    }
    

    cout << "Enter x: ";
    cin >> x;

    cout << "linear search: " << linear_search(a, x) << endl;
    cout << "bin search: " << bin_search(a, x, 0, a.size() - 1) << endl;
    


    return 0;
}