#include <iostream>
#include <vector>
#include "fstream"

using namespace std;


int bin_search(const vector<int> &a, int x, int l, int r) {

    if (l > r) return 0;

    else if (l == r) {
        return a[l] == x ? 1 : 0;
    }
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

int main() {

    vector<int> a = {1, 1, 1, 2, 2, 2, 2, 5, 6, 9, 9, 11, 11, 12};

    cout << bin_search(a, 12, 0, a.size() - 1);


    return 0;
}