#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, ""); // �����ڵ� ����� ���� ������ ����

    wchar_t alphabet[1024];
    wchar_t alphabet2[1024];
    int len = 0;
    int i;
    wprintf(L"���ڿ��� �Է��ϼ���: \n");
    fgetws(alphabet, 1024, stdin); // gets ��� fgetws ���
    while (alphabet[len] != L'\0')
    {
        len++; // ���ڿ��� ���� ���
    }
    wprintf(L"�Ųٷ� ��� : ");
    for (i = len - 1; i >= 0; i--)
    {
        wprintf(L"%lc", alphabet[i]); // %c ��� %lc ���
    }
    wprintf(L"\n���ڿ��� �� : %d\n", len-1);

    for (int j = 0; j <= len; j++)
    {
        alphabet2[j] = alphabet[j]; // ���� ������ ���� ������ ����
    }
    wprintf(L"����� ���ڿ� : %ls\n", alphabet2); // %s ��� %ls ���

    return 0;
}
