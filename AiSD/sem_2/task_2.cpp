#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

vector<int> linear_search(const string& str, const string& substr) {

    vector<int> ans;

    int counter = 0;
    int cmprs  = 0;
    int j = 0;

    for (int i = 0; i < str.length(); i++) {

        cmprs += 1;

        if (str[i] == substr[0]) {

            bool found = true;

            for (int j = 1; j < substr.length(); j++) {

                cmprs += 1;

                if (str[i + j] != substr[j]) {

                    found = false;
                    break;
                }
            }

            if (found) counter++;

        }


    }

    ans.push_back(counter);
    ans.push_back(cmprs);
    
    return ans;
}

int Hash(const char* str) {

    int p = 3, M = 1e9 + 7;
    int hash = 0;

    for (; *str != 0; ++str) hash = (hash * p + *str) % M;
    return hash;
}

vector<int> rk_search(const string& s, const string& x) {

    int cmprs = 0;

    vector<int> ans;

    int p = 3, M = 1e9 + 7, l = 0;
    int n = s.length(), m = x.length();
    int i, j, t, Ti, Tim, hp;
    string tmp = s.substr(0, m);
    int hs = Hash(x.c_str());
    int h = Hash(tmp.c_str());

    int counter = 0;

    for (i = 0; i < n - m; i++) {

        cmprs += 1;

        if (hs == h) {

            t = i;
            j = 0;

            while (s[t] == x[j]) {

                t++;
                j++;

                cmprs += 1;
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

            cmprs += 1;
        }

        if (j == m) {

            counter++;

        }
    }

    ans.push_back(counter);
    ans.push_back(cmprs);
    
    return ans;

}





int main()  {

    ifstream myfile;
    myfile.open("data.txt");
    string search_word = "Kolobok";
    string line;

    int linear_counter = 0;
    int rk_counter = 0;

     int linear_cmprs = 0;
    int rk_cmprs = 0;


    /* getline(myfile, line);

    cout << linear_search(line, search_word) << endl;
    cout << rk_search(line, search_word) << endl;
    cout << kmp_search(line, search_word) << endl;
    cout << bm_search(line, search_word) << endl; */
    

    

    while (myfile) {

        std::getline(myfile, line);


        linear_counter += linear_search(line, search_word)[0];
        rk_counter += rk_search(line, search_word)[0];

        linear_cmprs += linear_search(line, search_word)[1];
        rk_cmprs += rk_search(line, search_word)[1];

        

    }

    cout << "Linear search: " << linear_counter << " cmprs - " << linear_cmprs <<  endl;
    cout << "Rabin Karp search: " << rk_counter << " cmprs - " << rk_cmprs  << endl;


    

    return 0;
    
}

