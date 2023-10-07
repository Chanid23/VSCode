#include <stdio.h>
#include <stdlib.h>

// ����ʿ���ڵ�
typedef struct Node {
    int number;          // ʿ���ı��
    struct Node* next;   // ָ����һ��ʿ���ڵ��ָ��
} Node;

// ����ѭ������
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

    tail->next = head;  // �γ�ѭ������

    return head;
}

// ģ��Լɪ�����⣬���ʿ�����еĹ���
void josephusProblem(Node* head, int k, int m) {
    Node* current = head;
    Node* prev = NULL;

    // �ҵ����Ϊk��ʿ��
    while (current->number != k) {
        prev = current;
        current = current->next;
    }

    // ��ʼ����������
    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        printf("Soldier %d is out.\n", current->number);

        // ɾ�����е�ʿ���ڵ�
        prev->next = current->next;
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    printf("The last soldier remaining is %d.\n", current->number);

    // �ͷ����һ��ʿ���ڵ���ڴ�
    free(current);
}

int main() {
    int n, k, m;
    printf("Enter the number of soldiers: ");//����ʿ��������
    scanf("%d", &n);
    printf("Enter the starting soldier's number: ");//�������ʿ���ı��
    scanf("%d", &k);
    printf("Enter the counting number: ");
    scanf("%d", &m);

    Node* head = createList(n);
    josephusProblem(head, k, m);

    return 0;
}
