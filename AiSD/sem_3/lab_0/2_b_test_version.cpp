#include<iostream>
#include<vector>
#include <algorithm>
#include <conio.h>

using namespace std;

int f(int a, int b, int c, int x) {

    return a*x*x + b*x + c;
}

void out(vector<float> a) {

    for (float x : a) 
        cout << x << " ";
    cout << endl;
}

void out(vector<int> a) {

    for (int x : a) 
        cout << x << " ";
    cout << endl;
}




int main() {

    float vertex;
    vector<int> nums = {-100, -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87, -86, -85, -84, -83, -82, -81, -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69, -68, -67, -66, -65, -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51, -50, -49, -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33, -32, -31, -30, -29, -28, -27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
    vector<int> x, my_x, x_sorted;
    vector<float> d;
    bool is_equal;

    float a = 2, b = -9, c = -10;

    for (a = -10; a <= 10; a++) {

        for (b = -10; b <= 10; b++) {

            for (c = -10; c <= 10; c++) {

                if (a == 0) continue;

                vertex = -b/(2*a);


                for (float el : nums) {

                    d.push_back(abs(vertex - el));
                    x.push_back(f(a, b, c, el));
                }

                sort(x.begin(), x.end());

                int i = 0;
                int j = nums.size() - 1;

                while (i <= j) {

                    if (d[i] < d[j]) {
                        my_x.push_back(f(a, b, c, nums[j]));
                        j -= 1;
                    } else {
                        my_x.push_back(f(a, b, c, nums[i]));
                        i += 1;
                    }
                }

                if (a > 0) reverse(my_x.begin(), my_x.end());

                is_equal = equal(x.begin(), x.end(), my_x.begin(), my_x.end());

                if (!is_equal) cout << "FALSE\n";

                x.clear();
                my_x.clear();
                d.clear();
    
            }
        }
    }

    

    
    


    

    /* out(nums);
    out(d);
    out(x);
    out(my_x); */




    return 0;
}

