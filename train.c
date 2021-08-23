#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>
void available_trains(void)
{
    printf("------------------------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\n");
	printf("------------------------------------------------------------------------------------------");
	printf("\n10215\tSuper fast Express\tMadgaon to Ernakulam\t\tRs.480\t\t9am");
	printf("\n10216\tAntyodaya Express\tKochuvelli To Mangaluru\t\tRs.500\t\t12pm");
	printf("\n10217\tJanashatabdi Express\tHubballi To Bengaluru\t\tRs.450\t\t8am");
	printf("\n10218\tRajyarani Express\tyashwanthpur To Pandarpur\tRs.320\t\t11am");
	printf("\n10219\tCity Express\t\tMysuru To Belagavi\t\tRs.420\t\t7am");
	printf("\n10220\tchennai Express\tMysuru To Bengaluru\t\tRs.450\t\t9.30am");
    printf("\n10221\tKeystone Express\tHubballi To Mysuru\t\tRs.400\t\t1pm");
    printf("\n10222\tUdupi Express\t\tUdupi To Mysuru\t\t\tRs.350\t\t4pm");
    printf("\n10223\tKrishna Express\t\tBelagavi To Udupi\t\tRs.490\t\t3.35pm");
    printf("\n10224\tNamma Express\t\tMangaluru To Belagavi\t\tRs.550\t\t4.15pm");

}
details_t* reserve(int n)
{
    available_trains();
    char *destination;
    char *train_name;
    char *charge;
    int total_charge;
    char *time;
    printf("enter the tr no of the desired destination\n");
    char tr_no[10];
    scanf("%s",tr_no);
    FILE *fp = fopen("D://c_programming//junk folder//train_list.csv","r");
    if(fp==NULL)
        printf("cannot open\n");
    else    
    {
        char data[500];
        fgets(data,500,fp);
        while(fgets(data,500,fp)!=NULL)
        {
            char *train_no = strtok(data,",");
	    	
            if(!(strcmp(tr_no,train_no)))
            {
                train_name = strtok(NULL,",");
                destination = strtok(NULL,",");
                charge = strtok(NULL,",");
                time = strtok(NULL,",");
		break; 
            }
        }
    }
    fclose(fp);
    details_t* list_passengers = (details_t*)calloc(30,sizeof(details_t));
    for(int i=0;i<n;i++)
    {
        printf("enter the passenger name : ");
        scanf("%s",list_passengers[i].name);
        printf("eneter the passenger age : ");
        scanf("%d",&list_passengers[i].age);
    }
    printf("proceed towards confirmation(y/n)\t");
    char ch;
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='y')
    {
        int initial_seat_no = 1;
        int initial_ticket_no = 20210701;
        printf("ticket is successfully booked\n");
	    printf("train name is %s\n",train_name);
	    
        if(!strcmp(tr_no,"10215"))
            total_charge = 480*n;
        else if(!strcmp(tr_no,"10216"))
            total_charge = 500*n;
        else if(!strcmp(tr_no,"10217"))
            total_charge = 450*n;
        else if(!strcmp(tr_no,"10218"))
            total_charge = 320*n;
        else if(!strcmp(tr_no,"10219"))
            total_charge = 420*n;
        else if(!strcmp(tr_no,"10220"))
            total_charge = 450*n;
        else if(!strcmp(tr_no,"10221"))
            total_charge = 400*n;
        else if(!strcmp(tr_no,"10222"))
            total_charge = 350*n;
        else if(!strcmp(tr_no,"10223"))
            total_charge = 490*n;
        else if(!strcmp(tr_no,"10224"))
            total_charge = 550*n;
        printf("ticket total cost of the ticket is %d\n",total_charge);
        printf("the destination is %s\n",destination);
        printf("the departure time is %s",time);
        printf("name%15s%15s%15s\n","age","ticket_no","seat_no");
        for(int i=0;i<n;i++)
        {
            list_passengers[i].ticket_no = initial_ticket_no++;
            list_passengers[i].seat_no = initial_seat_no++;
            printf("%s%15d%15d%15d\n",list_passengers[i].name,list_passengers[i].age,list_passengers[i].ticket_no,list_passengers[i].seat_no);
        }
    }
    return list_passengers;
    
}
void cancel(details_t* list,int a,int n)
{
    if(list != NULL)
    {
        int i;
        printf("before cancellation\n");
        for(i=0;i<n;i++)
        {
            printf("%s%15d%15d\n",list[i].name,list[i].age,list[i].ticket_no);
        }
        for(i=0;i<n;i++)
        {
            if(a==list[i].ticket_no)
            { 
                
                int k = i;
                while(k<n)
                {
                    list[k] = list[k+1];
                    k = k+1;
                }
                printf("ticket is successfully cancelled\n");
                break; 
            }
            else
            {
                printf("");
            }
        }
        if(i==n)
        {
            printf("the ticket number does not exist\n");
        }
        printf("after cancellation\n");
        for(i=0;i<n;i++)
        {
            printf("%s%15d\n",list[i].name,list[i].age);
        }
    }
    else
    {
        printf("please do the reservation first\n");
    }
}
