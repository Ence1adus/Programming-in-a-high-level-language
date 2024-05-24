#include <iostream>
#include "sample.h"
#include<complex>
#include <vector>
#include <fstream>
#include "Matrix.h"
using namespace std;

int main() {
	
	Matrix mat_1(3, 2);
	mat_1.SetValue(3);
	mat_1.printMatrix();
	cout << "#######################################" << endl;
	Matrix mat_2 = mat_2.IdentityMatrix(5);
	mat_2.printMatrix();
	cout << "#######################################" << endl;
	Matrix mat_3(2, 5);
	mat_3.SetValue(5);
	mat_1 = mat_1 * mat_3;
	mat_1.printMatrix();
	cout << "#######################################" << endl;
	cout << "Input data" << endl;
	mat_3.printMatrix();
	Matrix mat_4 = ~mat_3;
	cout << "OUTPUT data" << endl;
	mat_4.printMatrix();
	cout << "#######################################" << endl;
	mat_4.CanMul(mat_1);
	cout << "#######################################" << endl;
	mat_4 /= mat_2;
	
}