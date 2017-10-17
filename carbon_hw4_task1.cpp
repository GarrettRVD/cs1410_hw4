// File: carbon_hw4_task1.cpp
// Created by Garrett Van Dyke and Kevin Tenney on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
#include <iostream>
#include <iomanip>
using namespace std;

// Constants, Classes, Structures
const int SIZE = 3;

class HouseInfo
{
private:
    int streetNum;
    string streetName;
    double price;
public:
    HouseInfo InputHouse()
    {
        //Create a copy of the class HouseInfo
        HouseInfo hi;
        //Get the address and price of home
        cout << "Please enter the street number: " << endl;
        cin >> hi.streetNum;
        cin.ignore();
        cout << "Please enter the street name: " << endl;
        getline(cin, hi.streetName);

        cout << "Please enter the price of the house: " << endl;
        cin >> hi.price;
        cin.ignore();

        return hi;
    }

    int GetStreetNum()
    {
        return streetNum;
    }

    string GetStreetName()
    {
        return streetName;
    }

    double GetPrice()
    {
        return price;
    }

};

// Prototypes
void PrintHouse(int houseNum, HouseInfo h);
int ComparePrices(HouseInfo array[]);

// Main Program
int main()
{
    HouseInfo array[SIZE];
    HouseInfo h1, h2, h3;
    cout<< "Enter the info for house 1"<<endl;
    array[0] = h1.InputHouse();

    cout << "\nEnter info for house 2\n";
    array[1] = h2.InputHouse();

    cout << "\nEnter info for house 3"<<endl;
    array[2] = h3.InputHouse();

    cout << "\nYour 3 houses are:"<<endl;
    PrintHouse(1, array[0]);
    PrintHouse(2, array[1]);
    PrintHouse(3, array[2]);


    //Compare the prices of the two homes with a function
    int comparison = ComparePrices(array);
    //Switch statement for the cases of comparision
    switch(comparison)
    {
        case 1:
            cout << "\nYou should buy house number 1" << endl;
            break;
        case 2:
            cout << "\nYou should buy house number 2" << endl;
            break;
        case 3:
            cout << "\nYou should buy house number 3" << endl;
            break;
        case 4:
            cout << "\nYou should buy house number 1 or house number 2" << endl;
            break;
        case 5:
            cout << "\nYou should buy house number 2 or house number 3" << endl;
            break;
        case 6:
            cout << "\nYou should buy house number 1 or house number 3" << endl;
            break;
        case 7:
            cout << "\nYou should buy any of the houses" << endl;
            break;
        default:
            cout << "\nInvalid input" << endl;
    }

    return 0;
}


// Function Definitions
void PrintHouse(int houseNum, HouseInfo h)
{
    cout << houseNum <<" House: at " << h.GetStreetNum() << " "
    << h.GetStreetName() << " " << "for $[" << fixed << setprecision(2) << h.GetPrice() << "]" << endl;

}

int ComparePrices(HouseInfo array[])
{

    if (array[0].GetPrice() < array[1].GetPrice() && array[0].GetPrice() < array[2].GetPrice())
    {
        return 1;
    }
    else if (array[1].GetPrice() <  array[0].GetPrice() && array[1].GetPrice() < array[2].GetPrice())
    {
        return 2;
    }
    else if (array[2].GetPrice() < array[1].GetPrice() && array[2].GetPrice() < array[0].GetPrice())
    {
        return 3;
    }
    else if (array[0].GetPrice() == array[1].GetPrice() && array[0].GetPrice() < array[2].GetPrice())
    {
        return 4;
    }
    else if (array[1].GetPrice() == array[2].GetPrice() && array[1].GetPrice() < array[0].GetPrice())
    {
        return 5;
    }
    else if (array[0].GetPrice() == array[2].GetPrice() && array[0].GetPrice() < array[1].GetPrice())
    {
        return 6;
    }
    else if (array[0].GetPrice() == array[1].GetPrice() && array[1].GetPrice() == array[2].GetPrice())
    {
        return 7;
    }

}
