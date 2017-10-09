#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55000;
const int INF = 0x3f3f3f3f;
const int eps = 1e-8;
int sgn(double x)//判断浮点数x的符号,0返回0，正数返回1，负数返回-1
{
    if (fabs(x) < eps)return 0;
    if (x < 0)return -1;
    else return 1;
}
struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y)
    {
        x = _x; y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }

    double operator ^(const Point &b)const //叉积
    {
        return x * b.y - y * b.x;
    }

    double operator *(const Point &b)const //点积
    {
        return x * b.x + y * b.y;
    }
    bool operator ==(const Point &b)const
    {
        return (x == b.x) && (y == b.y);
    }
    bool operator !=(const Point&b)const
    {
        return (x != b.x) || (y != b.y);
    }
    void input() { //点的输入
        scanf("%d%d", &x, &y);
    }
};
struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e) {
        s = _s; e = _e;
    }
};

double dist(Point& a, Point& b) //*两点间距离
{
    return sqrt((a - b) * (a - b));
}
Point zero;
int k;
bool cmp(Point& a, Point &b)
{
    double tmp = (a - zero) ^ (b - zero);
    if (sgn(tmp) > 0) {
        return 1;
    }
    if (sgn(tmp) == 0 && sgn(dist(a, zero) - dist(b, zero)) <= 0)
        return 1;
    return 0;
}
int n;
Point a[MAXN];
int l[MAXN];
int cou = 0;
void Gram()
{
    cou = 0;
    swap(a[0], a[k]);
    sort(a + 1, a + n, cmp);
    if (n == 1) {
        l[cou++] = 0;
        return;
    }
    if (n == 2) {
        l[cou++] = 0;
        l[cou++] = 1;
        return;
    }
    l[cou++] = 0;
    l[cou++] = 1;
    for (int i = 2; i < n; i++) {
        while (sgn((a[i] - a[l[cou - 2]]) ^ (a[l[cou - 1]] - a[l[cou - 2]])) != -1) {
            cou--;
        }
        l[cou++] = i;
    }
}
int main()
{
    //freopen("data.in", "r", stdin);
    while (~scanf("%d", &n)) {
        zero.x = zero.y = INF;
        for (int i = 0; i < n; i++) {
            a[i].input();
            if (a[i].y < zero.y) {
                zero.x = a[i].x;
                zero.y = a[i].y;
                k = i;
            }
            else if (a[i].y == zero.y) {
                if (a[i].x < zero.x) {
                    zero.x = a[i].x;
                    zero.y = a[i].y;
                    k = i;
                }
            }
        }
        //cout<<zero.x<<"\t"<<zero.y<<endl;
        Gram();
//        for(int i=0;i<n;i++)
//        cout<<a[i].x<<"\t"<<a[i].y<<endl;
//        cout<<"--------------------"<<endl;
//        for(int i=0;i<cou;i++){
//            cout<<l[i]<<"\t"<<a[l[i]].x<<"\t"<<a[l[i]].y<<endl;
//        }
        //cout<<cou<<endl;
        // double one=-1,second=-1;
        // Point x,y,z;
        // for(int i=0;i<cou;i++){
        //     for(int j=0;j<cou;j++){
        //         double tmp=dist(a[l[i]],a[l[j]]);
        //         if(tmp>one){
        //             one=tmp;
        //             x=a[l[i]];
        //             y=a[l[j]];
        //         }
        //     }
        // }
        // for(int i=0;i<cou;i++){
        //     if(a[l[i]]!=x&&a[l[i]]!=y){
        //         double tmp1=dist(a[l[i]],x);
        //         double tmp2=dist(a[l[i]],y);
        //         if(tmp1>second){
        //             z=a[l[i]];
        //             second=tmp1;
        //         }
        //         if(tmp2>second){
        //             z=a[l[i]];
        //             second=tmp2;
        //         }
        //     }
        // }
        //cout<<x.x<<"\t"<<x.y<<"\t"<<y.x<<"\t"<<y.y<<"\t"<<z.x<<"\t"<<z.y<<endl;
        double res = -3;
        for (int i = 0; i < cou; i++) {
            for (int j = 0; j < cou; j++) {
                for (int k = 0; k < cou; k++) {
                    double tmp = fabs((a[l[i]] - a[l[j]]) ^ (a[l[k]] - a[l[j]]));
                    if (tmp > res) {
                        res = tmp;
                    }
                }
            }
        }
        res = res / 2 ;
        // printf("%.2lf\n",fabs((x-y)^(x-z))/2+0.005);
        printf("%.2lf\n", res);
    }
}
