#include<stdio.h>
#include<string.h>
struct haha
{
	int mar[10][10];
}a,b,c;
int n,m;
struct haha multi(struct haha a1,struct haha a2)
{
	struct haha temp;
	int i,j,k;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			temp.mar[i][j]=0;
			for(k=0;k<10;k++)
			{
				temp.mar[i][j]+=(a1.mar[i][k]*a2.mar[k][j])%m;
			}
			temp.mar[i][j]%=m;
		}
		return temp;

}
struct haha bin(int cnt)//二分思想  下面有更精简的方法
{
	struct haha tmp;
	if(cnt==1) return a;
	if(cnt%2==0) 
	{
		tmp=bin(cnt/2); return multi(tmp,tmp);
	}
	else  
	{
		tmp=bin((cnt-1)/2); tmp=multi(tmp,tmp);return multi(tmp,a);
	}
}
/*void matrix_binary()//二分思想也可以用二进制方法解决 
{
    while(k)
    {
        if(k & 1) //与1计算后可以得到二进制最后一位是否为1，为1就乘，不是就不乘          
            b = matrixmul(b,a);//注意 b的初始为E单位矩阵  
        a = matrixmul(a,a);
        k = k >> 1;
    }  
}
//上面原理解释： 假设k的二进制是10111 即为23 矩阵要乘23次  a始终用来记录2 4 8 16.......
当k=10111  b变成了a   a为2次矩阵相乘 当k=1011  b=b*a 为3次矩阵相乘  a变成了4次相乘
k=101 b为7次 a为8次 k=10 b为7次  a为16次  k=1  b为23 a=32 k=0 退出
那么这时候b就是我们得到的矩阵相乘结果23次
*/

int main()
{
          int i,j,ans;
		  while(scanf("%d %d",&n,&m)!=EOF)
		  {
		   //   for(i=0;i<10;i++)
			 //      for(j=0;j<10;j++)
			//	   {
			//	           if(i==j-1) a.mar[i][j-1]=1;//搞了整整一天没想到居然是在这里犯的错误啊  矩阵的初始化搞错了
			//			   else a.mar[i][j]=0;
			//	   }
		    memset(a.mar,0,sizeof(a.mar));
            for(i = 1;i < 10;i++)
                 a.mar[i][i-1] = 1;

			     for(j=0;j<10;j++)
				     scanf("%d",&a.mar[0][j]);
				 if(n<10) {printf("%d\n",n);continue;}
			  n=n-9;
			  c=bin(n);
			  ans=0;
		        for(i = 0;i < 10;i++)
                    ans += (c.mar[0][i] * (9-i)) % m;
                    printf("%d\n",ans%m);
		  }
		  return 0;
}