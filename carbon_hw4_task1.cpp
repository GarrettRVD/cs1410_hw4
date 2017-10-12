// File: carbon_hw4_task1.cpp
// Created by Garrett Van Dyke and Kevin Tenney on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU

#include <iostream>
using namespace std;
// Constants, Classes, Structures
class house
{
private:
    int streetNum;
    string streetName;
    double price;
public:
    house InputHouse()
    {
        //Create a copy of the structure house
        house h;
        //Get the address and price of home
        cout << "Please enter the street number: " << endl;
        cin >> h.streetNum;
        cin.ignore();
        cout << "Please enter the street name: " << endl;
        getline(cin, h.streetName);

        cout << "Please enter the price of the house: " << endl;
        cin >> h.price;
        cin.ignore();
        return h;

    }

    int ComparePrices(house array[])
    {

        if ( array[0].price < array[1].price && array[0].price < array[2].price)
        {
            return 1;
        }
        else if ( array[1].price <  array[0].price && array[1].price < array[2].price)
        {
            return 2;
        }
        else if (array[2].price < array[1].price && array[2].price < array[0].price)
        {
            return 3;
        }
        else if (array[0].price == array[1].price && array[0].price < array[2].price)
        {
            return 4;
        }
        else if (array[1].price == array[2].price && array[1].price < array[0].price)
        {
            return 5;
        }
        else if (array[0].price == array[2].price && array[0].price < array[1].price)
        {
            return 6;
        }
        else if (array[0].price == array[1].price && array[1].price == array[2].price)
        {
            return 7;
        }
        else
            return 8;
    }
    void PrintHouse( int houseNum, house h)
    {

        cout <<houseNum<<" House: at " << h.streetNum << " "
             << h.streetName << " " << "for "<< h.price<<endl;

    }
};
// Prototypes
const int SIZE = 3;
// Main Program
int main()
{
    house array[SIZE];
    house h1, h2, h3;
    cout<< "Enter the info for house 1"<<endl;
    array[0] = h1.InputHouse();

    cout << "Enter info for house 2\n";
    array[1] = h2.InputHouse();

    cout << "Enter info for house 3"<<endl;
    array[2] = h3.InputHouse();

    cout << "Your 3 houses are:"<<endl;
    h1.PrintHouse(1, array[0]);
    h2.PrintHouse(2, array[1]);
    h3.PrintHouse(3, array[2]);


    //Compare the prices of the two homes with a function
    int comparison = array[SIZE].ComparePrices(array[]);
    //Switch statement for the 4 cases of comparision
    switch(comparison)
    {
        case 1:
            cout << "You should buy house number 1" << endl;
            break;
        case 2:
            cout << "You should buy house number 2" << endl;
            break;
        case 3:
            cout << "You should buy house number 3" << endl;
            break;
        case 4:
            cout << "You should buy house number 1 or house number 2" << endl;
            break;
        case 5:
            cout << "You should buy house number 2 or house number 3" << endl;
        case 6:
            cout << "You should buy house number 1 or house number 3" << endl;
        case 7:
            cout << "You should buy any of the houses" << endl;
        case 8:
            cout << "Invalid input" << endl;
    }

    return 0;
}



// Function Definitions