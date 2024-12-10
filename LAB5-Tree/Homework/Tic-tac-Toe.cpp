#include <iostream>
using namespace std;

class TicTacToe {
public:
    int board[3][3];

    TicTacToe() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = 0;
    }

    bool isMovesLeft() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 0) return true;
        return false;
    }

    int evaluate() {
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == 2) return 10;
                else if (board[row][0] == 1) return -10;
            }
        }

        for (int col = 0; col < 3; col++) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == 2) return 10;
                else if (board[0][col] == 1) return -10;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 2) return 10;
            else if (board[0][0] == 1) return -10;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 2) return 10;
            else if (board[0][2] == 1) return -10;
        }

        return 0;
    }

    int minimax(bool isMax) {
        int score = evaluate();
        if (score == 10 || score == -10) return score;
        if (!isMovesLeft()) return 0;

        if (isMax) {
            int best = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = 2;
                        best = max(best, minimax(false));
                        board[i][j] = 0;
                    }
                }
            }
            return best;
        }
        else {
            int best = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = 1;
                        best = min(best, minimax(true));
                        board[i][j] = 0;
                    }
                }
            }
            return best;
        }
    }
};

int main() {
    TicTacToe game;
    game.board[0][0] = 2; // AI
    game.board[1][1] = 1; // Player
    cout << "Best Score: " << game.minimax(true) << endl;
    return 0;
}
