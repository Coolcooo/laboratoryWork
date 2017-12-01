#include <iostream>
using namespace std;
int main()
{
    double a,b,c, Xn,Xo,dX,f;
    cin>>Xn>>Xo>>dX>>a>>b>>c;
    for (double x=Xn;x<=Xo;x+=dX)
    {
        if (x+c<0 && a!=0)
    	{
        	f=-a*x*x*x-b;
        }
        else if(x+c>0 && a==0)
        {
        	f=(x-a)/(x-c);
        }
        else
        {
        	f=(x/c)+(c/x);
        }
        if ((int(a)^int(b))|(int(a)^int(c))==0)
        {
        f=int(f);
        };
     cout <<"x= "<<x<<" f= "<<f<<endl;
    }
	return 0;
}
