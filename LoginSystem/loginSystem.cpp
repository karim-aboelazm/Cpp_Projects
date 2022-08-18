// -------------------------------
// Login System 
// [1] Register
// [2] Save Data
// [3] Login.
// [4] check ------>
// [5] new regesteration
// ---------------------------------
#include <iostream>
#include <string> //---> strings 
#include <windows.h> //---> hidden password
#include <fstream>  //---> save Data
using namespace std;

string HiddenPassword(){
    string p;
    // Console Mode Code ......>
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    // -------------------------
    cout << "Enter Your Password  : "<<endl;
    cin>> p;
    return p;
}
void Register(){
    string username , password;
    system("cls");
    ofstream file ("loginsystem.txt");
    cout<< "----------------------- hint ------------------"<<endl;
    cout<<"Usernames can contain letters (a-z), \
    numbers (0-9), and periods (.).\nUsernames cannot contain an ampersand (&),\
    equals sign (=), underscore (_), apostrophe ('), dash (-), plus sign (+), \
    comma (,), brackets (<,>), or more than one period (.) in a row.\
    \nUsernames can begin or end with \
    non-alphanumeric characters except periods (.). Other than this rule,"<<endl;
    cout<< "-----------------------------------------------"<<endl;
    cout << "Enter Your User Name : "<<endl;
    cin >> username;
    file << username<<endl;
    cout << endl;
    system("cls");
    cout<< "----------------------- hint ------------------"<<endl;
    cout<<"At least 10 characters (and up to 100 characters)\n5 or \
    more unique characters At least 3 of \nthe following: \
    uppercase, lowercase, numeric,\n or special characters. \
     \nThe allowed special characters \nare ~ ! @ # $ % ^ \
     * - _ = + [ { ] } / ; : , . ?  [no spaces allowed!]"<<endl;
    cout<< "-----------------------------------------------"<<endl;
    password=HiddenPassword();
    file << password<<endl;
    file.close();
    cout<<"\n\nYour Account Is Done and You Can Login in to it at any time :) "<<endl;
    system("pause");
    system("cls");
}
void Login(){
    system("cls");
    string userName , Password , un , pw;
    cout<<"\nEnter Username : "<<endl;
    cin >> userName;
    ifstream file("loginsystem.txt");
    getline(file,un);
    if(userName == un){
        Password = HiddenPassword();
        getline(file,pw);
        if(Password == pw){
            cout<<"Login Is Successfully.. :) "<<endl;
        }
        else{
            cout<<"Password is incorrect.. :( "<<endl;
            cout<<"You Can Try 5 Times Only.."<<endl;
            for(int i = 0; i<5;i++){
                Password = HiddenPassword();
                getline(file,pw);
                if(Password == pw){
                    cout<<"Login Is Successfully.. :) "<<endl;
                    break;
                }
                else{
                    cout<<"\nNow You Can Try "<<4-i << " times.."<<endl;
                }
            }
            system("pause");
        }
    }
    else{
        cout<<"Username is incorrect.. :( "<<endl;
        system("pause");
        system("cls");
        Login();
    }
    getline(file,pw);
    file.close();
}
void Display(){
    int choice;
    cout<<"-------[ Welcome To Our Login System ]--------"<<endl;
    cout<<"\n\n| [1] Create New Account.\n| [2] Login.\n| [3] Exit.\n| your choice : ";
    cin>> choice;
    if(choice == 1){
        Register();
    }
    else if(choice == 2){
        Login();
    }
    else if(choice == 3){
       exit(1);
    }
    else{
        cout << choice << " Is not Supported... :("<<endl;
        cout<<"--------------------------------"<<endl;
        Display();
    }

}
int main()
{   
    while(true)
    {
        Display();
        system("cls");
    }
}
