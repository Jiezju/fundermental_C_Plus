//
// Created by bright on 2021/6/15.
//

#include "String.h"

String::String(const char *str)
{
    if (str== nullptr)
    {
        m_data = new char[1];
        if (m_data != nullptr)
        {
            *m_data = '\0';
        }
        else
        {
            exit(-1);
        }
    }
    else
    {
        int len = strlen(str);
        m_data = new char[len+1];
        if (m_data != nullptr)
        {
            strcpy(m_data, str);
        }
        else
        {
            exit(-1);
        }
    }
}

String::String(const String &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    if (m_data != nullptr)
    {
        strcpy(m_data, other.m_data);
    }
    else
    {
        exit(-1);
    }
}

String::~String()
{
    if (m_data != nullptr)
    {
        delete []  m_data;
    }
}

String& String::operator=(const String &other) {
    if (this == &other)
    {
        return *this;
    }

    delete [] m_data;
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    if (m_data != nullptr)
    {
        strcpy(m_data, other.m_data);
    }
    else
    {
        exit(-1);
    }
    return *this;
}

String::String(String&& other) {
    if (other.m_data != nullptr)
    {
        m_data = other.m_data;
        other.m_data = nullptr;
    }
}

String& String::operator=(String&& other) noexcept
{
    if (this != &other)
    {
        delete [] m_data;
        m_data = other.m_data;
        other.m_data = nullptr;
    }
    return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
    os<<s.m_data;
    return os;
}

int main()
{
    String s1("Hello");                    // 构造函数
    cout << s1 << endl;
    //String s2 = s1;                     // 调用拷贝构造函数
    String s2(s1);                       // 调用拷贝构造函数
    cout << s2 << endl;
    String s2A(std::move(s1));          // 移动构造函数
    cout << s2A << endl;
    String s3;                         // 无参构造函数
    cout << s3 << endl;
    s3 = s2;                          // 调用赋值函数
    cout << s3 << endl;
    String s3A;                      // 无参构造函数
    s3A = std::move(s2A);           // 移动赋值运算符
    cout << s3A << endl;

    return 0;
}
