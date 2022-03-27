#pragma once
class Number
{
    char* vector;
    int base;
    int vector_size;
    long long unsigned decimal;

    void calculateDecimal();
    static char* processingVector(unsigned new_decimal, unsigned new_base);

  public:
    Number(const char* value, int base=10);
    Number(long long unsigned value); 
    Number(const Number& obj);
    Number(Number &&obj);
    ~Number();

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const; 
    int GetBase() const; 

    friend Number operator+(const Number& lfs, const Number& rhs);
    friend Number operator-(const Number& lfs, const Number& rhs);

    Number& operator--();
    Number& operator--(int);

    char operator[](int index) const;

    bool operator>(const Number& obj) const;
    bool operator>=(const Number& obj) const;
    bool operator<(const Number& obj) const;
    bool operator<=(const Number& obj) const;
    bool operator==(const Number& obj) const;
    bool operator!=(const Number& obj) const;

    void operator=(const Number& obj);
    void operator=(long long unsigned value);
    void operator=(const char * value);
};