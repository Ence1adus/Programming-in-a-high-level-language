// Laba 3_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <boost/asio.hpp>
#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"
#include "fftw3.h"
#include <iostream>
#include "sample.h"
#include<complex>
#include <vector>
#include <fstream>
#include"SampleComplex.h"
#include "Matrix.h"
using namespace std;


void print_matrix_2_2(const std::string& sText, boost::numeric::ublas::matrix<double> a)
{
    std::cout << sText << std::endl;
    std::cout << a(0, 0) << " " << a(0, 1) << std::endl;
    std::cout << a(1, 0) << " " << a(1, 1) << std::endl << std::endl;
}

int main()
{
    // Сравнение произведенитя матриц при помощи boost
    // Создаем и заполняем первую матрицу с помощью boost

    cout << "boost library:" << endl;

    boost::numeric::ublas::matrix<double> a(2, 2);
    a(0, 0) = 1.;
    a(0, 1) = 2.;
    a(1, 0) = 3.;
    a(1, 1) = 4.;
    print_matrix_2_2("a:", a);

    // матрица b - единичная
    boost::numeric::ublas::matrix<double> b(2, 2);
    b(0, 0) = 1.;
    b(0, 1) = 0.;
    b(1, 0) = 0.;
    b(1, 1) = 1.;
    print_matrix_2_2("b:", b);

    // перемножение двух матриц
    boost::numeric::ublas::matrix<double> c = prod(b, a);
    print_matrix_2_2("c=a*b:", c);
    cout << "My Multiplication mat"<<endl;
    Matrix mat_a(2, 2);
    mat_a(0, 0) = 1.;
    mat_a(0, 1) = 2.;
    mat_a(1, 0) = 3.;
    mat_a(1, 1) = 4.;
    cout << "My data input a matrix :" << endl;
    mat_a.printMatrix();
    Matrix mat_b = mat_b.IdentityMatrix(2);
    cout << "My data input b matrix :" << endl;
    mat_b.printMatrix();
    cout << "Mul matrix :" << endl;
    mat_a = mat_a * mat_b;
    mat_a.printMatrix();
    cout << "FFT";
    // Использование FFT
    SampleComplex FFT_prim(512);
    complex<double> fft_num(1, 0);
    FFT_prim.SetValue(fft_num);
    
    // создаем одномерную выборку, все значения которой равны 1

    // создаем план для библиотеки fftw

    fftw_plan plan = fftw_plan_dft_2d(FFT_prim.GetSize(), FFT_prim.GetSize(), (fftw_complex*)FFT_prim.GetPointer(), (fftw_complex*)FFT_prim.GetPointer(), FFTW_FORWARD, FFTW_ESTIMATE);

    // преобразование Фурье
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    // выводим в файл результат преобразования Фурье (должна получиться Дельта-функция)
    ofstream out("D:\\speсtrum.txt");
    for (int i = 0; i < FFT_prim.GetSize(); i++)
    {
        for (int  j = 0; j < FFT_prim.GetSize(); j++)

        out << FFT_prim(i, j) << endl;
        
    }
    cout << "THE END!!!!!!!!!!!!!!!!!!!!!"<<endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
