#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<char>> board;
vector<vector<int>> positions;

vector<int> s;
vector<int> e;

bool is_valid_move(const vector<vector<char>>& board, vector<int> move) {
    int x = move[0];
    int y = move[1];

    return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] != '*' && board[x][y] != '#';
}

vector<vector<int>> knight_moves(const vector<vector<char>>& board, vector<int> pos) {
    int x = pos[0];
    int y = pos[1];

    vector<vector<int>> moves;

    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < 8; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (is_valid_move(board, {new_x, new_y})) {
            moves.push_back({new_x, new_y});
        }
    }

    return moves;
}

bool find_path(vector<int> start, vector<int> end, int k) {
    if (k == 64) {
        return start == s;
    } else {
        vector<vector<int>> moves = knight_moves(board, start);

        for (auto m : moves) {
            int new_x = m[0];
            int new_y = m[1];

            board[new_x][new_y] = '#';

            if (find_path({new_x, new_y}, end, k + 1)) {
                return true;
            }

            board[new_x][new_y] = '0';
        }
    }

    return false;
}

int main() {
    ifstream fin("board.txt");

    for (int i = 0; i < 8; i++) {
        vector<char> tmp_vec;
        for (int j = 0; j < 8; j++) {
            char tmp_char;
            fin >> tmp_char;
            tmp_vec.push_back(tmp_char);

            if (tmp_char == 'L') {
                s = {i, j};
            }
            if (tmp_char == 'K') {
                e = {i, j};
            }
        }
        board.push_back(tmp_vec);
    }

    bool found = find_path(s, e, 1);

    if (found) {
        cout << "Решение найдено:" << endl;
        
    } else {
        cout << "Решение не найдено." << endl;
    }

    return 0;
}