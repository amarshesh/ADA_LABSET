#include <iostream>

using namespace std;
class subset
{
public:
    int set[10],x[10],n,d,c;
    subset()
    {
        c=0;

    }
    void sumofsubset(int s , int k, int r)
    {
        x[k] =1;
        if(s+set[k]==d)
        {
            cout<<"subset = { ";
            for(int i=0;i<=k;i++)
            {
                if(x[i])
                {
                    cout<<set[i];
                    if(i!=k)
                    {
                        cout<<"," ;
                        c=1;
                    }
                }
            }
            cout<<" } \n " ;
        }
        else if(s+set[k]+set[k+1]<=d)
            sumofsubset(s+set[k],k+1,r-set[k]);
        if((s+r-set[k]>=d)&&(s+set[k+1]<=d))
        {
            x[k]=0;
            sumofsubset(s,k+1,r-set[k]);
        }
    }
    void check()
    {
        if(c==0)
            cout<<"Not possible " ;

    }
};

int main()
{
    int r=0;
    subset s;
    cout<<"enter the number of elements : "<<endl;
    cin>>s.n;
    cout<<"enter the elements \n "<<endl;
    for(int i=0;i<s.n;i++)
        cin>>s.set[i];
    cout<<"enter the sum "<<endl;
    cin>>s.d;
    for(int i=0; i<s.n;i++)
        s.x[i]=0;
    for(int i=0;i<s.n;i++)
        r+=s.set[i];
    cout<<endl;

    s.sumofsubset(0,0,r);
    s.check();
    return 0;
}