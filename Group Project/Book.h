#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class cBook
{
private:
	int iIdentifier, iQuantity, iDate[3];
	long long int lliISBN;
	double dWholeSaleCost, dRetailPrice;
	string sTitle, sAuthor, sPublisher;

public:
	//constructors
	cBook();
	cBook(int, int, int, int, int, long long int, double, double, string, string, string);
	
	//mutators (setters)
	void setiIdentifier(int);
	void setiQuantity(int);
	void setiDate(int, int, int);
	void setlliISBN(long long int);
	void setdWholeSaleCost(double);
	void setdRetailPrice(double);
	void setsTitle(string);
	void setsAuthor(string);
	void setsPublisher(string);

	//accessors (getters)
	int getiIdentifier() const;
	int getiQuantity() const;
	int getiDateYear() const;
	int getiDateMonth() const;
	int getiDateDay() const;
	long long int getlliISBN() const;
	double getdWholeSaleCost() const;
	double getdRetailPrice() const;
	string getsTitle() const;
	string getsAuthor() const;
	string getsPublisher() const;
};
#endif