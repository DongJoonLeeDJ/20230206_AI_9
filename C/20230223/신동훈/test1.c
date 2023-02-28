#include <stdio.h>

int main() {
    char alphabet[100];
    int count[26] = { 0 }; // 알파벳 26개 카운팅 배열 초기화

    printf("알파벳 문자열 입력: ");
    fgets(alphabet, sizeof(alphabet), stdin);

    int i = 0;
    while (alphabet[i] != '\0') {
        if (alphabet[i] >= 'A' && alphabet[i] <= 'Z') {
            alphabet[i] = alphabet[i] - 'A' + 'a'; // 대문자를 소문자로 변환
        }
        if (alphabet[i] >= 'a' && alphabet[i] <= 'z') {
            count[alphabet[i] - 'a']++; // 해당 알파벳 카운트 증가
        }
        i++;
    }

    // 결과 출력
    for (int j = 0; j < 26; j++) {
        if (count[j] > 0) {
            printf("%c: %d\n", 'a' + j, count[j]);
        }
    }

    return 0;
}
