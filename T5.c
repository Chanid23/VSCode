#include <stdio.h>
#include <stdlib.h>

#define N 8

// 检查在board[row][col]是否可以放置皇后
int isSafe(int board[N][N], int row, int col) {
    // 检查该列上方的所有行
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return 0; // 该列已经有一个皇后了，无法放置
        }
    }

    // 检查左上角到右下角的对角线
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0; // 左上角到右下角的对角线上已经有一个皇后了，无法放置
        }
    }

    // 检查左下角到右上角的对角线
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return 0; // 左下角到右上角的对角线上已经有一个皇后了，无法放置
        }
    }

    return 1; // 可以放置
}

// 在第row行放置皇后
void placeQueen(int board[N][N], int row, int *count) {
    // 找到一个可行的解
    if (row == N) {
        // 输出皇后的位置和序号
        printf("Solution %d:\n", ++(*count));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j]) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // 尝试在该行放置皇后
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            placeQueen(board, row + 1, count);
            board[row][col] = 0;
        }
    }
}

int main() {
    int board[N][N] = {0};
    int count = 0;
    placeQueen(board, 0, &count);

    printf("Total solutions: %d\n", count);

    return 0;
}
