#include <stdio.h>
#include <ctype.h>
#include <string.h>

int password_check2(char* password) 
{
    int digitIs = 0, alphaIs = 0, specialIs = 0;
    char allowed_special[] = { '!', '_' };

    for (int i = 0; i < strlen(password); i++) 
	{
        if (isdigit(password[i])) 
		{
            digitIs = 1;
        }
        else if (isalpha(password[i])) 
		{
            alphaIs = 1;
        }
        else 
		{
            for (int j = 0; j < sizeof(allowed_special); j++) 
			{
                if (password[i] == allowed_special[j]) 
				{
                    specialIs = 1;
                    break;
                }
            }
        }
    }
    if (digitIs && alphaIs && specialIs && strlen(password) >= 8)
        return 1;
    else
        return 0;
}

int main() 
{
    char* keyInStr[200] = { 0 };

    while (1) 
	{
        gets(keyInStr);

        if (password_check2(keyInStr)) 
		{
            printf("잘 하였습니다\n");
            break;
        }
        else
            printf("앗 무언가 빠졌네요, 숫자와 영어와 특수문자를 잘 조합하여 다시 입력해 주세요\n");
    }

    return 0;
}