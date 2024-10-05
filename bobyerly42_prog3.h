#ifndef BOBYERLY42_PROG3_H
#define BOBYERLY42_PROG3_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void getprofit(double &, double[], int);
double gettotal(double &, double [], int );
void getmax(string[], string&, double[], double&);
void getmin(string[], double&, double[], string&);
void getquarterly(double[], double[]);
void printresults(double, double, string&, double, string&, double[], ofstream&, string);
#endif