//
// Created by bright on 2021/6/15.
//

#ifndef C___STRING_H
#define C___STRING_H
#include <iostream>
#include <string.h>


class String {
public:
    String(const char* str = nullptr);
    String(const String& other);
    ~String();
    String& operator=(const String& other);

    // move
    String(String&& other);
    String& operator=(String&& other) noexcept;

    friend ostream& operator<<(ostream& os, const String& c);

private:
    char* m_data;
};


#endif //C___STRING_H
