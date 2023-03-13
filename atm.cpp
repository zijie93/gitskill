#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void welcomeBank () {
    cout<<"welcome bank of american! "<<endl;
}

void welcomeName (string name) {
    cout <<"welcome, "<<name<<endl;
}

void showMenu () {
    cout<<"Press 1: Check Balance; "<<endl;
    cout<<"Press 2: Withdraw Amount; "<<endl;
    cout<<"Press 3: Fast Cash; "<<endl;
    cout<<"Press 4: Deposit Amount; "<<endl;
    cout<<"Press 5: LogOut. "<<endl;
}

int withdraw(int balance) {
    int withNum;
    char ch;
    cout<<"your balance is: "<<balance<<endl;
    while (true) {
        cout<<"please enter the withdraw number: "; cin>>withNum;
        if (withNum>balance) cout<<"please enter a valid number! "; 
        else {
            balance-=withNum;
            cout<<"the current balance is: "<<balance<<endl;
            cout<<"do you want to withdraw more? y/n: "; cin>>ch;
            if (ch=='n' || ch=='N') break;
        } 
    }
    return balance;
}

int fastcash(int balance) {
    int fastNum;
    char ch;
    cout<<"your balance is: "<<balance<<endl;
    while (true) {
        cout<<"20,     40"<<endl;
        cout<<"60,     80"<<endl;
        cout<<"100,    200"<<endl;
        cout<<"please enter the fast cash number: "; cin>>fastNum;
        if (fastNum>balance) cout<<"please enter a valid number! "; 
        else {
            balance-=fastNum;
            cout<<"the current balance is: "<<balance<<endl;
            cout<<"do you want to fast cash more? y/n: "; cin>>ch;
            if (ch=='n' || ch=='N') break;
        } 
    }
    return balance;
}

int deposit(int balance) {
    int depositNum;
    char ch;
    cout<<"your balance is: "<<balance<<endl;
    while (true) {
        cout<<"please enter the deposit number: "; cin>>depositNum;
        balance+=depositNum;
        cout<<"the current balance is: "<<balance<<endl;
        cout<<"do you want to deposit more? y/n: "; cin>>ch;
        if (ch=='n' || ch=='N') {break;}
    }
    return balance;  
}

void login () {
    int numOfLog=0, balance=0, choice, flag=0;
    string name, email, savedName, savedEmail, savedPinS, balanceS, pin, savedPin;
    char ch;
    while (true) {
        cout<<"please enter login name: "; cin>>name;
        cout<<"please enter login pin: "; cin>>pin;
        //fstream file ("D:\\" + name + ".txt");
        fstream file;
        file.open (name);
        
        if (file.fail()) {
            cout<<"account doesn't exit, please re-enter! "<<endl;
        }else {
            getline(file, savedName);
            getline(file, savedPin);
            getline(file, savedEmail);
            getline(file, balanceS);
            file.close();
            if (name==savedName && pin==savedPin) {
                welcomeName(name);
                balance=stoi(balanceS); 
                email=savedEmail;              
                flag=1;
                break;
            } else {
                cout<<"username and pin not matched, please re-enter! "<<endl;
            }
        }
        numOfLog++;
        if (numOfLog>=3) {
            cout<<"please go to front desk! "<<endl;
            return;
        }
    }
    while (flag) {
        showMenu();
        cout<<"select your choice: "; cin>>choice;
        switch(choice) {
            case 1:
                cout<<"your balance is: "<<balance<<endl;
                break;
            case 2:
                balance=withdraw(balance);
                break;
            case 3:
                balance=fastcash(balance);
                break;
            case 4:
                balance=deposit(balance);
                break;
            case 5:
                break;
        }

        //ofstream file2 ("D:\\" + name + ".txt");
        ofstream file2;
        file2.open (name);
        file2<<name<<endl;
        file2<<pin<<endl;
        file2<<email<<endl;
        file2<<balance<<endl; 
        file2.close();
        cout<<" do you want to logout? [y/n] "; cin>>ch;
        if (ch=='y' || ch=='Y') break; 
    }
    return;
}

void signup() {
        int pin, savedPin, confirmPin, numOfLog=0, balance;
        string name, email, savedName, savedEmail, savedPinS, balanceS;
        cout<<"please enter your name: "; cin>>name;
        cout<<"please enter your pin: "; cin>>pin;
        cout<<"please enter your email: "; cin>>email;
        cout<<"please enter your balance: "; cin>>balance;
        ofstream file;
        //file.open ("D:\\" + name + ".txt");
        file.open (name);
        file<<name<<endl;
        file<<pin<<endl;
        file<<email<<endl;
        file<<balance<<endl; 
        file.close();   
}

void ATM () {
    welcomeBank ();
    int logInChoice;
    char ch;
     
    while (true) {  
        cout<<"press 1 to login, 2 to sign up a new account, others to exit "; cin>>logInChoice; 
        if (logInChoice==1) {
            login();
        } else if (logInChoice==2) {
            signup();
            //logInChoice=1;
        } else {
            cout<<"do you want to exit? [y/n] "; cin>>ch;
            if (ch=='y' || ch=='Y') break;
        }
        
    }
    return;
}

int main () {
    ATM ();
    return 0;
}