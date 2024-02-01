import sys
import time
import random

# Define the initial peg arrangement
# 0 = empty, 1 = busy, 2 = wall
initial_board = [
    [2, 2, 1, 1, 1, 2, 2],
    [2, 2, 1, 1, 1, 2, 2],
    [1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 0, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 1],
    [2, 2, 1, 1, 1, 2, 2],
    [2, 2, 1, 1, 1, 2, 2],
]

class Position:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def draw_board(board):
    for row in board:
        print(row)
    print("\n")

# d = direction of try (0 = up, 1 = right, 2 = down, 3 = left)
def move_board(board, x, y, d):
    board[y][x] = 0
    switch_dict = {
        0:  (y + 1, x),
        1:  (y, x + 1),
        2:  (y - 1, x),
        3:  (y, x - 1),
    }
    new_y, new_x = switch_dict[d]
    board[new_y][new_x] = 0
    board[y + 2 * (new_y - y)][x + 2 * (new_x - x)] = 1
    return board

def try_move(board, pos):
    directions = [0, 1, 2, 3]
    random.shuffle(directions)
    for d in directions:
        new_y, new_x = pos.y + 2 * (d == 0) - 2 * (d == 2), pos.x + 2 * (d == 1) - 2 * (d == 3)
        if 0 <= new_y < 7 and 0 <= new_x < 7 and board[new_y][new_x] == 0:
            return d
    return None

def count_ones_left(board):
    count = 0
    for row in board:
        for cell in row:
            if cell == 1:
                count += 1
    return count

def main():
    timeout = 0
    limit = 1
    board = [row.copy() for row in initial_board]
    while count_ones_left(board) > limit or board[3][3] == 0:
        if (timeout >= 250):
            board = [row.copy() for row in initial_board]
            timeout = 0
        pos = Position(random.randint(0, 6), random.randint(0, 6))
        while board[pos.y][pos.x] != 1:
            pos = Position(random.randint(0, 6), random.randint(0, 6))
        move_direction = try_move(board, pos)
        if move_direction is not None:
            move_board(board, pos.x, pos.y, move_direction)
        timeout += 1
    draw_board(board)

        #time.sleep(1)

main()
