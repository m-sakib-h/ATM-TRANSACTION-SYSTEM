                                        ///***ATM TRANSACTION***
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct atm
{
    long amountdeposit;
    long amountwithdraw;
    long airtime;
    long payment;
    long transfer;
}s;

void login();
void display();
void option();
void deposit();
void withdraw();
void airtime();
void design();
void payment();
void help();
void moneytransfer();
long getbalance();

const int pin=1111;
const int voter_id=19961996;

int main()
{
    design();
    login();
    option();
    fflush(stdin);
    getch();
    return 0;
}

void design()
{
    printf("              ** **          ** ***         ** ***         **           \n");
    printf("              **    **       **    **       **    **       **           \n");
    printf("              **     **      **      **     **      **     **           \n");
    printf("              **      **     **  ****       ** ****        **           \n");
    printf("              **     **      **      **     **      **     **           \n");
    printf("              **   **        **    **       **    **       **           \n");
    printf("              ** **      [_] ** ***     [_] ** ***     [_] ** ******* \n\n");

    printf("\n\t___________________________________________________________________\n");
    printf("\n\t\t           \"Dutch Bangla Bank Limited\"            \n");
    printf("\n\t___________________________________________________________________\n\n");
    printf("\t\t------------Welcome to our ATM service---------------\n\n\n");
    system("color 1b");
}

void login()
{
    int tmpPin;
    printf("\t\t\t    Please Enter Your Pin: ");
    vp :
    scanf("%d",&tmpPin);

    if(tmpPin==pin)
    {
        printf("\n\t\t\t          ***Valid pin***\n");
    }
    else
    {
        system("cls");
        design();
        printf("\n\t\t\t        !!!INVALID PIN!!!");
        printf("\n\n\n\n\t\t           Please Enter A Valid Pin: ");
        goto vp;
        login();    ///recursive function
    }
}

void option()
{
    char transaction='y';
    int k=0;
    valid:
    do
    {
        printf("\n\n\n\t\t     ****** What do you want to do? ******\n\n\n");
        printf("\t\t\t     1. Check your balance \n\n\n");
        printf("\t\t\t     2. Deposit money: \n\n\n");
        printf("\t\t\t     3. Withdraw money \n\n\n");
        printf("\t\t\t     4. Buy airtime \n\n\n");
        printf("\t\t\t     5. Payment \n\n\n");
        printf("\t\t\t     6. Money Transfer \n\n\n");
        printf("\t\t\t     7. Help\n\n\n");
        printf("\t\t\t     8. Exit\n\n\n");
        printf("\n\t\t     ###Please select a service(1-7) ### : ");

        int option;
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            display();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4 :
            airtime();
            break;
        case 5:
            payment();
            break;
        case 6:
            moneytransfer();
            break;
        case 7:
            help();
            break;
        case 8:
            exit(1);
        default:
            printf("\n\n\t\t\t      !!!Invalid option!!!\n");
            printf("\n\n\t\t \t   Please select a valid option: \n");

            goto valid;
            system("cls");
            design();
        }

        printf("\n\n\n\t\t***DO U WISH TO HAVE ANOTHER TRANSCATION?***(y/n): ");
        fflush(stdin);
        scanf("%c", &transaction);
        system("cls");
        design();
        if (transaction == 'n'|| transaction == 'N')
        {
            k = 1;
            printf("\n\n\n\n\t\t\t      THANKS FOR VISITING");
            printf("\n\n\t\t\t\t   :-):-):-)\n");
        }
    } while (!k);

}

void display()
{
    long bln=0;
    printf("\n\n\t\t     Your Current Balance is = %ld taka only",getbalance());
}

void deposit()
{
    system("cls");
    design();
    long amount;

    printf("\n\t\t              \xB2\xB2 \"Deposit MONEY\" \xB2\xB2\n");
    printf("\n\n\t\t      How much money you want to deposit ?: ");
    depo:
    scanf("%ld",&amount);
    if(amount>0)
    {
        FILE *fp;
        fp=fopen("deposit.txt","a");
        s.amountdeposit = amount;
        fwrite(&s,sizeof(s),1,fp);
        fclose(fp);
        printf("\n\n\t\t        ***Your Deposit Is = %ld Taka Only***",s.amountdeposit);
    }
    else if(amount<=0)
    {
        printf("\n\n\t\t            !!!Invalid Deposit Amount!!!\n");
        printf("\n\n\t                 Please Enter A Valid Deposit Amount:");
        goto depo;
    }
    fflush(stdin);
}

