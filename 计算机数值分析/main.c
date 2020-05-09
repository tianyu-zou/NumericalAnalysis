//
//  main.c
//  计算机数值分析
//
//  Created by tianyu on 2020/4/27.
//  Copyright © 2020 tianyu. All rights reserved.
//

#include <stdio.h>

double lagrange()
{
    double x[10];
    double y[10];
    double l[10];//保存差值基数
    double x0 = 0;
    double y0 = 0;
    int n;//插值次数
    //录入相关信息
    scanf("%d",&n);
    for (int i = 0;i<n+1;i++)
    {
        scanf("%lf %lf",&x[i],&y[i]);
    }
    scanf("%lf",&x0);
    //计算插值基函数和y
    for (int i = 0;i<n+1;i++)
    {
        l[i] = 1;
        for (int j = 0;j<n+1;j++)
        {
            if (j!=i)
            {
                //累成求插值基函数
                l[i] = (x0-x[j])/(x[i]-x[j])*l[i];
            }
        }
        //累加求出函数在点x0的近似值
        y0 += l[i]*y[i];
    }
    return y0;
}

double Newton()
{
    double x[10];
    double y[10];
    double l[10][10];//保存差商表
    double x0 = 0;
    double y0 = 0;
    int n;//插值次数
    //录入相关信息
    scanf("%d",&n);
    for (int i = 0;i<n+1;i++)
    {
        scanf("%lf %lf",&x[i],&y[i]);
    }
    scanf("%lf",&x0);
    //为差商表赋初值
    for (int i = 0;i<n+1;i++)
    {
        l[i][0] = y[i];
    }
    //计算差商表
    for (int i = 1;i<n+1;i++)
    {
        for (int j = i;j<n+1;j++)
        {
            l[j][i] = (l[j][i-1]-l[j-1][i-1])/(x[j]-x[j-i]);
        }
    }
    //计算函数值
    double m = 1;//保存累成的结果
    y0 = y[0];
    for (int i = 1;i<n+1;i++)
    {
        m = m*(x0-x[i-1]);
        y0+=l[i][i]*m;
    }
    return y0;
}

double CurveFit()
{
    double x[10];
    double y[10];
    double x0 = 0;
    double y0 = 0;
    double sumx = 0;//所以x的和
    double sumy = 0;//所有y的和
    double sumxy = 0;//所有x与y乘积的和
    double sumx2 = 0;//所有x的平方的和
    double a,b;//系数
    int n;//数据个数
    //录入相关信息并计算数据的和
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        scanf("%lf %lf",&x[i],&y[i]);
        sumx+=x[i];
        sumy+=y[i];
        sumx2+=x[i]*x[i];
        sumxy+=x[i]*y[i];
    }
    scanf("%lf",&x0);
    //利用公式计算出a,b的值
    a = (sumy*sumx2-sumx*sumxy)/(n*sumx2-sumx*sumx);
    b = (sumx*sumy-sumxy*n)/(n*sumx2-sumx*sumx)*(-1);
    printf("曲线拟合方程: y = %.4lf + %.4lfx\n",a,b);
    y0 = a+b*x0;
    printf("对应的函数值:%.4lf\n",y0);
    return y0;
}
int main(int argc, const char * argv[]) {
    double reasult;
    reasult =  CurveFit();
   // printf("%.4lf\n",reasult);
    return 0;
}
