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
    head=NULL;    //�ڽ�һ���ձ�
    head=creat(head);/*����������*/
    print(head);/*��ӡ������*/
}
struct node*creat(struct node *head)/*���ص�����ڵ���ͬ���͵�ָ��*/
{
    struct node*p1,*p2;
    int i=1;
    p1=p2=(struct node*)malloc(sizeof(struct node));
    p1->num=str[0];
    p1->next=NULL;/*���½ڵ��ָ����Ϊ��*/
    while(str[i]!='\0')/*����ڵ����ֵ����0*/
        {
            //�ܽ��½ڵ��ָ���Ա��ֵΪ�ա����ǿձ����½ڵ����ӵ���ͷ�����Ƿǿձ����½ڵ�ӵ���β;
            if(head==NULL)
                head=p1;/*�ձ������ͷ*/
            else
                p2->next=p1;/*�ǿձ��ӵ���β*/
            p2=p1;
            p1=(struct node*)malloc(sizeof(struct node));/*��һ���½ڵ�*/
            p1->num=str[i];
            i++;
        }
    free(p1);  //���뵽��û¼�룬�����ͷŵ�
    p1=NULL;   //ʹָ���
    p2->next = NULL; //����β�ˣ�ָ���
    return head;/*���������ͷָ��*/
}
/*******************************************/
void print(struct node*head)/*����headΪͷ��������ڵ��ֵ*/
{
    FILE *fp;
    fp=fopen("number.txt","w");
    struct node *temp;
    temp=head;/*ȡ�������ͷָ��*/
    while(temp!=NULL)/*ֻҪ�Ƿǿձ�*/
        {
            if((temp->num)%2){
                fputc(temp->num,fp);
            }
            temp=temp->next;/*������������*/
        }
    temp=head;
    while(temp!=NULL)/*ֻҪ�Ƿǿձ�*/
        {
            if((temp->num)%2==0){
                //printf("%6d\n",temp->num);/*�������ڵ��ֵ*/
                fputc(temp->num,fp);
            }
            temp=temp->next;/*������������*/
        }
    fclose(fp);
}
