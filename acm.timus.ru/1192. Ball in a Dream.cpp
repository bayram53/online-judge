#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int V;
    double a;
    double K;
    scanf("%d %Lf %Lf", &V, &a, &K);
    double s=0;
    if(a!=0&&a!=90)
    {
        double p = a*3.1415926535/180;
        double Vy = V*sin(p);
            double Vx = V*cos(p);
        s = Vx*Vy*0.2/(1-1/K);
    }

    printf("%.2f",s);



    return 0;
}
