#include <iostream>
#include <stack>
using namespace  std;

namespace gtStack
{
class Stack
{
    private:
        int _st[100];
        int _minSt[100];
        unsigned _size;
        int _index;
        unsigned int _count;
    public: 
        Stack();
        ~Stack(){}
        void push(int);
        void pop();
        int top();
        int getMin();
        void printSt();

};
}
gtStack::Stack::Stack()
{
    this->_size = 100;
    this->_count = 0;
    this->_index = -1;
}
void gtStack::Stack::push(int num)
{
    if(_count == _size)
    {
        cout<<"push error: stack full!"<<endl;
        return;
    }
    if(!_count)
    {
        ++_index;
        _st[_index] = num;
        _minSt[_index] = num;
        ++_count;
    }
    else 
    {
        ++_index;
        if(num < _minSt[_index-1] )
        {
            _st[_index] = num;
            _minSt[_index] = num;
        }
        else
        {
            _st[_index] = num;
            _minSt[_index] = _minSt[_index-1];
            
        }
        ++_count;
    }
}
void gtStack::Stack::pop()
{
    if(!_count)
        return;
    _st[_index] = 0;
    _minSt[_index] = 0;
    _index--;
    _count--;
}
int gtStack::Stack::getMin()
{
    return _st[_index];
}
void gtStack::Stack::printSt()
{
    int i = 1;

    cout<<"stack:"<<endl;

    while(i <= _index)
    {
        cout<<_st[i]<<"  ";
        i++;
    }
    cout<<endl;

    i = 1;
    
    cout<<"minStack:"<<endl;
    
    while(i <= _index)
    {
        cout<<_minSt[i]<<"  ";
        i++;
    }

    cout<<endl;
}
int main()
{
    gtStack::Stack st;
    st.push(5);
    st.push(1);
    st.push(6);
    st.push(7);
    st.push(2);
    st.push(0);
    st.printSt();
    st.pop();
    st.printSt();

    return 0;
}
