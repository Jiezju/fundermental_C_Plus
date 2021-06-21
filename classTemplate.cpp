//
// Created by bright on 2021/6/21.
//
#include <iostream>

using namespace std;

template<class T>
class TC {
public:
    TC(T a, T b, T c);

    T Min();

    T Max();

private:
    T m_a, m_b, m_c;
};

template<class T>
TC<T>::TC(T a, T b, T c) : m_a{a}, m_b{b}, m_c{c} { ; }

template<class T>
T TC<T>::Min() {
    T minab = m_a < m_b ? m_a : m_b;
    return minab < m_c ? minab : m_c;
}

template<class T>
T TC<T>::Max() {
    T maxab = m_a > m_b ? m_a : m_b;
    return maxab > m_c ? maxab : m_c;
}

int main() {
    TC<int> obj1(2, 3, 4);
    cout << obj1.Min() << endl;
    cout << obj1.Max() << endl;

    TC<double> obj2(2.5, 4.4, 3.3);
    cout << obj2.Min() << endl;
    cout << obj2.Max() << endl;

    return 0;
}