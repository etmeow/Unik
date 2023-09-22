#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int linear_search(const string& str, const string& substr) {

    int counter = 0;
    int j = 0;

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == substr[0]) {

            bool found = true;

            for (int j = 1; j < substr.length(); j++) {

                if (str[i + j] != substr[j]) {

                    found = false;
                    break;
                }
            }

            if (found) counter++;

        }


    }
    
    return counter;
}

int Hash(const char* str) {

    int p = 3, M = 1e9 + 7;
    int hash = 0;

    for (; *str != 0; ++str) hash = (hash * p + *str) % M;
    return hash;
}

int rk_search(const string& s, const string& x) {


    int p = 3, M = 1e9 + 7, l = 0;
    int n = s.length(), m = x.length();
    int i, j, t, Ti, Tim, hp;
    string tmp = s.substr(0, m);
    int hs = Hash(x.c_str());
    int h = Hash(tmp.c_str());

    int counter = 0;

    for (i = 0; i < n - m; i++) {

        if (hs == h) {

            t = i;
            j = 0;

            while (s[t] == x[j]) {

                t++;
                j++;
            }

            if (j == m) {

                counter++;
            }
        }

        hp = h * p;
        Ti = s[i] * pow(p, m);
        Tim = s[i + m];

        h = hp - Ti + Tim;

    }

    if (hs == h) {

        t = i;
        j = 0;

        while (s[t] == x[j] && s[t] != 0) {

            t++;
            j++;
        }

        if (j == m) {

            counter++;

        }
    }

    return counter;

}





int main()  {

    ifstream myfile;
    myfile.open("data.txt");
    string search_word = "Kolobok";
    string line;

    int linear_counter = 0;
    int rk_counter = 0;


    /* getline(myfile, line);

    cout << linear_search(line, search_word) << endl;
    cout << rk_search(line, search_word) << endl;
    cout << kmp_search(line, search_word) << endl;
    cout << bm_search(line, search_word) << endl; */
    

    

    while (myfile) {

        std::getline(myfile, line);

        linear_counter += linear_search(line, search_word);
        rk_counter += rk_search(line, search_word);

    }

    cout << linear_counter << endl;
    cout << rk_counter << endl;


    

    return 0;
    
}

