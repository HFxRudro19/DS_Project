#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Reg
{
    char n1[50];
    char n2[50];
    char un[50];
    char id[50];
};

typedef struct SCH
{
    char shift1[20];
    char time1[50];
    char bus1[50];

    char shift2[20];
    char time2[50];
    char bus2[50];
} sch;

typedef struct Node
{
    char road_name1[50];
    char road_name2[50];
    sch schedule;
    struct Node *next;
} node;

typedef struct Stack
{
    char bus[10];
    struct Stack *next;
} stack;

int c1 = 0, c2 = 0, count2 = 0, d, g, h, co1 = 0, p, pp, r = 0, rr, e, ee, c, cc, count = 0, count_1 = 0;
char ch1[101], ch2[101];

node *head;
stack *top1, *top2;

void fornt1();
void fornt2();
void fornt3();
void adminFornt1();
void reg();
void login();
void authority();
int transport_menu();
char admin_security1();
char admin_verify();
int admin_menu();
int Transport_Card_Chack();
void admin_insert();
void Update_print();
void search();
void update();
void del();
void push1(char d[10]);
void push2(char e[10]);
void print1();
void print2();
char *peek1();
char *peek2();
int booking_ticket_M();
int booking_ticket_D();
int del_booking_ticket_M();
int del_booking_ticket_D();
char *pop_M();
char *pop_D();

