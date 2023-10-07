#include <stdio.h>

void magicSquare(int n) {
    int square[10][10] = {0}; // 创建一个二维数组用于存储魔方阵
    int num = 1;
    int row = 1, col = (n + 1) / 2; // 从第1行中间列开始填充

    while (num <= n * n) {
        square[row][col] = num;

        // 计算下一个位置
        int nextRow = row - 1;
        int nextCol = col + 1;

        // 处理越界情况
        if (nextRow == 0) {
            nextRow = n;
        }
        if (nextCol > n) {
            nextCol = 1;
        }

        // 当下一个位置已经被填充或者是第1行第n列时，将下一个位置移动到当前位置的下方
        if (square[nextRow][nextCol] || (row == 1 && col == n)) {
            nextRow = row + 1;
            nextCol = col;
        }

        // 更新当前位置
        row = nextRow;
        col = nextCol;
        num++;
    }

    // 输出魔方阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%-4d", square[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("请输入要输出的魔方阵的阶数n（n为奇数）: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("请输入奇数阶数n。\n");
        return 0;
    }

    printf("%d阶魔方阵如下所示：\n", n);
    magicSquare(n);

    return 0;
}