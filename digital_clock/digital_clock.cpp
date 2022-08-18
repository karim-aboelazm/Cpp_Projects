#include <iostream>
#include <windows.h>
using namespace std;
int main(){
    int hour,minute,second,error,ancor;
    error = ancor = 0;
    while(error == 0){
        cout<<"Enter Hours : "<<endl;cin>>hour;
        cout<<"Enter minutes : "<<endl;cin>>minute;
        cout<<"Enter seconds : "<<endl;cin>>second;
        if(hour<24 && minute<60 && second<60)
            error++;
        else
            system("cls");
    }
    while(ancor == 0){
        system("cls");
        cout<<"\n\n\n\n\t\t            < Digital Clock >          "<<endl;
        cout<<"\t\t|---------------------------------------|"<<endl;
        cout<<"\t\t"<<"|\t\t"<<hour << ":" << minute << ":" << second<< "\t\t|"<<endl;
        cout<<"\t\t|---------------------------------------|"<<endl;
        Sleep(1000);
        second++;
        if(second > 59){
            second=0;
            minute++;
        }
        if(minute > 59){
            minute=0;
            hour++;
        }
        if(hour > 24){
            hour=0;
        }
    }
    return 0;
}