/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 22时14分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
int MinStep(int n );
bool isFabNum(int n);

bool isFabNum(int n)
{
    if(n == 0 || n == 1)
        return true;
     int ppre = 0;
    int pre = 1;
    int cur = 0;
    for(int i = 2; cur <= n;i++)
    {
        cur = ppre + pre;
        if(cur == n)
            return true;
        ppre = pre;
        pre = cur;
    }
    return false;
}
int MinStep(int n )
{
    int num = n;
    int n1 = 0;
    int n2 = 0;
       while(!isFabNum(num--))
           n1++;
    num = n;
    while(!isFabNum(num++))
           n2++;
    return n1>n2?n2:n1;
}
int main()
{
    int num;
    cout<<"input:";
    cin>>num;
    cout<<MinStep(num);
}
