#include<stdio.h>
#include<stdlib.h>
int main_exit;
char name[50];
int diposit_amt,amt=10000,acc_no;
void menu();
void new_account();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_details();
void last_details();
void transaction_detail();
void divider()

{
    for(int i=0;i<50;i++)
    {
        printf("-");
    }
}
int withdraw_amt;
int transfer_amt;

int main()
{
    int choice;
   system("cls");

       while(1)
         {
             menu();

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            new_account();
            break;
        case 2:
            deposit_money();
            break;
        case 3:
            withdraw_money();
            break;
        case 4:
            transfer_money();
            break;
        case 5:
            account_details();
            break;
        case 6:
             transaction_detail();
            break;

        case 7:
            last_details();
            exit(0);
            break;
        default:
            printf("invalid choice!!!!");
        }


         }



}
void menu()
{
        printf("\nMAIN MENU \n");
        divider();

        printf("\n1.Create Account\n");
        printf("2.Deposit Money\n");
        printf("3.Withdraw Money\n");
        printf("4.Transfer Money\n");
        printf("5.Account Details\n");
        printf("6.Transcition Details\n");
        printf("7.Exit\n");

}
void new_account()
{
    system("cls");
char x1[10],x2[10],x3[10],x4[10],x5[10],x6[10],x7[10],x8[10],x9[10],x10[10],x11[10];
 printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

 printf("\n\nFIRST NAME: ");
 scanf("%s", x1);

 printf("\n\n\nLAST NAME: ");
 scanf("%s", x2);

 printf("\n\nFATHER's NAME: ");
 scanf("%s", x3);

 printf("\n\nMOTHER's NAME: ");
 scanf("%s", x4);

 printf("\n\nADDRESS: ");
 scanf("%s", x5);

 printf("\n\nACCOUNT TYPE::\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
 scanf("%s", x6);

 printf("\n\nDATE OF BIRTH..");
 printf("\nDATE-");
 scanf("%s", x7);
 printf("\nMONTH-");
 scanf("%s", x8);
 printf("\nYEAR-");
 scanf("%s", x9);

 printf("\n\nPHONE NUMBER: ");
 scanf("%s", x10);

 printf("\n\nUSERNAME:  ");
 scanf("%s", x11);
 printf("\n******Account created successfully!******\n");
 printf("\n\n\nPress Enter key to go main menu........\n");
 getch();
 system("cls");
}
void deposit_money()
{   system("cls");

    time_t tm;
    time(&tm);
    FILE *ptr=fopen("D:\\program.txt","a");
    char x[10];
    printf("Enter account name= ");
    scanf("%s",x);
    printf("Enter your account no= ");
    scanf("%d",&acc_no);
    printf("\n\n\n******Depositing Money******\n");
    divider();
    printf("\n    Enter the amount: ");
    scanf("%d",&diposit_amt);
    amt=amt+diposit_amt;
    printf("    MONEY DEPOSITED\n");
    printf("    Current balance: %d\n",amt);
    fprintf(ptr,"    Rs%d had been deposited to your account\n",diposit_amt);
    fprintf(ptr,"    Date /time of transaction %s",ctime(&tm));
    fclose(ptr);
    printf("Press Enter key to go main menu........\n");
    getch();
    system("cls");

}
void withdraw_money()
{
    system("cls");

    time_t tm;
    time(&tm);
    FILE *ptr=fopen("D:\\program.txt","a");
    char x[10];
    printf("Enter account name= ");
    scanf("%s",x);
    printf("Enter your account no= ");
    scanf("%d",&acc_no);

    printf("\n\n    ******WITHDRAW MONEY******\n");
    divider();
    printf("\n    Enter the amount: ");
    scanf("%d",&withdraw_amt);
    amt=amt-withdraw_amt;
    printf("    MONEY WITHDRAWN\n");
    printf("    Current balance %d",amt);
    fprintf(ptr,"    Rs%d had been withdrawn to your account\n",withdraw_amt);
    fprintf(ptr,"    Date /time of transaction %s",ctime(&tm));
    fclose(ptr);
    printf("\n\n\nPress Enter key to go main menu........\n");
    getch();
    system("cls");
}

void transfer_money()
{
    system("cls");

    int ac;
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("D:\\program.txt","a");
    char x[10];
    printf("Enter account name= ");
    scanf("%s",x);
    printf("Enter your account no= ");
    scanf("%d",&acc_no);

    printf("\n\n      ******TRANSFERRING MONEY******\n");
    divider();
    printf("\n    Enter the amount: ");
    scanf("%d",&transfer_amt);
    printf("    Enter the ac no which you want to transfer: ");
    scanf("%d",&ac);
    if(amt<transfer_amt)
    {
        printf("    You dont have sufficieant balance\n");

    }
    else
    {
        amt=amt-transfer_amt;
        printf("    Money Transfered\n");
        printf("    Current balance: %d",amt);
    fprintf(ptr,"    Rs%d had been transfered to your account\n",transfer_amt);
    fprintf(ptr,"    Date /time of transaction %s",ctime(&tm));
    }
    fclose(ptr);

     printf("\n\n\nPress Enter key to go main menu........\n");
      getch();
  system("cls");
}
void account_details()
{
    system("cls");
    int i;
    char x[10];
    printf("Enter account name= ");
    scanf("%s",x);
    printf("Enter your account no= ");
    scanf("%d",&acc_no);
    printf("\n\n\n   ******ACCOUNT DETAIL******\n");
    for(i=0;i<50;i++)
    {
        printf("-");

    }
    printf("\n    Name: %s\n",x);
    printf("    Account No: %d\n",acc_no);
    printf("    Total Balane: %d\n",amt);
    printf("\n\n\nPress Enter key to go main menu........\n");
    getch();
    system("cls");

}
void transaction_detail()
{
    system("cls");
    FILE *ptr=fopen("D:\\program.txt","r");


    char c=fgetc(ptr);
    if(c== EOF)
    {
         printf("NO recent transaction\n");

    }
    else
    {

        printf("\n\n\n    ******Transation Details******");
        while(c != EOF)
        {
            printf("%c",c);
            c=fgetc(ptr);
        }
    }
    getch();

  system("cls");
}

void last_details()
{   system("cls");
    printf("      press any key For exting....");
    return 0;
    getch();
}
