const int MAXN = 55000;
const int INF = 0x3f3f3f3f;
const int eps = 1e-8;
int sgn(double x)//�жϸ�����x�ķ���,0����0����������1����������-1
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

    double operator ^(const Point &b)const //���
    {
        return x * b.y - y * b.x;
    }

    double operator *(const Point &b)const //���
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
    void input() { //�������
        scanf("%d%d", &x, &y);
    }
};
struct Line {   //�߶�
    Point s, e;
    Line() {}
    Line(Point _s, Point _e) {
        s = _s; e = _e;
    }
};

double dist(Point& a, Point& b) //*��������
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


int n;  //�������
Point a[MAXN];//�洢�������
int l[MAXN];//ʹ������ģ�����
int cou = 0;//��¼���д�С
Point zero;int k;//����������ʱ�ҵ�y������С�ĵ�zero����Ϊ���������ǵ�ԭ�㣬kΪzero��a���飨�洢������ݣ��е�λ��

void Gram()//Gram�㷨
{
    cou = 0;
    swap(a[0], a[k]);       //��zero�Ƶ�0��λ�ã���Ϊ�������Ƿ��ְ��������cmp����sortʱ��ʱ�޷���zero�ŵ�0������ֱ�ӽ�zero�Ƶ�0��
    sort(a + 1, a + n, cmp);//����ʱֱ�Ӵ�1��ʼ����
    //����nΪ1��2�����
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
