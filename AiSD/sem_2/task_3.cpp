#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> ans;
vector<vector<bool>> bool_board = {

    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
};


int cnt = 1000;

void print_board(const vector<vector<char>>& board) {

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

vector<vector<int>> fill_board(vector<vector<char>>& board) {

    vector<vector<int>> positions;

    ifstream fin("board.txt");
    char tmp_char;
    
    for (int i = 0; i < 8; i++) {

        vector<char> tmp_vec;

        for (int j = 0; j < 8; j++) {

            fin >> tmp_char;
            tmp_vec.push_back(tmp_char);

            if (tmp_char == 'K') positions.push_back({i, j});
            if (tmp_char == 'L') positions.push_back({i, j});
        }

        board.push_back(tmp_vec);
    }

    return positions;
}

bool is_valid_move(vector<vector<char>>& board, int x, int y) {

    return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] != '*' && board[x][y] != '#';
}

vector<vector<int>> knight_moves(int x, int y) {

    vector<vector<int>> moves;

    moves.push_back({x + 2, y + 1});
    moves.push_back({x + 2, y - 1});
    moves.push_back({x - 2, y + 1});
    moves.push_back({x - 2, y - 1});

    moves.push_back({x + 1, y + 2});
    moves.push_back({x + 1, y - 2});
    moves.push_back({x - 1, y + 2});
    moves.push_back({x - 1, y - 2});

    return moves;

}

void draw_path(const vector<vector<int>>& path, vector<vector<char>>& board) {

    for (auto p : path) {

        int x = p[0];
        int y = p[1];

        board[x][y] = 'L';
        print_board(board);
        board[x][y] = '#';

        cin >> x;

    }
}

void try_to_defeat_king(vector<int> knight_pos, vector<int> king_pos, vector<vector<char>>& board,
vector<vector<int>> path) {

    if (knight_pos == king_pos) {

        cout << "The king is defeated!\n";

        if (path.size() < cnt) {

            ans = path;
            cnt = path.size();
        }

        
    }

    int x = knight_pos[0];
    int y = knight_pos[1];

    bool_board[x][y] = false;

    //print_board(board);

    vector<vector<int>> moves = knight_moves(x, y);

    
void draw_path(const vector<vector<int>>& path, vector<vector<char>>& board) {

    for (auto p : path) {

        int x = p[0];
        int y = p[1];

        board[x][y] = 'L';
        print_board(board);
        board[x][y] = '#';

        cin >> x;

    }
    
}
        int new_x = pos[0];
        int new_y = pos[1];

        if (is_valid_move(board, new_x, new_y) && bool_board[new_x][new_y]) {

            path.push_back(pos);
            try_to_defeat_king(pos, king_pos, board, path);
            bool_board[x][y] = true;

        }
    }
}




int main() {

    vector<vector<char>> game_board;
    vector<vector<int>> path;

    vector<vector<int>> poss = fill_board(game_board);

    
    vector<int> king_pos = poss[0];
    vector<int> knight_pos = poss[1];

    path.push_back(knight_pos);

    

    try_to_defeat_king(knight_pos, king_pos, game_board, path);

    //raw_path(ans, game_board);

    cout << ans.size();


    /* for(auto x : ans) {

        cout << x[0] << " " << x[1] << " -> ";
    } */


    

    return 0;
}
