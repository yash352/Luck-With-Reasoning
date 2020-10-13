#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rulebook()
{
 cout << "\t\tRULES OF THE GAME\n";
 cout << "\t1. Choose level of difficulty between 1 to 10\n";
 cout<<"\t as the level of difficulty increases by 1 possiblity of finding winning number increases by
10 "
 <<"winning amount also doubles if you made the correct guess\n";
 cout<<"\t2.you will get three tries to guess the winning number as the tries increase the value of
your bet decreases\n ";
 cout<<"\tafter each wrong try you will get to know whether you have made higher number
guess/lower number guess";
 cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
 cout << "\t4.If you want you will be provided with a golden opportunity to reduce your lost
amount\n";
 cout<<"\tIn this golden chaance you will be a given problem statement and you have to make a
wise guess using conclusion of your wrong tries\n";
 cout<<"\n\t\t\tBEST OF LUCK!!";
}
void hint(int ptr,int &ba)
{
 srand(time(NULL));
 int i;
 int qw=(rand()%1000) + 1;
 int x=qw%ptr;
 cout<<"Now you will be given a problem statement to find winning number\n";
 cout<<"when "<<qw <<" is divided by the winning number it gives remainder as "<<x;
 int op;
 int w=0;
 for(i=1;i<=3;i++)
 {
 cout<<"make a guess of winning number ";
 cin>>op;
 if(op==ptr)
 {
 w=1;
 break;
 }
 else
 {
 cout<<"You have still made a wrong guess you have to do it again\n";
 }
 }
 if(w==1)
 {
 cout<<"you have reduced lost amount by "<<ba/i;
 ba=ba-(ba/i);

 }
 else
 {
 cout<<"Bad luck in this round!! best of luck for next round.\n";
 cout << "\nThe winning number was :- " << ptr;
 }
}
int main()
{
 string name,chosen,lucky;
 char choice;
 int ta;//for initial depository total amount,
 int ba;//for betting amount;
 int ptr;//for pointing random number
 cout<<"\n \t \t welcome to the LUCKIEST NUMBER game presented by ''Yash Cassino'' \n \n
";//name of my game
 cout<<"Do you want to know about the rule of LUCKIEST NUMBER game??? \n \t \t \t \t hit 'Y' for
Yes and 'N' for No\t ";
 char r;
 cin>>r;
 if(r=='Y')
 {
 rulebook();
 }
 cout<<"Do you want to try your luck on numbers by betting ??? \n \t \t hit 'Y' for Yes and 'N' for
No \t";
 cin >> choice;
 if(choice=='Y')
 {
 cout<<"\n \nWhat's your name player \t";
 cin>>name;
 cout<<"\n \n welcome to the game "<<name<< ".\n \t \t Hope you enjoy it";
 cout<<"\n \n \t \tEnter a depository amount to start playing the game\t";
 cin>>ta;
 ba=1;
 while(ta>=ba)
 {
 srand(time(0));
 cout<<"\n \n \nyour current amount in deposit is "<< ta;
 cout<<"\n How much money you want to bet ?\t";
 cin>>ba;
 if(ba>ta)
 {
 cout<<"\n your betting amount is more than your total deposited money in the game\n"
 <<"\t so plese renter the correct betting amount to place a bet on the number \t";
 ba=1;
 continue;
 }
 int lev;
 do
 {
 cout<<"Enter the level of difficulty beween (1-10) at which you want to play/bet ";
 cin>>lev;
 if(lev < 1 || lev> 10)
 cout << "Please check the level of difficulty should be between 1 to 10\n"
 <<"\nRe-enter difficulty level data\n ";
 }while(lev <= 0 || lev > 10);

 int l=10*lev;
 ptr=rand()%l+1;
 int guess;
 int er=0,i;
 int trya=(2*lev + 2)*ba;
 int tryb=(2*lev)*ba;
 int tryc=lev+ba;
 for ( i=0;i<3;i++)
 {
 do
 {
 cout<<"\n" << name <<" Guess your lucky number (between 1 to "<<l<<" ) on which
you want to bet : ";
 cin >> guess;
 if(guess <1 || guess > l)
 cout << "Please check the number!! should be between 1 to "<<lev<<"\nRe-enter
data ";
 }while(guess < 1 || guess > l);
 if(guess==ptr)
 {
 er=1;
 break;
 }
 else if(guess>ptr && i!=2)
 {
 cout<<"-> you have guessed a higher number . So, guess a lower number in next try.\n" ;
 }
 else if(guess<ptr && i!=2)
 {
 cout<<"-> you have guessed a lower number . So, guess a higher number in next try\n " ;
 }
 }
 if(er==0)
 {

 cout <<"Since you have made all wrong guesses ,you have lost betting amount of "<<
ba;
 cout<<"\nDo you want to reduce your lost amount by playing with winning number
Y/N?? ";
 char chrt;
 cin>>chrt;
 if(chrt=='Y')
 {
 hint(ptr,ba);
 }
 else
 {
 cout << "\nThe winning number was :- " << ptr;
 }

 ta=ta-ba;
 }
 else
 {

 if(i==0)
 {
 cout<<"-->>Congratulations, since you have guessed corretly in first try => you have
won amount of "<<trya;
 ta=ta+trya;
 }
 if(i==1)
 {
 cout<<" Since you have guessed corretly in second try =>You have won an amount
of"<< tryb;
 ta=ta + tryb;
 }
 if(i==2)
 {
 cout<<"Since you have guessed corretly in third try =>You have won an amount of
"<<tryc;
 ta=ta + tryc;
 }
 }
 cout<<"\n \n";

 cout << "\n"<<name<<", You are left with amount of " << ta << "\n";
 if(ta == 0)
 {
 cout << "You have no money to play ";
 cout<<"\n \nDo you want to add more money in your account "<<name<<"?? ";
 char qw;
 cin>>qw;
 if(qw=='Y')
 {
 cout<<"\nHow much amount you want to add in your account "<<name<<"?? ";
 cin>>ta;
 }
 ba=1;
 continue;
 }
 cout << "\n\n-->Do you want to try your luck on numbers again (Y/N)? ";
 cin >> choice;
 if(choice=='N')
 {
 ta=-1;
 }
 else
 {
 ta=ta;
 ba=1;
 }
 }
 cout<<"Thanks for playing the game "<<name<<" Hope you enjoyed!! ";
 }

 
 return 0;
}