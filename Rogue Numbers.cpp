  #include<iostream>
    #include<cstdio>
    #include<cstdlib>
    #include<string>
    #include<cstring>
    #include<cmath>
    #include<algorithm>
    #define LL long long
    using namespace std;
     
    LL n;
    int m,cnt;
    int s[20],p[20][102],ss[10];
    LL aa,f[262150][102],jc[20];
     
    int main()
    {
        int x=0,x1=0,x2=0;
        LL a=0;
        cin>>n>>m;
        a=n;while(a){s[++cnt]=a%10;a/=10;}
        jc[0]=1;for(int i=1;i<=cnt;i++) jc[i]=jc[i-1]*i;
        for(int i=1;i<=cnt;i++) for(int j=0;j<=100;j++){a=s[i];for(int k=1;k<=j;k++) a*=10;p[i][j]=a%m;}
        a=(1<<cnt)-1;for(int j=0;j<10;j++) ss[j]=0;
        x1=0;while(a){x1++;if(a&1) ss[s[x1]]++;a>>=1;}
        aa=1;for(int j=0;j<10;j++) aa*=jc[ss[j]];
        for(int i=1;i<(1<<cnt);i++)
        {
           a=i;x1=x2=0;while(a){if(a&1) x2++;a>>=1;x1++;}
           if(x2==1){f[i][s[x1]%m]=1;continue;}
           for(int j=0;j<x1;j++)
           {
                 a=i^(1<<j);
                 if(x2==cnt&&!s[j+1]) continue;
                 for(int k=0;k<m;k++)
                 {
                      f[i][k]+=f[a][(m+k-p[j+1][x2-1])%m];
              }
           }
        }
        cout<<f[(1<<cnt)-1][0]/aa<<endl;
        return 0;
    }
