#include <stdio.h>
#include <stdlib.h>

// 定义士兵节点
typedef struct Node {
    int number;          // 士兵的编号
    struct Node* next;   // 指向下一个士兵节点的指针
} Node;

// 创建循环链表
Node* createList(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->number = i;

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    tail->next = head;  // 形成循环链表

    return head;
}

// 模拟约瑟夫问题，输出士兵出列的过程
void josephusProblem(Node* head, int k, int m) {
    Node* current = head;
    Node* prev = NULL;

    // 找到编号为k的士兵
    while (current->number != k) {
        prev = current;
        current = current->next;
    }

    // 开始报数并出列
    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        printf("Soldier %d is out.\n", current->number);

        // 删除出列的士兵节点
        prev->next = current->next;
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    printf("The last soldier remaining is %d.\n", current->number);

    // 释放最后一个士兵节点的内存
    free(current);
}

int main() {
    int n, k, m;
    printf("Enter the number of soldiers: ");//输入士兵的数量
    scanf("%d", &n);
    printf("Enter the starting soldier's number: ");//输入出发士兵的编号
    scanf("%d", &k);
    printf("Enter the counting number: ");
    scanf("%d", &m);

    Node* head = createList(n);
    josephusProblem(head, k, m);

    return 0;
}
