#include<iostream>
using namespace std;
const int M=100010;
struct node{
    int sum;
    int left;
    int right;
}tree[4*M];//�߶�������
int a[M];//ԭʼ��������
//*********************//
void build(int id,int left,int right)//�ݹ齨��
{
    if(left==right){
        tree[id].left=left;
        tree[id].right=right;
        tree[id].max=a[left];
        tree[id].sum=a[left];
    }
    else{
        build(2*id,left,(left+right)/2);
        build(2*id+1,(left+right)/2,right);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
    }
}
void update(int id,int pos,int val)//����ĳ���ڵ��ֵ
{
    if(tree[id].left==tree[id].right){
        tree[id].sum=val;
        tree[id].max=val;
    }
    else{
        int mid=(tree[id].left+tree[id].right)/2;
        if(pos<=mid){
            update(id*2,pos,val);
        }
        else{
            update(id*2+1,pos,val);
        }
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
    }
}
int query(int id,int ql,int qr)//��ѯĳ�����ڵ����ֵ
{
    if(tree[id].left==ql&&tree[id].right==qr){
        return tree[id].max;
    }
    else{
        int mid=(tree[id].left+tree[id].right)/2;
        if(qr<=mid){
            return query(id*2,ql,qr);
        }
        else if(ql>mid){
            return query(id*2+1,ql,qr);
        }
        else{
            return query(id*2,ql,mid)+query(id*2+1,mid,qr);
        }
    }
}
int main()
{

}
