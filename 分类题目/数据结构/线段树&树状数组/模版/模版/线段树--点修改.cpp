const int M;
struct node{
    int max;
    int sum;
    int left;
    int right;
}tree[4*M];//线段树数组
int a[M];//原始数据数组
//*********************//
void build(int id,int left,int right)//递归建树
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
void update(int id,int pos,int val)//更新某个节点的值
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
int query(int id,int ql,int qr)//查询某区间内的最大值
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

