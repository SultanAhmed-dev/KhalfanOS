#include <iostream>

using namespace std;

int main(){
    cout<<"Wellcom to KhalfanOS."<<endl;
    cout<<"If you want help write \"help\"."<<endl;
    int x = 1;
    while(x > 0){
        string w;
        cout<<"> ";cin>>w;
        if(w == "help"){
            cout<<"info: informaition of this OS."<<endl;
            cout<<"off : off the PC.\n"<<endl;
        }else if(w == "info"){
            cout<<"KhalfanOS version 0.1\n\n";
        }else if(w == "off"){
            x = 0;
        }else{
            cout<<"Aaam, sory \""<<w<<"\" is not found...\n\n";
        }
    }
}