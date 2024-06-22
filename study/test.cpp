#include <string>
#include <iostream>
#include <utility>

class TestClassA 
{
public:
    TestClassA(int iSize):m_iSize(iSize)
    {
         m_pkData = new char[m_iSize];
    }
    
    void func() {
        
        std::cout << "hello world" << std::endl;
        std::cout<< m_iSize << std::endl;
    }

    ~TestClassA()
    {
        if(m_pkData)
        {
            delete []m_pkData;
            m_pkData = nullptr;
        }
    }
    int m_iSize;
    char* m_pkData;
};


int main() {
  TestClassA a1(999);
  TestClassA a2(a1);

//   TestClassA *a = nullptr;
//   a->func();
}