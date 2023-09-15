#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

const int MAXN = 100;

int sx, sy, ex, ey; // начальная и конечная клетки
bool visited[MAXN][MAXN];
int len_shortestPath = -1;










int main() {

    string line;
    vector<vector<int>> maze;
    ifstream file("maze.txt");

    

    while (file) {

        vector<int> tmp;

        getline(file, line);
        //cout << line << endl;
        for (char c: line) {
            tmp.push_back(c - '0');
        }

        maze.push_back(tmp);
    }
    maze.pop_back();



    


    
    


    return 0;
}


