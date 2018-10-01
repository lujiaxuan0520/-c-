#include<iostream>
#include<math.h>
#include<string>
#include<stdio.h>
using namespace std;
class bigInteger
{
public:
    int digit[1000];
    int size;
    void init()
    {
        for(int i=0;i<1000;i++)
        {
            digit[i]=0;
            size=0;
        }
    }
    void setInteger(string str)
    {
        size=ceil(str.size()/4.0);
        int index=str.size()-4;
        int c=0;
        while(index>=0)
        {
            int q=str[index]-'0';
            int b=str[index+1]-'0';
            int s=str[index+2]-'0';
            int g=str[index+3]-'0';
            int sum=g+s*10+b*100+q*1000;
            digit[c]=sum;
            c++;
            index-=4;
        }
        if(index==-4) return;
        else if(index==-3)
            digit[c]=str[0]-'0';
        else if(index==-2)
            digit[c]=10*(str[0]-'0')+(str[1]-'0');
        else if(index==-1)
            digit[c]=100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0');
        return;
    }
    bigInteger operator+(const bigInteger &b)
    {
        int carry=0;
        int maxSize=max(this->size,b.size);
        bigInteger result;
        result.init();
        for(int i=0;i<maxSize;i++)
        {
            int tmp=this->digit[i]+b.digit[i]+carry;
            result.digit[i]=tmp%10000;
            result.size++;
            if(tmp>=10000)
                carry=1;
            else
                carry=0;
        }
        if(carry==1)
        {
            result.digit[maxSize]=1;
            result.size++;
        }

        return result;
    }
    bigInteger operator*(const int &x)
    {
        int carry=0;
        bigInteger result;
        result.init();
        result.size=size;
        for(int i=0;i<size;i++)
        {
            long long sum=x*digit[i]+carry;
            if(sum>=10000)
            {
                result.digit[i]=sum%10000;
                carry=sum/10000;
            }
            else
            {
                result.digit[i]=sum;
                carry=0;
            }
        }
        if(carry!=0)
        {
            result.digit[size]=carry;
            result.size++;
        }
        return result;
    }
    int operator%(const int &n)
    {
        int yushu=0;
        for(int i=size-1;i>=0;i--)
        {
            int beichushu=yushu*10000+digit[i];
            //int shan=beichushu/n;
            yushu=beichushu%n;
        }
        return yushu;
    }
    bigInteger operator/(const int &n)
    {
        bigInteger result;
        result.init();
        int mark=0;
        int yushu=0;
        for(int i=size-1;i>=0;i--)
        {
            int beichushu=yushu*10000+digit[i];
            int shan=beichushu/n;
            result.digit[i]=shan;
            if(shan!=0&&mark==0)
            {
                mark=1;
                result.size=i+1;
            }
            yushu=beichushu%n;
        }
        result.size=result.countSize();
        return result;
    }
    bool isZero()
    {
        for(int i=0;i<size;i++)
        {
            if(digit[i]!=0) return false;
        }
        return true;
    }
    int countSize()
    {
        int count=0;
        for(int i=0;i<1000;i++)
        {
            if(digit[i]!=0)
                count++;
        }
        return count;
    }
    void printInteger()
    {
        for(int i=size-1;i>=0;i--)
        {
            if(i!=size-1)
                printf("%04d",digit[i]);
            else
                cout<<digit[i];
        }
        cout<<endl;
    }
};
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        string X;
        cin>>X;
        bigInteger s;
        s.init();
        s.setInteger("1");
        bigInteger sum;
        sum.init();
        sum.setInteger("0");
        int mark=0;
        for(int i=X.size()-1;i>=0;i--)
        {
            int num;
            if(X[i]>='0'&&X[i]<='9')
                num=X[i]-'0';
            else if(X[i]>='A'&&X[i]<='Z')
                num=X[i]-'A'+10;
            if(mark==0)
            {
                s.setInteger("1");
                mark=1;
            }
            else
            {
                s=s*m;
            }
            sum=sum+s*num;
        }
        //已转换为10进制
        char res[1000]={0};
        for(int i=0;i<1000;i++)
            res[i]='\n';
        int size=0,i=0;
        while(!sum.isZero())
        {
            int x=sum%n;
            if(x<=9)
            {
                res[i]='0'+x;
                i++;
                size++;
            }
            else
            {
                res[i]=x-10+'a';
                i++;
                size++;
            }
            sum=sum/n;
        }
        for(int i=size-1;i>=0;i--)
            cout<<res[i];
        cout<<endl;
    }
    return 0;
}

