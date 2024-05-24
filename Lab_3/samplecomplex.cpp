#include <iostream>
#include "sample.h"
#include<complex>
#include <vector>
#include <fstream>
#include"SampleComplex.h"
#include "Matrix.h"
using namespace std;


int main()
{
    // Демонстрация complex
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    cout << "Sample_complex" << endl;
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    SampleComplex comp_1(4);
    complex<double> num_comp(2, 3);
    comp_1.SetValue(num_comp);
    comp_1.printMatrix();
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    Sample<double> comp_2 = comp_1.GetAbs();
    comp_2.printMatrix();
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    Sample<double> comp_3 = comp_1.GetPhase();
    comp_3.printMatrix();
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    SampleComplex comp_4 = comp_1.GetIntensity();
    comp_4.printMatrix();
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    Sample<double> comp_5 = comp_4.ComplexToDouble();
    comp_5.printMatrix();
    SampleComplex comp_6 = comp_6.DoubleToComplex(comp_2);
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    comp_6.printMatrix();
    comp_6.SaveRealPart("D:\\Testdata.txt");
    cout << "||||||||||||||||||||||||||||||||||" << endl;
}