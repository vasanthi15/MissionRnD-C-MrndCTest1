/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
void initialise(int date[3][3])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		date[i][0] = 0;
		date[i][1] = 0;
	}
}
int calcDate(struct node *date1head, struct node *date2head, int date[3][3])
{
	int i,years=0,days=0,months=0;
	i = 2;
	initialise(date);
	while (i)
	{

		date[0][0] = date[0][0]*10+date1head->data;
		date[0][1] = date[0][1]*10+date2head->data;
		date1head=date1head->next;
		date2head = date2head->next;
		i--;
	}
	i = 2;
	while (i)
	{
		date[0][0] = date[0][0] * 10 + date1head->data;
		date[0][1] = date[0][1] * 10 + date2head->data;
		date1head = date1head->next;
		date2head = date2head->next;
		i--;
	}
	i = 4;
	date[2][0] = 0;
	date[2][1] = 0;
	while (i)
	{
		date[2][0] = date[2][0]*10+date1head->data;
		date[2][1] = date[2][1] * 10 + date2head->data;
		i--;
		date1head = date1head->next;
		date2head = date2head->next;
	}
	years = date[2][1] - date[2][0];
	years < 0 ? years*-1 : years*1;
	months = date[1][1] - date[1][0];
	months < 0 ? months*-1 : months * 1;
	days = date[0][1] - date[0][0];
	days < 0 ? days*-1 : days * 1;
	return (years*365+months*30+days);
}
int between_days(struct node *date1head, struct node *date2head){
	int date[3][3];
	if (date1head==NULL||date2head==NULL)
	return -1;
	return calcDate(date1head,date2head,date);

}