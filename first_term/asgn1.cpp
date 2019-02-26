/*********************************************************
 * Project Filename: asgn1.cpp
 * Author: Thomas Weathers
 * Date: 1/13/18
 * Description: This program outputs different print statements of procedures and results of different math equations
 * Input: n/a
 * Output: multiple cout statements with no value returned
 * * ******************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main(){

	//basic problems with  printed  results

	//COS(2/3)
	double cosResult = cos(2.0 / 3.0);
	cout << "Cos(2/3) = " << cosResult << endl;

	//SIN(2/3)
	double sinResult = sin(2.0 / 3.0);
	sinResult *= 2;
	cout << "2Sin(2/3) = " << sinResult <<endl;

	//TAN(-3/4)
	double temp = 3.0 / 4.0;
	temp *= -1;
	double tanResult = tan(temp);
	cout << "tan(-3/4) = " << tanResult << endl;

	//LOG10(55)
	double log10Result = log10(55.0);
	cout << "log10(55) = " << log10Result << endl;

	//LN(60)
	double lnResult = log(60.0);
	cout << "ln(60) = " << lnResult << endl;

	//printed  steps and results of problems

	//log2(15)
	cout << "1. to solve log2(15) we can change the format to ln(15)/ln(2)" << endl;
	double lnNumerator1 = log(15);
	cout << "2. next we need to solve for the numerator, ln(15), which equals: " << lnNumerator1 << endl;
	double lnDenominator1 = log(2);
	cout << "3. next we calculate the denominator, ln(2), which equals: " << lnDenominator1 << endl;
	double equation1Final = lnNumerator1 / lnDenominator1;
	cout << "4. lastly we divide the numerator by the denominator to get: " << equation1Final << endl;
	//LOG4(40)
	cout << "\n1. to solve log4(40) we can change the format to ln(40)/ln(4)" << endl;
        double lnNumerator2 = log(40);
        cout << "2. next we need to solve for the numerator, ln(40), which equals: " << lnNumerator2 << endl;
        double lnDenominator2 = log(4);
        cout << "3. next we calculate the denominator, ln(4), which equals: " << lnDenominator2 << endl;
        double equation2Final = lnNumerator2 / lnDenominator2;
        cout << "4. lastly we divide the numerator by the denominator to get: " << equation2Final << endl;

	//3^SIN(X)
	//X = 1,10,100

	//X = 1
	double exponent1 = sin(1);
	cout << "\n1. to find 3^sin(x) when x = 1, first we need to find the exponent, sin(1), which equals: " << exponent1 << endl;
	double equation3Final = pow(3.0, exponent1);
	cout << "2. next we find 3 to the power of the value we just found \n which equals: " << equation3Final << endl;

  	//X = 10
  	exponent1 = sin(10);
        cout << "\n1.next we find 3^sin(x) when x = 10, first we need to find the exponent, sin(10), which equals: " << exponent1 << endl;
        equation3Final = pow(3.0, exponent1);
        cout << "2. next we find 3 to the power of the value we just found\n which equals: " << equation3Final << endl;

	//X = 100
	exponent1 = sin(100);
        cout << "\n1. to find 3^sin(x) when x = 100, first we need to find the exponent, sin(100), which equals: " << exponent1 << endl;
        equation3Final = pow(3.0, exponent1);
        cout << "2. next we find 3 to the power of the value we just found\n  which equals: " << equation3Final << endl;

	//LOG2(X^2 + 1)
	//X = 1,10,100
	double x = 1;
	double exponentAddOne = pow(x,2) + 1;
	//x=1
	cout << "\nto find log2(x^2 + 1 when x = 1, first find the value of the equation x^2 + 1 when x = 1. This value is: " << exponentAddOne << endl;
	cout << "2. next we have to evaluate log base 2 of "<< exponentAddOne << "by using ln("<<exponentAddOne<<") / ln(2)" << endl;
	double ex3Num =  log(exponentAddOne);
	double ex3Denom = log(2);
	cout <<"3. ln("<<exponentAddOne<<") equals: " << ex3Num << endl;
	cout <<"4. ln(2) equals: " << ex3Denom << endl;
	double ex3Final = ex3Num / ex3Denom;
	cout <<"5. lastly we have to divide the numerator by the denominator to get: " << ex3Final << endl;

	//x = 10
	x = 10;
 	exponentAddOne = pow(x,2) + 1;
	cout <<"\nto find log2(x^2 + 1) when x = 10, first find the value of the equation x^2 + 1 when x = 10. \n the value is: " << exponentAddOne << endl;
	cout << "2. next we have to evaluate log base 2 of "<< exponentAddOne << "by using ln("<<exponentAddOne<<") / ln(2)" << endl;
        ex3Num =  log(exponentAddOne);
        ex3Denom = log(2);
        cout <<"3. ln("<<exponentAddOne<<") equals: " << ex3Num << endl;
        cout <<"4. ln(2) equals: " << ex3Denom<<endl;
        ex3Final = ex3Num / ex3Denom;
        cout <<"5. lastly we have to divide the numerator by the denominator to get: " << ex3Final << endl;

	//x = 100
	x = 100;
	exponentAddOne = pow(x,2) + 1;
	cout <<"\nto find log2(x^2 + 1) when x = 100, first find the value of the equation x^2 + 1 when x = 100. \n the value is: " << exponentAddOne << endl;
        cout << "2. next we have to evaluate log base 2 of "<< exponentAddOne << "by using ln("<<exponentAddOne<<") / ln(2)" << endl;
        ex3Num =  log(exponentAddOne);
        ex3Denom = log(2);
        cout <<"3. ln("<<exponentAddOne<<") equals: " << ex3Num << endl;
        cout <<"4. ln(2) equals: " << ex3Denom << endl;
        ex3Final = ex3Num / ex3Denom;
        cout <<"5. lastly we have to divide the numerator by the denominator to get: " << ex3Final << endl;




	return 0;
}
