#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

vector<Point> bestPath;
int best_hor_steps = 9999;


bool findPath(int hor_steps, const Point& start, const Point& end, std::vector<std::vector<int>>& maze, std::vector<Point>& result, std::vector<std::vector<bool>>& visited) {
    if (start.x == end.x && start.y == end.y) {

        cout << "end";

        result.push_back(start);

        if (result.size() < bestPath.size() || bestPath.size() == 0) {

            cout << hor_steps << "\n";

            
            bestPath = result;
            
        }


        return true;
    }

    if (start.x < 0 || start.x >= maze.size() || start.y < 0 || start.y >= maze[0].size() || maze[start.x][start.y] == 1) {
        return false;
    }

    if (visited[start.x][start.y]) {
        return false;
    }

    visited[start.x][start.y] = true;

    std::vector<Point> children = {{start.x - 1, start.y}, {start.x, start.y - 1}, {start.x + 1, start.y}, {start.x, start.y + 1}};

    for (const auto& child : children) {
        std::vector<Point> path;

        if (abs(child.x - start.x) == 1) {

            bool found = findPath(hor_steps + 1, child, end, maze, path, visited);

            if (found) {
                result.push_back(start);
                for (const auto& p : path) {
                    result.push_back(p);
                }
                return true;
            }

        }
        else {

            bool found = findPath(hor_steps, child, end, maze, path, visited);

            if (found) {
                result.push_back(start);
                for (const auto& p : path) {
                    result.push_back(p);
                }
                return true;
            }

        }

            

        
    }

    visited[start.x][start.y] = false;

    return false;
}

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

    for (vector<int> line : maze) {

        for (int x : line) {

            cout << x;
        }

        cout << "\n";
    } 

    
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<Point> result;
    Point start = {0, 0};
    Point end = {4, 4};

    bool found = findPath(0, start, end, maze, result, visited);

    if (found) {

        for (const auto& p : result) {
                std::cout << "(" << p.x << "," << p.y << ") ";
            }
        } else {
            std::cout << "No path found!" << std::endl;
    }

    cout << "\n\n" <<  best_hor_steps;

    return 0;
}