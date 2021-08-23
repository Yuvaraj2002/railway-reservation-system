#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
int main()
{
    printf("welcome to railway reservation system\n\n\n");
    printf("enter the user name\t");
    char user_name[10];
    scanf("%s",user_name);
    printf("enter the password\t");
    char password[10];
    scanf("%s",password);
    char char1[10] = "pesu";
    char char2[10] = "vvvy";
    if(!strcmp(user_name,char1) && !strcmp(password,char2))
    {
        int choice;
        details_t* passenger_list;
        passenger_list = NULL;
        int n;
        do
        {
            //system("cls");
            printf("1.Reserve ticket\n");
            printf("2.view available trains\n");
            printf("3.cancel reservation\n");
            printf("4.exit\n");
            scanf("%d",&choice);
            if(choice<=4)
            {
                switch (choice)
                {
                case 1:
                {
                    //int n;
                    printf("enter the number of seats to be reserved\n");
                    scanf("%d",&n);
                    //details_t* passenger_list;
                    passenger_list = reserve(n);
                    //int n = sizeof(passenger_list)/sizeof(details_t);
                    /*for(int i=0;i<n;i++)
                    {
                        printf("%s%15d%15d\n",passenger_list[i].name,passenger_list[i].age,passenger_list[i].ticket_no);
                    }*/
                    choice = 5;
                    break;
                }
                case 2:
                {
                    available_trains();
                    choice = 5;
                    break;
                }
                case 3:
                {
                    
                    int tkt_no;
                    printf("enter the ticket number of the seat to be cancelled\n");
                    scanf("%d",&tkt_no);
                    cancel(passenger_list,tkt_no,n);
                    choice = 5;
                    break;
                }
                case 4:
                {
                    printf("thank u\n");
                    choice = 2;
                }
                /*default:
                    choice = 5;
                    printf("invalid entry\n");*/
                }
            }
            else
                printf("invalid entry\n");
        }while(choice>3);
        
    }
    else
        printf("the user name and password is incorrect\n");
}