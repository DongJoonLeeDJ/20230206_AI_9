#include <stdio.h>

int main() {
    char alphabet[100];
    int first[26];

    // first 배열 초기화
    for (int i = 0; i < 26; i++) {
        first[i] = -1;
    }

    printf("문자열을 입력하세요: ");
   // scanf("%s", alphabet);
    fgets(alphabet, sizeof(alphabet), stdin);


    int len = 0;
    while (alphabet[len] != '\0') {
        len++; // 문자열의 길이 계산
    }

    for (int i = 0; i < len; i++) {
        char ch = alphabet[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a'; // 대문자를 소문자로 변환
        }
        int idx = ch - 'a';
        if (first[idx] == -1) {
            first[idx] = i+1;
        }
    }

    // 결과 출력
    printf("알파벳 문자의 최초 위치:\n");
    for (int i = 0; i < 26; i++) {
        if (first[i] != -1) {
            printf("%c는 %d번째에서 처음 등장합니다\n", 'a' + i, first[i]);
        }
    }

    return 0;
}
