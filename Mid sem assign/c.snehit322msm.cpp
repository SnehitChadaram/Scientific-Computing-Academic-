//Snehit Chadaram
//R.No: 130123012

#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdio>
float cs(float a,float b,float c,float d,int i,float p)     // Calculating the values on cubic splines
{
  return (a+b*(p-i)+c*(p-i)*(p-i)+d*(p-i)*(p-i)*(p-i));
}

int main()
{
  int n, i, j;    float *x, *y , h = 1;  float temp;
  //cout<<"Enter the number of set of co-ordinates: ";    
  //******Make sure n is EVEN else the code misbehaves***
  cin>>n;
  float *a1, *b1, *c1, *d1, *a2, *b2, *c2, *d2;                     //Here 'i' corresponds to t which correspons 
  float *alpha1, *l1, *mu1, *z1, *alpha2, *l2, *mu2, *z2;           //to our actual 'x', so h is 1
  x = new float[n];                            //These are the functional values(pre calculated) of the splines 
  y = new float[n];
  a1 = new float[n];       a2 = new float[n];  // The splines are parametrized by the coefficients
  b1 = new float[n];       b2 = new float[n];  //So n-1 coefficient sets for n-1 splines
  c1 = new float[n];       c2 = new float[n];
  d1 = new float[n];       d2 = new float[n];
  alpha1 = new float[n];   alpha2 = new float[n];
  l1 = new float[n];       l2 = new float[n];
  mu1 = new float[n];      mu2 = new float[n];
  z1 = new float[n];       z2 = new float[n];

  for(i=0;i<n;i++)                             //Taking input the functional values of 2d in x and y
  {
      //cout<<"Enter the "<<i<<"'th co-ordinates: ";
      cin>>x[i]>>y[i];
      a1[i] = x[i];                         //Since the constant values equal the funtional values
      a2[i] = y[i];
  }
  for(i=1;i<(n-1);i++)                      //Computing the values of alpha for each dimension
  {
      alpha1[i] = (3)*(a1[i+1] - a1[i]) - (3)*(a1[i]-a1[i-1]);
      alpha2[i] = (3)*(a2[i+1] - a2[i]) - (3)*(a2[i]-a2[i-1]);
      //cout<<alpha1[i]<<" "<<alpha2[i]<<endl;
  }
  l1[0] = 1; mu1[0] = 0; z1[0] = 0;
  l2[0] = 1; mu2[0] = 0; z2[0] = 0;
  for(i=1;i<n;i++)                          //Computing by implementing the tridiagonal linear system
  { 
    l1[i] = 2*((i+1)-(i-1)) - mu1[i-1];
    mu1[i] = 1/l1[i];
    z1[i] = (alpha1[i] - z1[i-1])/l1[i];
    l2[i] = 2*((i+1)-(i-1)) - mu2[i-1];
    mu2[i] = 1/l2[i];
    z2[i] = (alpha2[i] - z2[i-1])/l2[i];
  }
  l1[n] = 1; mu1[n] = 0; z1[n] = 0;
  l2[n] = 1; mu2[n] = 0; z2[n] = 0;
  for(j=(n-1);j>=0;j--)
  {
      c1[j] = z1[j] - mu1[j]*c1[j+1];
      b1[j] = (a1[j+1] - a1[j]) - (c1[j+1] + 2*c1[j])/3;
      d1[j] = (c1[j+1] - c1[j])/(3);
      c2[j] = z2[j] - mu2[j]*c2[j+1];
      b2[j] = (a2[j+1] - a2[j]) - (c2[j+1] + 2*c2[j])/3;
      d2[j] = (c2[j+1] - c2[j])/(3);
      //cout<<a1[j]<<" "<<b1[j]<<" "<<c1[j]<<" "<<d1[j]<<endl;
      //cout<<a2[j]<<" "<<b2[j]<<" "<<c2[j]<<" "<<d2[j]<<endl;
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<100;j++)
    {
      float p, temp1, temp2;
      p = i+(j*0.01);
      cout<<cs(a1[i],b1[i],c1[i],d1[i],i,p)<<" ";       //Printing the co-ordinates for plotting
      cout<<cs(a2[i],b2[i],c2[i],d2[i],i,p)<<endl;
    }
  }
  return 0;
}