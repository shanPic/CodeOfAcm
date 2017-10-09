#include<iostream>

#include<queue>

using namespace std;

#define N 210

struct node{

   int x ;

   int t ;

}n1,n2,m;

int hash[N],map[N];  //标记数组，和一个记录楼层状态的数组

int flag ;                 //记录能否到达目标楼层

int n , a , b ;          //n层，a,起始楼层，b，目的楼层

int main(  )

{

    while( scanf("%d" , &n ) , n )

    {

       if( n== 0 ) break ;        //结束

       cin>>a>>b;                    

       for( int i= 1;  i<= n ; i++ )     //初始化

       { cin>>map[i] ; hash[i] = 0 ; }

       flag = 0 ;                      //初始为0 

       n1.x = a ; n1.t = 0 ;        //把a开始所在楼层赋给结构体， 所走步数为0

       queue<node>Q;               //建立队列Q

       Q.push(n1);                        //入队

       hash[n1.x] = 1 ;          //标记已经走过

       while( !Q.empty() )       //直到为空为止

       {

          m = Q.front() ;            //把队列中第一个值赋给结构体变量m

          Q.pop();                   //出队

          if( m.x == b )            //如果到达终点便退出

          { flag = 1 ; break ; }

          n1.x = m.x - map[m.x];  //按向下的按钮

          n2.x = m.x + map[m.x]; //按向上的按钮

          if( n1.x>0 && n1.x<= b && !hash[n1.x] )//向下

          {

                n1.t = m.t + 1 ;         //步数加一

                hash[n1.x] = 1 ;       //标记

                Q.push(n1);       

              }

            if( n2.x>0 && n2.x<= b && !hash[n2.x] )//向上

             {

                n2.t = m.t+1 ;

                hash[n2.x] = 1 ;

                Q.push(n2);

             }

       } 

       if( flag ) cout<<m.t<<endl;

       else cout<<"-1"<<endl;   

    }

  //  system( "pause" );

    return 0;

}