#pragma once
#include <iostream>
#include "sample.h"
#include<complex>
#include <vector>
#include <fstream>

class SampleComplex : public Sample<std::complex<double>> {
public:
    // Конструктор квадратной выборки
    SampleComplex() = default;
    SampleComplex(int m_size_x) : Sample<std::complex<double>>(m_size_x, m_size_x) {}
    ~SampleComplex() = default;
    //Функция вычисления модуля всех элементов выборки
    Sample<double> GetAbs();
    //Функция вычисления фазы всех элементов выборки
    Sample<double> GetPhase();
    //Функция вычисления интенсивности всех элементов выборки
    SampleComplex GetIntensity();
    //Функция преобразования из complex в double 
    Sample<double> ComplexToDouble();
    //Функция преобразования из double в complex 
    SampleComplex DoubleToComplex(Sample<double>& temp);
    void SaveRealPart(string path_1);
    void SaveImagePart(string path_1);
    void SaveAbs(string path_1);
    void SavePhase(string path_1);
    void SaveIntensity(string path_1);

};

Sample<double> SampleComplex::GetAbs()
{
    Sample<double> return_data;
    return_data.Resize(m_size_x);
    return_data.SetValue(0);

    for (int i = 0; i < m_size_x; i++) {
        for (int j = 0; j < m_size_x; j++) {
            return_data(i, j) = real(this->operator()(i, j)) * real(this->operator()(i, j)) + imag(this->operator()(i, j)) * imag(this->operator()(i, j));
        }
    }
    return return_data;

}

Sample<double> SampleComplex::GetPhase()
{
    Sample<double> return_data;
    return_data.Resize(m_size_x);
    return_data.SetValue(0);

    for (int i = 0; i < m_size_x; i++) {
        for (int j = 0; j < m_size_x; j++) {
            return_data(i, j) = arg(this->operator()(i, j));
        }
    }

    return return_data;

}

SampleComplex SampleComplex::GetIntensity()
{
    SampleComplex return_data;
    return_data.Resize(m_size_x);
    return_data.SetValue(0);
    double real_part = 0;
    for (int i = 0; i < m_size_x; i++) {
        for (int j = 0; j < m_size_x; j++) {
            std::complex<double> num = (0, 0.0);
            real_part = real(this->operator()(i, j)) * real(this->operator()(i, j)) + imag(this->operator()(i, j)) * imag(this->operator()(i, j));
            num.real(real_part * real_part);
            return_data(i, j) = num;
        }
    }


    return return_data;
}

Sample<double> SampleComplex::ComplexToDouble()
{
    Sample<double> return_data;
    return_data.Resize(m_size_x);
    return_data.SetValue(0);

    for (int i = 0; i < m_size_x; i++) {
        for (int j = 0; j < m_size_x; j++) {
            return_data(i, j) = real(this->operator()(i, j));
        }
    }

    return return_data;
}


SampleComplex SampleComplex::DoubleToComplex(Sample<double>& temp)
{
    SampleComplex return_data;
    return_data.Resize(temp.GetSize());
    return_data.SetValue(0);
    complex<double> num = 0;
    for (int i = 0; i < temp.GetSize(); i++) {
        for (int j = 0; j < temp.GetSize(); j++) {
            num.real(temp(i, j));
            num.imag(0.0);
            return_data(i, j) = num;
        }
    }

    return return_data;
}

void SampleComplex::SaveRealPart(string path_1)
{
    ofstream out;
    out.open(path_1);
    if (!out.is_open())
    {
        throw std::runtime_error("Something wrong! Cant open write file!");
    }
    else
    {
        for (int i = 0; i < m_size_x; i++) {
            for (int j = 0; j < m_size_y; j++) {
                out << real(this->operator()(i, j)) << " ";
            }
            out << std::endl;
        }
       
    }
    out.close();

}

void SampleComplex::SaveImagePart(string path_1)
{

    ofstream out;
    out.open(path_1);
    if (!out.is_open())
    {
        throw std::runtime_error("Something wrong! Cant open write file!");
    }
    else
    {
        for (int i = 0; i < m_size_x; i++) {
            for (int j = 0; j < m_size_y; j++) {
                out << imag(this->operator()(i, j)) << " ";
            }
            out << std::endl;
        }
        
    }
    out.close();

}

void SampleComplex::SaveAbs(string path_1)
{
    ofstream out;
    out.open(path_1);
    if (!out.is_open())
    {
        throw std::runtime_error("Something wrong! Cant open write file!");
    }
    else
    {
        for (int i = 0; i < m_size_x; i++) {
            for (int j = 0; j < m_size_y; j++) {
                out << real(this->operator()(i, j)) * real(this->operator()(i, j)) + imag(this->operator()(i, j)) * imag(this->operator()(i, j)) << " ";
            }
            out << std::endl;
        }
        
    }
    out.close();
}

void SampleComplex::SavePhase(string path_1)
{
    ofstream out;
    out.open(path_1);
    if (!out.is_open())
    {
        throw std::runtime_error("Something wrong! Cant open write file!");
    }
    else
    {
        for (int i = 0; i < m_size_x; i++) {
            for (int j = 0; j < m_size_y; j++) {
                out << arg(this->operator()(i, j)) << " ";
            }
            out << std::endl;
        }
        
    }
    out.close();
}

void SampleComplex::SaveIntensity(string path_1)
{

    ofstream out;
    out.open(path_1);
    if (!out.is_open())
    {
        throw std::runtime_error("Something wrong! Cant open write file!");

    }
    else
    {
        for (int i = 0; i < m_size_x; i++) {
            for (int j = 0; j < m_size_y; j++) {
                out << real(this->operator()(i, j)) * real(this->operator()(i, j)) + imag(this->operator()(i, j)) * imag(this->operator()(i, j)) << " ";
            }
            out << std::endl;
        }
       
    }
    out.close();

}