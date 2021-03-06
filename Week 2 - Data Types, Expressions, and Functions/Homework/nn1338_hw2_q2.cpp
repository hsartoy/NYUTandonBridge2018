//
//  main.cpp
//  nn1338_hw2_q2
//
//  Created by NomNomNam on 4/25/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that asks the user to enter an amount of money in the format of dollars and
 remaining cents. The program should calculate and print the minimum number of coins
 (quarters, dimes, nickels and pennies) that are equivalent to the given amount.
 
 Hint: In order to find the minimum number of coins, first find the maximum number of
 quarters that fit in the given amount of money, then find the maximum number of dimes
 that fit in the remaining amount, and so on.
 
 Your program should interact with the user exactly as it shows in the following example:
 
 Please enter your amount in the format of dollars and cents separated by a space:
 4 37
 4 dollars and 37 cents are:
 17 quarters, 1 dimes, 0 nickels and 2 pennies
 
 */

#include <iostream>
using namespace std;

const int CENTS_TO_DOLLAR = 100;
const int VALUE_OF_A_QUARTER = 25;
const int VALUE_OF_A_DIME = 10;
const int VALUE_OF_A_NICKEL = 5;
const int VALUE_OF_A_PENNY = 1;

int main() {
    
    int dollarInputAmount, centInputAmount;
    int dollarToCent, totalCentAmount;
    int minQuarterAmount, minDimeAmount, minNickelAmount, minPennyAmount;
    
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollarInputAmount>>centInputAmount;
    
    cout<<dollarInputAmount<<" dollars and "<<centInputAmount<<" cents are:"<<endl;
    
    // Convert dollar(s) to cent(s)
    dollarToCent = dollarInputAmount * CENTS_TO_DOLLAR;
    
    // Get total cent amount to be able to calculate minimum coin amounts
    totalCentAmount = dollarToCent + centInputAmount;
    
    // To get minimum coin amounts, start off with the biggest coin (quarter) and divide total cent amount
    minQuarterAmount = totalCentAmount / VALUE_OF_A_QUARTER;
    
    // After dividing it by the quarter, based on sequential flow, the next biggest coin is the dime
    // Take the amount leftover  and divide by 10 to find how many times go into the remaining amount
    minDimeAmount = (totalCentAmount - minQuarterAmount * VALUE_OF_A_QUARTER) / VALUE_OF_A_DIME;
    
    // Continue this idea with nickels and pennies
    minNickelAmount = (totalCentAmount - minQuarterAmount * VALUE_OF_A_QUARTER - minDimeAmount * VALUE_OF_A_DIME) / VALUE_OF_A_NICKEL;
    
    minPennyAmount = (totalCentAmount - minQuarterAmount * VALUE_OF_A_QUARTER - minDimeAmount * VALUE_OF_A_DIME - minNickelAmount * VALUE_OF_A_NICKEL) / VALUE_OF_A_PENNY;
    
    // Print-out of the coins
    cout<<minQuarterAmount<<" quarters, "<<minDimeAmount<<" dimes, "<<minNickelAmount<<" nickels";
    cout<<" and "<<minPennyAmount<<" pennies"<<endl;
    
    return 0;
}
