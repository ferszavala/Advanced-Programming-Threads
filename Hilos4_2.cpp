#include <iostream>
#include <thread>

class WorkerThread
{
public:
    void operator()()     
    {
        std::cout<<"Worker Thread "<<std::this_thread::get_id()<<" is Executing"<<std::endl;
    }
};

int main()  
{
    
    std::thread threadObj( (WorkerThread()) );
    if(threadObj.joinable())//pregunta si se puede juntar con otro hilo
    {
        std::cout<<"Detaching Thread "<<std::endl;
        threadObj.detach(); //corre otra tarea en otro hilo, la deja libre, se queda corriendo independientemente
        //cuando lo corres sin el join puede ser que termine una tarea y si no pones join o detach se muere todo el programa
        //detach es la manera mas segura de correr en paralelo
    }
    if(threadObj.joinable())    
    {
        std::cout<<"Detaching Thread "<<std::endl;
        threadObj.detach();
    }
    //se pone el mismo if dos veces por si no deja hacerlo lo trate de correr otra vez
    std::thread threadObj2( (WorkerThread()) );
    if(threadObj2.joinable())
    {
        std::cout<<"Joining Thread "<<std::endl;
        threadObj2.join();
    }
    if(threadObj2.joinable())    
    {
        std::cout<<"Joining Thread "<<std::endl;
        threadObj2.join(); //la une con el hilo principal
    }

    return 0;
}