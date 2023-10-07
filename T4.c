#include <stdio.h>

// 使用二分法查找不同质量的球
void findDifferentBall(int n) {
    if (n <= 1 || n>20) {
        printf("范围错误。\n");
        return;
    }

    // 初始化球的质量
    int balls[20] = {0};
    for (int i = 0; i < n; i++) {
        balls[i] = 1;
    }
    balls[n] = -1; // 设置一个球的质量不同

    // 二分法查找
    int left = 0, right = n - 1;
    int step = 1;
    while (left < right) {
        int mid = (left + right) / 2;

        // 将球分成两组进行称重
        int sum1 = 0, sum2 = 0;
        for (int i = left; i <= mid; i++) {
            sum1 += balls[i];
        }
        for (int i = mid + 1; i <= right; i++) {
            sum2 += balls[i];
        }

        printf("第%d次称球，左侧第%d个球到右侧第%d个球：", step, left + 1, right + 1);
        if (sum1 == sum2) {
            printf("两侧质量相等\n");
            left = mid + 1;
        } else if (sum1 < sum2) {
            printf("左侧质量轻\n");
            right = mid;
        } else {
            printf("右侧质量轻\n");
            left = mid + 1;
        }

        step++;
    }

    // 输出结果
    printf("找到质量不同的球，球号为%d。\n", left + 1);
}

int main() {
    int n;
    printf("请输入球的数量n(1 <= n <20)：");
    scanf("%d", &n);

    findDifferentBall(n);

    return 0;
}
