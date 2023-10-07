#include <stdio.h>

void magicSquare(int n) {
    int square[10][10] = {0}; // ����һ����ά�������ڴ洢ħ����
    int num = 1;
    int row = 1, col = (n + 1) / 2; // �ӵ�1���м��п�ʼ���

    while (num <= n * n) {
        square[row][col] = num;

        // ������һ��λ��
        int nextRow = row - 1;
        int nextCol = col + 1;

        // ����Խ�����
        if (nextRow == 0) {
            nextRow = n;
        }
        if (nextCol > n) {
            nextCol = 1;
        }

        // ����һ��λ���Ѿ����������ǵ�1�е�n��ʱ������һ��λ���ƶ�����ǰλ�õ��·�
        if (square[nextRow][nextCol] || (row == 1 && col == n)) {
            nextRow = row + 1;
            nextCol = col;
        }

        // ���µ�ǰλ��
        row = nextRow;
        col = nextCol;
        num++;
    }

    // ���ħ����
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%-4d", square[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("������Ҫ�����ħ����Ľ���n��nΪ������: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("��������������n��\n");
        return 0;
    }

    printf("%d��ħ����������ʾ��\n", n);
    magicSquare(n);

    return 0;
}