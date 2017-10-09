#include <stdlib.h>
#include <stdio.h>
char str[200];
struct node
{
    char num;
    struct node *next;
};
struct node *creat();
main( )
{
    scanf("%s",str);
    struct node *head;
    head=NULL;    //②建一个空表
    head=creat(head);/*创建单链表*/
    print(head);/*打印单链表*/
}
struct node*creat(struct node *head)/*返回的是与节点相同类型的指针*/
{
    struct node*p1,*p2;
    int i=1;
    p1=p2=(struct node*)malloc(sizeof(struct node));
    p1->num=str[0];
    p1->next=NULL;/*将新节点的指针置为空*/
    while(str[i]!='\0')/*输入节点的数值大于0*/
        {
            //④将新节点的指针成员赋值为空。若是空表，将新节点连接到表头；若是非空表，将新节点接到表尾;
            if(head==NULL)
                head=p1;/*空表，接入表头*/
            else
                p2->next=p1;/*非空表，接到表尾*/
            p2=p1;
            p1=(struct node*)malloc(sizeof(struct node));/*下一个新节点*/
            p1->num=str[i];
            i++;
        }
    free(p1);  //申请到的没录入，所以释放掉
    p1=NULL;   //使指向空
    p2->next = NULL; //到表尾了，指向空
    return head;/*返回链表的头指针*/
}
/*******************************************/
void print(struct node*head)/*出以head为头的链表各节点的值*/
{
    FILE *fp;
    fp=fopen("number.txt","w");
    struct node *temp;
    temp=head;/*取得链表的头指针*/
    while(temp!=NULL)/*只要是非空表*/
        {
            if((temp->num)%2){
                fputc(temp->num,fp);
            }
            temp=temp->next;/*跟踪链表增长*/
        }
    temp=head;
    while(temp!=NULL)/*只要是非空表*/
        {
            if((temp->num)%2==0){
                //printf("%6d\n",temp->num);/*输出链表节点的值*/
                fputc(temp->num,fp);
            }
            temp=temp->next;/*跟踪链表增长*/
        }
    fclose(fp);
}
