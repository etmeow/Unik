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

vector<int> pref(const string& s) {

    int m = s.length(), k;
    vector<int> p = { -1 };

    for (int i = 1; i <= m; ++i) {

        k = p[i - 1];

        while (k != -1 && s[k] != s[i - 1]) {

            k = p[k];
        }

        p.push_back(k + 1);

    }

    return p;
}

int kmp_search(const string& s, const string& x) {

    vector<int> ans;

    string t = x + "#" + s;
    vector<int> p = pref(t);
    int m = x.length(), l = 0;

    int counter = 0;

    for (int i = m + 1; i < p.size(); i++) {

        l++;

        if (p[i] == m) {

            counter++;
        }
    }


    return counter;
}

map<char, int> offsets(const string& x) {

    map<char, int> d;
    int i, m = x.length();

    for (i = m - 2; i >= 0; i--)

        if (d.find(x[i]) == d.end())

            d[x[i]] = m - i - 1;

    if (d.find(x[m - 1]) == d.end())
        d[x[m - 1]] = m;

    d['*'] = m;

    return d;

}

int bm_search(const string& s, const string& x) {

    vector<int> ans;
    int count = 0;

    int i, j, k, off, l = 0;
    int n = s.size(), m = x.size();

    map<char, int> d = offsets(x);


    i = m - 1;

    while (i < n) {

        k = 0;

        for (j = m - 1; j >= 0; j--) {

            l++;

            if (s[i - k] != x[j]) {

                if (j == m - 1)
                    off = (d.find(s[i]) == d.end()) ? d['*'] : d[s[i]];
                else
                    off = d[x[j]];

                i += off;
                break;
            }

            k++;
        }

        if (j == -1) {

            ans.push_back(i - k + 1);
            ans.push_back(l);
            count += 1;
            i += 1;
        }
    }

    return count;

}





int main()  {

    ifstream myfile;
    myfile.open("data.txt");
    string search_word = "Mumu";
    string line;

    int linear_counter = 0;
    int rk_counter = 0;
    int kmp_counter = 0;
    int bm_counter = 0;

    /* getline(myfile, line);

    cout << linear_search(line, search_word) << endl;
    cout << rk_search(line, search_word) << endl;
    cout << kmp_search(line, search_word) << endl;
    cout << bm_search(line, search_word) << endl; */
    

    

    while (myfile) {

        

        std::getline(myfile, line);

        linear_counter += linear_search(line, search_word);
        rk_counter += rk_search(line, search_word);
        kmp_counter += kmp_search(line, search_word);
        bm_counter += bm_search(line, search_word);

    

    }

    cout << linear_counter << endl;
    cout << rk_counter << endl;
    cout << kmp_counter << endl;
    cout << bm_counter << endl;
    

    

    return 0;
    
}