void withdraw()
{
    long bln;
    int user_pin;
    bln = getbalance();
    system("cls");
    design();
    long amountwithdraw;
    printf("\n\t\t             \xB2\xB2 ~WITHDRAW MONEY~ \xB2\xB2 \n\n");
    printf("\n\t\t    How much money do you want to withdraw ? : ");
    withdraw :
    scanf("%ld",&s.amountwithdraw);
    printf("\n\n\t\t            Enter your pin to confirm:");
    pinn:
    scanf("%d",&user_pin);

    if(user_pin==pin)     ///Check the pin
    {
        if(amountwithdraw<=0)
        {
            printf("\n\n\t\t      Please Enter A Valid Positive Amount: ");
            goto withdraw;
        }
        else if(s.amountwithdraw<=bln && s.amountwithdraw %20==0)
        {
            FILE *fp;
            fp =fopen("withdraw.txt","a");
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            printf("\n\n\t\t      Your Withdrawal Balance Is = %ld Taka Only\n",s.amountwithdraw);
        }
        else
        {
            if(s.amountwithdraw>bln)
            {
                printf("\n\n\t\t\t\n\n\t\t      !!! SORRY!!You don't have enough money !!!\n");
                printf("\n\n\t\t\t            :-( :-( :-( ");
            }
            else
            {
                printf("\n\n\t\t!! You must enter an amount that is divisible by 20 !! \n");
                printf("\n\n\t\t     Please Re-Enter Your Amount To Withdraw: ");
                goto withdraw;
            }
        }
        fflush(stdin);
    }

    else
    {
        system("cls");
        design();
        printf("\n\t\t\t        !!!INVALID PIN!!!");
        printf("\n\n\n\n\t\t             Please Enter A Valid Pin: ");
        goto pinn;
    }
}

