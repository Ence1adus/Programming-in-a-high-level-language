#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

template <class PAR>
class Sample {
protected:
	int m_size_x = 0, m_size_y = 0;
	std::vector<PAR> m_data;

public:
	Sample() = default;
	~Sample() = default;
	Sample(int m_size_x, int m_size_y) : m_size_x(m_size_x), m_size_y(m_size_y), m_data(m_size_x* m_size_y) {}
	// Вывод матрицы
	void printMatrix();
	// изменение размера для квадратной выборки
	void Resize(int size);
	// изменение размера для прямоугольной выборки
	void Resize(int size_x, int size_y);

	// размер выборки (для квадратной)
	int GetSize() const;
	// размер выборки по X и Y
	int GetSizeX() const;
	int GetSizeY() const;
	// оператор получения значения элемента с номером i,j
	PAR& operator()(int i, int j);
	// оператор получения const значения элемента с номером i,j
	const PAR& operator()(int i, int j) const;
	// проверка квадратная ли выборка
	bool IsSquare() const;
	// проверка что размер != 0
	bool IsZeroSize() const;
	//Заполнение матрицы значениеми
	void setMatrix();
	// инициализация всех элементов выборки одинаковым значением
	void SetValue(PAR value);
	// получение указателя на всю выборку
	PAR* GetPointer();
	// вычисление максимального значения
	PAR GetMax() const;

	// операции с выборкой и числом
	// сложение всех элементов выборки и числа
	Sample<PAR>& operator+=(PAR value);
	// умножение всех элементов выборки на число
	virtual Sample<PAR>& operator*=(PAR value);
	// деление всех элементов выборки на число
	virtual Sample<PAR>& operator/=(PAR value);

	// операции с двумя выборками
	// присваивание
	Sample<PAR>& operator= (const Sample<PAR>& temp);
	// поэлементное сложение двух выборок
	Sample<PAR>& operator+=(const Sample<PAR>& temp);
	// поэлементное вычитание двух выборок
	Sample<PAR>& operator-=(const Sample<PAR>& temp);
	// поэлементное перемножение двух выборок
	virtual Sample<PAR>& operator*=(const Sample<PAR>& temp);

	// вывод выборки в поток (файл или экран)
	std::ostream& Save(string path);
	// перегрузка оператора чтения выборки из файла 
	std::istream& Load(string path);

protected:
	// проверяет квадратная ли выборка, если нет - создает исключение
	void CheckSquare() const;

};


template <class PAR>
void Sample<PAR>::printMatrix() {
	for (int i = 0; i < this->m_size_x; i++) {
		for (int j = 0; j < this->m_size_y; j++) {
			std::cout << m_data[i * m_size_y + j] << " ";
		}
		std::cout << std::endl;
	}
}

template <class PAR>
void Sample<PAR>::Resize(int size) {
	m_data.resize(size * size);
	this->m_size_x = size;
	this->m_size_y = size;
}

template <class PAR>
void Sample<PAR>::Resize(int n, int m) {
	m_data.resize(n * m);
	this->m_size_x = n;
	this->m_size_y = m;
}

template <class PAR>
int Sample<PAR>::GetSize() const
{
	return m_size_x;
}
// размер выборки по X и Y
template <class PAR>
int Sample<PAR>::GetSizeX() const
{
	return m_size_x;
}
template <class PAR>
int Sample<PAR>::GetSizeY() const
{
	return m_size_y;
}

template<class PAR>
PAR& Sample<PAR>::operator()(int i, int j)
{
	return m_data[i * m_size_y + j];
}

template<class PAR>
const PAR& Sample<PAR>::operator()(int i, int j) const
{
	return m_data[i * m_size_y + j];
}
template<class PAR>
bool Sample<PAR>::IsSquare() const
{
	return (m_size_y == m_size_x);
}

template<class PAR>
bool Sample<PAR>::IsZeroSize() const
{
	return(m_size_y == 0 && m_size_x == 0);
}

