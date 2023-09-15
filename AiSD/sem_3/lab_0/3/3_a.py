
def is_valid_move(x, y, maze):
    # Проверяем, что координаты (x, y) находятся в пределах лабиринта и клетка свободна
    return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 0





def main():
    # Чтение лабиринта из файла
    with open('maze.txt', 'r') as file:
        maze = [list(map(int, line.strip())) for line in file]

    for x in maze:
        print(x)
                

   



if __name__ == "__main__":
    main()