/*Ejercicio 3. Escribe un programa el cual dictamine el numero de hilos a utilizar para que en general el programa dure un tiempo introducido 
por el usuario. Las únicas duraciones de los hilos deben ser 1,3 y 5 segundos, toma en cuenta que el numero de duración máxima es 60 segundos.*/
#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void foo1()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void foo3()
{
    this_thread::sleep_for(chrono::milliseconds(3000));
}

void foo5()
{
    this_thread::sleep_for(chrono::milliseconds(5000));
}

int main()
{
    bool bol = false;
    int t=0, aux=0;
    do
    {
        cout<<"Ingresa la duración que desea:"<<endl; cin>>t;
        if(t<60)
        {
            bol = true;
        }
    } while (bol==false);
    aux = t;
    if((t/5>=1))
    {
        aux = t/5;
        for(int i=0;i<aux;i++)
        {
            thread h(foo5);
            h.join();
        }
        t-=(t/5)*5;
    }
    if((t/3)>1)
    {
        aux = t/3;
        for(int i=0;i<aux;i++)
        {
            thread h(foo3);
            h.join();
        }
        t-=(t/3)*3;
    }
    if(t>0)
    {
        for(int i=0;i<aux;i++)
        {
            thread h(foo1);
            h.join();
        }
    }
    return 0;
}