template<class PAR>
void Sample<PAR>::setMatrix()
{
	std::cout << "Размер выборки " << m_size_y << " x " << m_size_x << std::endl;
	std::cout << "То есть " << m_size_y << " вектора, каждый из которых содержит " << m_size_x << " элементов" << std::endl;
	std::cout << "Введите " << m_size_y * m_size_x << " элементов" << std::endl;
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			std::cin >> m_data[i * m_size_y + j];
		}
	}
}

template<class PAR>
void Sample<PAR>::SetValue(PAR value)
{
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			m_data[i * m_size_y + j] = value;
		}
	}
}

template<class PAR>
PAR* Sample<PAR>::GetPointer()
{
	return m_data.data();
}

template<class PAR>
PAR Sample<PAR>::GetMax() const
{
	PAR max_elem = m_data.front();
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {

			if (max_elem < m_data[i * m_size_y + j])
			{
				max_elem = m_data[i * m_size_y + j];
			}
		}
	}
	return max_elem;
}

template<class PAR>
Sample<PAR>& Sample<PAR>::operator+=(PAR value)
{
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++)
		{

			m_data[i * m_size_y + j] = m_data[i * m_size_y + j] + value;
		}
	}

	return *this;
}

template<class PAR>
Sample<PAR>& Sample<PAR>::operator*=(PAR value)
{
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++)
		{

			m_data[i * m_size_y + j] = m_data[i * m_size_y + j] * value;
		}
	}

	return *this;
}

template <class PAR>
Sample<PAR>& Sample<PAR>::operator/=(PAR value) {
	for (PAR& i : m_data) {
		if (abs(i) < abs(value)) {
			throw std::invalid_argument("Division by zero");
		}
		i /= value;
	}
	return *this;
}

template<class PAR>
Sample<PAR>& Sample<PAR>::operator=(const Sample<PAR>& temp)
{
	if (this != &temp) {
		m_size_x = temp.m_size_x;
		m_size_y = temp.m_size_y;
		m_data = temp.m_data;
	}
	return *this;
}

template<class PAR>
Sample<PAR>& Sample<PAR>::operator+=(const Sample<PAR>& temp)
{
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			m_data[i * m_size_y + j] = m_data[i * m_size_y + j] + temp.m_data[i * m_size_y + j];
		}
	}
	return *this;
}

template<class PAR>
Sample<PAR>& Sample<PAR>::operator-=(const Sample<PAR>& temp)
{
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			m_data[i * m_size_y + j] = m_data[i * m_size_y + j] - temp.m_data[i * m_size_y + j];
		}
	}
	return *this;
}

template<class PAR>
Sample<PAR>& Sample<PAR>::operator*=(const Sample<PAR>& temp)
{
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			m_data[i * m_size_y + j] = m_data[i * m_size_y + j] * temp.m_data[i * m_size_y + j];
		}
	}
	return *this;
}

template<class PAR>
std::ostream& Sample<PAR>::Save(string path)
{
	std::ofstream out_file(path);
	if (!out_file.is_open()) {
		throw std::runtime_error("Something wrong! Cant open write file!");
	}
	else {
		for (int i = 0; i < m_size_x; i++) {
			for (int j = 0; j < m_size_y; j++) {
				out_file << m_data[i * m_size_y + j] << " ";
			}
			out_file << std::endl;
		}
	}
	out_file.close();
}

template<class PAR>
std::istream& Sample<PAR>::Load(string path)
{
	std::ifstream out_file(path);
	std::istream_iterator<double> start(out_file), end;
	std::vector<PAR> numbers(start, end);
	std::cout << "Read" << numbers.size() << " numbers" << std::endl;
	int k = 0;
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			m_data[i * m_size_y + j] = numbers[k];
			k++;
		}
	}
}

template<class PAR>
void Sample<PAR>::CheckSquare() const
{
	if (m_size_x != m_size_y) {
		throw std::runtime_error("Matrix is not square");
	}

}
