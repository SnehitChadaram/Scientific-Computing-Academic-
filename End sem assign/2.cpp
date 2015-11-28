#include <iostream>
using namespace std;
int main()
{
    double Re, delx, a[100], b[100], c[100],d[100],x[100], t; 
    int n = 11, i;
    cin>>Re>>delx;
    for(i=0; i<n; i++)
    {
    	b[i]=2;
    	d[i]=0;
    }
    t = Re*delx/2;
    for(i=1;i<n;i++)
    {
    	a[i]=-1*(t+1);
    }
    for(i=0;i<n;i++)
    {
    	c[i]=t-1;
    }
    d[n-1] = 0 - c[n-1]*1;
    for(i=1;i<n;i++)
    {
    	a[i]= a[i]/b[i-1];
    	b[i] = b[i] - a[i]*c[i-1];
    	d[i] = d[i] - a[i]*d[i-1];
    }
    x[n-1] = d[n-1]/b[n-1];
    for(i=n-2;i>=0;i--)
    {
    	x[i] = (d[i] - c[i]*x[i+1])/b[i];
    }
    for(i=0;i<n;i++)
    	cout<<x[i]<<endl;
    return 0;
}