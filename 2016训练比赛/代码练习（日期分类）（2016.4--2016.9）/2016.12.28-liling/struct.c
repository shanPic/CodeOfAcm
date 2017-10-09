#include<stdio.h>
typedef enum
{
	diamond,club,spade,heart
}Cards;
typedef struct
{
	Cards type;
	int point;
}Poker;
int get_card(Poker *pk)
{
	char c;
	scanf("%c%d",&c,(*pk).point);
	switch(c){
		case 'A':(*pk).type=diamond;break;
		case 'B':(*pk).type=club;break;
		case 'C':(*pk).type=spade;break;
		case 'D':(*pk).type=heart;break;
	}
}
int card_cmp(Poker p1,Poker p2)
{
	if(p1.point!=p2.point){
		if(p1.point>p2.point) return 1;
		else return -1;
	}
	else {
		if(p1.type>p2.type) return 1;
		else if(p1.type<p2.type) return -1;
		else return 0;
	}
}
int main()
{
	Poker tom,jac;
	get_card(&tom);
	get_card(&jac);
	switch(card_cmp(tom,jac)){
		case 1:printf("Tom wins.\n");break;
		case 2:printf("Jack wins.\n");break;
		case 3:printf("Tie.\n");break;
	}
	return 0;
}
