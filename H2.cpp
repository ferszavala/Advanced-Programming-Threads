#include <iostream>
#include <thread>

using namespace std;

//Pointer function
void foo(int z)
{
    for(int i=0;i<z;i++)
    {
        cout<<"Thread using pointer function";
    }
}

//Callable object
class thread_object
{
    public:
        void operator()(int x)
        {
            for(int i=0;i<x;i++)
            {
                cout<<"Thread using function from callable object"<<endl;
            }
        }
};

int main()
{
    thread th1(foo, 5);
    thread th2(thread_object(),5);

    th1.join();
    th2.join();
    
    return 0;
}