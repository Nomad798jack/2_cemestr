#include <iostream>

class BigInt {
private:
    char mas[1000];
    int size;
public:

    BigInt() : size(0) {
        for (int i = 0; i < 1000; i++)
            mas[i] = '0';
    }

    BigInt(const BigInt& other) : size(other.size) {
        for (int i = 0; i < 1000; i++)
            mas[i] = other.mas[i];
    }

    BigInt operator = (const BigInt& other) {
        if (this != &other) {
            size = other.size;
            for (int i = 0; i < 1000; i++)
                mas[i] = other.mas[i];
        }
        return *this;
    }

    BigInt operator + (const BigInt& other) {
        BigInt result;
        int remainder = 0;
        int maxlen = std::max(size, other.size);
        for (int i = 0; i < maxlen || remainder; i++) {
            int this_number = i < size ? mas[i] - '0' : 0;
            int other_number = i < other.size ? other.mas[i] - '0' : 0;
            int current = this_number + other_number + remainder;
            result.mas[result.size++] = '0' + (current % 10);
            remainder = current / 10;
        }
        return result;
    }

    BigInt operator += (const BigInt& other) {
        *this = *this + other;
        return *this;
    }

    BigInt operator * (const BigInt& other) {
        BigInt result;
        BigInt tmp;
        int remainder = 0;
        for (int i = 0; i < size; i++) {
            tmp.size = 0;
            for (int j = 0; j < i; j++)
                tmp.mas[tmp.size++] = '0';
            for (int j = 0; j < other.size || remainder; j++) {
                int this_number = mas[i] - '0';
                int other_number = j < other.size ? other.mas[j] - '0' : 0;
                int current = this_number * other_number + remainder;
                tmp.mas[tmp.size++] = '0' + (current % 10);
                remainder = current / 10;
            }
            result += tmp;
        }
        return result;
    }

    BigInt& operator *= (const BigInt& other) {
        *this = *this * other;
        return *this;
    }
    
    bool operator < (const BigInt& other) {
        if (size != other.size)
            return size < other.size;
        for (int i = size - 1; i >= 0; i--) {
            if (mas[i] != other.mas[i])
                return mas[i] < other.mas[i];
        }
        return false;
    }

    bool operator > (const BigInt& other) {
        if (size != other.size)
            return size > other.size;
        for (int i = size - 1; i >= 0; i--) {
            if (mas[i] != other.mas[i])
                return mas[i] > other.mas[i];
        }
        return false;
    }

    bool operator == (const BigInt& other) {
        if (!(*this < other || *this > other))
            return true;
    }
    
    bool operator != (const BigInt& other) {
        if (*this < other || *this > other)
            return true;
    }

    friend std::istream& operator >> (std::istream& in, BigInt& In){
        std::string input;
        in >> input;
        In.size = input.size();
        for (int i = 0; i < In.size; i++)
            In.mas[i] = input[In.size - i - 1];
        return in;
    }

    friend std::ostream& operator << (std::ostream& out, const BigInt& Out) {
        if (Out.size == 0) out << "0";
        else {
            for (int i = Out.size - 1; i >= 0; i--) out << Out.mas[i];
        }
        return out;
    }
};

int main()
{
    BigInt bigint1;
    std::cout << "Cin bigint 1" << std::endl;
    std::cin >> bigint1;
    
    BigInt bigint2;
    std::cout << "Cin bigint 2" << std::endl;
    std::cin >> bigint2;

    BigInt copy(bigint1);
    std::cout << "bigint copy" << std::endl;
    std::cout << copy << std::endl;

    BigInt sum;
    sum = bigint1 + bigint2;
    std::cout << '+' << std::endl;
    std::cout << sum << std::endl;

    BigInt Sum;
    std::cout << "cin for +=" << std::endl;
    std::cin >> Sum;
    Sum += bigint1;
    std::cout << Sum << std::endl;

    BigInt product;
    product = bigint1 * bigint2;
    std::cout << '*' << std::endl;
    std::cout << product << std::endl;

    BigInt Product;
    std::cout << "cin for *=" << std::endl;
    std::cin >> Product;
    Product *= bigint1;
    std::cout << "Product *= bigint1" << std::endl;
    std::cout << Product << std::endl;

    std::cout << "bigint1 < bigint2: " << (bigint1 < bigint2) << std::endl;
    std::cout << "bigint1 > bigint2: " << (bigint1 > bigint2) << std::endl;
    std::cout << "bigint1 == bigint1: " << (bigint1 == bigint1) << std::endl;
    std::cout << "bigint1 != bigint2: " << (bigint1 != bigint2) << std::endl;
}