void airtime()
{
    char sim_type[9];
    int n,user_pin,sim,length;
    long amount;
    long bln;
    bln = getbalance();
    system("cls");
    design();
    tt:
    printf("\n\n\t\t\t       \xB2\xB2~BUY AIRTIME~\xB2\xB2 ");
    printf("\n\n\n\t\t\t        ^_^Operators^_^\n");
    printf("\n\n\t\t\t         1.Robi\n");
    printf("\n\t\t\t         2.Banglalink\n");
    printf("\n\t\t\t         3.Grameenphone\n");
    printf("\n\t\t\t         4.Airtel\n");
    printf("\n\t\t\t         5.Teletalk\n");
    printf("\n\n\t\t\t  Please Select An Operator: ");

    scanf("%d",&sim);    ///Check the sim whom i want to send the money..

    switch(sim)
    {
        case 1:     ///check robi sim
        {
            system("cls");
            design();
            opop:
            printf("\n\t\t\t        ^_^Operators^_^: ");
            printf("\n\n\t\t\t             \"Robi\"");
            printf("\n\n\t\t\t           1.Prepaid\n ");
            printf("\n\t\t\t           2.Postpaid\n");
            printf("\n\n\t\t            Please Select An Option: ");
            scanf("%d",&n);

            switch(n)   ///Check the robi number wheather it is prepaid or postpaid ?
            {
                case 1:    ///check prepaid
                robipre:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t               \"ROBI\"\n");
                    printf("\n\n\t\t\t           ^_^PREPAID^_^\n");
                    printf("\n\n\t\t\t       Robi Number: ");
                    printf("018");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        am:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        pppz:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto am;
                            }
                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto pppz;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto robipre;
                    }
                    break;
                }

                case 2:    ///check postpaid
                robipost:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t               \"ROBI\"\n");
                    printf("\n\n\t\t\t           ^_^POSTPAID^_^ \n");
                    printf("\n\n\t\t\t       Robi Number: ");
                    printf("018");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        jm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        pppzp:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto jm;
                            }
                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto pppzp;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto robipost;
                    }
                    break;
                }
                default:
                    {
                        system("cls");
                        design();
                        printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
                        goto opop;
                    }
            }
            break;
        }

        case 2:     ///check Banglalink sim
        {
            system("cls");
            design();
            tpop:
            printf("\n\t\t\t         ^_^Operators^_^: ");
            printf("\n\n\t\t\t           \"Banglalink\"");
            printf("\n\n\t\t\t            1.Prepaid\n ");
            printf("\n\t\t\t            2.Postpaid\n");
            printf("\n\n\t\t            Please Select An Option: ");
            scanf("%d",&n);

            switch(n)   ///Check the Banglalink number wheather it is prepaid or postpaid ?
            {
                case 1:    ///check prepaid
                blnkpre:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t            \"Banglalink\"\n");
                    printf("\n\n\t\t\t           ^_^PREPAID^_^ \n");
                    printf("\n\n\t\t\t    Banglalink Number: ");
                    printf("019");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        sm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        ppjj:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto sm;
                            }
                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto ppjj;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto blnkpre;
                    }
                    break;
                }

                case 2:    ///check postpaid
                blnkpost:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t            \"Banglalink\"\n");
                    printf("\n\n\t\t\t           ^_^POSTPAID^_^ \n");
                    printf("\n\n\t\t\t     Banglalink Number: ");
                    printf("019");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        kkm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        ppkj:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto kkm;
                            }

                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto ppkj;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto blnkpost;
                    }
                    break;
                }
                default:
                    {
                        system("cls");
                        design();
                        printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
                        goto tpop;
                    }
            }
            break;
        }

        case 3:     ///check Gp sim
        {
            system("cls");
            design();
            jjop:
            printf("\n\t\t\t        ^_^Operators^_^: ");
            printf("\n\n\t\t\t         \"Grameenphone\"");
            printf("\n\n\t\t\t           1.Prepaid\n ");
            printf("\n\t\t\t           2.Postpaid\n");
            printf("\n\n\t\t            Please Select An Option: ");
            scanf("%d",&n);

            switch(n)   ///Check the robi number wheather it is prepaid or postpaid ?
            {
                case 1:    ///check prepaid
                gppre:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t           \"Grameenphone\"\n");
                    printf("\n\n\t\t\t            ^_^PREPAID^_^ \n");
                    printf("\n\n\t\t\t   Grameenphone Number: ");
                    printf("017");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        llm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        ppkko:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto llm;
                            }

                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto ppkko;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto gppre;
                    }
                    break;
                }

                case 2:    ///check postpaid
                gppost:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t             \"Grameenphone\"\n");
                    printf("\n\n\t\t\t             ^_^POSTPAID^_^ \n");
                    printf("\n\n\t\t\t    Grameenphone Number: ");
                    printf("017");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        rrm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        ptktq:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto rrm;
                            }

                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto ptktq;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto gppost;
                    }
                    break;
                }
                default:
                    {
                        system("cls");
                        design();
                        printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
                        goto jjop;
                    }
            }
            break;
        }

        case 4:     ///check Airtel sim
        {
            system("cls");
            design();
            lqp:
            printf("\n\t\t\t        ^_^Operators^_^: ");
            printf("\n\n\t\t\t            \"Airtel\"");
            printf("\n\n\t\t\t           1.Prepaid\n ");
            printf("\n\t\t\t           2.Postpaid\n");
            printf("\n\n\t\t            Please Select An Option: ");
            scanf("%d",&n);

            switch(n)   ///Check the Airtel number wheather it is prepaid or postpaid ?
            {
                case 1:    ///check prepaid
                airpre:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t             \"Airtel\"\n");
                    printf("\n\n\t\t\t          ^_^PREPAID^_^ \n");
                    printf("\n\n\t\t\t     Airtel Number: ");
                    printf("016");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        nkm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        pspsl:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto nkm;
                            }

                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto pspsl;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto airpre;
                    }
                    break;
                }

                case 2:    ///check postpaid
                airpost:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t             \"Airtel\"\n");
                    printf("\n\n\t\t\t          ^_^POSTPAID^_^ \n");
                    printf("\n\n\t\t\t     Airtel Number: ");
                    printf("016");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        trm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        aza:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto trm;
                            }
                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto aza;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto airpost;
                    }
                    break;
                }
                default:
                    {
                        system("cls");
                        design();
                        printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
                        goto lqp;
                    }
            }
            break;
        }

        case 5:     ///check Teletalk sim
        {
            system("cls");
            design();
            dpp:
            printf("\n\t\t\t        ^_^Operators^_^: ");
            printf("\n\n\t\t\t           \"Teletalk\"");
            printf("\n\n\t\t\t           1.Prepaid\n ");
            printf("\n\t\t\t           2.Postpaid\n");
            printf("\n\n\t\t            Please Select An Option: ");
            scanf("%d",&n);

            switch(n)   ///Check the Teletalk number wheather it is prepaid or postpaid ?
            {
                case 1:    ///check prepaid
                telepre:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t           \"Teletalk\"\n");
                    printf("\n\n\t\t\t         ^_^PREPAID^_^ \n");
                    printf("\n\n\t\t\t   Teletalk Number: ");
                    printf("015");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        ttm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        bsp:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto ttm;
                            }

                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto bsp;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto telepre;
                    }
                    break;
                }

                case 2:    ///check postpaid
                telepost:
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t            \"Teletalk\"\n");
                    printf("\n\n\t\t\t          ^_^POSTPAID^_^ \n");
                    printf("\n\n\t\t\t   Teletalk Number: ");
                    printf("015");
                    scanf("%s",sim_type);
                    length=strlen(sim_type);

                    if(length>7 && length<9)
                    {
                        printf("\n\n\t\t\t        Enter your amount: ");
                        tjm:
                        scanf("%ld",&amount);
                        printf("\n\n\t\t            Enter your pin to confirm:");
                        hs:
                        scanf("%d",&user_pin);

                        if(user_pin==pin)     ///Check the pin
                        {
                            if(amount<=0)
                            {
                                printf("\n\n\t\t   ***Please Enter A Valid Positive Amount*** :");
                                goto tjm;
                            }

                        }
                        else
                        {
                            printf("\n\n\n\n\t\t\t            !!!INVALID PIN!!!\n");
                            printf("\n\n\t\t\t     Please input the correct pin:");
                            goto hs;
                        }
                    }
                    else
                    {
                        printf("\n\n\t\t   !!!Please Enter A Valid Number With 11 Digit!!!\n\n");
                        goto telepost;
                    }
                    break;
                }
                default:
                {
                    system("cls");
                    design();
                    printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
                    goto dpp;
                }
            }
            break;
        }

        default:
        {
            system("cls");
            design();
            printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
            printf("\n\n\t\t\t***PLEASE SELECT A VALID OPTION***\n\n");
            goto tt;
        }
    }

    if(amount>0 && amount<=bln)
    {
        s.airtime = amount;
        FILE * fp;
        fp = fopen("airtime.txt","a");
        fwrite(&s, sizeof(s),1,fp);
        fclose(fp);
        printf("\n\n\n\t\t      You are success to buy airtime %ld taka\n\n",amount);
        printf("\n\t\t          ****Thanks for your patience**** ");
        printf("\n\n\t\t\t\t       :-):-):-)   ");
    }
    else
    {
        printf("\n\n\t       !!! SORRY!!You don't have enough money for Recharge !!!");
        printf("\n\n\t\t\t\t     :-(:-(:-(   \n");
    }
    fflush(stdin);
}

