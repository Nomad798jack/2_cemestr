#include<iostream>

template <typename A, int m, int n>
class Matrix
{
private:
    A data[n][m];
public:
    Matrix() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = A();
            }
        }
    }
    Matrix(const Matrix& other) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    Matrix& operator = (const Matrix& other) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }
    Matrix operator + (const Matrix& other) {
        Matrix result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix& operator += (const Matrix& other) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return *this;
    }
    Matrix operator * (const Matrix& other) {
        Matrix result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.data[i][j] = data[i][k] * other.data[k][i];
                }
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }
    Matrix& operator++() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j]++;
            }
        }
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Matrix& matrix) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                out << matrix.data[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    A determinant() const {
        if (m != n) {
            std::cerr << "Error" << std::endl;
        }
        else if (m == 1) return data[0][0];
        else if (m == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        else return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
            data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
            data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
    }

    A& operator() (int i, int j) {
        return data[i][j];
    }

    A Get_el(int i, int j) const {
        if (i < m && j < n) return data[i][j];
    }

    void Set_el(int i, int j, A number) {
        if (i < m && j < n) {
            data[i][j] = number;
        }
        else {
            std::cerr << "Error" << std::endl;
        }
    }
};





int main()
{
    std::cout << "Int matrix 1" << std::endl;
    Matrix<int, 3, 3>M1;
    std::cin >> M1;

    std::cout << "Int matrix 2" << std::endl;
    Matrix<int, 3, 3>M2;
    std::cin >> M2;

    std::cout << "M1 + M2" << std::endl;
    Matrix<int, 3, 3>SUMM = M1 + M2;
    std::cout << SUMM << std::endl;

    std::cout << "M1 * M2" << std::endl;
    Matrix<int, 3, 3>MULTPL = M1*M2;
    std::cout << MULTPL << std::endl;

    std::cout << "M1 ++" << std::endl;
    ++M1;
    std::cout << M1 << std::endl;

    std::cout << "Determinant M1" << std::endl;
    std::cout << M1.determinant() << std::endl;

    std::cout << "El[1][1] of M1" << std::endl;
    std::cout << M1(0, 0) << std::endl;

    M1(1, 2) = 28;
    std::cout << "Changed El[2][3] of M1" << std::endl;
    std::cout << M1(1, 2) << std::endl;

    int EL11 = M1.Get_el(0, 0);
    std::cout << "Number that equal to El[1][1] M1" << std::endl;
    std::cout << EL11 << std::endl;

    M1.Set_el(0, 1, 128);
    std::cout << "Set El[1][2] M1 number 128" << std::endl;
    std::cout << M1 << std::endl;


    return 0;
}