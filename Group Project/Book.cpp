#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"

//enumerated data type for use with iDate
enum eDate { YEAR, MONTH, DAY };

//constructors

//default constructor
cBook::cBook()
{
	iIdentifier = 00000;
	iQuantity = 0;
	iDate[YEAR] = 1970;
	iDate[MONTH] = 01;
	iDate[DAY] = 01;
	lliISBN = 0000000000000;
	dWholeSaleCost = 0.00;
	dRetailPrice = 0.00;
	sTitle = "Title";
	sAuthor = "Author";
	sPublisher = "Publisher";
}

//allows implementer to create a class book with relevant parameters initialized at creation
cBook::cBook(int iIdentifierLocal, int iQuantityLocal, int iDateYearLocal, int iDateMonthLocal, int iDateDayLocal, long long int illiISBNLocal, double dWholeSaleCostLocal, double dRetailPriceLocal, string sTitleLocal, string sAuthorLocal, string sPublisherLocal)
{
	iIdentifier = iIdentifierLocal;
	iQuantity = iQuantityLocal;
	iDate[YEAR] = iDateYearLocal;
	iDate[MONTH] = iDateMonthLocal;
	iDate[DAY] = iDateDayLocal;
	lliISBN = illiISBNLocal;
	dWholeSaleCost = dWholeSaleCostLocal;
	dRetailPrice = dRetailPriceLocal;
	sTitle = sTitleLocal;
	sAuthor = sAuthorLocal;
	sPublisher = sPublisherLocal;
}

//Mutators (Setters)
void cBook::setiIdentifier(int iNum)
{
	iIdentifier = iNum;
}

void cBook::setiQuantity(int iNum)
{
	iQuantity = iNum;
}

void cBook::setiDate(int iNum1, int iNum2, int iNum3)
{
	iDate[YEAR] = iNum1;
	iDate[MONTH] = iNum2;
	iDate[DAY] = iNum3;
}

void cBook::setlliISBN(long long int iNum)
{
	lliISBN = iNum;
}

void cBook::setdWholeSaleCost(double iNum)
{
	dWholeSaleCost = iNum;
}

void cBook::setdRetailPrice(double iNum)
{
	dRetailPrice = iNum;
}

void cBook::setsTitle(string sString)
{
	sTitle = sString;
}

void cBook::setsAuthor(string sString)
{
	sAuthor = sString;
}

void cBook::setsPublisher(string sString)
{
	sPublisher = sString;
}

//Accessors (Getters)
int cBook::getiIdentifier() const
{
	return iIdentifier;
}

int cBook::getiQuantity() const
{
	return iQuantity;
}

int cBook::getiDateYear() const
{
	return iDate[YEAR];
}

int cBook::getiDateMonth() const
{
	return iDate[MONTH];
}

int cBook::getiDateDay() const
{
	return iDate[DAY];
}

long long int cBook::getlliISBN() const
{
	return lliISBN;
}

double cBook::getdWholeSaleCost() const
{
	return dWholeSaleCost;
}

double cBook::getdRetailPrice() const
{
	return dRetailPrice;
}

string cBook::getsTitle() const
{
	return sTitle;
}

string cBook::getsAuthor() const
{
	return sAuthor;
}

string cBook::getsPublisher() const
{
	return sPublisher;
}
