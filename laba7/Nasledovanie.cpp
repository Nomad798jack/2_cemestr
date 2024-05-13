#include <iostream>
#include <fstream>
#include <memory>
#include <filesystem>
// N < 256, a_i < 256 для всех i=1..N
// .txt - массив данных в формате  N и a_i, где i = 1..N (ASCII)
// .bin - массив данных в формате  N и a_i, где i = 1..N (bin)

class DataReader
{
protected:
    std::ifstream m_in;
    std::string m_filename;
    uint8_t* m_data;
    uint8_t m_n;

public:
    DataReader(const std::string& filename) :
        m_filename(filename), m_n(0), m_data(nullptr) {}
    virtual ~DataReader() {}
    virtual bool Open() = 0;
    void Close() {
        m_in.close();
    }
    virtual void Read() = 0;
    virtual void Write() = 0;
    virtual void GetData(uint8_t* buf, uint8_t& n) = 0;
};

class TxtReader : public DataReader
{
public:
    TxtReader(const std::string& filename) : DataReader(filename) {}

    virtual ~TxtReader() {
        if (m_data != nullptr)
            delete[] m_data;
    }
    bool Open() override {
        m_in.open(m_filename);
        if (m_in.is_open())
            return false;
        return true;
    }

    void Read() override {
        int tmp;
        m_in >> tmp;
        m_n = tmp;
        m_in >> m_n;
        m_data = new uint8_t[m_n];
        for (int i = 0; i < m_n; i++)
        {
            int tmp;
            m_in >> tmp;
            m_data[i] = tmp;
        }
    }

    void Write() override {

    }
    void GetData(uint8_t* buf, uint8_t& n) override {}
};

class BinReader : public DataReader
{
public:
    BinReader(const std::string& filename) : DataReader(filename) {}

    virtual ~BinReader() {
        if (m_data != nullptr)
            delete[] m_data;
    }
    bool Open() override {
        m_in.open(m_filename, std::ios::binary);
        if (!m_in.is_open())
            return false;
        return true;
    }

    void Read() override {
        m_in.read((char*)&m_n, 1);
        m_data = new uint8_t[m_n];
        m_in.read((char*)m_data, m_n);
    }

    void Write() override {

    }
    void GetData(uint8_t* buf, uint8_t& n) override {}
};
class BinFReader : public DataReader
{
public:
    BinFReader(const std::string& filename) : DataReader(filename) {}

    virtual ~BinFReader() {
        if (m_data != nullptr)
            delete[] m_data;
    }
    bool Open() override {
        m_in.open(m_filename, std::ios::binary);
        if (!m_in.is_open())
            return false;
        return true;
    }
    void Read() override {
        uint8_t numFloats;
        m_in.read(reinterpret_cast<char*>(&numFloats), sizeof(uint8_t));
        m_n = numFloats;
        m_data = new uint8_t[m_n*sizeof(float)];
        m_in.read(reinterpret_cast<char*>(m_data), m_n*sizeof(float));
    }
    void Write() {}
    void GetData(uint8_t* buf, uint8_t& n) override {
        std::cout << int(m_n) << std::endl;
        for (size_t i = 0; i < m_n * 4; i += 4) {
            std::cout << *(float*)(m_data + i) << std::endl;
        }
    }
};

void CreateBin() {
    std::ofstream out("input2.bin", std::ios::binary);
    uint8_t buf[6];
    buf[0] = 5;
    for (int i = 0; i < 5; i++) {
        buf[i + 1] == i + 127;
    }
    out.write((char*)buf, 6);
}
void CreateBinF() {
    std::ofstream out("input3.binf", std::ios::binary);
    float buf[4] = { 3.018f,8.0f,8.905f,7.16f };
    uint8_t size = 4;
    out.write(reinterpret_cast<char*>(&size), sizeof(uint8_t));
    out.write(reinterpret_cast<char*>(buf), sizeof(buf));
}

std::unique_ptr<DataReader> Factory(const std::string& filename)
{
    std::string extension = filename.substr(filename.find_last_of('.') + 1);
    if (extension == "txt")
        return std::make_unique<TxtReader>(filename);
    else if (extension == "bin")
        return std::make_unique<BinReader>(filename);
    else if (extension == "binf")
        return std::make_unique<BinFReader>(filename);
    return nullptr;
}

int main()
{
    CreateBinF();
    uint8_t n;
    uint8_t buf[100];
    std::unique_ptr<DataReader> Reader = Factory("input3.binf");
    if (Reader == nullptr)
        return -1;
    Reader->Open();
    Reader->Read();
    Reader->GetData(buf,n);
 }

