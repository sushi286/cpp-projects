//*****************************************************************************************************
//
//      This header file defines a Stock class with overloaded comparison and output operators to 
//      facilitate easy comparison and display of stock information.
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;

class Stock {

private:

    string name;
    string symbol;
    double price;

public:

    Stock(string n="",string s="",double p=0);

    string getName() const;
    string getSymbol() const;
    double getPrice() const;

    bool operator<(const Stock& other) const;
    bool operator==(const Stock& other) const;

    friend ostream& operator<<(ostream& out,const Stock& s);
};

#endif
