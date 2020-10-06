/*Crea un programa que corra 2 hilos paralelos de la misma función la cual recibe como parámetro un entero positivo menor a 100 generado 
aleatoriamente e itere n veces el parámetro de entrada y al terminar escriba el parámetro de entrada.*/
#include <iostream>
#include <thread>

using namespace std;
void foo1(int n)
{
      for(int i=0;i<n;i++)
      {

      }
      cout<<n<<endl;
}

int main()
{
    int a=0, b=0;
    a = 1+rand()%99;
    b = 1+rand()%99;

    thread t1(foo1, a);
    thread t2(foo1, b);
    t1.join();
    t2.join();
    return 0;
}