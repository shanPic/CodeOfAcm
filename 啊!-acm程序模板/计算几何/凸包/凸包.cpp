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
struct Line {   //线段
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


int n;  //点的总数
Point a[MAXN];//存储点的数据
int l[MAXN];//使用数组模拟队列
int cou = 0;//记录队列大小
Point zero;int k;//在数据输入时找到y坐标最小的点zero，作为极角排序是的原点，k为zero在a数组（存储点的数据）中的位置

void Gram()//Gram算法
{
    cou = 0;
    swap(a[0], a[k]);       //将zero移到0的位置，因为在排序是发现按照上面的cmp函数sort时有时无法将zero排到0，所以直接将zero移到0，
    sort(a + 1, a + n, cmp);//排序时直接从1开始排序
    //特判n为1或2的情况
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
