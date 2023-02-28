#include <stdio.h>
/*
ァケずつ하핳ㅋ안녕Hello
ァケずつ하핳ㅋ안녕Helloo
ァケずつ하핳ㅋ안녕Hello핰
ァケずつ하핳ㅋ안녕Hello핰o
sentense1 = "あいうエオ"
sentense1 = "ァケずつ하핳ㅋ안녕Hello핰o" (혹은 더 긴 문자열)
"안녕하세요? Hello World! 이것은 테스트입니다."
*/
int main()
{
    char sentense1[1024] = { NULL };
    char sentense2[1024] = { NULL };

    printf("문자열1 입력해주세요.");
    gets(sentense1);

    printf("\n%s %s\n", sentense1, sentense2);
    int count = 0;
    for (count = 0; sentense1[count] != NULL; count++);
    int i = 0;
    int len = count-1;
    for (i = 0; sentense1[i] != NULL; i++, len--)
    {
        if (sentense1[i] >= 0 && sentense1[i] <= 127)
        {
            sentense2[len] = sentense1[i];
        }
        else
        {

            if (len <= 0)
            {
                printf("끝!(근데 이런 상황 발생 안 하는 거 확인 함)");
                printf("len=%d\n", len);
                break;
            }

            sentense2[len-1] = sentense1[i];
            sentense2[len] = sentense1[i+1];
            i++;
            len--;


        }

    }
    printf("\n%s %s\n", sentense1, sentense2);
    return 0;
}

