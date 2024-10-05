#include "bobyerly42_prog3.h"

/******************************************************************************************************
* Function Name: getprofit
* Purpose: let the user enter in valeus for each month. This function also calls the function get total. 
        Which will calculate the running total and will send all data to function (printresults)
*******************************************************************************************************/

void getprofit(double &yearlyProfits, double profitArr[], int size)  
{                                                                   // size is set to 12 in the gettotal function
    for(int i=0; i<size; i++)
    {
        cout << "Enter the profit for month " << i+1 << ": $";
        cin >> profitArr[i];
        while(profitArr[i] <0)//gets an array of how much money was earned per month.
        {                       //and validates if <0
            cout << "I'm sorry, you must enter a profit greater than zero."; 
            cout << "\nEnter the profit for month " << i+1 << ": $";
            cin >> profitArr[i];
        }
        gettotal(yearlyProfits, profitArr, i);
    }
}
/****************************************************************************************************************
* Function Name; gettotal
* Purpose: Grab the running total data from the function getprofit and send the results to function: (printresults)
******************************************************************************************************************/

double gettotal(double &yearlyProfit, double profitArr[], int i)
{   
    yearlyProfit +=profitArr[i];
    return yearlyProfit;
}
/********************************************************************************************************************
* Function: getmax
* Purpose: Find the maximum value out of the 12 values inputed into the profit array and sends results to printresults.
*********************************************************************************************************************/

void getmax(string monthNames[], string &month, double profitArr[], double &maxVal)
{
    maxVal=0;
    for( int i=0; i<12; i++)
    {
        if(profitArr[i] > maxVal)
        {
            maxVal = profitArr[i];
            month = monthNames[i];   
        }               
    }
}
/********************************************************************************************************************
* Function: getmin
* Purpose: Find the minimum value out of the 12 values inputed into the profit array and sends results to printresults.
*********************************************************************************************************************/

void getmin(string monthNames[], double &minVal, double profitArr[], string &month2)
{
    minVal=profitArr[0];
    for(int i=0; i<12; i++)
    {
        if(profitArr[i] <= minVal)
        {
            minVal = profitArr[i];
            month2 = monthNames[i];
        }
    }
}
/************************************************************************************************************************
* Function: getquarterly
* Purpose: Find the quarterly values out of the 12 values inputed into the profit array and sends results to printresults.
*************************************************************************************************************************/

void getquarterly(double profitArr[], double qtrArr[])
{
    qtrArr[0] = profitArr[0] + profitArr[1] + profitArr[2]; 
    qtrArr[1] = profitArr[3] + profitArr[4] + profitArr[5];
    qtrArr[2] = profitArr[6] + profitArr[7] + profitArr[8];
    qtrArr[3] = profitArr[9] + profitArr[10] + profitArr[11];
}
/*************************************************************************************************************************
* Function printresults
* Purpose: to grab all of the data from the other function and outputs to a file that the user creates and to the screen. 
**************************************************************************************************************************/

void printresults(double yearlyProfits, double maxVal, string &month, double minVal, string &month2, double qtrArr[], ofstream &outFile, string filename)
{
    cout << "\nWhat is the name of the file you wish to print to? (example.txt)" << "\nFILENAME:";
    cin >> filename;
    outFile.open(filename);

    cout << "\n\n\n\n";
    cout << setw(75) << setfill('-') << "" <<  endl;
    cout << setw(75) << setfill('-') << "" <<  endl;
    cout << setw(35) << setfill(' ') << "TOTAL PROFITS FOR YEAR: " << setw(10) << setfill(' ') << "$" << fixed << setprecision(2) << yearlyProfits << endl;
    cout << setw(35) << "YEARLY AVERAGE PROFIT: " << setw(10) << setfill(' ') << "$" << fixed << setprecision(2) << yearlyProfits/12 << endl;
    cout << setw(8) << setfill(' ') << "" << "MONTH WITH LARGEST PROFIT:          " << month << " totalling $" << maxVal << endl;
    if(minVal == maxVal)    //makes smallest month = largest month (if minVal = maxVal)
        month2 = month;
    cout << setw(7) << setfill(' ') << "" << "MONTH WITH SMALLEST PROFIT:          " << month2 << " totalling $" << minVal << endl;
    cout << setw(75) << setfill('-') << "" << endl << endl;
    cout << setw(42) << setfill(' ') << "QUARTERLY PROFITS" << endl;
    cout << setw(29) << setfill(' ') << "January - March" << setw(10) << setfill(' ') << "" << "$" << qtrArr[0] << endl;
    cout << setw(29) << setfill(' ') << "April - June" << setw(10) << setfill(' ') << "" << "$" << qtrArr[1] << endl;
    cout << setw(29) << setfill(' ') << "July - September" << setw(10) << setfill(' ') << "" << "$" << qtrArr[2] << endl;
    cout << setw(29) << setfill(' ') << "October - December" << setw(10) << setfill(' ') << "" << "$" << qtrArr[3] << endl;
    cout << setw(75) << setfill('-') << "" <<  endl;
    cout << setw(75) << setfill('-') << "" <<  endl;
//****************************************************************************************************************************************************************
//exact copy from above put outputs to the text file
    outFile << setw(75) << setfill('-') << "" <<  endl;
    outFile << setw(75) << setfill('-') << "" <<  endl;
    outFile << setw(35) << setfill(' ') << "TOTAL PROFITS FOR YEAR: " << setw(10) << setfill(' ') << "$" << fixed << setprecision(2) << yearlyProfits << endl;
    outFile << setw(35) << "YEARLY AVERAGE PROFIT: " << setw(10) << setfill(' ') << "$" << fixed << setprecision(2) << yearlyProfits/12 << endl;
    outFile << setw(8) << setfill(' ') << "" << "MONTH WITH LARGEST PROFIT:          " << month << " totalling $" << maxVal << endl;
    outFile << setw(7) << setfill(' ') << "" << "MONTH WITH SMALLEST PROFIT:          " << month2 << " totalling $" << minVal << endl;
    outFile << setw(75) << setfill('-') << "" << endl << endl;
    outFile << setw(42) << setfill(' ') << "QUARTERLY PROFITS" << endl;
    outFile << setw(29) << setfill(' ') << "January - March" << setw(10) << setfill(' ') << "" << "$" << qtrArr[0] << endl;
    outFile << setw(29) << setfill(' ') << "April - June" << setw(10) << setfill(' ') << "" << "$" << qtrArr[1] << endl;
    outFile << setw(29) << setfill(' ') << "July - September" << setw(10) << setfill(' ') << "" << "$" << qtrArr[2] << endl;
    outFile << setw(29) << setfill(' ') << "October - December" << setw(10) << setfill(' ') << "" << "$" << qtrArr[3] << endl;
    outFile << setw(75) << setfill('-') << "" <<  endl;
    outFile << setw(75) << setfill('-') << "" <<  endl;
    outFile.close();
}
