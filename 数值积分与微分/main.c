//
//  main.c
//  数值积分与微分
//
//  Created by tianyu on 2020/5/1.
//  Copyright © 2020 tianyu. All rights reserved.
//

#include <stdio.h>
#include <math.h>
//利用书上的习题
//积分函数    f(x) = sin(x)/x
double f(double x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return sin(x) / x;
    }
}

//梯形法递推算法
//参数：区间 [a,b]，误差阈值 w
void Trapezoid(double a,double b,double w)
{
    
    double h = b - a;     // h 代表步长
    double T1, T2; // T1，T2 代表积分值，
    double S;     //S 代表内切分点函数值总和
    double x;             // x 代表除区间边界外的内切分点
    int k = 0;            // 迭代次数(设置最大迭代次数20)
    T1 = h/2*(f(a)+f(b));
    while (k<20)
    {
        printf("T%.1f = %lf\n",pow(2, k),T1);
        S = 0;
        x = a+h/2;
        while (x<b)
        {
            S += f(x);
            x += h;
        }
        T2 = T1/2+h/2*S;
        if (fabs( T2-T1)<w)
        {
            printf("复化梯形算法:%lf\n",T2);
            break;
        }
        T1 = T2;
        h /= 2;
        k++;
    }
    
}

void Romberg(double a, double b, double w)
{
    double h = b - a;
    double S, x;
    
    //计数器
    int k = 1;

    //梯形、辛普森、科特斯、龙贝格公式
    double T1, T2;
    double S1, S2;
    double C1 = 0.0, C2;
    double R1 = 0.0, R2 = 0.0;

    T1 = 0.5*h*(f(a) + f(b));

    //循环，直到误差足够小
    while (k<20) {

        //初始化
        x = a + 0.5*h;
        S = 0;

        //将各切分点的函数值累加至累加 S
        while (x < b) {
            S += f(x);
            x += h;
        }

        T2 = 0.5*T1 + 0.5*h*S;
        printf("T%.1f = %lf\n",pow(2, k),T2);

        //梯形公式外推辛普森公式
        S2 = T2 + (T2 - T1) / 3;
        printf("S%.1f = %lf\n",pow(2, k-1),S2);
        if (k == 1) {
            //步长对半
            k += 1;  h = 0.5*h;
            T1 = T2;  S1 = S2;
        }
        else {
            //辛普森公式外推科特斯公式
            C2 = S2 + (S2 - S2) / 15;
            printf("C%.1f = %lf\n",pow(2, k),C2);
           
            if (k == 2) {
                C1 = C2;
                //步长对半
                k += 1;  h = 0.5*h;
                T1 = T2;  S1 = S2;
            }
            else {
                //科特斯公式外推龙贝格公式
                R2 = C2 + (C2 - C1) / 63;
                printf("R%.1f = %lf\n",pow(2, k-3),R2);
                if (k == 3) {
                    R1 = R2;
                    C1 = C2;
                    //步长对半
                    k += 1;  h = 0.5*h;
                    T1 = T2;  S1 = S2;
                }
                else {
                    if (fabs(R2 - R1) < w) break;
                    else {
                        R1 = R2;
                        C1 = C2;
                        //步长对半
                        k += 1;  h = 0.5*h;
                        T1 = T2;  S1 = S2;
                    }
                }
            }
        }
    }

    //打印最终结果
    printf("龙格贝算法:%lf\n",R2);
}

int main(int argc, const char * argv[]) {
    Romberg(0, 1,1e-6);
    return 0;
}
