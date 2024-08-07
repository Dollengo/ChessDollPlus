# ChessDollPlus

ChessDollPlus is a simple representation of a chess game using a custom notation. This project aims to demonstrate the basics of a chess game, including piece movement, capturing, and determining the winner based on the capture of the king.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Pieces Representation](#pieces-representation)
- [Game Play](#game-play)
- [Contributing](#contributing)
- [License](#license)

## Introduction

ChessDollPlus is a minimalistic chess game implemented in C++. The board and pieces are represented using specific symbols, and players can input their moves using standard chess notation. The game will alternate turns between the two players and check for valid moves and captures.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Dollengo/ChessDollPlus
    ```
2. Navigate to the project directory:
    ```bash
    cd ChessDollPlus
    ```
3. Compile the code:
    ```bash
    g++ -o chessdollplus main.cpp
    ```

## Usage

Run the compiled program:
```bash
./chessdollplus
```
The game will display the board and prompt the players to enter their moves.

## Game Rules

1. The game starts with a random selection of whether the top or bottom player makes the first move.
2. Players take turns to make moves.
3. A player moves a piece by entering the source and destination coordinates (e.g., `E2 E4`).
4. A move is valid if it adheres to the rules of chess and the piece's movement capabilities.
5. The game ends when a king is captured.

## Pieces Representation

Each piece is represented by a specific symbol:
- `@` = Rook (Tower)
- `$` = Knight (Horse)
- `!` = Bishop
- `%` = King
- `&` = Queen
- `*` = Pawn
- `#` = Empty

## Game Play

At the start of the game, the initial board setup is displayed. The board is an 8x8 grid, with coordinates from A1 to H8.

Example of the initial board setup:
```
  A B C D E F G H
8 @ $ ! % & ! $ @ 8
7 * * * * * * * * 7
6 # # # # # # # # 6
5 # # # # # # # # 5
4 # # # # # # # # 4
3 # # # # # # # # 3
2 * * * * * * * * 2
1 @ $ ! % & ! $ @ 1
  A B C D E F G H
```

Players enter their moves in the format `E2 E4`. The game will validate the move and update the board accordingly.

## Contributing

Contributions are welcome! Please follow these steps to contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix:
    ```bash
    git checkout -b feature-name
    ```
3. Commit your changes:
    ```bash
    git commit -m "Add new feature"
    ```
4. Push to the branch:
    ```bash
    git push origin feature-name
    ```
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
