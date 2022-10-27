/**********************************************************************************
 *
 *  FILENAME        : func1.c
 *  DESCRIPTION     : This file is used to  retreive and store data from sports and teachers file
 *
 * ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXPW 32
#include "header.h"


/*******************************************************************************************
 *
 *  FUNCTION NAME   : Admin_Corner
 *
 *  DESCRIPTION     : In this function it displays the menu list for Admin corner
 *
 *  RETURN          : Return EXIT_SUCCESS
 *
 *******************************************************************************************/

int Admin()
{
	int ch=0;

	while(ch!=4)
	{
	printf("\n------------------------------------------------------------------------------------------------------------------\n");
		printf("\n                                  ADMIN ACCESS FOR SPORTS DATABASE\n");
	printf("\n------------------------------------------------------------------------------------------------------------------\n");
		printf("\n1.Maintain Sports Database\n2.Maintain teacher database\n3.Reports\n4.Go back to main menu\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:Maintain_Sports_Database();
			       break;
			case 2:Maintain_Teachers_Database();
			       break;
			case 3:Reports();
			       break;
			case 4:break;

			default:printf("\nInvalid Choice\n");
		}
	}
}

/*******************************************************************************************************
 *
 *  FUNCTION NAME   : Maintain_Sports_Database
 *
 *  DESCRIPTION     : In this function the admin maintains all the sports and teachers data
 *
 *  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
 *
 *******************************************************************************************************/

int Maintain_Sports_Database()
{
	int ch=0;
	while(ch!=5)
	{
	printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n                                               MAINTAIN SPORTS DATABASE\n");
	printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
		printf("1. Add SPORTS Data\n2. Edit SPORTS Data\n3. Delete SPORTS Data\n4. View SPORTS Data\n5. Go to Admin Corner");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add_data();
			       break;
			case 2:edit_data();
			       break;
			case 3:delete_data();
			       break;
			case 4:view_data();
			       break;
			case 5:break;
			default:printf("\ninvalid choice\n");
		}
	}

	return EXIT_SUCCESS;
}



/*******************************************************************************************************
 *
 *  FUNCTION NAME   : Add_data
 *  DESCRIPTION     : In this function the admin add all sports details
 *  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
 *
 *******************************************************************************************************/

int add_data()
{
	if((new=(sd *)calloc(1,sizeof(sd)))==NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		while(1)
		{
			printf("Enter sports ID between 100 and 999 :");
			scanf("%d",&new->sports_id);
			if(new->sports_id<100 ||  new->sports_id>999)
			{
				printf("\nINVALID SPORTS ID!!\n");
				continue;
			}
			else
				break;
		}

		if(start)
		{
			for(ptr=start;(ptr) && ptr->sports_id!=new->sports_id;ptr=ptr->next);
			if(ptr)
			{
				printf("\nsports id %d is duplicate\n",new->sports_id);
				continue;
			}
			else
			{
				break;
			}
		}
		break;
	}
	while(1)
	{
		printf("Enter sports name :");
		scanf("%s",new->sports_name);
		char sname[20];
		strcpy(sname,new->sports_name);
		if(alpha_validation(sname))
		{
			printf("sports name should be only characters\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("Enter sports type 1 for indoor, 2 for outdoor :");
		scanf("%d",&new->sports_type);
		if(new->sports_type==1|| new->sports_type==2)
		{
			break;
		}
		else
		{
			printf("Enter the number 1 or 2 \n");
			continue;
		}
	}
	while(1)
	{
		printf("Enter the total no.of students registered(3-40) :");
		scanf("%d",&new->total_students);
		if(new->total_students<3 || new->total_students>40)
		{
			printf("\nEnter the students within the limit (3-40)\n");
			continue;
		}
		else
		{
			break;
		}

	}
	int j;
	char months[12][5]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	while(1)
	{
		printf("Enter Month in which the event is held :");
		scanf("%s",new->month);
		for(j=0;j<strlen(new->month);j++)
		{


			if(new->month[j]>='a' && new->month[j]<='z')
			{
				new->month[j]=new->month[j]-32;
			}
		}
		int temp=0;
		for(int i=0;i<12;i++)
		{
			if((strcmp(new->month,months[i]))==0)
			{
				temp=1;
				break;
			}
		}
		if(temp==1)
		{
			break;
		}
		else
		{
			printf("\n enter the valid month name \n");
			continue;
		}
	}
	while(1){

		printf("Enter sport teacher ID :");
		scanf("%d",&new->teacher_id);
		if((new->teacher_id<1 ||  new->teacher_id>99))
		{
			printf("\nINVALID TEACHER  ID!!\n");
			continue;

		}
		for(ptr1=start1;(ptr1) && ptr1->teacher_id!=new->teacher_id;ptr1=ptr1->next1);
		if(!ptr1)
		{

			printf("\nInvalid Teacher ID\n");
			continue;
		}
		if((ptr1->teacher_id==new->teacher_id) && ptr1->sctr==3)
		{
			printf("\nThe teacher is already assinged to 3 sports assign another teacher\n");
			continue;
		}
		
		else
		{
			ptr1->sctr++;
			break;
		}
	}

	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->sports_id<start->sports_id)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->sports_id<new->sports_id;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}
	return EXIT_SUCCESS;
}

