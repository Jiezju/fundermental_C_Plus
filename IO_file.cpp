#include <iostream>
#include <fstream>
#include <string>


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

bool DumpArray(const string& src, const string& dst)
{
    ifstream in(src.c_str(), std::ios::in);
    ofstream out(dst.c_str(), std::ios::out);

    if (!in || !out)
    {
        return false;
    }

    int iArray[25][2] = {0};
    string strArray[25][4];

    // Read
    for (unsigned int i = 0; i<25; ++i)
    {
        for (unsigned int j = 0; j<2; ++j)
        {
            in>>iArray[i][j];
        }
    }

    for (unsigned int i = 25; i<50; ++i)
    {
        for (unsigned int j = 0; j<4; ++j)
        {
            in>>strArray[i-25][j];
        }
    }

    // write
    for (unsigned int i = 0; i<25; ++i)
    {
        out<<iArray[i][0]<<"\t"<<iArray[i][1]<<"\t"<<strArray[0]<<"\t"<<strArray[1]<<"\t"<<strArray[2]<<"\t"<<strArray[3]<<endl;
    }

    in.close();
    out.close();

    return true;
}

