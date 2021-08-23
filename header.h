struct passenger_details
{
    char name[25];
    int age;
    int ticket_no;
    int seat_no;
    //struct passenger_details* link;
};
typedef struct passenger_details details_t;
details_t* reserve(int);
void available_trains(void);
void cancel(details_t*,int,int);

