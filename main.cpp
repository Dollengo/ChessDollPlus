#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

std::string mBoard[64] = {
    "@", "$", "!", "%", "&", "!", "$", "@",
    "*", "*", "*", "*", "*", "*", "*", "*",
    "#", "#", "#", "#", "#", "#", "#", "#",
    "#", "#", "#", "#", "#", "#", "#", "#",
    "#", "#", "#", "#", "#", "#", "#", "#",
    "#", "#", "#", "#", "#", "#", "#", "#",
    "*", "*", "*", "*", "*", "*", "*", "*",
    "@", "$", "!", "%", "&", "!", "$", "@"
};

void printIntroduction() {
    std::cout << "ChessDollPlus" << std::endl;
    std::cout << std::endl;
    std::cout << "This is a simple representation of a chess board using the ChessDollPlus notation." << std::endl;
    std::cout << "Each piece is represented by a specific symbol:" << std::endl;
    std::cout << std::endl;
    std::cout << "@ = Rook (Tower)" << std::endl;
    std::cout << "$ = Knight (Horse)" << std::endl;
    std::cout << "! = Bishop" << std::endl;
    std::cout << "% = King" << std::endl;
    std::cout << "& = Queen" << std::endl;
    std::cout << "* = Pawn" << std::endl;
    std::cout << "# = Empty" << std::endl;
    std::cout << std::endl;
    std::cout << "The board is an 8x8 grid, with coordinates from A1 to H8." << std::endl;
    std::cout << "The initial setup of the board is displayed below, with pieces" << std::endl;
    std::cout << "positioned as they would be at the start of a standard chess game." << std::endl;
    std::cout << std::endl;
}

void printBoard(const std::string board[]) {
    std::cout << "  A B C D E F G H" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i * 8 + j] << " ";
        }
        std::cout << 8 - i << std::endl;
    }
    std::cout << "  A B C D E F G H" << std::endl;
}

int positionToIndex(char column, char row) {
    int col = column - 'A';
    int r = 8 - (row - '1' + 1);
    return r * 8 + col;
}

bool isValidMove(std::string board[], int from, int to, bool topPlayerTurn) {
    // Simplified check, just ensures the target is empty or occupied by opponent piece
    if (from < 0 || from >= 64 || to < 0 || to >= 64) {
        return false;
    }
    if (board[from] == "#") {
        return false;
    }
    // Ensure the player is moving their own piece
    if ((topPlayerTurn && islower(board[from][0])) || (!topPlayerTurn && isupper(board[from][0]))) {
        return false;
    }
    return board[to] == "#" || islower(board[from][0]) != islower(board[to][0]);
}

void movePiece(std::string board[], int from, int to) {
    board[to] = board[from];
    board[from] = "#";
}

bool isKingCaptured(std::string board[], bool topPlayerTurn) {
    std::string king = topPlayerTurn ? "%" : "&";
    for (int i = 0; i < 64; ++i) {
        if (board[i] == king) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    printIntroduction();
    printBoard(mBoard);

    bool topPlayerTurn = rand() % 2 == 0;
    int turn = 1;

    while (true) {
        std::cout << turn << " - " << (topPlayerTurn ? "Top" : "Bottom") << " player: " << std::endl;

        char fromColumn, toColumn;
        char fromRow, toRow;

        std::cout << "Enter move (e.g., E2 E4): ";
        std::cin >> fromColumn >> fromRow >> toColumn >> toRow;

        int fromIndex = positionToIndex(fromColumn, fromRow);
        int toIndex = positionToIndex(toColumn, toRow);

        if (isValidMove(mBoard, fromIndex, toIndex, topPlayerTurn)) {
            movePiece(mBoard, fromIndex, toIndex);
            printBoard(mBoard);

            if (isKingCaptured(mBoard, topPlayerTurn)) {
                std::cout << (topPlayerTurn ? "Bottom" : "Top") << " player wins!" << std::endl;
                break;
            }

            topPlayerTurn = !topPlayerTurn;
            turn++;
        } else {
            std::cout << "Invalid move, try again." << std::endl;
        }
    }

    return 0;
}
