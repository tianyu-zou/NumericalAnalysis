//
//  main.c
//  常微分方程
//
//  Created by tianyu on 2020/5/2.
//  Copyright © 2020 tianyu. All rights reserved.
//

#include <stdio.h>


void Euler()
{
    double x,y;
    double yp,yc;
    double h;//步长
    int n;//步数
    scanf("%d",&n);
    //为初始条件赋值
    x = 0;
    y = 1;
    h = 0.1;
    //逐步计算
    for(int i = 0;i<n;i++)
    {
        yp = y+h*(y-2*x/y);
        x += h;
        yc = y+h*(yp-2*x/yp);
        y = (yp+yc)/2;
        printf("y(%.1lf) = %lf\n",x,y);
    }
}

void Runge_Kutta()
{
    double x,y;
    double k1,k2,k3,k4;
    double h;//步长
    int n;//步数
    scanf("%d",&n);
    //为初始条件赋值
    x = 0;
    y = 1;
    h = 0.1;
    //逐步计算
    for(int i = 0;i<n;i++)
    {
        k1 = y-2*x/y;
        k2 = y+h*k1/2-(2*x+h)/(y+h*k1/2);
        k3 = y+h*k2/2-(2*x+h)/(y+h*k2/2);
        k4 = y+h*k3-2*(x+h)/(y+h*k3);
        x += h;
        y = y+h*(k1+2*k2+2*k3+k4)/6;
        printf("y(%.1lf) = %lf\n",x,y);
    }
}
int main(int argc, const char * argv[]) {
    Runge_Kutta();
    return 0;
}
