#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// We create a struct User to store the necessary details of each user
typedef struct User{
    char name[20];
    char card_code[20];
    int pin;
    int bank_balance;
}user;


int main(){
    //We create an array of each member of the struct User and store the values according to
    //what is given in users.txt

    char names[10][20];
    strcpy (names[0],"Ashmit");
    strcpy (names[1],"Abhinav");
    strcpy (names[2],"Vasa");
    strcpy (names[3],"Rahul");
    strcpy (names[4],"John");
    strcpy (names[5],"Shyam");
    strcpy (names[6],"Riya");
    strcpy (names[7],"Mohan");
    strcpy (names[8],"Yash");
    strcpy (names[9],"Shalini");

    char cardcodes[10][20];
    strcpy (cardcodes[0],"AS2021");
    strcpy (cardcodes[1],"AB2022");
    strcpy (cardcodes[2],"VS2023");
    strcpy (cardcodes[3],"RK2024");
    strcpy (cardcodes[4],"JN2025");
    strcpy (cardcodes[5],"SH2026");
    strcpy (cardcodes[6],"RY2027");
    strcpy (cardcodes[7],"MN2028");
    strcpy (cardcodes[8],"YH2029");
    strcpy (cardcodes[9],"SN2030");

    int pins[10]={2712, 2341, 1823, 1920, 2901, 1754, 1973, 2131, 2876, 2619};
    int balance[10]={15000, 12000, 17000, 11000, 9000, 10000, 4500, 7500, 11500, 3500};

    // finally we create an array of struct User itself and store all the details
    //of each user in the array

    user user_array[10];
    for(int i=0;i<10;i++){
        strcpy(user_array[i].name, names[i]);
        strcpy(user_array[i].card_code,cardcodes[i]);
        user_array[i].pin=pins[i];
        user_array[i].bank_balance=balance[i];
    }
  
    
     char input_card[20];
     int input_pin;
     while(1){
     //the user will have to enter their card code/No to start with the machne
     printf("Please insert your card\n");
     scanf("%s", &input_card);
     int flag_card=0;
     int index;
     //the machine checks if the card is valid or not
     for(int i=0;i<10;i++){
         int comp = strcmp(input_card,user_array[i].card_code);
         if(comp==0){
             flag_card=1;
             index=i;
             break;
         }
     }
     //if the card is valid we take input of the PIN and verify it
     //if the user enters incorrect PIN three times then the session is closed and
     //they are asked to come some time later
     if(flag_card){
         int flag_pin=0;
         int count=0;
         printf("Welcome %s, please enter your PIN to proceed\n",user_array[index].name);
         while(flag_pin!=1){
         scanf("%d",&input_pin);
         if(input_pin == user_array[index].pin){
             flag_pin=1;
             
         }
         else{
             count++;
             if(count<=2)
             printf("The PIN entered is incorrect,you have %d more attempts\nEnter you PIN  ",3-count);
             else{
                 printf("You have entered wrong PIN several times, come some time later\n\n");
                 break;
             }
         }
     }
     //if the pin entered is correct the user has four options,
     //they can check their balance, deposit money, withdraw money and transfer money to someone else's account
     if(flag_pin){
          int user_input;
          int deposit,withdraw,transfer;
           char input_cno[20];
        
          printf("\nNow you have access to the machine,what would you like to do?\nEnter 1 to check your balance\nEnter 2 to deposit money\nEnter 3 to withdraw money\nEnter 4 to transfer\nEnter 5 to cancel\n");
          while(1){
          scanf("%d",&user_input);
          switch(user_input){
             case 1: 
             printf("Your account balance is Rs %d\n\n",user_array[index].bank_balance);
             break;

             case 2:
             printf("Enter amount to deposit\n");
             scanf("%d",&deposit);
             //cannot deposit more than 5000 at once
             if(deposit<=5000){
             user_array[index].bank_balance+=deposit;
             printf("You have successfuly deposited Rs %d in your account\n",deposit);
             printf("Your remaining balance after deposit is Rs %d\n\n",user_array[index].bank_balance);
             
             }
             else{
                 printf("You cannot deposit more than Rs 5000 in your bank account\n\n");
             }
             break;
             
             case 3:
             printf("Enter amount to withdraw\n");
             scanf("%d",&withdraw);
             //cannot withdraw more than 5000 at once and ofcourse not more than
             //their current balance
             if(withdraw<=5000 && withdraw<=user_array[index].bank_balance){
                 user_array[index].bank_balance-=withdraw;
                 printf("You have successfully withdrawn Rs %d from your account\n",withdraw);
                 printf("Your remaining balance is Rs %d\n\n",user_array[index].bank_balance);
             }
             else if(withdraw>5000 && withdraw<=user_array[index].bank_balance){
                 printf("You cannot withdraw more than Rs 5000 at once\n\n");
             }
             else {
                 printf("You don't have enough money in your account\n");
                 printf("Your current balance is Rs %d\n\n", user_array[index].bank_balance);
             }
             break;
             //for transfer a user have to enter the card code/No of the other
             //user they want to transfer money too, the machine then checks
             //if the card is valid or not
             case 4:
             printf("Whose account you want to transfer money?Enter their card number\n");
             scanf("%s",&input_cno);
             int flagn=0;
             for(int i=0;i<10;i++){
                 int compn= strcmp(input_cno,user_array[i].card_code);
                 
                 if(compn==0){
                     flagn=1;
                     printf("Enter the amount you want to deposit in %s's account\n",user_array[i].name);
                     scanf("%d",&transfer);
                     if(transfer<=user_array[index].bank_balance){
                         //the bank balance of both the users are modified accordingly
                         user_array[index].bank_balance-=transfer;
                         user_array[i].bank_balance+=transfer;
                     printf("You have successfully transferred Rs %d in %s's account\n",transfer, user_array[i].name);
                     printf("Your current balance is Rs %d\n\n",user_array[index].bank_balance);
                     }
                     else{
                          printf("You don't have enough money in your account\n");
                          printf("Your current balance is Rs %d\n\n", user_array[index].bank_balance);
                     }
                     break;

                 }
                
             }
             if(flagn==0){
                     printf("No registered user found with this card\n\n");
                 }
             break;

             case 5:
             break;

             default:
             printf("Enter a valid key\n\n");
             break;

         }
         //if the user enters 1 he can use the machine again, else the session ends
         //for that user
         int wish;
         printf("Press 1 if you wish to continue further or any other key if you don't\n");
         scanf("%d",&wish);
         if(wish==1){
             printf("What would you like to do?\nEnter 1 to check your balance\nEnter 2 to deposit money\nEnter 3 to withdraw money\nEnter 4 to transfer\nEnter 5 to cancel\n");
         }
         else{
             printf("Thank you for using our service, we hope to see you again soon\n\n");
             break;

         }
          }
     }
     }
     else{
         printf("Sorry this card is not registered\n\n");
         
     }
     //After the session ends for one user, we are asked to verify if they are more users
     //left or not. If we press any key other than 1 we repeat the entire process again.
     //If we press 1, the machine is closed.
     int check;
     printf("If there are no users left to use the machine enter 1, or any other key in the other case\n");
     scanf("%d",&check);
     if(check==1){
         printf("ATM Machine closed, i.e.,this is the end of our project. Thank you!\n");
         break;
     }
     }
     
}

   
   
