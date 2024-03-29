#include "CMemoryPool.cc"
#include "CCriticalSection.cc"
#include <iostream>
#include <unistd.h>


using namespace std;

class CTest{
    public:
        int m_n;
        int m_n1;

    void* operator new(size_t size){
        void* p = s_pool->Alloc(size);
        return p;
    }

    void operator delete(void* p, size_t size){
        s_pool->Free(p);
    }

    static void NewPool(){
        s_pool = new CMTMemoryPool<CMemoryPool<CTest>,CCriticalSection>;
    }

    static void DeletePool(){
        delete s_pool;
        s_pool = nullptr;
    }

    static CMTMemoryPool<CMemoryPool<CTest>,CCriticalSection>* s_pool;
};

CMTMemoryPool<CMemoryPool<CTest>,CCriticalSection>* CTest::s_pool = nullptr;

void testFun(){
    int i;
    const int nLoop = 10;
    const int nCount = 10000;

    for(int j=0; j<nLoop; ++j){
        typedef CTest* LPTest;
        LPTest arData[nCount];
        for(i=0; i<nCount; ++i){
            arData[i] = new CTest;
        }

        for(i=0; i<nCount; ++i){
            delete arData[i];
        }
    }
};

int main(int argc, char** argv){
    {
       // unsigned int dwStartTickCount = GetTickCount();
        CTest::NewPool();
        testFun();
        CTest::DeletePool();
        cout<<"total cost"<<endl;//GetTickCount()-dwStartTickCount<<endl;
    }

    return 0;
}
