#include <stdio.h>

int main() {
    char alphabet[100];
    int first[26];

    // first �迭 �ʱ�ȭ
    for (int i = 0; i < 26; i++) {
        first[i] = -1;
    }

    printf("���ڿ��� �Է��ϼ���: ");
   // scanf("%s", alphabet);
    fgets(alphabet, sizeof(alphabet), stdin);


    int len = 0;
    while (alphabet[len] != '\0') {
        len++; // ���ڿ��� ���� ���
    }

    for (int i = 0; i < len; i++) {
        char ch = alphabet[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a'; // �빮�ڸ� �ҹ��ڷ� ��ȯ
        }
        int idx = ch - 'a';
        if (first[idx] == -1) {
            first[idx] = i+1;
        }
    }

    // ��� ���
    printf("���ĺ� ������ ���� ��ġ:\n");
    for (int i = 0; i < 26; i++) {
        if (first[i] != -1) {
            printf("%c�� %d��°���� ó�� �����մϴ�\n", 'a' + i, first[i]);
        }
    }

    return 0;
}
