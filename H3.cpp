#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

#define N_THREADS 5

void print(int n,const string &str){
string msg = to_string(n)+":"+str;
cout<<msg<<endl;
this_thread::sleep_for(chrono::milliseconds(1000));

}

int main(){

string s[5]={
"IIA",
"IB",
"IM",
"II",
"ITE"};

thread threads[N_THREADS];

for(int i =0;i<N_THREADS;i++){
threads[i]=thread(print,i,s[i]);
threads[i].join();
}

cout<<"Hi from main"<<endl;
return 0;
}