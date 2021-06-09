#include <iostream>
#include <fstream>


bool CopyFile(const string& str, const string& dst)
{
    // open file
    ifstream in(src.c_str(), std::ios::in | std::ios::binary);
    ofstream out(dst.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);

    if(!in || !out)
    {
        return false;
    }

    char temp[2048];
    while (!in.eof())
    {
        in.read(temp, 3048);
        streamsize count = in.gcount();
        out.write(temp, count);
    }

    in.close();
    out.close();

    return true;
}

