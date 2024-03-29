﻿#include <iostream>


class String
{
    char* m_str;
    size_t m_size;


public:


    String(const char* s) {
        //std::cout << "Constr" << std::endl;
        m_size = strlen(s) + 1;
        m_str = new char[m_size];
        std::copy(s, s + m_size, m_str);
    }

    //Конструктор копирования

    String(const String& other) : String(other.m_str)
    {
        //std::cout << "Copy Constr" << std::endl;
    }

    // Оператор присваивания копированием

private:

    void Swap(String& s)
    {
        std::swap(m_str, s.m_str);
        std::swap(m_size, s.m_size);
    }
public:

    String& operator = (String copy)
    {
        //std::cout << "Copy operator" << std::endl;
        Swap(copy);
        return *this;
    }

    //Принт

    void Print() const
    {
        std::cout << m_str << std::endl;
    }

    String() {
        m_size = 0;
        m_str = nullptr;
    }

    //Деструктор

    ~String()
    {
        //std::cout << "Destr" << std::endl;
        delete[] m_str;
    }


    String operator+(const String& other)
    {
        int thislength = strlen(m_str);
        int otherlength = strlen(other.m_str);

        char* newm_str = new char[thislength + otherlength + 1];
        int i = 0;
        for (; i < thislength; i++)
        {
            newm_str[i] = m_str[i];
        }
        for (int j = 0; j < otherlength; j++, i++)
        {
            newm_str[i] = other.m_str[j];
        }
        newm_str[thislength + otherlength] = '\0';
        return newm_str;

    }

    String operator+=(const String& other)
    {
        *this = *this + other;
        return *this;

    }

    bool operator==(const String& other)
    {
        int k = 0;
        if (m_size == other.m_size) {
            for (int i = 0; i < m_size; i++) {
                if (m_str[i] == other.m_str[i]) {
                    k++;
                }
            }
            if (k == m_size) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    bool operator>(const String& other) {
        return strcmp(m_str, other.m_str) > 0;
    }

    bool operator<(const String& other) {
        return strcmp(m_str, other.m_str) < 0;
    }


    char operator[](int n) {
        if ((m_size - 1) > 0) {
            return m_str[n];
        }
        else std::cout << "" << std::endl;
    }
    const char& operator[](int n) const {
        if ((m_size - 1) > 0) {
            return m_str[n];
        }
        else std::cout << "" << std::endl;
    }


    int Lenght()
    {
        return strlen(m_str);
    }

    char* c_str()
    {
        return this->m_str;
    }

    int find(char n) {
        int i = 0;
        for (i; i < m_size; i++) {
            if (m_str[i] == n) {
                return i;
            }
        }
        if (i == m_size) return -1;

    }

    char at(int i) {
        if (i < m_size && i>0) {
            return m_str[i];
        }
        std::cout << "out of range";
        return 0;
    }




    friend std::ostream& operator<<(std::ostream& out, const String& str);
    friend std::istream& operator>>(std::istream& in, String& str);
};

std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.m_str;
    return out;
}
std::istream& operator>>(std::istream& in, String& str)
{
    delete[] str.m_str;
    char* tmp = new char[100];
    in >> tmp;
    str.m_size = strlen(tmp);
    str.m_str = tmp;
    return in;
}





int main()
{
    String s1("abc");
    s1.Print();

    String s2("bca");
    s2 = s1;
    s2.Print();

    String s3;
    s3 = s1 + s2;
    s3.Print();

    String s4("bbb");
    s4 += "dfg";
    s4.Print();

    String s5("");
    String s6("");
    s6 = s1 + s2;
    s5 += s6;

    String s7("");
    std::cin >> s7;
    std::cout << s7;
    std::cout << s3.Lenght() << "   " << "Lenght of s3" << std::endl;
    std::cout << s4.c_str() << "   " << "c_str of s4" << std::endl;
    std::cout << s4.find('g') << "   " << "find 'g' in s4" << std::endl;
    std::cout << s4.at(7) << "   " << "7th index in s4" << std::endl;
    std::cout << s4.at(3) << "   " << "3rd index in s4" << std::endl;
    std::cout << (s1 == s3) << "   " << "s1 equals s3?" << std::endl;
    std::cout << (s1 == s2) << "   " << "s1 equals s2?" << std::endl;
    std::cout << (s4 > s1) << "   " << "s4 more than s1?" << std::endl;
    std::cout << (s4 < s1) << "   " << "s4 less than s1?" << std::endl;
    

    std::cout << s5[1] << std::endl;
    std::cout << s4[1] << std::endl;
    std::cout << s4[5] << std::endl;

    return 0;
}
