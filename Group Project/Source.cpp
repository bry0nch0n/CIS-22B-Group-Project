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
	fstream inventoryFile;
	string sFilename;
	double dTotalWholeSaleValue = 0.00, dTotalRetailPrice = 0.00;

	//enumerated data type for use with iDateLocal
	enum eDate { YEAR, MONTH, DAY };

	//local variables use with class "cBook" setters
	int iIdentifierLocal, iQuantityLocal, iDateLocal[3];
	long long int lliISBNLocal;
	double dWholeSaleCostLocal, dRetailPriceLocal;
	string sTitleLocal, sAuthorLocal, sPublisherLocal;

	//Reading Inventory File Name
	cout << "Enter filename: ";
	cin >> sFilename;
	inventoryFile.open(sFilename);

	while (inventoryFile.fail())
	{
		cout << "\nInvalid filename.\nEnter filename:\n";
		cin >> sFilename;
		inventoryFile.open("sFilename", ios::in, ios::out);
	}

	//Default "Inventory.txt"
	//inventoryFile.open("Inventory.txt", ios::in, ios::out);

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
	}

	//Test Output of Book Inventory using Getters from cBook Class
	cout << endl;
	for (int i = 0; i < iNumBooks; i++)
	{
		if (vInventory[i].cBook::getiQuantity() >= 1)
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
		
		else;
	}

	//Total Wholesale Value
	cout << "Wholesale Value\n";
	for (int i = 0; i < iNumBooks; i++)
	{
		if (vInventory[i].cBook::getiQuantity() >= 1)
		{
			dTotalWholeSaleValue += vInventory[i].cBook::getdWholeSaleCost();
			cout << vInventory[i].cBook::getsTitle() << ": $" << vInventory[i].cBook::getdWholeSaleCost() << endl;
		}

		else;
	}
	cout << "\nTotal Wholesale Value: $" << dTotalWholeSaleValue << "\n\n";

	//Total Retail Price
	cout << "Retail Value\n";
	for (int i = 0; i < iNumBooks; i++)
	{
		if (vInventory[i].cBook::getiQuantity() >= 1)
		{
		dTotalRetailPrice += vInventory[i].cBook::getdRetailPrice();
		cout << vInventory[i].cBook::getsTitle() << ": $" << vInventory[i].cBook::getdRetailPrice() << endl;
		}

		else;
	}
	cout << "\nTotal Retail Value: $" << dTotalRetailPrice << "\n\n";

	//List by Quantity
	cout << "List by Quantity\n";

	

	//List by Cost
	cout << "List by Wholesale Cost\n";


	//List by Age
	cout << "List by Age\n";

	cin.ignore();
	cout << "\n\nPress enter to exit.\n";
	cin.get();
	
	inventoryFile.close();

	return 0;
}
