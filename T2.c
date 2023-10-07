#include <stdio.h>

// ���������C(n, k)
int combination(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    } else {
        return combination(n - 1, k - 1) + combination(n - 1, k);
    }
}

// ������������
void printPascalTriangle(int rows) {
    int i, j;
    int max_width = 0;

    // �������ֵ�Ŀ��
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
        // ��ӡ�ո�ʹ�������ξ���
        for (j = 0; j < (rows - i - 1) * (max_width + 1) / 2; j++) {
            printf(" ");
        }

        // ��ӡ��ǰ�е�����
        for (j = 0; j <= i; j++) {
            int num = combination(i, j);
            printf("%-*d ", max_width, num);
        }

        printf("\n");
    }
}

int main() {
    int rows;

    printf("������������");
    scanf("%d", &rows);

    printf("���������������ʾ��\n");
    printPascalTriangle(rows);

    return 0;
}