//
// Created by bright on 2021/6/22.
//
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include<algorithm>

using namespace std;

template<typename T>
void Display(T a)
{
    cout<<a<<" ";
}

template<>
void Display(pair<string, double> info)
{
    cout<<info.first << " " <<info.second<<" ";
}


int main()
{
    int iArr[] = {1,2,3,4,5};
    vector<int> iVec(iArr, iArr+5);
    list<int> iList(iArr, iArr+5);
    deque<int> iDeq(iArr, iArr+5);
    stack<int> iStack(iDeq);
    queue<int> iQue(iDeq);
    priority_queue<int> iPrio(iArr, iArr+5);

    for_each(iVec.begin(), iVec.end(), Display<int>);
    cout << endl;
    for_each(iList.begin(), iList.end(), Display<int>);
    cout << endl;
    for_each(iDeq.begin(), iDeq.end(), Display<int>);
    cout << endl;

    while (!iQue.empty())
    {
        cout<<iQue.front()<<" ";
        iQue.pop();
    }

    while (!iStack.empty())
    {
        cout << iStack.top() << " ";    // 4 3  2  1
        iStack.pop();
    }
    cout << endl;

    while (!iPrio.empty())
    {
        cout << iPrio.top() << " "; // 4 3 2 1
        iPrio.pop();
    }
    cout << endl;

    map<string, double> studentScores;
    studentScores["LiMing"] = 95.0;
    studentScores.insert(make_pair("WangWu", 94.5));
    studentScores.insert(pair<string, double>("LiLei", 92.3));
    for_each(studentScores.begin(), studentScores.end(), Display<pair<string,double>>);


    return 0;
}