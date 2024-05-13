#include <iostream>


class Matrix {
private:
	int m_n;
	int n_n;
	int** data;

public:

	Matrix(int m, int n) { 
		m_n = m;
		n_n = n;
		data = new int* [m_n];
		for (int i = 0; i < m; i++)
			data[i] = new int[n_n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				data[i][j] = rand() % 9 + 1;
		}
	}

	~Matrix() {
		for (int i = 0; i < m_n; i++)
			delete[] data[i];
		delete data;
	}

	Matrix(const Matrix& other) : m_n(other.m_n), n_n(other.n_n){
		data = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			data[i] = new int[n_n];
		for (int i = 0; i < m_n; i++) {
			for (int j = 0; j < n_n; j++)
				data[i][j] = other.data[i][j];
		}
	}

	Matrix & operator = (const Matrix& other) {
		if (this != &other) {
			for (int i = 0; i < m_n; i++)
				delete[] data[i];
		}
		delete[] data;

		m_n = other.m_n;
		n_n = other.n_n;
		data = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			data[i] = new int[n_n];

		for (int i = 0; i < m_n; i++) {
			for (int j = 0; j < n_n; j++)
				data[i][j] = other.data[i][j];	
		}
		return *this;
	}

	void Print() const {
		for (int i = 0; i < m_n; i++) {
			for (int j = 0; j < n_n; j++) {
				std::cout << data[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main()
{
	Matrix M(5, 5);
	M.Print();

	std::cout << ' ' << std::endl;

	Matrix N = M;
	N.Print();

	std::cout << ' ' << std::endl;

	Matrix B(3, 3);
	B.Print();
}