int main()
{
    int a;
    fornt3();
    printf("\n\n\t\t\t\t\t\t|------------------|\t\t  |-------------------|\t\t|----------------|\n");
    printf("\t\t\t\t\t\t|\033[5;36m  1. Admin Panal.\033[0m |\t\t  |\033[5;36m   2. User panal\033[0m   |\t\t|\033[5;36m   3. About Us\033[0m  |\n");

    printf("\t\t\t\t\t\t|------------------|\t\t  |-------------------|\t\t|----------------|\n");

    printf("\033[5;32m");
    printf("\n\n\n\t\t\t\t\tEnter your choice: ");
    printf("\033[0m");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
    {
        adminFornt1();
        admin_security1();

        while (1)
        {

            d = admin_menu();

            switch (d)
            {
            case 1:
            {
                system("cls");
                admin_insert(head);
                break;
            }
            case 2:
            {
                system("cls");
                char ch[50];
                printf("\033[5;33m");
                printf("\n\n\t\t|-----------------|\n");
                printf("\t\t\t\t|     UPDATE      |\n");
                printf("\t\t\t\t|-----------------|\n");
                printf("\033[0m");
                printf("\n\n\t\t\t\tEnter Road name: ");
                fflush(stdin);
                gets(ch);
                update(head, ch);
                break;
            }
            case 3:
            {
                system("cls");
                char ch[50];
                printf("\033[5;33m");
                printf("\t\t\t\t|-----------------|\n");
                printf("\t\t\t\t|     DELETE      |\n");
                printf("\t\t\t\t|-----------------|\n");
                printf("\033[0m");
                printf("\n\n\t\t\t\tEnter Road name: ");
                fflush(stdin);
                gets(ch);
                del(head, ch);
                break;
            }
            case 4:
            {
                int c3 = 0;
                while (1)
                {
                    int x;
                    printf("\t\t\t\t\t\t\t\t\t\tPlease select the road : \n");
                    printf("\t\t\t\t\t\t\t\t1. Mirpur.\n");
                    printf("\t\t\t\t\t\t\t\t2. Dhanmondi.\n");
                    printf("\t\t\t\t\t\t\t\t3. Exit.\n");
                    printf("\033[5;38m");
                    printf("\t\t\t\t\t\t\t\tEnter the number you want: ");
                    printf("\033[0m");
                    scanf("%d", &x);
                    switch (x)
                    {
                    case 1:
                    {
                        printf("\033[5;33m");
                        printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                        printf("\t\t\t\t\t\t\t\t|     MIRPUR      |\n");
                        printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                        printf("\033[0m");
                        char m[10];
                        while (1)
                        {
                            // printf("\033[5;39m");
                            printf("\n\t\t\t\t\t\t\t\tEnter the data of bus : ");
                            // printf("\033[0m");
                            fflush(stdin);
                            gets(m);
                            if (strcmp(m, "0") == 0)
                            {
                                printf("\033[5;32m");
                                printf("\n\n\t\t\t\t\t\t\tSuccessfully added all the imformation of bus.....\n\n");
                                printf("\033[0m");
                                getchar();
                                system("cls");
                                break;
                            }
                            else
                            {
                                push1(m);
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        printf("\033[5;33m");
                        printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                        printf("\t\t\t\t\t\t\t\t|    Dhanmondi    |\n");
                        printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                        printf("\033[0m");
                        char o[10];
                        while (1)
                        {
                            printf("\n\t\t\t\t\t\t\t\tEnter the data of bus : ");
                            fflush(stdin);
                            gets(o);
                            if (strcmp(o, "0") == 0)
                            {
                                printf("\033[5;32m");
                                printf("\n\n\t\t\t\t\t\t\tSuccessfully added all the imformation of bus.....\n\n");
                                printf("\033[0m");
                                getchar();
                                system("cls");
                                break;
                            }
                            else
                            {
                                push2(o);
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        c3++;
                        printf("\033[5;33m");
                        printf("\n\n\t\t\t\t\t\t\t\t press ENTER to continue.....");
                        printf("\033[0m");
                        getch();
                        system("cls");
                        printf("\n\n\n\n");
                        break;
                    }
                    }
                    if (c3 == 1)
                    {
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                printf("\033[5;34m");
                printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                printf("\t\t\t\t\t\t\t\t|     MIRPUR      |\n");
                printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                printf("\033[0m");
                printf("\n\n\t\t\t\t\t\t\tAvailable bases are: .....\n\n");
                print1();
                printf("\033[5;34m");
                printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                printf("\t\t\t\t\t\t\t\t|    Dhanmondi    |\n");
                printf("\t\t\t\t\t\t\t\t|-----------------|\n");
                printf("\033[0m");
                printf("\n\n\t\t\t\t\t\t\tAvailable bases are: .....\n\n");
                print2();
                getch();
                system("cls");
                printf("\n\n\n\n");
                break;
            }
            case 6:
            {
                printf("\033[5;33m");
                printf("\n\n\t\t\t\tpress ENTER to continue.....");
                printf("\033[0m");
                getch();
                system("cls");
                main();
                break;
            }
            }
        }
        /*printf("press ENTER to continue.....");
        getch();
        system("cls");
        main();*/
        break;
    }

    case 2:
    {
        system("cls");
        printf("\n\n\n");
        int count2 = 0;
        fornt1();
        if (c1 > 0)
        {
            system("cls");
            fornt2();
            login();
        }
        while (1)
        {
            count2++;
            if (count2 == 1)
            {
                printf("\n\n");
                h = Transport_Card_Chack();
            }
            else
            {
                printf("\n\n");
                h = transport_menu();
            }

            switch (h)
            {
            case 1:
            {
                system("cls");
                printf("\n\n\n");
                char ch[50];
                printf("\t\t\t\tEnter Road name: ");
                fflush(stdin);
                gets(ch);
                search(head, ch);
                break;
            }

            case 2:
            {
                system("cls");
                printf("\n\n\n");
                Update_print(head);
                break;
            }

            case 3:
            {
                system("cls");
                int y, c4 = 0;
                while (1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\tPlease select the road : \n");
                    printf("\t\t\t\t\t\t\t\t1. Mirpur.\n");
                    printf("\t\t\t\t\t\t\t\t2. Dhanmondi.\n");
                    printf("\t\t\t\t\t\t\t\t3. Exit.\n");
                    printf("\033[5;37m");
                    printf("\t\t\t\t\t\t\t\tEnter the number you want: ");
                    printf("\033[0m");
                    scanf("%d", &y);
                    switch (y)
                    {
                    case 1:
                    {
                        p = booking_ticket_M();
                        if (p == 50)
                        {
                            char *k;
                            k = pop_M();
                            printf("\n\n\n\t\t\t\t\t|-----------------------------------------|\n");
                            printf("\t\t\t\t\t\t\t\t|\033[1;32m    The\033[5;31m %s\033[0m bus is ready to leave.\033[0m        |\n", k);
                            printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n\n");
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\t\t|-----------------------------------------|\n");
                            printf("\t\t\t\t\t\t\t\t|\033[1;31m     NO bus is ready to leave.\033[0m           |\n");
                            printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n\n");
                        }
                        printf("\033[5;32m");
                        printf("\n\n\t\t\t\t\t\t|-----------------------------------------|\n");
                        printf("\t\t\t\t\t\t\t\t|     Successfully added your seat.       |\n");
                        printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n\n");
                        printf("\033[0m");
                        getch();
                        system("cls");

                        break;
                    }
                    case 2:
                    {
                        pp = booking_ticket_D();
                        if (pp == 50)
                        {
                            char *l;
                            l = pop_D();
                            printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n");
                            printf("\t\t\t\t\t\t\t\t|\033[1;32m    The\033[5;31m %s\033[0m bus is ready to leave.\033[0m        |\n", l);
                            printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n\n");
                        }
                        else
                        {
                            printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n");
                            printf("\t\t\t\t\t\t\t\t|\033[1;31m     NO bus is ready to leave.\033[0m           |\n");
                            printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n\n");
                        }
                        printf("\033[5;32m");
                        printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n");
                        printf("\t\t\t\t\t\t\t\t|     Successfully added your seat.       |\n");
                        printf("\t\t\t\t\t\t\t\t|-----------------------------------------|\n");
                        printf("\033[0m");
                        getch();
                        system("cls");
                        break;
                    }
                    case 3:
                    {
                        c4++;
                        printf("\033[5;33m");
                        printf("\n\n\t\t\t\t\t\t\t\t press ENTER to continue.....");
                        printf("\033[0m");
                        getch();
                        system("cls");
                        break;
                    }
                    }
                    if (c4 == 1)
                    {
                        break;
                    }
                }

                break;
            }

            case 4:
            {
                system("cls");
                int z, c5 = 0;
                while (1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\tPlease select the road : \n");
                    printf("\t\t\t\t\t\t\t\t1. Mirpur.\n");
                    printf("\t\t\t\t\t\t\t\t2. Dhanmondi.\n");
                    printf("\t\t\t\t\t\t\t\t3. Exit.\n");
                    printf("\033[5;37m");
                    printf("\t\t\t\t\t\t\t\tEnter the number you want: ");
                    printf("\033[0m");
                    scanf("%d", &z);
                    switch (z)
                    {
                    case 1:
                    {
                        r = del_booking_ticket_M();
                        break;
                    }
                    case 2:
                    {
                        rr = del_booking_ticket_D();
                        break;
                    }
                    case 3:
                    {
                        c5++;
                        printf("\033[5;33m");
                        printf("\n\n\t\t\t\t\t\t\t\t press ENTER to continue.....");
                        printf("\033[0m");
                        getch();
                        system("cls");
                        break;
                    }
                    }
                    if (c5 == 1)
                    {
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                printf("\033[5;33m");
                printf("\t\t\t\t\t\t\t\tpress ENTER to continue.....");
                printf("\033[0m");
                getch();
                system("cls");
                main();
                break;
            }
            }
        }
        break;
    }
    case 3:
    {
        authority();
        break;
    }
    }
}

void admin_insert(node *h)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    printf("\033[5;38m");
    printf("\n\n\t\t\t\t|---------------|\n");
    printf("\t\t\t\t|\033[5;34m MORNING SHIFT |\n");
    printf("\t\t\t\t|---------------|\n\n\n");
    printf("\033[0m");
    sch sc;
    char name[50];
    printf("\t\t\tEnter the shift 1: ");
    fflush(stdin);
    gets(name);
    strcpy(sc.shift1, name);

    printf("\t\t\tEnter the time 1: ");
    fflush(stdin);
    gets(name);
    strcpy(sc.time1, name);

    printf("\t\t\tEnter the bus 1: ");
    fflush(stdin);
    gets(name);
    strcpy(sc.bus1, name);

    printf("\t\t\tEnter the road name: ");
    char rn[30];
    fflush(stdin);
    gets(rn);
    strcpy(t->road_name1, rn);

    printf("\033[5;38m");
    printf("\n\n\t\t|-----------------|\n");
    printf("\t\t\t\t|\033[5;34m AFTERNOON SHIFT |\n");
    printf("\t\t\t\t|-----------------|\n\n\n");
    printf("\033[0m");

    char name1[50];
    printf("\t\t\tEnter the shift 2: ");
    fflush(stdin);
    gets(name1);
    strcpy(sc.shift2, name1);

    printf("\t\t\tEnter the time 2: ");
    fflush(stdin);
    gets(name1);
    strcpy(sc.time2, name1);

    printf("\t\t\tEnter the bus 2: ");
    fflush(stdin);
    gets(name1);
    strcpy(sc.bus2, name1);

    printf("\t\t\tEnter the road name: ");
    char rna[30];
    fflush(stdin);
    gets(rna);
    strcpy(t->road_name2, rna);

    t->schedule = sc;
    t->next = NULL;

    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->next = t;
    }
    printf("\n\n\n");
}

void update(node *h, char ch[50])
{
    node *t = h;
    int flag1 = 0, flag2 = 0;
    while (t != NULL)
    {
        if (strcmp(t->road_name1, ch) == 0)
        {
            flag1 = 1;
            break;
        }
        else if (strcmp(t->road_name2, ch) == 0)
        {
            flag2 = 1;
            break;
        }
        t = t->next;
    }
    if (flag1 == 1)
    {
        node *temp;
        temp = t;
        printf("\n\n\t\t\t\tRoad: %s\n\t\t\t\tShift: %s\n\t\t\t\tTime : %s\n\t\t\t\tBus: %s\n\n", temp->road_name1, temp->schedule.shift1, temp->schedule.time1, temp->schedule.bus1);
        printf("\033[5;36m");
        printf("\n\n\t\t\t\t.....Update Schedule Details.....\n");
        printf("\033[0m");

        printf("\n\n\t\t|---------------|\n");
        printf("\t\t\t\t| MORNING SHIFT |\n");
        printf("\t\t\t\t|---------------|\n\n\n");
        char name[50];
        printf("\t\t\t\tEnter the shift 1: ");
        fflush(stdin);
        gets(name);
        strcpy(t->schedule.shift1, name);

        printf("\t\t\t\tEnter the time 1: ");
        fflush(stdin);
        gets(name);
        strcpy(t->schedule.time1, name);

        printf("\t\t\t\tEnter the bus 1: ");
        fflush(stdin);
        gets(name);
        strcpy(t->schedule.bus1, name);

        printf("\t\t\t\tEnter the road name: ");
        char rn[30];
        fflush(stdin);
        gets(rn);
        strcpy(t->road_name1, rn);
        printf("\033[5;32m");
        printf("\n\n\t\t\t\tUpdate is successfulldy done.........");
        printf("\033[0m");
        getchar();
        printf("\n\n\n");
    }
    else if (flag2 == 1)
    {
        node *temp;
        temp = t;
        printf("\n\n\t\t\t\tRoad: %s\n\t\t\t\tShift: %s\n\t\t\t\tTime : %s\n\t\t\t\tBus: %s\n\n", temp->road_name2, temp->schedule.shift2, temp->schedule.time2, temp->schedule.bus2);
        printf("\033[5;36m");
        printf("\n\n\t\t\t\t.....Update Schedule Details.....\n");
        printf("\033[0m");

        printf("\n\n\t\t|-----------------|\n");
        printf("\t\t\t\t| AFTERNOON SHIFT |\n");
        printf("\t\t\t\t|-----------------|\n\n\n");

        char name1[50];
        printf("\t\t\t\tEnter the shift 2: ");
        fflush(stdin);
        gets(name1);
        strcpy(t->schedule.shift2, name1);

        printf("\t\t\t\tEnter the time 2: ");
        fflush(stdin);
        gets(name1);
        strcpy(t->schedule.time2, name1);

        printf("\t\t\t\tEnter the bus 2: ");
        fflush(stdin);
        gets(name1);
        strcpy(t->schedule.bus2, name1);

        printf("\t\t\t\tEnter the road name: ");
        char rna[30];
        fflush(stdin);
        gets(rna);
        strcpy(t->road_name2, rna);

        printf("\033[5;32m");
        printf("\n\n\t\t\t\tUpdate is successfulldy done.........");
        printf("\033[0m");
        getchar();
        printf("\n\n\n");
    }
    else
    {
        printf("\033[5;31m");
        printf("\n\n\n\n\t\t\t\tWrong Road Name.......");
        printf("\033[0m");
        return;
    }
}

void Update_print(node *h)
{
    node *he;
    he = h;
    while (he != NULL)
    {
        printf("\n\n\t\t\t\tRoad: %s\n\t\t\t\tShift: %s\n\t\t\t\tTime : %s\n\t\t\t\tBus: %s\n\n\t\t\t\tRoad: %s\n\t\t\t\tShift: %s\n\t\t\t\tTime : %s\n\t\t\t\tBus: %s\n\n\n", he->road_name1, he->schedule.shift1, he->schedule.time1, he->schedule.bus1, he->road_name2, he->schedule.shift2, he->schedule.time2, he->schedule.bus2);
        he = he->next;
    }
}

void search(node *h, char ch[50])
{
    node *t = h;
    int flag1 = 0, flag2 = 0;
    while (t != NULL)
    {
        if (strcmp(t->road_name1, ch) == 0)
        {
            flag1 = 1;
            break;
        }
        else if (strcmp(t->road_name2, ch) == 0)
        {
            flag2 = 1;
            break;
        }
        t = t->next;
    }
    if (flag1 == 1)
    {
        node *temp;
        temp = t;
        printf("\n\n\t\t\t\tRoad: %s\n\t\t\t\tShift: %s\n\t\t\t\tTime : %s\n\t\t\t\tBus: %s\n\n", temp->road_name1, temp->schedule.shift1, temp->schedule.time1, temp->schedule.bus1);
    }
    else if (flag2 == 1)
    {
        node *temp;
        temp = t;
        printf("\n\n\t\t\t\tRoad: %s\n\t\t\t\tShift: %s\n\t\t\t\tTime : %s\n\t\t\t\tBus: %s\n\n", temp->road_name2, temp->schedule.shift2, temp->schedule.time2, temp->schedule.bus2);
    }
    else
    {
        printf("\033[5;31m");
        printf("\n\n\t\t\t\tWrong Road Name.......\n\n");
        printf("\033[0m");
        getchar();
        system("cls");
        return;
    }
}

void del(node *h, char ch[50])
{
    node *t = h;
    int flag1 = 0, flag2 = 0, count3 = 0;
    while (t != NULL)
    {
        if (strcmp(t->road_name1, ch) == 0)
        {
            flag1 = 1;
            break;
        }
        else if (strcmp(t->road_name2, ch) == 0)
        {
            flag2 = 1;
            break;
        }
        count3++;
        t = t->next;
    }
    if (flag1 == 1)
    {
        /*node *temp;
        temp = t;
        printf("\n\nRoad: %s\nShift: %s\nTime : %s\nBus: %s\n\n", temp->road_name1, temp->schedule.shift1, temp->schedule.time1, temp->schedule.bus1);
        // fflush(stdin);
        // getchar();*/
        printf("\n\n\t\t\t\t.....Are you sure to delete this schedule details?\n");
        printf("\n\t\t\t\t\t..... It will delete DSC to %s. All the information ........\n", ch);
        printf("\033[5;36m");
        printf("\n\t\t\t\tEnter Choice(Y/N):");
        printf("\033[0m");
        char e;
        scanf("%c", &e);
        if (e == 'Y' || e == 'y')
        {
            if (count3 == 0)
            {

                node *temp = h;
                head = h->next;
                free(temp);
                printf("\033[5;32m");
                printf("\n\t\t\t\tRoad Details Deleted successfull..");
                printf("\033[0m");
                getchar();
                printf("\n\n\n");
            }
            else
            {
                node *t = h;
                while (t->next->road_name1 != ch)
                {
                    t = t->next;
                }
                node *temp = t;
                temp = t->next;
                t->next = temp->next;
                free(temp);
                printf("\033[5;32m");
                printf("\n\t\t\t\tRoad Details Deleted successfull..");
                printf("\033[0m");
                getchar();
                printf("\n\n\n");
            }
        }
        else if (e == 'N' || e == 'n')
        {
            return;
        }
        else
        {
            printf("\033[5;31m");
            printf("\n\t\t\t\tWrong input...");
            printf("\033[0m");
            getchar();
            printf("\n\n\n");
        }
    }
    else if (flag2 == 1)
    {
        /*node *temp;
        temp = t;
        printf("\n\nRoad: %s\nShift: %s\nTime : %s\nBus: %s\n\n", temp->road_name2, temp->schedule.shift2, temp->schedule.time2, temp->schedule.bus2);
        // fflush(stdin);
        // getchar();*/
        printf("\n\n\t\t\t\t.....Are you sure to delete this schedule details?");
        printf("\n\t\t\t\t\t..... It will delete %s to DSC. All the information ........\n", ch);
        printf("\033[5;36m");
        printf("\n\t\t\t\tEnter Choice(Y/N):");
        printf("\033[0m");
        char e;
        scanf("%c", &e);
        if (e == 'Y' || e == 'y')
        {
            if (count3 == 0)
            {

                node *temp = h;
                head = h->next;
                free(temp);
                printf("\033[5;32m");
                printf("\n\t\t\t\tRoad Details Deleted successfull..");
                printf("\033[0m");
                getchar();
                printf("\n\n\n");
            }
            else
            {
                node *t = h;
                while (t->next->road_name2 != ch)
                {
                    t = t->next;
                }
                node *temp = t;
                temp = t->next;
                t->next = temp->next;
                free(temp);
                printf("\033[5;32m");
                printf("\n\t\t\t\tRoad Details Deleted successfull..");
                printf("\033[0m");
                getchar();
                printf("\n\n\n");
            }
        }
        else if (e == 'N' || e == 'n')
        {
            return;
        }
        else
        {
            printf("\033[5;31m");
            printf("\n\t\t\t\tWrong input...");
            printf("\033[0m");
            getchar();
            printf("\n\n\n");
        }
    }
    else
    {
        printf("\033[5;31m");
        printf("\n\n\t\t\t\tWrong Road Name.......\n\n\n");
        printf("\033[0m");
        return;
    }
}

void push1(char d[10])
{
    stack *head = (stack *)malloc(sizeof(stack));
    if (head == NULL)
    {
        printf("Stack is full.\n");
        exit(1);
    }
    strcpy(head->bus, d);
    head->next = NULL;

    head->next = top1;
    top1 = head;
}

void push2(char e[10])
{
    stack *head = (stack *)malloc(sizeof(stack));
    if (head == NULL)
    {
        printf("Stack is full.\n");
        exit(1);
    }
    strcpy(head->bus, e);
    head->next = NULL;

    head->next = top2;
    top2 = head;
}

void print1()
{
    stack *temp;
    temp = top1;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t\t\t|-----------|\n");
        printf("\t\t\t\t\t\t\t\t|   %s   |\n", temp->bus);
        printf("\t\t\t\t\t\t\t\t|-----------|\n\n");
        temp = temp->next;
    }
    printf("\n\n\n");
}
void print2()
{
    stack *temp;
    temp = top2;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t\t\t|-----------|\n");
        printf("\t\t\t\t\t\t\t\t|   %s   |\n", temp->bus);
        printf("\t\t\t\t\t\t\t\t|-----------|\n\n");
        temp = temp->next;
    }
    printf("\n\n\n");
}

char *peek1()
{
    return top1->bus;
}
char *peek2()
{
    return top2->bus;
}

int booking_ticket_M()
{
    printf("\033[5;36m");
    printf("\t\t\t\t\t\t\t\t|-----------------|\n");
    printf("\t\t\t\t\t\t\t\t|     MIRPUR      |\n");
    printf("\t\t\t\t\t\t\t\t|-----------------|\n");
    printf("\033[0m");
    printf("\n\n\t\t\t\t\t\t\t\tAvailable bus name is ==>>  %s\n", peek1());
    printf("\t\t\t\t\t\t\t\tAvailable sit is ==>> 50\n");
    if (r > 0)
    {
        printf("\t\t\t\t\t\t\t\tTotal booked tickets are ==>> %d\n", r);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tTotal booked tickets are ==>> %d\n", count);
    }

    int b, i, g;
    g = r;
    if (g > 0)
    {
        count = g;
    }

    printf("\n\n\t\t\t\tEnter how many seat you need: ");
    scanf("%d", &b);
    if (count == -1)
    {
        for (i = 1; i <= b + 1; i++)
        {
            count++;
        }
        c = count;
        printf("\t\t\t\tTotal booked tickets are ==>> %d\n", count);
        if (count == 50)
        {
            count = 0;
        }
        return c;
    }
    else
    {
        for (i = 1; i <= b; i++)
        {
            count++;
        }
        c = count;
        printf("\t\t\t\tTotal booked tickets are ==>> %d\n", count);
        if (count == 50)
        {
            count = 0;
        }
        r = 0;
        return c;
    }
}

int booking_ticket_D()
{
    printf("\033[5;36m");
    printf("\t\t\t\t\t\t\t\t|-----------------|\n");
    printf("\t\t\t\t\t\t\t\t|    Dhanmondi    |\n");
    printf("\t\t\t\t\t\t\t\t|-----------------|\n");
    printf("\033[0m");
    printf("\n\n\t\t\t\t\t\t\t\tAvailable bus name is ==>>  %s\n", peek2());
    printf("\t\t\t\t\t\t\t\tAvailable sit is ==>> 50\n");
    if (rr > 0)
    {
        printf("\t\t\t\t\t\t\t\tTotal booked tickets are ==>> %d\n", rr);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tTotal booked tickets are ==>> %d\n", count_1);
    }

    int b, i, g;
    g = rr;
    if (g > 0)
    {
        count_1 = g;
    }

    printf("\n\n\t\t\t\tEnter how many seat you need: ");
    scanf("%d", &b);
    if (count_1 == -1)
    {
        for (i = 1; i <= b + 1; i++)
        {
            count_1++;
        }
        cc = count_1;
        printf("\t\t\t\tTotal booked tickets are ==>> %d\n", count_1);
        if (count_1 == 50)
        {
            count_1 = 0;
        }
        return cc;
    }
    else
    {
        for (i = 1; i <= b; i++)
        {
            count_1++;
        }
        cc = count_1;
        printf("\t\t\t\tTotal booked tickets are ==>> %d\n", count_1);
        if (count_1 == 50)
        {
            count_1 = 0;
        }
        rr = 0;
        return cc;
    }
}

int del_booking_ticket_M()
{
    int f, j, g;
    e = p;
    printf("\n\t\t\t\tGive the number of seat you want to\033[5;31m reject\033[0m: ");
    scanf("%d", &f);
    for (j = 1; j <= f; j++)
    {
        e--;
    }
    if (f == 1)
    {
        printf("\n\t\t\t\t\t\t\t\033[1;32mSuccessfully delete\033[5;31m %d\033[0m \033[1;32mticket\033[0m\n\n", f);
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\033[1;32mSuccessfully delete\033[5;31m %d\033[0m \033[1;32mticket's\033[0m\n\n", f);
    }
    g = e;
    return g;
}

int del_booking_ticket_D()
{
    int f, j, g;
    ee = pp;
    printf("\n\t\t\t\tGive the number of seat you want to \033[5;31mreject\033[0m: ");
    scanf("%d", &f);
    for (j = 1; j <= f; j++)
    {
        ee--;
    }
    if (f == 1)
    {
        printf("\n\t\t\t\t\t\t\t\033[1;32mSuccessfully delete\033[5;31m %d\033[0m \033[1;32mticket\033[0m\n\n", f);
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\033[1;32mSuccessfully delete\033[5;31m %d\033[0m \033[1;32mticket's\033[0m\n\n", f);
    }
    g = ee;
    return g;
}

char *pop_M()
{
    static char v[10];
    stack *temp;
    temp = top1;

    strcpy(v, top1->bus);

    top1 = top1->next;
    free(temp);
    temp = NULL;
    if (top1 == NULL)
    {
        printf("No bus is available.\n");
    }
    return v;
}

char *pop_D()
{
    static char v[10];
    stack *temp;
    temp = top2;

    strcpy(v, top2->bus);

    top2 = top2->next;
    free(temp);
    temp = NULL;
    if (top2 == NULL)
    {
        printf("No bus is available.\n");
    }
    return v;
}

void reg()
{
    c1 = 0;
    struct Reg r;
    FILE *regs;
    regs = fopen("reg1.txt", "a");

    printf("\n\n\n\t\t\t\t\t\t\t\tEnter your first name: ");
    fflush(stdin);
    gets(r.n1);
    printf("\n\t\t\t\t\t\t\t\tEnter your last name: ");
    fflush(stdin);
    gets(r.n2);
    printf("\n\t\t\t\t\t\t\t\tEnter your Username: ");
    fflush(stdin);
    gets(r.un);
    printf("\n\t\t\t\t\t\t\t\tEnter your password: ");
    fflush(stdin);
    gets(r.id);
    printf("\n");

    fwrite(&r, sizeof(r), 1, regs);
    fclose(regs);
    printf("\033[5;32m");
    printf("\n\n\t\t\t\t\t\t\t\tRegestration Successfully Completed.\n");
    printf("\033[0m");

    c1++;
}

void login()
{
    int count1 = 0;

    struct Reg r;
    char username[50], pass[50];
    FILE *regs;
    regs = fopen("reg1.txt", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\tUserID: ");
    fflush(stdin);
    gets(username);
    printf("\n\t\t\t\t\t\t\t\tPassword: ");
    fflush(stdin);
    gets(pass);

    while (fread(&r, sizeof(r), 1, regs))
    {

        if (strcmp(username, r.un) == 0 && strcmp(pass, r.id) == 0)
        {
            count1 = 1;
        }
        else
        {
            continue;
        }
    }

    if (count1 == 1)
    {
        printf("\033[5;32m");
        printf("\t\t\t\t\t\t\t\t|-------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t|      Login Successfully.      |\n");
        printf("\t\t\t\t\t\t\t\t|-------------------------------|\n");
        printf("\033[0m");
    }
    else
    {
        count2++;
        if (count2 == 3)
        {
            printf("\n\n\n\t\t\t\t\t\t\t\tI think you forget your UserID or Password\n");
            printf("\t\t\t\t\t\t\t\t    Don't worry. Please Regester again.\n");
            printf("\n\t\t\t\t\t\t\t\t FOr again Regestration , please press ENTER.....");
            getch();
            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t\t\tNow you regester your information, newly.\n\t\t\t\t\t\t\t\tPlease remember your UserId and Password.");
            printf("\n\t\t\t\t\t\t\t\tYour username is usrID.\n");
            printf("\t\t\t\t\t\t\t\tNow login with userID and Password\n");
            reg();
            printf("\n\t\t\t\t\t\t\t\tPlease press ENTER for contunue process...........");
            getch();
        }
        else
        {
            printf("\t\t\t\t\t\t\t\t\033[5;31mEncorrect UserID and Password.\033[0m\n\t\t\t\t\t\t\t\t\033[5;33mTry again.\033[0m\n");
            login();
        }
    }

    fclose(regs);
}

int Transport_Card_Chack()
{
    int a;
    char b[5];
    printf("\n\t\t\t\t\t\t\t\tDo you have transport Card?\n");
    printf("\t\t\t\t\t\t\t\t1.\033[5;35m YES\033[0m \t\t 2.\033[5;35m NO\033[0m\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d", &a);
    if (a == 1)
    {
        printf("\n\n\t\t\t\t\t\t\tPlease Give your transport pass code: ");
        fflush(stdin);
        gets(b);
        if (strcmp(b, "123") == 0)
        {
            system("cls");
            g = transport_menu();
            return g;
        }
        else
        {
            printf("\033[5;31m");
            printf("\n\n\t\t\t\t\t\t|----------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|     Envalide Transport Pass Code.      |\n");
            printf("\t\t\t\t\t\t\t\t|----------------------------------------|\n");
            printf("\033[0m");
            system("cls");
            printf("\n\n\n");
            Transport_Card_Chack();
        }
    }
    else
    {
        co1++;

        FILE *file;
        file = fopen("counter1.txt", "a");
        fprintf(file, "%d", co1);
        fclose(file);

        printf("\n\t\t\t\tYou use transport in ==>> ");

        file = fopen("counter1.txt", "r");
        // fscanf(file , "%d" , &co1);
        printf("%d", co1);
        fclose(file);

        printf("  times.\n\n");
        if (co1 >= 4)
        {
            printf("\n\t\tYou have already use 3 times. You can also use transport next semester.\n\t\t\t\tThank You\n\n");
            getch();
            system("cls");
            // fornt3();
            main();
        }
        // Transport_Card_Chack();
        // system("cls");
        g = transport_menu();
        return g;
    }
}

int transport_menu()
{
    int f;
    printf("\033[5;33m");
    printf("\t\t\t\t\t\t\t\t\t|-------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t|        MENU       |\n");
    printf("\t\t\t\t\t\t\t\t\t|-------------------|\n\n");
    printf("\033[0m");
    printf("\n\t\t\t\t\t\t\t\tChoose the answear: \n");
    printf("\t\t\t\t\t\t\t\t1. Search by area.\n");
    printf("\t\t\t\t\t\t\t\t2. See all upcomming schedule.\n");
    printf("\t\t\t\t\t\t\t\t3. Booking ticket.\n");
    printf("\t\t\t\t\t\t\t\t4. Delete booking.\n");
    printf("\t\t\t\t\t\t\t\t5. Exit.\n");
    printf("\033[5;37m");
    printf("\n\t\t\t\t\t\t\t\tEnter your choice: ");
    printf("\033[0m");
    scanf("%d", &f);
    return f;
}

int admin_menu()
{
    int e;
    printf("\n\t\t\tPlease select your desire option: \n");
    printf("\t\t\t1. Insert information.\n");
    printf("\t\t\t2. Update information.\n");
    printf("\t\t\t3. Delete information.\n");
    printf("\t\t\t4. Add bus information.\n");
    printf("\t\t\t5. Show bus information.\n");
    printf("\t\t\t6. Exit.\n");
    printf("\033[5;36m");
    printf("\t\t\t\tEnter a number: ");
    printf("\033[0m");
    scanf("%d", &e);
    return e;
}

void adminFornt1()
{
    system("cls");
    printf("\033[5;36m");
    printf("\n\t\t\t\t\t\t\t\t\t\t|-------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t  |      Admin Login        |\n");
    printf("\t\t\t\t\t\t\t\t\t\t  |-------------------------|\n\n");
    printf("\033[0m");

    printf("\t\t\t\t\t\t\t\t\t\t-------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t|         Please sir          |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|      Inter your admin       |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|\033[5;31m       security code\033[0m         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|            AND              |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|\033[5;31m          PASSWORD\033[0m           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t-------------------------------\n");
}

char admin_security1()
{
    printf("\033[5;37m");
    printf("\n\n\t\t\t\t\t\t\t\tAdmin userid : ");
    printf("\033[0m");
    fflush(stdin);
    gets(ch1);
    printf("\033[5;37m");
    printf("\t\t\t\t\t\t\t\tAdmin Password  : ");
    printf("\033[0m");
    fflush(stdin);
    gets(ch2);

    return admin_verify(ch1, ch2);
}

char admin_verify(char ch1[], char ch2[])
{
    system("cls");
    printf("\n\n\n");
    if (strcmp(ch1, "deb241-15-158@diu.edu.bd") == 0 && strcmp(ch2, "1008") == 0)
    {
        printf("\033[1;32m");
        printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t|            Mitin Deb Rudro            |\n");
        printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n");
        printf("\033[0m");
    }
    else if (strcmp(ch1, "adhora241-15-147@diu.edu.bd") == 0 && strcmp(ch2, "1817") == 0)
    {
        printf("\033[1;32m");
        printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t|            Adhora Madhuri             |\n");
        printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n");
        printf("\033[0m");
    }
    else if (strcmp(ch1, "swity241-15-477@diu.edu.bd") == 0 && strcmp(ch2, "1647") == 0)
    {
        printf("\033[1;32m");
        printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t|            Swity Saima                |\n");
        printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n");
        printf("\033[0m");
    }
    else if (strcmp(ch1, "durjoy241-15-282@diu.edu.bd") == 0 && strcmp(ch2, "1093") == 0)
    {
        printf("\033[1;32m");
        printf("\t\t\t\t\t\t\t\t\t\t---------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t|         Durjoy Das            |\n");
        printf("\t\t\t\t\t\t\t\t\t\t---------------------------------\n");
        printf("\033[0m");
    }
    else
    {
        c2++;
        if (c2 == 3)
        {
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t\t\t\t\t\tSORRY.\n");
            printf("\t\t\t\t\t\t\tPlease press ENTER To go back menu..........");
            printf("\033[0m");
            getch();
            system("cls");
            main();
        }

        system("cls");
        printf("\033[1;31m");
        printf("\t\t\t\t\t\t\t\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t|     Invalid user name and password     |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t------------------------------------------\n");

        printf("\t\t\t\t\t\t\t\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t|                Try Again               |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t------------------------------------------\n");
        printf("\033[0m");
        printf("\n");

        admin_security1();
    }
}
void fornt1()
{
    int n;
    printf("\033[5;33m");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t    If You haven't regestration so regestration first. \n\n\n");
    printf("\033[0m");
    printf("\t\t\t\t\t\t\t\t|--------------|\t\t\t   |---------------------|\n");
    printf("\t\t\t\t\t\t\t\t|\033[5;36m  1. Logint.\033[0m  |\t\t\t   |\033[5;36m   2. Regestration.\033[0m  |\n");
    printf("\t\t\t\t\t\t\t\t|--------------|\t\t\t   |---------------------|\n\n\n");

    printf("\t\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    if (n == 1)
    {
        login();
    }
    else if (n == 2)
    {
        reg();

        printf("\n\t\t\t\t\t\t\t\tYour\033[1;33m username\033[0m is \033[1;32musrID.\033[0m\n");
        printf("\t\t\t\t\t\t\t\tNow login with \033[1;32muserID\033[0m and \033[1;32mPassword\033[0m\n");
        printf("\033[5;34m");
        printf("\n\t\t\t\t\t\t\t\tPlease press ENTER for contunue process...........");
        printf("\033[0m");
        getch();
    }
    else
    {
        printf("\033[5;31m");
        printf("\n\n\n\t\t\t\t\t\t\t\tEncorrect Number.please enter the correct number.\n");
        printf("\033[0m");
        printf("\033[5;38m");
        printf("\n\t\t\t\t\t\t\t\tPlease press ENTER for contunue process...........");
        printf("\033[0m");
        getch();
        system("cls");

        main();
    }
}

void fornt2()
{

    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|   Welcome to our apps    |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");

    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|\033[5;32m       D\033[0mI\033[5;36mU\033[0m \033[5;33mEASY\033[0m \033[5;32mWAY\033[0m       |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    A Transport System    |\n\t\t\t\t\t\t\t\t\t\t|         Softwere         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
}

void fornt3()
{
    system("color 7");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|  Welcome to our project  |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");

    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|\033[5;32m       D\033[0mI\033[5;36mU\033[0m \033[5;33mEASY\033[0m \033[5;32mWAY\033[0m       |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    A Transport System    |\n\t\t\t\t\t\t\t\t\t\t|         Softwere         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|--------------------------|\n");
}

void authority()
{
    int b;
    system("cls");
    printf("\t\t\t\t\t\t\t\t\t\t-------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t|        INFORMATION OF GROUP MEMBERS     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t-------------------------------------------\n");

    printf("\t\t\t\t\t\t\t\t\t\t|------------------------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|           Group name :  [FALCONS]        |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|------------------------------------------|\n\n\n");

    printf("\t\t\t\t\t\t\t\t\t\t|------------------------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    NAME     : Mitin Deb Rudro.           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    ID       : 241-15-158                 |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    SECTION  : '66_N'                     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    PHONE NO : 01734779538                |\n");
    printf("\t\t\t\t\t\t\t\t\t\t| Designation : Project Administrator  &   |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|                   Group leader           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|------------------------------------------|\n\n\n");

    printf("\t\t\t\t|----------------------------------------|\t\t\t\t\t\t\t|----------------------------------------|\n");
    printf("\t\t\t\t|    NAME     : Adhora Madhuri           |\t\t\t\t\t\t\t|    NAME     : Durjoy Das               |\n");
    printf("\t\t\t\t|    ID       : 241-15-147               |\t\t\t\t\t\t\t|    ID       : 241-15-282               |\n");
    printf("\t\t\t\t|    SECTION  : '66_N'                   |\t\t\t\t\t\t\t|    SECTION  : '66_N'                   |\n");
    printf("\t\t\t\t|    PHONE NO : 01614043815              |\t\t\t\t\t\t\t|    PHONE NO : 01628108983              |\n");
    printf("\t\t\t\t| Designation : Database Administrator & |\t\t\t\t\t\t\t| Designation : Web manager    &         |\n");
    printf("\t\t\t\t|                   content writer       |\t\t\t\t\t\t\t|               video editor             |\n");
    printf("\t\t\t\t|----------------------------------------|\t\t\t\t\t\t\t|----------------------------------------|\n");

    printf("\n");

    printf("\t\t\t\t\t\t\t\t\t\t|----------------------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    NAME     : Swity Saima              |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    ID       : 241-15-477               |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    SECTION  : '66_N'                   |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|    PHONE NO : 01970296933              |\n");
    printf("\t\t\t\t\t\t\t\t\t\t| Designation : Software Designer &      |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|                    Developer           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t|----------------------------------------|\n");

    printf("\033[5;39m");
    printf("\n\n\t\t\tPress 1 for continue and 0 for exit.....");
    printf("\033[0m");
    scanf("%d", &b);
    if (b == 1)
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tThank Your for using our APPS.\n\t\t\t\t\t\t\t\t\t\t\t   Cheers.\n");
        exit(1);
    }
}   