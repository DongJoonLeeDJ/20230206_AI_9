#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, ""); // 유니코드 출력을 위한 로케일 설정

    wchar_t alphabet[1024];
    wchar_t alphabet2[1024];
    int len = 0;
    int i;
    wprintf(L"문자열을 입력하세요: \n");
    fgetws(alphabet, 1024, stdin); // gets 대신 fgetws 사용
    while (alphabet[len] != L'\0')
    {
        len++; // 문자열의 길이 계산
    }
    wprintf(L"거꾸로 출력 : ");
    for (i = len - 1; i >= 0; i--)
    {
        wprintf(L"%lc", alphabet[i]); // %c 대신 %lc 사용
    }
    wprintf(L"\n문자열의 수 : %d\n", len-1);

    for (int j = 0; j <= len; j++)
    {
        alphabet2[j] = alphabet[j]; // 다음 수열을 현재 수열로 복사
    }
    wprintf(L"복사된 문자열 : %ls\n", alphabet2); // %s 대신 %ls 사용

    return 0;
}
