/**********************************************************************************
 *
 *  FILENAME        : func3.c
 *  DESCRIPTION     : This file is used to  retreive and store data from sports and teachers file
 *
 * ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


/********************This function allocate memory for the sports database to open and read the file from
  beginning till end of file and put each sports into the list.*****************/

int sports_to_list()
{
	FILE *p;
	s t1;
	if((p=fopen("sport","rb"))==NULL)
	{
		printf("\nSports File is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&t1,sizeof(s),1,p);
	while(!feof(p))
	{
		if((new=(sd *)calloc(1,sizeof(sd)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new->sports_id=t1.sports_id;
		strcpy(new->sports_name,t1.sports_name);
		new->sports_type=t1.sports_type;
		new->total_students=t1.total_students;
		strcpy(new->month,t1.month);
		new->teacher_id=t1.teacher_id;
		new->A=t1.A;
		new->P=t1.P;
		for(int i=0;i<3;i++)
		{

			new->sports_id=t1.sports_id;
			strcpy(new->winner1,t1.winner1);
			strcpy(new->winner2,t1.winner2);
			strcpy(new->winner3,t1.winner3);
		}


		if(!start)
		{
			start=last=new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}

		fread(&t1,sizeof(s),1,p);
	}
	fclose(p);
	return EXIT_SUCCESS;
}

/*******This function is used to write sports data into the file by traversing the list**************/

int list_to_sports()
{
	s t2;
	if(!start)
	{
		printf("\nTHERE IS NO SPORTS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	FILE *p1;
	if((p1=fopen("sport","wb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		t2.sports_id=ptr->sports_id;
		strcpy(t2.sports_name,ptr->sports_name);
		t2.sports_type=ptr->sports_type;
		t2.total_students=ptr->total_students;
		strcpy(t2.month,ptr->month);
		t2.teacher_id=ptr->teacher_id;
		t2.A=ptr->A;
		t2.P=ptr->P;
		for(int i=0;i<3;i++)
		{
			t2.sports_id=ptr->sports_id;
			strcpy(t2.winner1,ptr->winner1);
			strcpy(t2.winner2,ptr->winner2);
			strcpy(t2.winner3,ptr->winner3);
		}
		fwrite(&t2,sizeof(s),1,p1);
	}
	fclose(p1);
	return EXIT_SUCCESS;
}

/********************This function allocate memory for the teachers database to open and read the file from
  beginning till end of file and put each teachers data into the list.*****************/

int teacher_to_list()
{
	FILE *p3;
	t f1;
	if((p3=fopen("teacher","rb"))==NULL)
	{
		printf("\nTeacher File is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&f1,sizeof(t),1,p3);
	while(!feof(p3))
	{
		if((new1=(td *)calloc(1,sizeof(td)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new1->teacher_id=f1.teacher_id;
		strcpy(new1->teacher_name,f1.teacher_name);
		new1->sctr=f1.sctr;


		if(!start1)
		{
			start1=last1=new1;
			new1->next1=NULL;
		}
		else
		{
			last1->next1=new1;
			last1=new1;
			new1->next1=NULL;
		}
		fread(&f1,sizeof(t),1,p3);
	}
	fclose(p3);
	return EXIT_SUCCESS;
}

/*******This function is used to write teachers data into the file by traversing the list**************/

int list_to_teacher()
{
	t f2;
	if(!start1)
	{
		printf("\nTHERE IS NO TEACHER DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	FILE *p4;
	if((p4=fopen("teacher","wb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr1=start1;(ptr1!=NULL);ptr1=ptr1->next1)
	{
		f2.teacher_id=ptr1->teacher_id;
		strcpy(f2.teacher_name,ptr1->teacher_name);
		f2.sctr=ptr1->sctr;
		fwrite(&f2,sizeof(t),1,p4);
	}
	fclose(p4);
	return EXIT_SUCCESS;
}

