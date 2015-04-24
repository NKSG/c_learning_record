#include <iostream>
#include <cstring>

class CMyString{
    public:
        CMyString(char *pData = nullptr);
        CMyString(const CMyString& str);
        ~CMyString(void);
        CMyString& operator= (const CMyString& str);

    private:
        char *m_pData;
};

CMyString::CMyString(char *pData):m_pData(nullptr){
    if(pData != nullptr){
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData,pData);
    }
}

CMyString::CMyString(const CMyString &str):m_pData(nullptr){
    if(str.m_pData != nullptr){
        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(m_pData,str.m_pData);
    }
}

CMyString& CMyString::operator=(const CMyString& str){
    if(this!=&str){
        CMyString strTemp(str);
        char *temp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = temp;
    }
    return *this;
}



CMyString::~CMyString(void){
    if(m_pData != nullptr){
        delete[] m_pData;
        m_pData = nullptr;
    }
}

int main(int argc, char *argv[]){
    CMyString str1("hello, world.");
    CMyString str = "I'm hy.";
    str1=str2;
    return 0;
}
