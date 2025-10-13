/*
 * Recursive Maze Solver
 * This program solves a given maze using backtracking.
 * The maze is represented as a 2D array where 0 indicates a blocked cell and 1 indicates an open cell.
 * The program finds a path from the top-left corner (0,0) to the bottom-right corner (N-1,N-1).
*/

#include <stdio.h>

#define N 4  // Size of the maze

int enterMaze(int maze[N][N]) {
    printf("Enter the maze (0 for blocked cell, 1 for open cell):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Cell [%d][%d]: ", i+1, j+1);
            scanf("%d", &maze[i][j]);
        }
    }
    return 0;
}

int printMaze(int maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Function to check if a cell is safe to move into
int isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the maze
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: if (x, y) is destination
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y)) {
        // Mark the cell as part of the path
        sol[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, sol))
            return 1;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return 1;

        // If neither works, backtrack
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

// Main function to solve the maze
int solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        printf("No path found.\n");
        return 0;
    }

    printf("Path found:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
    return 1;
}

int main() {
    int maze[N][N];

    enterMaze(maze);
    printf("The maze is:\n");
    printMaze(maze);
    if (solveMaze(maze)) {
        printf("The maze has a solution:\n");
        printMaze(maze);
    } else {
        printf("The maze has no solution.\n");
    }

    solveMaze(maze);
    
    return 0;
}