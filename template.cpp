//
// Created by bright on 2021/6/21.
//
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Node {
public:
    Node() : m_weight(0), m_string("0") {}

    Node(int weight, string name) {
        m_weight = weight;
        m_string = name;
    }

    int operator>(Node &other) {
        if (this->m_weight > other.m_weight) {
            return 1;
        } else {
            return 0;
        }
    }

    string getName() const { return m_string; }

    ~Node() = default;

private:
    int m_weight;
    string m_string;
};

template<typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

template<>
char *Max(char *a, char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

template<>
Node Max(Node n1, Node n2) {
    return n1 > n2 ? n1 : n2;
}

template int Max(int n1, int n2);

int main() {
    cout << Max(1, 2) << endl;
    cout << Max(1.5, 3.5) << endl;
    cout << Max('a', 'b') << endl;
    cout << Max("hello", "world") << endl;

    char *s1 = "hello";
    char *s2 = "world";
    cout << Max(s1, s2) << endl;
    cout << Max(1.00, 2.5) << endl;

    Node n1(2, string("Ming"));
    Node n2(1, string("Li"));

    Node res = Max(n1, n2);
    cout << res.getName() << endl;

    return 0;
}
