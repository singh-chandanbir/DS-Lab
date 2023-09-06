#include <iostream>
using namespace std;
class stack
{

private:
    int top = -1;
    char stk[100];

public:
    void push(char a)
    {
        if (-1 <= top < 100)
        {   top++;
            stk[top]=a;
        }
    }
    void pop(){
        if (-1 < top < 100){
            top--;
        }
    }
};
int main(){
    stack stk;

    char input;
    cin>> input;
    if (input == '(' || ')' || '+'|| '-' || '*' || '/' || '^' || '%'){

    };




    return 0;
}