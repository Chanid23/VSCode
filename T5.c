#include <stdio.h>
#include <stdlib.h>

#define N 8

// �����board[row][col]�Ƿ���Է��ûʺ�
int isSafe(int board[N][N], int row, int col) {
    // �������Ϸ���������
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return 0; // �����Ѿ���һ���ʺ��ˣ��޷�����
        }
    }

    // ������Ͻǵ����½ǵĶԽ���
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0; // ���Ͻǵ����½ǵĶԽ������Ѿ���һ���ʺ��ˣ��޷�����
        }
    }

    // ������½ǵ����ϽǵĶԽ���
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return 0; // ���½ǵ����ϽǵĶԽ������Ѿ���һ���ʺ��ˣ��޷�����
        }
    }

    return 1; // ���Է���
}

// �ڵ�row�з��ûʺ�
void placeQueen(int board[N][N], int row, int *count) {
    // �ҵ�һ�����еĽ�
    if (row == N) {
        // ����ʺ��λ�ú����
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

    // �����ڸ��з��ûʺ�
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
