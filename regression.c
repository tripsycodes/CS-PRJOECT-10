#include <math.h>
#include <stdio.h>
#define float double
int main()
{
    int n, i;
    float x, y, m, c, d;
    float sumx = 0, sumxsq = 0, sumy = 0, sumxy = 0;
    float sumysq = 0;
    float mae = 0;
    float mse = 0;
    printf("enter the number of values for n:");
    scanf("%d", &n);
    float ax[n];
    float ay[n];
    float p = n;
    for (i = 0; i < n; i++)
    {
        printf("enter values of x and y\n");
        scanf("%lf%lf", &x, &y);
        sumx = sumx + x;
        sumxsq = sumxsq + (x * x);
        sumy = sumy + y;
        sumxy = sumxy + (x * y);
        sumysq = sumysq + (y * y);
        ax[i] = x;
        ay[i] = y;
    }
    d = p * sumxsq - sumx * sumx;
    m = (p* sumxy - sumx * sumy) / d;
    c = (sumy * sumxsq - sumx * sumxy) / d;
  while(1)
  {
    printf("1.compute sum\n");
    printf("2.find best fitting line\n");
    printf("3.end\n");
    int num;
    scanf("%d", &num);
    if (num == 1)
    {
        printf("sum x = %lf\n", sumx);
        printf("sum y = %lf\n", sumy);
        printf("sum xy = %lf\n", sumxy);
        printf("sum xsq = %lf\n", sumxsq);
        printf("sum ysq = %lf\n", sumysq);
    }
    else if (num == 2)
    {
        float p = n;
        printf("the best fitting line is y = %lfx+%lf\n", m, c);
        for (int i = 0; i < n; i++)
        {
            mae += abs(ay[i] - (m * ax[i] + c));
            mse += (ay[i] - (m * ax[i] + c)) * (ay[i] - (m * ax[i] + c));
        }
        printf("mean absolute error = %lf\n", mae / p);
        printf("mean squared error = %lf\n", mse / p);
    }
    else if(num==3)
    {
        return 0;
    }
  }
}