/*************************************************************************************** 
   Program:     bobyerly42_driver.cpp, bobyerly42_prog3.h, bobyerly42_functions.cpp     
   Author:      Ben Byerly 
   Date:        November 2nd
   Purpose:     Calculate Flourish & Blotts Bookstore profited the previous year.
****************************************************************************************/

#include "bobyerly42_prog3.h"

int main()
{
    //initializes all values that are going to be used in entire program
    string maxMonth, minMonth, filename;
    double yearlyProfits, profitArr[12], maxVal, minVal, qtrArr[4];
    char runAgain;
    ofstream outFile;
//An array to declare all of the months and their names
   string monthNames[12] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    
    cout << "\nWelcome to Flourish and Blotts Bookstore!\n\n";
    
    getprofit(yearlyProfits, profitArr, 12);
    getmax(monthNames, maxMonth, profitArr, maxVal);
    getmin(monthNames, minVal, profitArr, minMonth);
    getquarterly(profitArr, qtrArr);
    printresults(yearlyProfits, maxVal, maxMonth, minVal, minMonth, qtrArr, outFile, filename);

    //Below: asks the user if they would like to run the program again, if y && Y then returns to main, if anyting else returs 0
    cout << "\nWould you like to run the program again? (Y/N) " << endl;
    cin >> runAgain;
    if(runAgain == 'y' && 'Y'){
        return main();
    }
    else return 0;

return 0;
}