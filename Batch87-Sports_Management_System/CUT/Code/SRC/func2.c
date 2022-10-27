/**********************************************************************************
 *
 *  FILENAME        : func2.c
 *  DESCRIPTION     : This file is used to  retreive and store data from sports and teachers file
 *
 * ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


/*******************************************************************************************
 *
 *  FUNCTION NAME   : Teacher
 *  DESCRIPTION     : In this function it displays the menu list for Teacher
 *  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
 *
 *******************************************************************************************/

int Teacher()
{
	int ch=0;

	while(ch!=4)
	{
		printf("                                      TEACHER ACCESS FOR SPORTS DATABASE\n");
		printf("\n----------------------------------------------------------------------------------------------------------\n");
		printf("\n1.Take attendance\n2.List winners\n3.view data\n4.Go back to main menu\n");
		printf("\nEnter choice :");
		(void)scanf("%d",&ch);
		switch(ch)
		{
			case 1:(void)Take_Attendance();
			       break;
			case 2:(void)List_Winners();
			       break;
			case 3:(void)View_Attendance();
			       break;
			case 4: break;

			default:printf("\nInvalid Choice\n");
		}
	}
}

/****************************function to mark attendance*************************/

int Take_Attendance()
{
	sd *att;
	int flag=0;
	int sptid;
	while(1)
	{
top:

		printf("Enter sports id :");
		(void)scanf("%d",&sptid);
		if(sptid<100 ||  sptid>999)
		{
			printf("\nINVALID SPORTS ID!!\n");
			continue;
		}
		else
		{
			break;
		}
	}

	for(ptr=start;(ptr);ptr=ptr->next){
		if(ptr->sports_id==sptid){
			att=ptr;
			printf("ID found");
			flag=1;
			break;
		}
	}
	if(flag!=1){
		printf("No such id");
		goto top;
	}
	while(1)
	{
	printf("\nEnter no.of students present :");
	(void)scanf("%d",&att->P);
	for(ptr=start;(ptr) && ptr->sports_id!=sptid;ptr=ptr->next);
	if(att->P > ptr->total_students)
	{
		printf("\nNo of students present should be less than or equal to total students\n");
		continue;
	}
	else
	{
		break;
	}
	}
	while(1)
	{
	printf("\nEnter no.of students absent :\n");
	(void)scanf("%d",&att->A);
	if(att->A > ptr->total_students)
	{
		printf("\nNo of students present should be less than or equal to total students\n");
		continue;
	}
	else
	{
		break;
	}
	}
	return EXIT_SUCCESS;
}

/************************function to list all the sports winners******************/

int List_Winners()
{
	int tid,sid,n;
	printf("\nEnter the teacher id :");
	(void)scanf("%d",&tid);
	printf("Enter how many data you want to enter :");
	(void)scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		printf("\nEnter sports id :");
		scanf("%d",&sid);

		for(ptr=start;(ptr);ptr=ptr->next)
		{
			if(ptr->sports_id==sid)
			{
				printf("\nEnter the winners list in the order 1, 2, 3\n");
				(void)scanf("%s",ptr->winner1);
				(void)scanf("%s",ptr->winner2);
				(void)scanf("%s",ptr->winner3);
			}
		}
	}
	return EXIT_SUCCESS;
}

/************************function to view the attendence report******************/

int View_Attendance()
{
	if(!start)
	{
		printf("\nTHERE IS NO SPORTS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	printf("\n                                        TEACHER DATA-ABSENT AND PRESENT\n");
	printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next){
		printf("\n%d\t\t %d\t %d\n",ptr->sports_id,ptr->A,ptr->P);
	}

}

