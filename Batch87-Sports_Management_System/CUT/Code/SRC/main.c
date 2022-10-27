
/*************************************************************************************************
 * *FILENAME          : main.c
 *
 * *DESCRIPTION       : This file defines the functions that consists of various subfunctions
 *                      to perform certain operations.
 *
****************************************************************************************************/
#include <stdio.h>       //Including required Header files
#include <stdlib.h>      //Includes standard libraries
#include <string.h>      //Includes string functions
#include <ctype.h> 
#include <termios.h>
#include <sys/types.h>
#include <unistd.h>      //Includes functions of ctype 
#include "header.h"
#include "func1.c"
#include "func2.c"
#include "func3.c"
#define MAXPW 32

/*************************************************************************************************
 * *FUNCTION NAME : main
 *
 * *DESCRIPTION   : This function calls the other functions to performs various
 *                  operations by taking choice option from the user.
 *
 * *RETURNS       : Admin_Access function
 *                  Teacher function
 *                  Reports function
 *                  exit - exit the main function
 *
**************************************************************************************************/
int main()
{
        int ch=0;
	(void)sports_to_list();
	(void)teacher_to_list();
                while(ch!=3)
                {
                        printf("Choose whether you are the Admin or Teacher\n");
                        printf("1.For Admin\n2.For Teacher\n3.Exit\n");
			printf("Enter the choice :");
                        (void)scanf("%d",&ch);
                        switch(ch){
                                case 1: (void)Admin_Access();
                                        break;
                                case 2: (void)Teacher_Access();
                                        break;
                                case 3: break;
                                default:printf("\nInvalid choice\n");
                        }
                }
		(void)list_to_sports();
		(void)list_to_teacher();
		return EXIT_SUCCESS;
}

/*************************************************************************************************
*
*  FUNCTION NAME   : Admin_Access
*  DESCRIPTION     : In this function the admin login to the sports database using password
*
*************************************************************************************************/

int Admin_Access()
{
	char pw[MAXPW]={0};
	char *pass=pw;
	FILE *fp = stdin;
	ssize_t nchr;
	nchr = getpasswd (&pass, MAXPW, 0, fp);  
		                printf ("Enter password: ");
				nchr = getpasswd (&pass, MAXPW,0 , fp);
				if((strcmp(pass,"Admin@123"))==0)
				{
					system("clear");          //clears the screen
					Admin();         //Function call for Admin database 
				}
				else
				{
					printf("You have entered incorrect password\n");
				}
}

/**********************************************************************************************
*
*  FUNCTION NAME   : Teacher_Access
*  DESCRIPTION     : In this function the admin login to the Teacher Portal using password
*
**********************************************************************************************/
int Teacher_Access()
{
	char pw[MAXPW]={0};
	char *pass=pw;
	FILE *fp = stdin;
	ssize_t nchr;
	nchr = getpasswd (&pass, MAXPW, 0, fp);  
		                printf ("Enter password: ");
				nchr = getpasswd (&pass, MAXPW,0 , fp);
				if((strcmp(pass,"Teacher@123"))==0)
				{
					system("clear");          //clears the screen
					Teacher();         //Function call for Teacher database 
				}
				else
				{
					printf("You have entered incorrect password\n");
				}
}


