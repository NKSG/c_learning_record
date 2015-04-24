CMyString& CMyString::operator = (const CMyString& str){
    if(this==&str)
        return *this;
    //这什么鬼
    delete [] m_pData;
    //在删掉之后，如果接下来new不出来出错之后，就会修改了原本的CMyString
    m_pData = nullptr;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
    return *this;
}

//改进
//先创建，再更改(删/换->删)
CMyString& CMyString::operator = (const CMyString& str){
    if(this!=&str){
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
//代码异常的安全性分析
//调用函数结束会释放strTemp.m_pData指向的内存，所以这方法真的很妙
