//*****************************************************************************************************
//
//      The implementation of the Stock class header file.
//
//      Other files required:
//        1.    stock.h - header file for the Stock class
//
//*****************************************************************************************************

#include "stock.h"
#include <iomanip>

Stock::Stock(string n,string s,double p) {

    name = n;
    symbol = s;
    price = p;
}

string Stock::getName() const {
    return name;
}

string Stock::getSymbol() const {
    return symbol;
}

double Stock::getPrice() const {
    return price;
}

bool Stock::operator<(const Stock& other) const {
    return symbol < other.symbol;
}

bool Stock::operator==(const Stock& other) const {
    return symbol == other.symbol;
}

ostream& operator<<(ostream& out,const Stock& s) {

    out<<s.name<<endl;
    out<<s.symbol<<endl;
    out<<fixed<<setprecision(2)<<s.price;

    return out;
}
//*****************************************************************************************************
