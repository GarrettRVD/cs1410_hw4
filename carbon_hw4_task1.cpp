// File: carbon_hw4_task1.cpp
// Created by Garrett Van Dyke and Kevin Tenney on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU

#include <iostream>
using namespace std;
// Constants, Classes, Structures
class HouseInfo
{
private:
    int streetNum;
    string streetName;
    double price;
public:
    HouseInfo InputHouse()
    {
        //Create a copy of the structure house
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

    void PrintHouse( int houseNum, HouseInfo h)
    {

        cout << houseNum <<" House: at " << h.streetNum << " "
             << h.streetName << " " << "for " << h.price << endl;

    }

    double GetPrice()
    {
        return price;
    }


};
// Prototypes
const int SIZE = 3;
int ComparePrices(HouseInfo array[]);

// Main Program
int main()
{
    HouseInfo array[SIZE];
    HouseInfo h1, h2, h3;
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
    int comparison = ComparePrices(array);
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
        default:
            cout << "Invalid input" << endl;
    }

    return 0;
}


// Function Definitions
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