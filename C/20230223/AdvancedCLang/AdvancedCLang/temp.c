#include <stdio.h>
/*
�����������K���ȳ�Hello
�����������K���ȳ�Helloo
�����������K���ȳ�Hello�H
�����������K���ȳ�Hello�Ho
sentense1 = "����������"
sentense1 = "�����������K���ȳ�Hello�Ho" (Ȥ�� �� �� ���ڿ�)
"�ȳ��ϼ���? Hello World! �̰��� �׽�Ʈ�Դϴ�."
*/
int main()
{
    char sentense1[1024] = { NULL };
    char sentense2[1024] = { NULL };

    printf("���ڿ�1 �Է����ּ���.");
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
                printf("��!(�ٵ� �̷� ��Ȳ �߻� �� �ϴ� �� Ȯ�� ��)");
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

