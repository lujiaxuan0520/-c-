#include<stdio.h>
int main()
{
    int h;
    while(scanf("%d",&h)!=EOF)
    {
        int zongshu=3*h-2;
        for(int i=1;i<=h;i++)
        {
            int xinghaoshu=h+2*(i-1);
            for(int j=0;j<zongshu-xinghaoshu;j++)
                printf(" ");
            for(int j=0;j<xinghaoshu;j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
