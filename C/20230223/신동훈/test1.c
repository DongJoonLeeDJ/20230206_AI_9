#include <stdio.h>

int main() {
    char alphabet[100];
    int count[26] = { 0 }; // ���ĺ� 26�� ī���� �迭 �ʱ�ȭ

    printf("���ĺ� ���ڿ� �Է�: ");
    fgets(alphabet, sizeof(alphabet), stdin);

    int i = 0;
    while (alphabet[i] != '\0') {
        if (alphabet[i] >= 'A' && alphabet[i] <= 'Z') {
            alphabet[i] = alphabet[i] - 'A' + 'a'; // �빮�ڸ� �ҹ��ڷ� ��ȯ
        }
        if (alphabet[i] >= 'a' && alphabet[i] <= 'z') {
            count[alphabet[i] - 'a']++; // �ش� ���ĺ� ī��Ʈ ����
        }
        i++;
    }

    // ��� ���
    for (int j = 0; j < 26; j++) {
        if (count[j] > 0) {
            printf("%c: %d\n", 'a' + j, count[j]);
        }
    }

    return 0;
}
