#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Book.h"

using namespace std;

int main()
{
	int iNumBooks;
	ifstream inventoryFile;
	string sFilename;

	//enumerated data type for use with iDateLocal
	enum eDate { YEAR, MONTH, DAY };

	//local variables use with class "cBook" setters
	int iIdentifierLocal, iQuantityLocal, iDateLocal[3];
	long long int lliISBNLocal;
	double dWholeSaleCostLocal, dRetailPriceLocal;
	string sTitleLocal, sAuthorLocal, sPublisherLocal;

	//Reading Inventory File Name
	cout << "Enter filename:\n";
	cin >> sFilename;
	inventoryFile.open(sFilename);

	while (inventoryFile.fail())
	{
		cout << "\nInvalid filename.\nEnter filename:\n";
		cin >> sFilename;
		inventoryFile.open(sFilename);
	}


	//Reading Inventory File into Inventory Vector
	inventoryFile >> iNumBooks;
	vector <cBook> vInventory(iNumBooks);
	//cout << "Number of Books: " << iNumBooks << endl << endl;
	
	for (int i = 0; i < iNumBooks; i++)
	{
		inventoryFile >> iIdentifierLocal;
		vInventory[i].setiIdentifier(iIdentifierLocal);
		
		inventoryFile >> lliISBNLocal;
		vInventory[i].setlliISBN(lliISBNLocal);
		
		inventoryFile.ignore();

		getline(inventoryFile, sTitleLocal);
		vInventory[i].setsTitle(sTitleLocal);

		getline(inventoryFile, sAuthorLocal);
		vInventory[i].setsAuthor(sAuthorLocal);

		getline(inventoryFile, sPublisherLocal);
		vInventory[i].setsPublisher(sPublisherLocal);

		inventoryFile >> iDateLocal[YEAR];
		inventoryFile >> iDateLocal[MONTH];
		inventoryFile >> iDateLocal[DAY];
		vInventory[i].setiDate(iDateLocal[YEAR], iDateLocal[MONTH], iDateLocal[DAY]);

		inventoryFile >> iQuantityLocal;
		vInventory[i].setiQuantity(iQuantityLocal);

		inventoryFile >> dWholeSaleCostLocal;
		vInventory[i].setdWholeSaleCost(dWholeSaleCostLocal);

		inventoryFile >> dRetailPriceLocal;
		vInventory[i].setdRetailPrice(dRetailPriceLocal);

		//cout << "Identifier: " << iIdentifierLocal << endl;
		//cout << "ISBN-13: " << lliISBNLocal << endl;
		//cout << "Title: " << sTitleLocal << endl;
		//cout << "Author : " << sAuthorLocal << endl;
		//cout << "Publisher: " << sPublisherLocal << endl;
		//cout << "Year: " << iDateLocal[YEAR] << endl;
		//cout << "Month: " << iDateLocal[MONTH] << endl;
		//cout << "Day: " << iDateLocal[DAY] << endl;
		//cout << "Quantity: " << iQuantityLocal << endl;
		//cout << "Wholesale Cost: $" << setprecision(2) << fixed << dWholeSaleCostLocal << endl;
		//cout << "Retail Price: $" << dRetailPriceLocal << endl << endl;

	}

	//Test Output of Book Inventory using Getters from cBook Class
	for (int i = 0; i < iNumBooks; i++)
	{
		cout << "Identifier: " << vInventory[i].cBook::getiIdentifier() << endl;
		cout << "ISBN-13: " << vInventory[i].cBook::getlliISBN() << endl;
		cout << "Title: " << vInventory[i].cBook::getsTitle() << endl;
		cout << "Author : " << vInventory[i].cBook::getsAuthor() << endl;
		cout << "Publisher: " << vInventory[i].cBook::getsPublisher() << endl;
		cout << "Year: " << vInventory[i].cBook::getiDateYear() << endl;
		cout << "Month: " << vInventory[i].cBook::getiDateMonth() << endl;
		cout << "Day: " << vInventory[i].cBook::getiDateDay() << endl;
		cout << "Quantity: " << vInventory[i].cBook::getiQuantity() << endl;
		cout << "Wholesale Cost: $" << setprecision(2) << fixed << vInventory[i].cBook::getdWholeSaleCost() << endl;
		cout << "Retail Price: $" << vInventory[i].cBook::getdRetailPrice() << endl << endl;
	}


	cin.ignore();
	cout << "\nPress enter to exit.\n";
	cin.get();
	
	inventoryFile.close();

	return 0;
}