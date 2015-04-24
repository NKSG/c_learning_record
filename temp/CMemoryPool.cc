#include <iostream>
template<typename T>
class CMemoryPool{
    public:
        enum{EXPANSION_SIZE = 32};

        CMemoryPool(unsigned int nItemCount = EXPANSION_SIZE){
            ExpandFreeList(nItemCount);
        }

        ~CMemoryPool(){
            CMemoryPool<T>* pNext = nullptr;
            for(pNext = m_pFreeList; pNext!=nullptr; pNext = m_pFreeList){
                m_pFreeList = m_pFreeList->m_pFreeList; 
                delete [](char*)pNext;
            }
        }

        void Alloc(unsigned int /*size*/){
            if(m_pFreeList == nullptr){
                ExpandFreeList();
            }

            CMemoryPool<T>* pHead = m_pFreeList;
            m_pFreeList = m_pFreeList->m_pFreeList;//这到底怎么定义的节点= =
            return pHead;
        }

        void Free(void* p){
            CMemoryPool<T>* pHead = static_cast<CMemoryPool<T>*>(p);
            pHead->m_pFreeList = m_pFreeList;
            m_pFreeList = pHead;
        }

    protected:
        void ExpandFreeList(unsigned nItemCount = EXPANSION_SIZE){
            unsigned int nSize = sizeof(T)>sizeof(CMemoryPool<T>*)?sizeof(T):sizeof(CMemoryPool<T>*);
            CMemoryPool<T>* pLastItem = static_cast<CMemoryPool<T>*>(static_cast<void*>(new char[nSize]));
            m_pFreeList = pLastItem;
            for(int i=0; i<nItemCount-1;++i){
                pLastItem->m_pFreeList = static_cast<CMemoryPool<T>*>(static_cast<void*>(new char[nSize]));
                pLastItem = pLastItem->m_pFreeList;
            }
            pLastItem->m_pFreeList = nullptr;
        }

    private:
        CMemoryPool<T>* m_pFreeList;
};