void payment()
{
    system("cls");
    design();
    long amountpayment,electric_bill,shopping_bill;
    int option,length,versity;
    int tmpPin;
    char id[12];
    long bln = getbalance();

    tt :
    printf("\n\n\t\t                 ^_^PAYMENT^_^ \n");
    printf("\n\n\t\t          How do you like to payment ? : ");
    printf("\n\n\t\t\t      1. University fee ");
    printf("\n\n\t\t\t      2. Current bill ");
    printf("\n\n\t\t\t      3: Shopping bill ");
    printf("\n\n\n\t\t         Please Select A Valid Option  :  ");

    scanf("%d",&option);
    switch(option)
    {
        case 1:     /// University fee
        {
            qq:
            system("cls");
            design();
            printf("\n\n\t\t                   ^_^PAYMENT^_^ \n");
            printf("\n\n\t\t\t        \xB2\xB2 University fee \xB2\xB2 \n\n");
            printf("\n\n\t\t\t  1. Daffodil International University  ");
            printf("\n\n\t\t\t  2. Dhaka University ");
            printf("\n\n\n\t\t\t Please Select A University: ");
            scanf("%d",&versity);

            switch(versity)
            {
                case 1:     ///Daffodil fee
                    {
                        system("cls");
                        design();
                        printf("\n\n\t\t                   ^_^PAYMENT^_^ \n");
                        printf("\n\n\t\t\t        \xB2\xB2 University fee \xB2\xB2 \n");
                        printf("\n\n\t\t\t \"Daffodil International University\"\n");
                        printf("\n\n\t\t      How much money do you want to send ? : ");
                        aa:
                        scanf("%ld",&amountpayment);

                        if(amountpayment<=0)
                        {
                            printf("\n\n\t\t      Please Enter A Valid Positive Amount: ");
                            goto aa;
                        }

                        printf("\n\n\t\t            Enter your pin to confirm:");
                        pine:
                        scanf("%d",&tmpPin);

                        if(tmpPin==pin)     ///Check the pin
                        {
                            if(amountpayment>0 && amountpayment<=bln)
                            {
                                printf("\n\n\t\tPlease Enter your id number (only 11 character) :");
                                valid_id:
                                    printf("Id= ");
                                scanf("%s",id);
                                length=strlen(id);

                                if (length>10 && length<12) ///length should be 11 characters only
                                {
                                    s.payment = amountpayment;
                                    FILE *fp;
                                    fp = fopen("payment.txt","a");
                                    fwrite(&s,sizeof(s),1,fp);
                                    fclose(fp);

                                    printf("\n\n\t\t     ***You are success to send the %ld taka only*** ",amountpayment);
                                    printf("\n\n\t\t        ****Thanks for your cooperation**** ");
                                    printf("\n\n\t\t\t\t       :-):-):-)   ");
                                }
                                else
                                {
                                    printf("\n\t\t\t     !!!Invalid Id!!!\n");
                                    printf("\n\n\t\t    Please Enter A Valid Id: ");
                                    goto valid_id;
                                }
                            }

                            if(amountpayment>bln)
                            {
                                printf("\n\n\t\t      !!! SORRY!!You don't have enough money !!!");
                                printf("\n\n\t\t\t         :-( :-( :-( ");
                            }
                        }
                        else
                        {
                            system("cls");
                            design();
                            printf("\n\t\t\t        !!!INVALID PIN!!!");
                            printf("\n\n\n\n\t\t             Please Enter A Valid Pin: ");
                            goto pine;
                        }
                        break;
                    }

                    case 2:     ///Dhaka fee
                    {
                        system("cls");
                        design();
                        printf("\n\n\t\t                   ^_^PAYMENT^_^ \n");
                        printf("\n\n\t\t\t        \xB2\xB2 University fee \xB2\xB2 \n");
                        printf("\n\n\t\t\t         \"Dhaka University\"\n");
                        printf("\n\n\t\t      How much money do you want to send ? : ");
                        yaa:
                        scanf("%ld",&amountpayment);

                        if(amountpayment<=0)
                        {
                            printf("\n\n\t\t      Please Enter A Valid Positive Amount: ");
                            goto yaa;
                        }

                        printf("\n\n\t\t            Enter your pin to confirm:");
                        pinnn:
                        scanf("%d",&tmpPin);

                        if(tmpPin==pin)     ///Check the pin
                        {
                            if(amountpayment>0 && amountpayment<=bln)
                            {
                                printf("\n\n\t\tPlease Enter your id number (only 11 character) :");
                                valid_id2:
                                scanf("%s",id);
                                length=strlen(id);

                                if (length>10 && length<12) ///length should be 11 characters only
                                {
                                    s.payment = amountpayment;
                                    FILE *fp;
                                    fp = fopen("payment.txt","a");
                                    fwrite(&s,sizeof(s),1,fp);
                                    fclose(fp);
                                    printf("\n\n\t\t     ***You are success to send the %ld taka only*** ",amountpayment);
                                    printf("\n\n\t\t        ****Thanks for your cooperation**** ");
                                    printf("\n\n\t\t\t\t       :-):-):-)   ");
                                }
                                else
                                {
                                    printf("\n\t\t\t     !!!Invalid Id!!!\n");
                                    printf("\n\n\t\t    Please Enter A Valid Id: ");
                                    goto valid_id2;
                                }
                            }

                            if(amountpayment>bln)
                            {
                                printf("\n\n\t\t      !!! SORRY!!You don't have enough money !!!");
                                printf("\n\n\t\t\t         :-( :-( :-( ");
                            }
                        }
                        else
                        {
                            system("cls");
                            design();
                            printf("\n\t\t\t        !!!INVALID PIN!!!");
                            printf("\n\n\n\n\t\t             Please Enter A Valid Pin: ");
                            goto pinnn;
                        }
                        break;
                    }


                    default:
                        {
                            system("cls");
                            design();
                            printf("\n\t\t\t     !!!Invalid Option!!!\n");
                            printf("\n\n\t\t         Please Select A Valid Option: ");
                            goto qq;
                        }
            }
            break;
        }

        case 2:    ///Current bill
            {
                system("cls");
                design();
                char name[15];
                char division[10],district[10];
                int vtr_id;
                printf("\n\n\t\t                   ^_^PAYMENT^_^ \n");
                printf("\n\t\t                \xB2\xB2 Electric Bill\xB2\xB2");

                printf("\n\n\n\t\t          Please Enter Your Name      : ");
                scanf("%s",name);

                printf("\n\n\t\t          Please Enter Your Division  : ");
                scanf("%s",division);

                printf("\n\n\t\t          Please Enter Your District  : ");
                scanf("%s",district);

                printf("\n\n\t\t          Please Enter Your Voter Id  : ");
                ji:
                scanf("%d",&vtr_id);

                printf("\n\n\t             Please Input Your Electric Bill Amount: ");
                dd:
                scanf("%ld",&electric_bill);

                printf("\n\n\t\t            Enter Your Pin To Confirm:");
                pinees:
                scanf("%d",&tmpPin);

                if(tmpPin==pin)     ///Check the pin
                {
                    if(electric_bill<=0)
                    {
                        printf("\n\n\t    !!Please Enter A Valid Positive Amount!!");
                        goto dd;
                    }

                    else if(electric_bill>0 && electric_bill<=bln)
                    {
                        printf("\n\n\t                         Hello \"%s\" \n",name);
                        printf("\n\t                         Voter Id - %d \n",vtr_id);
                        printf("\n\t                         Division - %s \n",division);
                        printf("\n\t                         District - %s \n",district);
                        if(vtr_id==voter_id)
                        {
                            s.payment = electric_bill;
                                        FILE *fp;
                                        fp = fopen("payment.txt","a");
                                        fwrite(&s,sizeof(s),1,fp);
                                        fclose(fp);
                            printf("\n\n\t\tYou Are Successfully Payment The Electric Bill %ld taka only ",electric_bill);
                            printf("\n\n\t\t        ****Thanks For Your Cooperation**** \n");
                            printf("\n\n\t\t\t\t    :-):-):-)   ");
                        }
                        else
                        {
                            printf("\n\n\t                   *** !!! INVALID VOTER ID!!! ***\n ");
                            printf("\n\n \t                  Please Enter A Valid Voter Id : ");
                            goto ji;
                        }
                    }
                    else
                    {
                        printf("\n\n\n\t\t     !!! SORRY!!You don't have enough money !!!");
                        printf("\n\n\t\t\t             :-( :-( :-( ");
                    }
                }
                else
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t        !!!INVALID PIN!!!");
                    printf("\n\n\n\n\t\t             Please Enter A Valid Pin: ");
                    goto pinees;
                }
                break;
            }

       case 3 :        ///Shopping bill
            {
                system("cls");
                design();
                printf("\n\n\t\t                   ^_^PAYMENT^_^");
                printf("\n\n\t\t                 \xB2\xB2 Shopping Bill\xB2\xB2\n");
                printf("\n\n\t\t    Please Enter Your Shopping Bill Amount: ");
                pa:
                scanf("%ld",&shopping_bill);
                if(shopping_bill<=0)
                {
                    printf("\n\n\t\t     !!Please Enter A Valid Positive Amount!! : ");
                    goto pa;
                }
                printf("\n\n\t\t\t    Please Enter Your Pin: ");
                vp :
                scanf("%d",&tmpPin);

                if(tmpPin==pin)
                {
                    printf("\n\t\t\t        ***Valid pin***\n");

                    if(shopping_bill>0 && shopping_bill<=bln)
                    {
                        s.payment = shopping_bill;
                        FILE *fp;
                        fp = fopen("payment.txt","a");
                        fwrite(&s,sizeof(s),1,fp);
                        fclose(fp);

                        printf("\n\n\t    You are successfully payment the Shopping Bill %ld taka only ",shopping_bill);
                        printf("\n\n\t\t       ****Thanks for your cooperation**** ");
                        printf("\n\n\t\t                   :-):-):-)   ");
                    }
                    else
                    {
                        printf("\n\n\t      !!! SORRY!!You don't have enough money for Shopping !!!");
                        printf("\n\n\t\t\t\t    :-(:-(:-(   ");
                    }
                }
                else
                {
                    system("cls");
                    design();
                    printf("\n\t\t\t        !!!INVALID PIN!!!");
                    printf("\n\n\n\n\t\t           Please Enter A Valid Pin: ");
                    goto vp;
                }
                break;
            }
       default:
        {
            system("cls");
            design();
            printf("\n\n\t\t\t     !!!INVALID OPTION!!!\n\n");
            goto tt;
        }
    }
    fflush(stdin);
}

