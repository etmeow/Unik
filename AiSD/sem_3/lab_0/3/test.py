def is_valid_move(x, y, maze):
    # Проверяем, что координаты (x, y) находятся в пределах лабиринта и клетка свободна
    return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 0

def find_shortest_path(maze, start, end, current_path, shortest_path):
    x, y = start

    # Если текущая клетка является конечной, проверяем, является ли текущий путь лучшим
    if start == end:
        if len(current_path) > len(shortest_path):
            shortest_path[:] = current_path[:]
        return

    # Возможные направления движения (все 8 соседних клеток)
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, 1), (1, -1), (-1, -1)]

    for dx, dy in directions:
        new_x, new_y = x + dx, y + dy

        if is_valid_move(new_x, new_y, maze):
            # Передвигаемся в новую клетку
            maze[new_x][new_y] = 1
            current_path.append((new_x, new_y))

            # Рекурсивно ищем путь из новой клетки
            find_shortest_path(maze, (new_x, new_y), end, current_path, shortest_path)

            # Возвращаемся назад (backtracking)
            maze[new_x][new_y] = 0
            current_path.pop()

def main():
    # Чтение лабиринта из файла
    with open('maze.txt', 'r') as file:
        maze = [list(map(int, line.strip())) for line in file]

    n = len(maze)
    m = len(maze[0])

    start = (0, 0)  # Начальная клетка
    end = (n - 1, m - 1)  # Конечная клетка

    current_path = [start]
    shortest_path = []

    find_shortest_path(maze, start, end, current_path, shortest_path)

    if shortest_path:
        print("Кратчайший путь:")
        for x, y in shortest_path:
            print(f"({x}, {y})")
    else:
        print("Путь не найден")

if __name__ == "__main__":
    main()
