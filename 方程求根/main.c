//
//  main.c
//  方程求根
//
//  Created by tianyu on 2020/5/3.
//  Copyright © 2020 tianyu. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double f(double x)
{
    double result;
    result = x*x*x-x-1;
    return result;
}
void Dicphoni()
{
    double x;
    double a = 1;
    double b = 1.5;
    double tol = 0.5e-5;
    int n = 20;//最大迭代次数20
    for (int i = 0;i<n;i++)
    {
        x = (a+b)/2;
        if (f(x)==0)
        {
            printf("方程的根为:%lf",x);
        }
        if (f(x)*f(a)<0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
        if (fabs(a-b)<tol)
        {
            printf("方程的根在%lf到%lf之间\n",a,b);
            break;
        }
    }
}

double g(double x)
{
    double result;
    result = x*exp(x)-1;
    return result;
}
double gd(double x)
{
    double result;
    result = (1+x)*exp(x);
    return result;
}
void Newton()
{
    double x0 = 0.5;
    double tol = 1e-5;
    int n = 20;//最大迭代次数20
    double x;
    for (int i = 0;i<n;i++)
    {
        if(gd(x0)==0)
        {
            printf("迭代失败!");
            break;
        }
        x = x0-g(x0)/gd(x0);
        if (fabs(x-x0)<tol)
        {
            break;
        }
        printf("x%d = %lf\n",i+1,x);
        x0 = x;
    }
}
void String_Interception()
{
    double x0 = 0.5;
    double x1 = 0.6;
    double tol = 1e-5;
    int n = 20;//最大迭代次数20
    double x;
    for (int i = 0;i<n;i++)
    {
        if(gd(x0)==0)
        {
            printf("迭代失败!");
            break;
        }
        x = x1-g(x1)/(g(x1)-g(x0))*(x1-x0);
        if (fabs(x-x1)<tol)
        {
            break;
        }
        printf("x%d = %lf\n",i+2,x);
        x0 = x1;
        x1 = x;
    }
}
int main(int argc, const char * argv[]) {
    String_Interception();
    return 0;
}
