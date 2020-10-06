#include <iostream>
#include <thread>

using namespace std;

void foo(int a)
{
    cout<<a<<endl;
}

int main()
{
    thread t(foo,10);

    t.join();

    for(int i=0;i<10;i++)
    {
        cout<<"Hi from master thread"<<endl;
    }
    return 0;
}