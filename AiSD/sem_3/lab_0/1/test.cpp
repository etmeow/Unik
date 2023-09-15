#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    int cardinality = 26;
   
    int count = 0;

    string s1 = "adegjqlqwekjl";
    string s2 = "efeolfseqwert";
    string evil = "aw";

     int n = s1.length();


    for (int i = 0; i < pow(cardinality, n); i++) {

        string x = "";

        for (int j = 0; j < n; j++) {

            int digit = (i / static_cast<int>(pow(cardinality, j))) % cardinality;
            char letter = 'a' + digit;
            x += letter;
        }

        if (s1 <= x && x <= s2 && (x.find(evil) == string::npos)) {

            count += 1;
            cout << x << "\n";
        }
    }

    cout << count << "\n";

    

    

    return 0;
}