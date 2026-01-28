#include <iostream>     //:الفكرة إستوحيتها من ->  "https://www.youtube.com/@introvert_programmer"  <-
#include <string>

using namespace std;

int main(){
    cout<<"wellcom to SultanOS"<<endl;
    cout<<"if you want help write \"help\""<<endl;
    int x = 0;
    while(x < 1){         //لإبقاء النظام يعمل
        string w;
        cout<<"~> ";cin>>w;
        if(w == "help"){     //لمعرفة الأوامر
            cout<<"info: information for this OS.\n";   
            cout<<"exit: off the PC.\n\n";
        }else if(w == "info"){
            cout<<"SultanOS Virsion 0.1\nThe maker of this OS is Sultan AL-Rashdi.\nThe link of his tube in the youtube:\"https://www.youtube.com/@SultanAL-Rashdi\"\n\n";
        }else if(w == "exit"){
            x = 2;
        }else {
            cout << "Command '" << w << "' not found.\n";
        }
    }
}
