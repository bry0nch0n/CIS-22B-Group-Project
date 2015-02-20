#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//class definition of book
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

//implementation of the class book; in actual project, definition and implementation will be separate .h and .cpp files
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

int main()
{
	const int ARRAY_SIZE = 16;
	int iNumBooks;
	ifstream inventoryFile;
	string sFilename;
	book inventory[ARRAY_SIZE];

	int iIdentifier, iQuantity, iDate[3];
	long long int lliISBN;
	double dWholeSaleCost, dRetailPrice;
	string sTitle, sAuthor, sPublisher;

	cout << "Enter filename:\n";
	cin >> sFilename;
	inventoryFile.open(sFilename);

	while (inventoryFile.fail())
	{
		cout << "\nInvalid filename.\n";
		cout << "Enter filename:\n";
		cin >> sFilename;
		inventoryFile.open(sFilename);
	}

	inventoryFile >> iNumBooks;
	cout << "Number of Books: " << iNumBooks << endl << endl;

	for (int i = 0; i < iNumBooks; i++)
	{
		inventoryFile >> iIdentifier;
		cout << "Identifier: " << iIdentifier << endl;

		inventoryFile >> lliISBN;
		cout << "ISBN-13: " << lliISBN << endl;
		
		inventoryFile.ignore();
		
		getline(inventoryFile, sTitle);
		cout << "Title: " << sTitle << endl;

		getline(inventoryFile, sAuthor);
		cout << "Author : " << sAuthor << endl;

		getline(inventoryFile, sPublisher);
		cout << "Publisher: " << sPublisher << endl;

		inventoryFile >> iDate[0];
		cout << "Year: " << iDate[0] << endl;

		inventoryFile >> iDate[1];
		cout << "Month: " << iDate[1] << endl;

		inventoryFile >> iDate[2];
		cout << "Day: " << iDate[2] << endl;

		inventoryFile >> iQuantity;
		cout << "Quantity: " << iQuantity << endl;

		inventoryFile >> dWholeSaleCost;
		cout << "Wholesale Cost: $" << setprecision(2) << fixed << dWholeSaleCost << endl;

		inventoryFile >> dRetailPrice;
		cout << "Retail Price: $" << dRetailPrice << endl << endl;
	}

	cin.ignore();
	cout << "\nPress enter to exit.\n";
	cin.get();
	
	inventoryFile.close();

	return 0;
}