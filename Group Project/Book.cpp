#include "Book.h"

void book::setiIdentifier(int iNum)
{
	iIdentifier = iNum;
}

void book::setiQuantity(int iNum)
{
	iQuantity = iNum;
}

void book::setiDate(int iNum1, int iNum2, int iNum3)
{
	//could use enumerators here
	//year -> month -> day
	iDate[0] = iNum1;
	iDate[1] = iNum2;
	iDate[2] = iNum3;
}

void book::setlliISBN(long long int iNum)
{
	lliISBN = iNum;
}

void book::setdWholeSaleCost(double iNum)
{
	dWholeSaleCost = iNum;
}

void book::setdRetailPrice(double iNum)
{
	dRetailPrice = iNum;
}

void book::setsTitle(string sString)
{
	sTitle = sString;
}

void book::setsAuthor(string sString)
{
	sAuthor = sString;
}

void book::setsPublisher(string sString)
{
	sPublisher = sString;
}