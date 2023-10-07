#include <stdio.h>

// ʹ�ö��ַ����Ҳ�ͬ��������
void findDifferentBall(int n) {
    if (n <= 1 || n>20) {
        printf("��Χ����\n");
        return;
    }

    // ��ʼ���������
    int balls[20] = {0};
    for (int i = 0; i < n; i++) {
        balls[i] = 1;
    }
    balls[n] = -1; // ����һ�����������ͬ

    // ���ַ�����
    int left = 0, right = n - 1;
    int step = 1;
    while (left < right) {
        int mid = (left + right) / 2;

        // ����ֳ�������г���
        int sum1 = 0, sum2 = 0;
        for (int i = left; i <= mid; i++) {
            sum1 += balls[i];
        }
        for (int i = mid + 1; i <= right; i++) {
            sum2 += balls[i];
        }

        printf("��%d�γ�������%d�����Ҳ��%d����", step, left + 1, right + 1);
        if (sum1 == sum2) {
            printf("�����������\n");
            left = mid + 1;
        } else if (sum1 < sum2) {
            printf("���������\n");
            right = mid;
        } else {
            printf("�Ҳ�������\n");
            left = mid + 1;
        }

        step++;
    }

    // ������
    printf("�ҵ�������ͬ�������Ϊ%d��\n", left + 1);
}

int main() {
    int n;
    printf("�������������n(1 <= n <20)��");
    scanf("%d", &n);

    findDifferentBall(n);

    return 0;
}
