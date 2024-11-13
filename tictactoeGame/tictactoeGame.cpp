#include <iostream>
#include <vector>
#include <string>

using namespace std;

void createBoard(vector<vector<char>>& board) {
    board.assign(3, vector<char>(3, ' '));
}
inline bool playerTurn(int x, int y, vector<vector<char>>& board, bool player1) {
    if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ') {
        return false;
    }
    board[x][y] = player1 ? 'X' : 'O';
    return true;
}
void displayBoard(const vector<vector<char>>& board) {
    static const char row[] = "+--+-+-+\n";
    cout << "   0 1 2\n  " << row;
    int i= 0;
    for (const auto& r : board) {
        cout << i++ << " ";
        cout << "|";
        for (char c : r) 
            cout << c << "|";
        cout << "\n " << row;
    }
}
bool checkWin(vector<vector<char>> &board, bool &player) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            player = (board[i][0] == 'X');
            return true;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            player = (board[0][i] == 'X');
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        player = (board[0][0] == 'X');
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        player = (board[0][2] == 'X');
        return true;
    }
    return false;
}
bool checkDraw(vector<vector<char>> &board){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    bool gameOver = false;
    bool player1 = true;
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int x, y;

    while (!gameOver) {
        displayBoard(board);
        cout << "Player " << (player1 ? "1" : "2") << " Turn: ";
        cin >> x >> y;
        
        if (!playerTurn(x, y, board, player1)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (checkWin(board, player1)) {
            gameOver = true;
            cout << "Player " << (player1 ? "1" : "2") << " wins\n";
        } else if (checkDraw(board)) {
            cout << "Draw\n";
            gameOver = true;
        }

        player1 = !player1;
    }

    return 0;
}
