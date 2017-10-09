// node 为结点类型，其中 ch[0]表示左结点指针， ch[1]表示右结点指针
// pre 表示指向父亲的指针
void Rotate(node *x, int c) // 旋转操作， c=0 表示左旋， c=1 表示右旋
{
	node *y = x->pre;
	y->ch[! c] = x->ch[c];	//x节点左（右）旋时，一定是x节点的原左(右)儿子转移到x原父亲的右(左)儿子
	if (x->ch[c] != Null) x->ch[c]->pre = y;
	x->pre = y->pre;
	if (y->pre != Null)
			if (y->pre->ch[0] == y) y->pre->ch[0] = x; else y->pre->ch[1] = x;
	x->ch[c] = y, y->pre = x;
	if (y == root) root = x; // root 表示整棵树的根结点
}
void Splay(node *x, node *f) // Splay 操作，表示把结点 x 转到结点 f 的下面,f为NULL时，x转到根节点
{
	for ( ; x->pre != f; ){
		if (x->pre->pre == f) // 父结点的父亲即为 f，执行单旋转
					if (x->pre->ch[0] == x) Rotate(x, 1); else Rotate(x, 0);
		else
		{
			node *y = x->pre, *z = y->pre;
			if (z->ch[0] == y){
				if (y->ch[0] == x)
					Rotate(y, 1), Rotate(x, 1); // 一字形旋转
				else
					Rotate(x, 0), Rotate(x, 1); // 之字形旋转
			}
			else{
				if (y->ch[1] == x)
					Rotate(y, 0), Rotate(x, 0); // 一字形旋转
				else
					Rotate(x, 1), Rotate(x, 0); // 之字形旋转
			}
		}
	}
}
