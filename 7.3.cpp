#include<stdio.h>
int paodan[26];
int result[26];
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            scanf("%d",&paodan[i]);
            result[i]=0;
        }
        result[0]=1;
        for(int i=1;i<k;i++)
        {
            int _max=1;
            for(int j=i-1;j>=0;j--)
            {
                if(paodan[j]>=paodan[i])
                {
                    int tmp=result[j]+1;
                    if(tmp>_max)
                        _max=tmp;
                }
            }
            result[i]=_max;
        }
        int max_num=0;
        for(int i=1;i<k;i++)
        {
            if(result[i]>max_num)
                max_num=result[i];
        }
        printf("%d\n",max_num);
    }
    return 0;
}