void moneytransfer()
{
    system("cls");
    design();
    printf("\n\t\t                   ^_^PAYMENT^_^\n");
    printf("\n\n\t\t                \xB2\xB2 Money Transfer\xB2\xB2\n");
    char name[15];
    int user_pin;
    long banking_amount;
    long bln = getbalance();
    int banking_id;

    printf("\n\n\t\t       Please Enter Bank Name          : ");
    scanf("%s",name);

    printf("\n\n\t\t       Please Enter your Banking Id    : ");
    scanf("%d",&banking_id);
    printf("\n\n\t\t       Please Enter Your Banking Amount: ");
    ggk:
    scanf("%ld",&banking_amount);
    printf("\n\n\n\t\t          Enter your pin to confirm:");
    pinfs:
    scanf("%d",&user_pin);

    if(user_pin==pin)     ///Check the pin
    {
        if(banking_amount<=0)
        {
            printf("\n\n\t\t !!Invalid Amount!!\n\n");
            printf("\n\n\t\t!!Please Enter A Valid Positive Amount!!");
            goto ggk;
        }
        if (banking_amount>0 && banking_amount<=bln)
        {
            s.transfer = banking_amount;
            FILE *fp;
            fp =fopen("transfer.txt","a");
            fwrite(&s, sizeof(s),1,fp);
            fclose(fp);
            printf("\n\n\n\t            ### Your Transferable Bank Name### \"%s\" \n",name);
            printf("\n\n\t                   @@@ Banking Id - \"%d\" \n",banking_id);

            printf("\n\n\n\t\t                 !!!CONGRATS!!! \n",banking_id);
            printf("\n\n     ^_^ You are successfully Transfer The Banking Amoount %ld taka only ^_^",s.transfer);
            printf("\n\n\t\t     ****Thanks for your cooperation**** ");
            printf("\n\n\t\t\t\t    :-):-):-)   ");
        }
        else
        {
            printf("\n\n\n\t\t      !!! SORRY!!You Don't Have Enough Money !!!");
            printf("\n\n\t\t\t            :-( :-( :-( ");
        }
    }

    else
    {
        system("cls");
        design();
        printf("\n\t\t\t        !!!INVALID PIN!!!");
        printf("\n\n\n\n\t\t             Please Enter A Valid Pin: ");
        goto pinfs;
    }
    fflush(stdin);
}

