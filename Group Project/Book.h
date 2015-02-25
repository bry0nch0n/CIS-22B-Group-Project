#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class book
{
private:
	int iIdentifier, iQuantity, iDate[3];
	long long int lliISBN;
	double dWholeSaleCost, dRetailPrice;
	string sTitle, sAuthor, sPublisher;

public:
	void setiIdentifier(int);
	void setiQuantity(int);
	void setiDate(int, int, int);
	void setlliISBN(long long int);
	void setdWholeSaleCost(double);
	void setdRetailPrice(double);
	void setsTitle(string);
	void setsAuthor(string);
	void setsPublisher(string);
};
#endif