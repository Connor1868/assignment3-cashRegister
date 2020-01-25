// Roster Number :75
//
// Author:Connor Widder
// Due Date: such as 10/07/2019
// Assignment Number: 3
// Fall - 2019 - CS 3358 - Your Section Number such as 1
// Instructor: Husain Gholoom
//
//Cash Register

#include <iostream>
#include <stdlib.h>     /* atoi */

using namespace std;
//*******************************************************************
// Cash register class. Handels money deposited
//
// public int varible cash

// cashRegister() - initializes cash val to 500
// cashSet(int) - sets the cash value in the register to the input
// returnCash() - returns the value of cash in the register
// depositeCash(int) - deposites cash into the register
//*******************************************************************
class cashRegister{
public:
    int cash;               //interger value for cash in register
    
    //Defualt Constructor
    cashRegister(){
        cash = 500;         //set itial cash value
    }
    //Set Cash
    void setCash(int cashSet);
    //Return Cash
    int returnCash();
    //Deposite Cash
    void depositeCash(int cashIn);
};
//Set Cash
void cashRegister::setCash(int cashSet){
    cash = cashSet;      //set cash in the register to a specified amount
}
//Return Cash
int cashRegister::returnCash(){
    return cash;        //return the amount of cash in the register
}
//Deposite Cash
void cashRegister::depositeCash(int cashIn){
    cash = cash + cashIn;   //deposits cash into the register
}
//*******************************************************************
// dispenser class
//
// Private int varible quantity - qty of the obj in despenser
// Private int varible price - price of the obj in despenser

//dispenser(int,int) - sets the quantity and price of the obj
//getQty() - returns the quantity of the obj
//getPrice() - returns the price of the obj
//reduce() - reduces the quantity of the obj by 1
//*******************************************************************
class dispenser{
private:
    int quantity;   //interger value for the quantity
    int price;      //interger value for the quantity
public:
    //Parameter Constructor
    dispenser(int q, int p){
        quantity = q;
        price = p;
    }
    //Return Quantities
    int getQty();
    //Return Price
    int getPrice();

    //Reduce Quantity
    void reduce();

};

 int dispenser::getQty(){
     return quantity;
 }

 int dispenser::getPrice(){
    return price;
 }

     void dispenser::reduce(){
        quantity--;
     }

//*****************************************************************
// Vend function: perfomrs vending operations
//
// cash register object
// object price
// object qty
// VOID return
//*******************************************************************
void vend(cashRegister cashRegisterint, int price, int qty);

int main(int argc, const char * argv[]) {
    
    cashRegister cashRegister;
    dispenser candy(2,75); //Set qty and price for, candy
    dispenser chips(2,100); //Set qty and price for, chips
    dispenser gum(2,25); //Set qty and price for, gum
    dispenser cookies(2,150); //Set qty and price for, cookies

    char userInput = '0';   //Char value for the input
        
    cout << "*** Welcome to the class Vending Machine ***" << endl << endl;
    
    while(userInput != '9'){
        cout << "Select One of the following" << endl << endl;

        cout << "1 for Candy" << endl;
        cout << "2 for Chips" << endl;
        cout << "3 for Gum" << endl;
        cout << "4 for Cookies" << endl;
        cout << "9 to exit" << endl;
        cout << endl;
        cin >> userInput;
        cout << endl;
        
        if ((userInput == '1')||(userInput == '2')||(userInput == '3')||(userInput == '4')){
            switch(userInput){
                case '1':
                    vend(cashRegister, candy.getPrice(), candy.getQty());
                    candy.reduce();
                    break;
                case '2':
                    vend(cashRegister, chips.getPrice(), chips.getQty());
                    candy.reduce();
                    break;
                case '3':
                    vend(cashRegister, gum.getPrice(), gum.getQty());
                    candy.reduce();
                    break;
                case '4':
                    vend(cashRegister, cookies.getPrice(), cookies.getQty());
                    candy.reduce();
                    break;
            }
        }else if(userInput == '9'){
            cout << "*** Thank you for using the class Vending Machine ***";
            return 0;
        }else{
            cout << "Invailid selection";
            userInput = '0';
        }
    }
}
//Vend fuction - performs vending operations
void vend(cashRegister cashRegister, int price, int qty){
    int itemQty = qty;
    cout << "QTY: " << itemQty << endl;
    int itemPrice = price;
    int deposite = 0;
    int deposite2 = 0;
    
    if(itemQty == 0){
        cout << "Sorry, this item is sold out." << endl << endl;
    }else{
        cout << "Please deposite " << itemPrice << " cents" << endl;
        cin >> deposite;
        cout << endl;
        
        if (deposite > itemPrice){          //Return Change
            cout << "Collect your change " << deposite - itemPrice << endl;
            cout << "Collect your item at the bottom and enjoy." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
        }else if (deposite < itemPrice){    //Insuffient funds case
            cout << "Please deposit another " << itemPrice - deposite << " cents" << endl;
            cin >> deposite2;
            
            deposite = deposite + deposite2;        //Add second deposite to                                                          intial deposite for total
            if (deposite < itemPrice){  //Re-Check deposite
                cout << "The amount is not enough. Collect what you deposited." << endl  << endl;
            } else if(deposite == itemPrice){
                cout << "Collect your item at the bottom and enjoy." << endl;
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;

            }else{
                    cout << "Collect your change " << deposite - itemPrice << endl;
                }
        }else{                          //Price = Deposite
            cout << "Collect your item at the bottom and enjoy." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
                }
        cashRegister.depositeCash(deposite);    //Deposite cash into the register.
    }
}