void help()
{
    printf("\n\n\t*** For Any Quiry Please Visit \"www.dbblatmtransaction.com\" *** ");
}

long getbalance()
{
    long amountdeposit=0;
    long amountwithdraw=0;
    long airtime =0;
    long balance=0;
    long payment=0;
    long transfer = 0;
    FILE   *fp;
    if ((fp=fopen("deposit.txt","r")) != NULL)
    {
        while(fread(&s,sizeof(s),1,fp))
        {
            amountdeposit +=s.amountdeposit;
        }
        fclose(fp);
    }

    FILE   *fp1;
    if((fp1=fopen("withdraw.txt","r"))!= NULL)
    {
        while(fread(&s,sizeof(s),1,fp1))
        {
            amountwithdraw +=s.amountwithdraw;
        }
        fclose(fp1);
    }

    FILE   *fp2;
    if (( fp2=fopen("airtime.txt","r")) != NULL)
    {
        while(fread(&s,sizeof(s),1,fp2))
        {
            airtime +=s.airtime;
        }

        fclose(fp2);
    }

    FILE   *fp3;
    if(( fp3 =fopen("payment.txt","r")) !=NULL)
    {
        while(fread(&s,sizeof(s),1,fp3))
        {
            payment +=s.payment;
        }
        fclose(fp3);
    }

    FILE   *fp4;
    if(( fp4 =fopen("transfer.txt","r")) !=NULL)
    {
         while(fread(&s,sizeof(s),1,fp4))
        {
            transfer +=s.transfer;
        }
        fclose(fp4);
    }
        balance=amountdeposit-(amountwithdraw+airtime+payment+transfer);
        return balance;
}
