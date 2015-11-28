#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
 
int main(void)
{
    float a[250][250], delx, beta, max=0, tol=0.0001, temp=1, val,itemp, jtemp ;
    int n = 0, m = 0; int i = 0, j = 0, k = 0; 
    cin>> delx >> beta;
    n = int(4/delx + 1);
    m = int(beta/delx + 1);

    for (i = 0; i < m; i++)
    {
        for (j=1; j<n; j++)
        {   
        	a[i][j]=0;
        	temp=1;
        	int k=1;
            while(fabs(temp) > 1e-5)
            {
                itemp = i*delx/beta;
                jtemp = j*delx;
                val = k*M_PI;
                temp = -2*(12800/pow(val,3))*(1/sinh(-1*val/4))*sin(val*jtemp/4)*sinh(val*(itemp-1)/4);
                a[i][j] = a[i][j] + temp;
                k+=2;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}