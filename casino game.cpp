#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <fstream>
using namespace std;

void drawLine(int n, char symbol);
void rules();
void getdata(string &playerName,int &nic,int &amount){
    ofstream fout;
    fout.open("Casino.txt",ios::app);

    fout<<playerName<<endl;

    fout<<nic<<endl;

    fout<<amount<<endl;
    fout.close();
    };
    void check(int &nic,string &playerName,int &amount,int &temp_nic,string &user,int &id,int &balance){
     ifstream fin;
    fin.open("Casino.txt");

    while(!fin.eof()){
        fin>>playerName;
        fin>>nic;
        fin>>amount;
        if(temp_nic==nic){
        user=playerName;
        id=nic;
        balance=amount;
            cout<<"Name : "<<playerName<<endl;
            cout<<"NIC Number : "<<nic<<endl;
            break;
    }
    }
    fin.close();
    };
int main()
{
string user;
int id,balance;
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount;
    int nic,temp_nic;
    int guess;
    int dice; // hold computer generated number
    char choice;
    int am;

    srand(time(0)); // "Seed" the random generator

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');
    cout<<"New to Casino (Y/N) : ";
    cin>>choice;
    if(choice=='Y'||choice=='y'){
    cout << "\n\nEnter Your Name : ";
    cin.ignore();
    getline(cin, playerName);
    cout<<"\n\nEnter NIC : ";
    cin>>nic;
    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> amount;
    getdata(playerName,nic,amount);
        do
        {
        ifstream fin;
        fin.open("Casino.txt");
        cout << "\n\nYour current balance is $ " << amount << "\n";
        fin.close();
        rules();
        do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
            cout << "Your betting amount is more than your current balance\n"
                 <<"\nRe-enter data\n ";


        }while(bettingAmount > amount);



		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
        cout<<"2nd Player  : "<<"Betting Amount : "<<rand()%900 + 1<<endl;
        cout<<"Betting Number : "<<rand()%10 + 1<<endl;
        cout<<"3rd Player  : "<<"Betting Amount : "<<rand()%779 + 1<<endl;
        cout<<"Betting Number : "<<rand()%8 + 1<<endl;
        cout<<"4th Player  : "<<"Betting Amount : "<<rand()%500 + 1<<endl;
        cout<<"Betting Number : "<<rand()%5 + 1<<endl;
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10

        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }

            cout << "\nThe winning number was : " << dice <<"\n";
            cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
            cout << "\n\n-->Do you want to play again (y/n)? ";
            cin >> choice;
        }while(choice =='Y'|| choice=='y');

        cout << "\n\n\n";
        drawLine(70,'=');
        cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
        drawLine(70,'=');
        }
        else if(choice=='N'||choice=='n'){
        cout<<"Enter the nic number : ";
        cin>>temp_nic;
        check(nic,playerName,amount,temp_nic,user,id,balance);

       do
        {
        ifstream fin;
        fin.open("Casino.txt");
        while(!fin.eof()){
        fin>>playerName;
        fin>>nic;
        fin>>amount;
        am=int(amount);
        if(temp_nic==nic)
        break;
        }
        cout << "\n\nYour current balance is $ " << balance << "\n";
        fin.close();
        rules();


		// Get player's betting amount
        do
        {

            cout <<user<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
            cout << "Your betting amount is more than your current balance\n"
                 <<"\nRe-enter data\n ";

        }while(bettingAmount > balance);

		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
            cout << "Please check the number!! should be between 1 to 10\n"
                 <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
        cout<<"2nd Player  : "<<"Betting Amount : "<<rand()%900 + 1<<endl;
        cout<<"Betting Number : "<<rand()%10 + 1<<endl;
        cout<<"3rd Player  : "<<"Betting Amount : "<<rand()%779 + 1<<endl;
        cout<<"Betting Number : "<<rand()%8 + 1<<endl;
        cout<<"4th Player  : "<<"Betting Amount : "<<rand()%500 + 1<<endl;
        cout<<"Betting Number : "<<rand()%5 + 1<<endl;
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10

        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;//calculating the total balance
            am=am+balance;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;//calculating total amount
            am=am-balance;
        }

        cout << "\nThe winning number was : " << dice <<"\n";//displaying th winner number
        cout << "\n"<<user<<", You have $ " << balance << "\n";//display user name and balance
        if(balance == 0)
        {
            cout << "You have no money to play ";//loop break if user is out of money
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');

    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << balance << "\n\n";
    drawLine(70,'=');
    }
    return 0;
}

void drawLine(int n, char symbol)//function for formating
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}

void rules()//funtion for displaying rules
{
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

// END OF PROGRAM
