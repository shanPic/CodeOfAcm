// node 为结点类型，其中 ch[0]表示左结点指针， ch[1]表示右结点指针
// pre 表示指向父亲的指针
void Rotate(node *x, int c) // 旋转操作， c=0 表示左旋， c=1 表示右旋
{
	node *y = x->pre;
	Push_Down(y), Push_Down(x);
// 先将 Y 结点的标记向下传递（因为 Y 在上面），再把 X 的标记向下传递
	y->ch[! c] = x->ch[c];
	if (x->ch[c] != Null) x->ch[c]->pre = y;
	x->pre = y->pre;
	if (y->pre != Null)
			if (y->pre->ch[0] == y) y->pre->ch[0] = x; else y->pre->ch[1] = x;
	x->ch[c] = y, y->pre = x, Update(y); // 维护 Y 结点
	if (y == root) root = x; // root 表示整棵树的根结点
}
void Splay(node *x, node *f) // Splay 操作，表示把结点 x 转到结点 f 的下面
{
	for (Push_Down(x) ; x->pre != f; ) // 一开始就将 X 的标记下传
		if (x->pre->pre == f) // 父结点的父亲即为 f，执行单旋转
					if (x->pre->ch[0] == x) Rotate(x, 1); else Rotate(x, 0);
		else
		{
			node *y = x->pre, *z = y->pre;
			if (z->ch[0] == y)
				if (y->ch[0] == x)
					Rotate(y, 1), Rotate(x, 1); // 一字形旋转
				else
					Rotate(x, 0), Rotate(x, 1); // 之字形旋转
			else if (y->ch[1] == x)
				Rotate(y, 0), Rotate(x, 0); // 一字形旋转
			else
				Rotate(x, 1), Rotate(x, 0); // 之字形旋转
		}
	Update(x); // 最后再维护 X 结点
}
// 找到处在中序遍历第 k 个结点，并将其旋转到结点 f 的下面
void Select(int k, node *f)
{
	int tmp;
	node *t;
	for (t = root; ; ) // 从根结点开始
	{
		Push_Down(t); // 由于要访问 t 的子结点， 将标记下传
		tmp = t->ch[0]->size; // 得到 t 左子树的大小
		if (k == tmp + 1) break; // 得出 t 即为查找结点， 退出循环
		if (k <= tmp) // 第 k 个结点在 t 左边，向左走
			t = t->ch[0];
		else // 否则在右边，而且在右子树中，这个结点不再是第 k 个
			k -= tmp + 1, t = t->ch[1];
	}
	Splay(t, f); // 执行旋转
}