#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int tmp;

vector<vector<int>> p1;
vector<vector<int>> p2;

vector<vector<int>> fill_board(vector<vector<char>>& board);

vector<vector<char>> board;
vector<vector<int>> positions = fill_board(board);

vector<int> s = positions[0];
vector<int> e = positions[1];

void print_board(const vector<vector<char>>& board) {

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

vector<vector<int>> fill_board(vector<vector<char>>& board) {

    vector<vector<int>> positions = {{}, {}};

    ifstream fin("board.txt");
    char tmp_char;
    
    for (int i = 0; i < 8; i++) {

        vector<char> tmp_vec;

        for (int j = 0; j < 8; j++) {

            fin >> tmp_char;
            tmp_vec.push_back(tmp_char);

            if (tmp_char == 'L') positions[0] = {i, j};
            if (tmp_char == 'K') positions[1] = {i, j};
        }

        board.push_back(tmp_vec);
    }

    return positions;
}

bool is_valid_move(const vector<vector<char>>& board, vector<int> move) {

    int x = move[0];
    int y = move[1];

    return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] != '*' && board[x][y] != '#';
}

vector<vector<int>> knight_moves(const vector<vector<char>>& board, vector<int> pos) {

    int x = pos[0];
    int y = pos[1];

    vector<vector<int>> all_moves;
    vector<vector<int>> moves;

    all_moves.push_back({x + 2, y + 1});
    all_moves.push_back({x + 2, y - 1});
    all_moves.push_back({x - 2, y + 1});
    all_moves.push_back({x - 2, y - 1});
    all_moves.push_back({x + 1, y + 2});
    all_moves.push_back({x + 1, y - 2});
    all_moves.push_back({x - 1, y + 2});
    all_moves.push_back({x - 1, y - 2});

    for (auto move : all_moves) {

        if (is_valid_move(board, move)) moves.push_back(move);
    }


    return moves;

}

bool way_back(vector<int> start, vector<int> end, vector<vector<int>> path) {

    if (start == end) {

        p2 = path;
        cout << "Way back!";
        return true;

    } else {

        int x = start[0];
        int y = start[1];

        vector<vector<int>> moves = knight_moves(board, start);

        for (auto m : moves) {

            int new_x = m[0];
            int new_y = m[1];


            board[new_x][new_y] = '#';
            path.push_back(m);

            if (way_back(m, end, path)) return true;

            board[new_x][new_y] = '0';
            path.pop_back();
            

        }
    
    }

    return false;
}


bool find_path(vector<int> start, vector<int> end, vector<vector<int>> path) {

    if (start == end) {

        
        if ( way_back(e, s, {{e}}) ) {

            p1 = path;
            return true;
        }

        return false;

    } else {

        int x = start[0];
        int y = start[1];


        vector<vector<int>> moves = knight_moves(board, start);

        for (auto m : moves) {

            int new_x = m[0];
            int new_y = m[1];


            board[new_x][new_y] = '#';
            path.push_back(m);

            if (find_path(m, end, path)) return true;

            board[new_x][new_y] = '0';
            path.pop_back();
            

        }
    
    }

    return false;
}




int main() {

    

    
    //board[s[0]][s[1]] = '#';

    vector<vector<int>> path;

    path.push_back(s);
    
    if (find_path(s, e, path) ) {
   

        print_board(board);

        for (auto x : p1) {

            cout << "(" <<x[0] << "," << x[1] << ")" << "->";
        }

        cout << "\n";

        for (auto x : p2) {

            cout << "(" <<x[0] << "," << x[1] << ")" << "->";
        }

    } else {
    
        cout << "\n((\n";
    }

    //print_board(board);








    return 0;
}