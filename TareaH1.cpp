/* Ejercicio 1. Escriba un programa que corra 2 hilos simultáneamente de 2 funciones de ordenamiento 1 deberá de ser burbuja y otro deberá de 
ser Mezclas y al terminar cada hilo imprimirá el arreglo ordenado respectivamente.*/
#include <iostream>
#include <thread>

using namespace std;
void burbuja(int array[], int n)
{
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n-1;j++)
         {
            if(array[j]>array[j+1])
            {
               int aux = array[j];
                array[j] =array[j+1];
                array[j+1]=aux;
            }
         }  
      }
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void merge(int *izq,int nIzq,int *der,int nDer,int *a)
{    
    int i=0,j=0,k=0;
    while( ( i < nIzq ) && ( j < nDer ) ){
        if( izq[i] <= der[j]){
            a[k] = izq[i];
            i++;
        }
        else{
            a[k] = der[j];
            j++;
        }
        k++;
    }
    while(i < nIzq){
        a[k] = izq[i];
        i++;k++;
    }
    while(j < nDer){
        a[k] = der[j];
        j++;k++;
    }
}

void mergesort(int *a,int n){
    if(n==1){
        return;
    }
    int mitad = n / 2;
    int *izq = new int[mitad];
    int *der = new int[n-mitad];
    for(int i=0;i<mitad;i++){
        izq[i] = a[i];
    }
    for(int i=mitad;i<n;i++){
        der[i-mitad] = a[i];
    }
    mergesort(izq, mitad);
    mergesort(der, n-mitad);
    merge(izq, mitad, der, n-mitad, a);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n=0;
    cout<<"Ingrese la longitud del arreglo: "; cin>>n;
    cout<<"Ingrese los datos: "<<endl;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%100;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    thread t1(burbuja,&arr[0],n);
    thread t2(mergesort,&arr[0],n);
    t1.join();
    t2.join();
    return 0;
}