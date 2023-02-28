#include <stdio.h>

int main() {
    int n;
    printf("몇번째항?\n");
    scanf("%d", &n); // 입력 받은 수열의 N번째 항
    char s[100000] = { '1', '\0' }; // 문자열로 수열을 저장할 배열 (초기값으로 "1"을 저장)
    char next[100000]; // 다음 수열을 저장할 배열
    for (int i = 1; i < n; i++) 
	{
        int count = 1; // 현재 수를 세는 변수
        char current = s[0]; // 현재 수
        int j = 0; // 현재 수열의 인덱스
        int k = 0; // 다음 수열의 인덱스
        while (current != '\0') { // 현재 수열의 끝까지 반복
            current = s[j]; // 현재 수를 가져옴
            if (current == s[j + 1]) { // 다음 수와 같으면
                count++; // 수를 세어줌
            }
            else { // 다음 수와 다르면
                next[k++] = current; // 현재 수를 다음 수열에 추가
                next[k++] = count + '0'; // 수를 문자열로 변환해서 다음 수열에 추가
                count = 1; // 다시 수를 세기 시작함
            }
            j++; // 다음 인덱스로 이동
        }
        next[k] = '\0'; // 다음 수열의 끝에 null 문자 추가
        for (int l = 0; l <= k; l++) {
            s[l] = next[l]; // 다음 수열을 현재 수열로 복사
        }
    }
    printf("%s\n", s); // 수열의 N번째 항 출력
    return 0;
}
