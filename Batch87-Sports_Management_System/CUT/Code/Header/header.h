/**************************************************************************************************
*     FILENAME      :      header.h
*
*    DESCRIPTION    :      This File contains structure definitions and all funcions prototypes.
*
***************************************************************************************************/
#ifndef HEADER_H
#define HEADER_H
#include <stddef.h>
typedef struct sports_database
{
        int sports_id;
        char sports_name[20];
        int sports_type;
        int total_students;
        char month[5];
	int teacher_id;
	int A;
	int P;
        char winner1[20];
	char winner2[20];
	char winner3[20];
        struct sports_database *next;
}sd;
typedef struct temp1
{
        int sports_id;
        char sports_name[20];
        int sports_type;
        int total_students;
        char month[5];
	int teacher_id;
	int A;
	int P;
        char winner1[20];
	char winner2[20];
	char winner3[20];
}s;
typedef struct teachers_database
{
        int teacher_id;
	char teacher_name[20];
	int sctr;
	struct teachers_database *next1;
}td;
typedef struct temp2
{
        int teacher_id;
	char teacher_name[20];
	int sctr;

}t;
sd *start,*new,*ptr,*next,*last,*prev;
td *start1,*new1,*ptr1,*next1,*last1,*prev1;
/***************functions from admin corner *****************/
int Admin();//function for admin portal
int Admin_Access();//function to verify admin password
int Maintain_Sports_Database();//function to maintain sports database
int Maintain_Teachers_Database();//function to maintain teacher database

/*****************functions from Sports_Database ************/
int add_data();//function to add data
int edit_data();//function to edit data
int delete_data();//function to delete data
int view_data();//function to view data
int sports_to_list();//sports file to list
int list_to_sports();//list to sports file
int alpha_validation(char *s);//to check the whether the input is character or not

/******** functions from Maintain_Teacher_Database** ********/
int add_teacher_data();//function to add  teachers data
int edit_teacher_data();//function to edit teachers data
int delete_teacher_data();//function to delete teachers data
int view_teacher_data();//function to view data
int list_to_teacher();//list to teacher file
int teacher_to_list();//teacher file to list

/************** functions from Teacher Database ************/
int Teacher();//function for teacher
int Teacher_Access();//function to verify teacher password
int Take_Attendance();//function to mark attendance
int List_Winners();//function to list winners
int View_Attendance();

/*************** functions from Reports *******************/
int Reports();//function for reports
int View_Results();//function to view results
int Sports_Pending_List();//function to list all sports which are not conducted
int First_Placed();//function to vew all first placed students
int Popular_Sports();//function to view the most popular sport
int Event_Completed_Sports_Teacher();//function to view list of teachers who successfully completed assigned sports
ssize_t getpasswd (char **pw, size_t sz, int mask, FILE *fp);  
#endif

