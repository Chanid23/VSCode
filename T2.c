#include <stdio.h>

// 计算组合数C(n, k)
int combination(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    } else {
        return combination(n - 1, k - 1) + combination(n - 1, k);
    }
}

// 输出杨辉三角形
void printPascalTriangle(int rows) {
    int i, j;
    int max_width = 0;

    // 计算最大值的宽度
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            int num = combination(i, j);
            int width = 0;
            while (num > 0) {
                num /= 10;
                width++;
            }

            if (width > max_width) {
                max_width = width;
            }
        }
    }

    for (i = 0; i < rows; i++) {
        // 打印空格使得三角形居中
        for (j = 0; j < (rows - i - 1) * (max_width + 1) / 2; j++) {
            printf(" ");
        }

        // 打印当前行的数字
        for (j = 0; j <= i; j++) {
            int num = combination(i, j);
            printf("%-*d ", max_width, num);
        }

        printf("\n");
    }
}

int main() {
    int rows;

    printf("请输入行数：");
    scanf("%d", &rows);

    printf("杨辉三角形如下所示：\n");
    printPascalTriangle(rows);

    return 0;
}