#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
 
int main(void)
{
    float a[250][250], delx, beta, max=0, tol=0.0001, temp=0, w, opt, ep;
    int n = 0, m = 0; int i = 0, j = 0, count=0; 
    cin>> delx >> beta >> w;            //w is the omega used while updating
    n = int(4/delx + 1);
    m = int(beta/delx + 1);

    ep = pow((cos(M_PI/n) + beta*beta*cos(M_PI/m))/(1+beta*beta),2);
    opt = 2*((1-sqrt(1-ep))/ep);        //This is the optimum omega theoretically

    for (i = 0; i < m; i++)
    {
        for (j=0; j<n; j++)
        {
            if(i==0)
            {
                a[i][j] =  200*delx*j*(delx*j-4);
            }
        }
    }
    while(1)
    {
        max = (a[2][1] + beta*beta*a[1][2] + a[0][1] + beta*beta*a[1][0]-2*(1+beta*beta)*a[1][1])/(2*(1+beta*beta));  
        for (i=1; i < m-1; i++)
        {
            for (j=1; j < n-1; j++)
            {
                temp = (a[i+1][j] + beta*beta*a[i][j+1] + a[i-1][j] + beta*beta*a[i][j-1]-2*(1+beta*beta)*a[i][j])/(2*(1+beta*beta));
                a[i][j] = a[i][j] + w*temp;
                if(fabs(max)<fabs(temp))
                    max = fabs(temp);
            }
        }
        count++;
        if(max < tol)
            break;
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<opt<<endl;
    cout<<count<<endl;                      //count is the number of interation 
                                            //for stabilization given a tolerance
    return 0;
}