/******************************fuction cecks whether a character is an alphabet or not************************/

int alpha_validation(char *str){
	for(char *p=str;*p!='\0';p++){
		if(!isalpha(*p)){
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

/******************************************function to view data**********************************************/

int view_data()
{
	if(!start)
	{
		printf("\nTHERE IS NO SPORTS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	printf("\n                                        ADMIN CORNER-ALL SPORTS DETAILS\n");
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("\n SPORTS ID\tSPORTS NAME\tSPORTS TYPE\tTOTOAL STUDENTS\tMONTH\tSPORTS TEACHER ID\n");
	printf("\n-------------------------------------------------------------------------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next)
		printf("\n%d\t\t %s\t\t %d\t \t%d\t %s\t \t%d\n",ptr->sports_id,ptr->sports_name,ptr->sports_type,ptr->total_students,ptr->month,ptr->teacher_id);
}

/******************************************function to edit data**********************************************/

int  edit_data()
{
	if(!start)
	{
		printf("\nTHERE IS NO SPORTS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	int sid;
	printf("\nEnter sports ID for editing :");
	scanf("%d",&sid);
	for(ptr=start;(ptr) && ptr->sports_id!=sid;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nSPORTS ID %d not found\n\n",sid);
		return EXIT_FAILURE;
	}
	printf("Old sports Data\n");
	printf("\n SPORTS NAME\tSPORTS TYPE\tTOTOAL STUDENTS\tMONTH\tSPORTS TEACHER ID\n");
	printf("\n%10s\t\t%3d\t%3d\t\t%5s\t\t%d\n",ptr->sports_name,ptr->sports_type,ptr->total_students,ptr->month,ptr->teacher_id);
	while(1)
	{
		printf("Enter sports name :");
		scanf("%s",ptr->sports_name);
		char sname[20];
		strcpy(sname,ptr->sports_name);
		if(alpha_validation(sname))
		{
			printf("sports name should be only characters\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("Enter sports type 1 for indoor, 2 for outdoor :");
		scanf("%d",&ptr->sports_type);
		if(ptr->sports_type==1|| ptr->sports_type==2)
		{
			break;
		}
		else
		{
			printf("Enter the number 1 or 2 \n");
			continue;
		}
	}
	while(1)
	{
		printf("Enter the total no.of students registered(3-40) :");
		scanf("%d",&ptr->total_students);
		if(ptr->total_students<3 || ptr->total_students>40)
		{
			printf("\nEnter the students within the limit (3-40)\n");
			continue;
		}
		else
		{
			break;
		}

	}
	while(1)
	{
		printf("Enter Month in which the event is held :");
		scanf("%s",ptr->month);
		for(int i=0;i<=strlen(ptr->month);i++)
		{
			if(ptr->month[i]>=97 && ptr->month[i]<=122)
			{
				ptr->month[i]=ptr->month[i]-32;
			}
		}
		int temp=0;
		char months[13][5]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
		for(int i=0;i<13;i++)
		{
			if(strcmp(ptr->month,months[i])==0)
			{
				temp=1;
				break;
			}
		}
		if(temp==1)
		{
			break;
		}
		else
		{
			printf("\n enter the valid month name \n");
			continue;
		}
	}
	while(1){
		printf("Enter sport teacher ID :");
		scanf("%d",&ptr->teacher_id);
		if(ptr->teacher_id<1 ||  ptr->teacher_id>99)
		{
			printf("\nINVALID TEACHER  ID!!\n");
			continue;
		}
		else
		{
			break;
		}
		return EXIT_SUCCESS;
	}
}

/**************************function to delete sports data*************************/

int delete_data()
{
	if(!start)
	{
		printf("\nTHERE IS NO SPORTS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	int spid;
	printf("\nEnter sports ID  for deleting :");//check
	scanf("%d",&spid);
	if(spid==start->sports_id)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->sports_id!=spid;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nsports ID  %d not found for deletion \n",spid);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);
	}
	return EXIT_SUCCESS;
}

/*******************************************************************************************************
 *
 *  FUNCTION NAME   : Maintain_Teachers_Database
 *  DESCRIPTION     : In this function the admin maintains all the teachers data
 *  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
 *
 *******************************************************************************************************/

int Maintain_Teachers_Database()
{
	int ch=0;
	while(ch!=5)
	{
	printf("\n--------------------------------------------------------------------------------------------------------\n");
		printf("\n                                 MAINTAIN TEACHERS DATABASE\n");
	printf("\n-------------------------------------------------------------------------------------------------------\n");
		printf("1. Add Teacher Data\n2. Edit Teacher Data\n3. Delete Teacher Data\n4. View Teacher  Data\n5. Go to Admin Corner");
		printf("\nEnter choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add_teacher_data();
			       break;
			case 2:edit_teacher_data();
			       break;
			case 3:delete_teacher_data();
			       break;
			case 4:view_teacher_data();
			       break;
			case 5: break;
			default:printf("\ninvalid choice\n");
		}
	}
	return EXIT_SUCCESS;
}

/***************************function to add teachers data*******************************/

int add_teacher_data()
{
	if((new1=(td *)calloc(1,sizeof(td)))==NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		while(1)
		{
		printf("Enter the teachers ID :");
		scanf("%d",&new1->teacher_id);
		if(new1->teacher_id<1 ||  new1->teacher_id>99)
		{

			printf("\nINVALID TEACHER  ID!!\n");
			continue;
		}
			else
			{
				break;
			}

		}

	if(start1)
	{
			for(ptr1=start1;(ptr1) && ptr1->teacher_id!=new1->teacher_id;ptr1=ptr1->next1);
			if(ptr1)
			{
				printf("\nTeacher id %d is duplicate\n",new1->teacher_id);
				continue;
			}
			else
			{
				break;
			}
		}
		break;
	
	}


	while(1)
	{
		printf("Enter the teacher name :");
		scanf("%s",new1->teacher_name);
		char tname[20];
		strcpy(tname,new1->teacher_name);
		if(alpha_validation(tname))
		{
			printf("Teacher name should be only characters\n");
			continue;
		}
		else
			break;
	}
	if(!start1)
	{
		start1=new1;
		new1->next1=NULL;
	}
	else if(new1->teacher_id<start1->teacher_id)
	{
		new1->next1=start1;
		start1=new1;
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->teacher_id<new1->teacher_id;prev1=ptr1,ptr1=ptr1->next1);
		prev1->next1=new1;
		new1->next1=ptr1;
	}
	return EXIT_SUCCESS;
}
/*****************************function to view teachers data***********************/

int view_teacher_data()
{
	if(!start1)
	{
		printf("\nTHERE IS NO TEACHERS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n                               TEACHERS DATA\n");
	printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		printf("\n Teacher Id- %d\t\t Teacher name-%s\n",ptr1->teacher_id,ptr1->teacher_name);
		printf("%s is assigned to %3d sports!\n",ptr1->teacher_name,ptr1->sctr);
		}
}

/*****************************function to edit teachers data***********************/

int  edit_teacher_data()
{
	if(!start1)
	{
		printf("\nTHERE IS NO TEACHERS DATA ENTERED BY AUTHORITY\n");
		return EXIT_FAILURE;
	}
	int tid;
	while(1)
	{
		printf("\nEnter  teacher ID for editing :");
		scanf("%d",&tid);
		if(tid<1 ||  tid>99)
		{
			printf("\nINVALID TEACHER  ID!!\n");
			continue;
		}
		else
		{
			break;
		}
	}
	for(ptr1=start1;(ptr1) && ptr1->teacher_id!=tid;ptr1=ptr1->next1);
	if(!ptr1)
	{
		printf("\nTEACHER ID %d not found\n",tid);
		return EXIT_FAILURE;
	}
	printf("\nThe old teacher name is ");
	printf("%s",ptr1->teacher_name);
	printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
	while(1)
	{
		printf("\nEnter new teacher name :");
		scanf("%s",ptr1->teacher_name);
		char tname[20];
		strcpy(tname,new1->teacher_name);
		if(alpha_validation(tname))
		{
			printf("Teacher name should be only characters\n");
			continue;
		}
		else
			break;
	}
}

/*****************************function to delete teachers data***********************/

int delete_teacher_data()
{
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int tid;
	while(1)
	{
		printf("\nEnter TEACHER ID  for deleting :");
		scanf("%d",&tid);
		if(tid<1 ||  tid>99)
		{
			printf("\nINVALID TEACHER  ID!!\n");
			continue;
		}
		else
		{
			break;
		}
	}
	if(tid==start1->teacher_id)
	{
		ptr1=start1;
		start1=start1->next1;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->teacher_id!=tid;prev1=ptr1,ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nTeacher ID  %d not found for deletion \n",tid);
			return EXIT_FAILURE;
		}
		prev1->next1=ptr1->next1;
		free(ptr1);
	}
	return EXIT_SUCCESS;
}

/**************************************************************************************************
 *  FUNCTION NAME  : Reports
 *
 *  DESCRIPTION    : This function displays reports of all sports
 *
 *************************************************************************************************/
int Reports()
{
	int ch=0;
	while(ch!=6)
	{
		printf("\n                             SPORTS REPORT\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("1.View the results\n2.List of sports pending for the year\n3.View all 1st placed students across various sports\n4.Most popular sport\n5.List of teachers who successfully completed their sports\n6.Go to main menu\n");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:View_Results();
			       break;
			case 2:Sports_Pending_List();
			       break;
			case 3:First_Placed();
			       break;
			case 4:Popular_Sports();
			       break;
			case 5:Event_Completed_Sports_Teacher();
			       break;
			case 6:break;
			default:printf("\ninvalid choice\n");
		}
	}
	return EXIT_SUCCESS;
}


/**************************************************************************************************
 *  FUNCTION NAME  : View_Results()
 *
 *  DESCRIPTION    : This function displays 1st, 2nd and 3rd winners of all sports that are conducted
 *
 *  RETURN          : Returns EXIT_SUCCESS if successful else returns EXIT_FAILURE
 *
 *************************************************************************************************/

int View_Results()
{

		printf("\n                      WINNERS LIST\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("\t\tSPORTSID    1st     2nd      3rd \n");
		printf("-----------------------------------------------------------------------------------\n");

	for(ptr=start;(ptr);ptr=ptr->next)
	{
		if((strlen(ptr->winner1))!=0)
		{

		printf("\t\t%d\t ",ptr->sports_id);
		printf("%s\t",ptr->winner1);
		printf("%s\t ",ptr->winner2);
		printf("%s\n ",ptr->winner3);

	}
	}
	return EXIT_SUCCESS;
}

/**************************************************************************************************
 *  FUNCTION NAME  : sports_pending_list
 *
 *  DESCRIPTION    : This function displays list of sports that are not conducted
 *
 *  RETURN         : Returns EXIT_SUCCESS if successful 
 *************************************************************************************************/

int Sports_Pending_List()
{
		printf("\n                      SPORTS PENDING LIST\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("SPORTSID     TEACHERID     NAME\n");
		printf("-----------------------------------------------------------------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		if((strlen(ptr->winner1))==0)
		{
			printf("\t%d\t\t%d\t\t%s\n",ptr->sports_id,ptr->teacher_id,ptr->sports_name);
		}
	}
	return EXIT_SUCCESS;
}

/**************************************************************************************************
 *  FUNCTION NAME  : First_Placed
 *
 *  DESCRIPTION    : This function displays all first placed students from sports
 *
 *  RETURN          : Returns EXIT_SUCCESS if successful
 *************************************************************************************************/

int First_Placed()
{
		printf("\n                    FIRST PLACED  WINNERS LIST\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("\t\tSPORTSID    SPORTS-NAME   WINNER1\n");
		printf("-----------------------------------------------------------------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next){
		{
		if((strlen(ptr->winner1))!=0)
		{
			printf("\t\t%d\t\t",ptr->sports_id);
			printf("%s\t\t",ptr->sports_name);
			printf("%s\n ",ptr->winner1);
		}
		}
	}
	return EXIT_SUCCESS;
}

/**************************************************************************************************
 *  FUNCTION NAME  : Popular_Sports 
 *
 *  DESCRIPTION    : This function displays the sports for which the most no.of students are registered
 *
 *  RETURN          : Returns EXIT_SUCCESS if successful  
 *************************************************************************************************/


int Popular_Sports()
{
	if(!start)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}
	int pop_sport=0;
	int sp_id;
	char sp_nm[10];
	ptr=start;
	while(ptr!=NULL)
	{
		if(pop_sport<ptr->total_students)
		{
			pop_sport=ptr->total_students;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	for(ptr=start;(ptr);ptr=ptr->next){
		if(pop_sport==ptr->total_students){
			sp_id=ptr->sports_id;
			strcpy(sp_nm,ptr->sports_name);
		}
	}
		printf("\n                     MAXIMUM STUDENTS REGISTERED SPORT\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("The sports id  is %d and sports name is  %s \n",sp_id,sp_nm);
	printf("Total students registered %d\n",pop_sport);
	return EXIT_SUCCESS;
}

/**************************************************************************************************
 *  FUNCTION NAME  : Event_Completed_Sports_teacher
 *
 *  DESCRIPTION    : This function displays the list of teachers who completed all sports successfully
 *
 *  RETURN          : Returns EXIT_SUCCESS if successful 
 **************************************************************************************************/


int Event_Completed_Sports_Teacher()
{
	printf("                              EVENT COMPLETED SPORTS TEACHER\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("     TEACHER-ID     SPORTS-NAME\n");
		printf("-----------------------------------------------------------------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next){
		if((strlen(ptr->winner1))!=0){
			printf("\t%d\t  %s\n",ptr->teacher_id,ptr->sports_name);
		}
	}
	return EXIT_SUCCESS;
}


/****************************************************************************************************
 *
 * FUNCTION NAME  : getpasswd

 * DESCRIPTION    : This function provides  the password .

 *  RETURN        : Returns EXIT_SUCCESS if successful 
 ****************************************************************************************************/
ssize_t getpasswd (char **pw, size_t sz, int mask, FILE *fp)
{
	if (!pw || !sz || !fp) return -1;       /* validate input   */
#ifdef MAXPW
	if (sz > MAXPW) sz = MAXPW;
#endif

	if (*pw == NULL) {              /* reallocate if no address */
		void *tmp = realloc (*pw, sz * sizeof **pw);
		if (!tmp)
			return -1;
		memset (tmp, 0, sz);    /* initialize memory to 0   */
		*pw =  (char*) tmp;
	}

	size_t idx = 0;         /* index, number of chars in read   */
	int c = 0;

	struct termios old_kbd_mode;    /* orig keyboard settings   */
	struct termios new_kbd_mode;

	if (tcgetattr (0, &old_kbd_mode)) { /* save orig settings   */
		fprintf (stderr, "%s() error: tcgetattr failed.\n", __func__);
		return -1;
	}   /* copy old to new */
	memcpy (&new_kbd_mode, &old_kbd_mode, sizeof(struct termios));

	new_kbd_mode.c_lflag &= ~(ICANON | ECHO);  /* new kbd flags */
	new_kbd_mode.c_cc[VTIME] = 0;
	new_kbd_mode.c_cc[VMIN] = 1;
	if (tcsetattr (0, TCSANOW, &new_kbd_mode)) {
		fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
		return -1;
	}

	/* read chars from fp, mask if valid char specified */
	while (((c = fgetc (fp)) != '\n' && c != EOF && idx < sz - 1) ||
			(idx == sz - 1 && c == 127))
	{
		if (c != 127) {
			if (31 < mask && mask < 127)    /* valid ascii char */
				fputc (mask, stdout);
			(*pw)[idx++] = c;
		}
		else if (idx > 0) {         /* handle backspace (del)   */
			if (31 < mask && mask < 127) {
				fputc (0x8, stdout);
				fputc (' ', stdout);
				fputc (0x8, stdout);
			}
			(*pw)[--idx] = 0;
		}
	}
	(*pw)[idx] = 0; /* null-terminate   */

	/* reset original keyboard  */
	if (tcsetattr (0, TCSANOW, &old_kbd_mode)) {
		fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
		return -1;
	}

	if (idx == sz - 1 && c != '\n') /* warn if pw truncated */
		fprintf (stderr, " (%s() warning: truncated at %zu chars.)\n",
				__func__, sz - 1);

	return idx; /* number of chars in passwd    */
}


















