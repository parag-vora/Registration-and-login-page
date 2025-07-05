#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std; 

class temp{
    private: 
    string _username, _password, _email;
    string _searchUsername, _searchPassword, _searchEmail;
    uint8_t _enterCtr = 1;
    time_t _currentTime = time(NULL);
    fstream file;
    public:
    void loginFun();
    void signupFun();
    void forgotFun();
    void deleteAccountFun();
}obj;

int main(){
    char enterValue;

    cout << "\n1. Login" << endl;
    cout << "\n2. Sign Up" << endl;
    cout << "\n3. Forgot Password" << endl;
    cout << "\n4. exit" << endl;
    cout << "\n5. Delete Account" << endl;
    cout << "Enter your choice.........";
    cin >> enterValue;
    cin.ignore();  

    switch (enterValue)
    {
    case '1':
        obj.loginFun();
        break;
    case '2':
        obj.signupFun();
        break;
    case '3':
        obj.forgotFun();
        break;
    case '4':
        return 0;
        break;  
    case '5':
        obj.deleteAccountFun();
        break;          
    default:
        cout << "Entered a Invalid Input" << endl;
        break;
    }
}

void temp::signupFun(){

    cout << "\nEnter your username: ";
    getline(cin, _username);
    cout << "Enter your Email: ";
    getline(cin, _email);
    cout << "Enter your password: ";
    getline(cin, _password);

    file.open("logindata.txt", ios::out | ios::app);
    file << _username << "*" << _email << "*" << _password << endl;
    file.close();
}

void temp::loginFun(){

    tm *tm_local = localtime(&_currentTime);
    cout << "\n............LOGIN PAGE.........." << endl;
    cout << "\nEnter your username: ";
    getline(cin, _searchUsername);
    cout << "\nEnter your password: ";
    getline(cin, _searchPassword);

    file.open("logindata.txt", ios::in);
    getline(file, _username, '*');
    getline(file, _email, '*');
    getline(file, _password, '\n');

    while(!file.eof()){
        if(_searchUsername == _username){
            if(_searchPassword == _password){
                cout << "Login Sucessfully at" << endl;
                cout << tm_local->tm_mday<< "." << tm_local->tm_mon + 1<< "." << tm_local->tm_year + 1900 << " H: " << tm_local->tm_hour << " M: " << tm_local->tm_min << " S: " << tm_local->tm_sec << endl;
                cout << "your Usernamer is: " << _username << endl;
                cout << "your email is: " << _email << endl;
                cout << "your password is: " << _password << endl;
            } else {
                cout << "you have enterd a wrong data....." << endl;
            }
        }
    getline(file, _username, '*');
    getline(file, _email, '*');
    getline(file, _password, '\n');    
    }
    file.close();
}

void temp::forgotFun(){
    cout << "\nEnter your username: ";
    getline(cin, _searchUsername);
    cout << "\nEnter your Email: ";
    getline(cin, _searchEmail);

    file.open("logindata.txt", ios::in);
    getline(file, _username, '*');
    getline(file, _email, '*');
    getline(file, _password, '\n');

    while(!file.eof()){
            if (_searchUsername == _username && _searchEmail == _email){
                    cout << "\nyour password is: " << _password << endl;
                    break; 
            } else {
                cout << "\nInvalid Input........." << endl;
                    cout << "\nAgain Enter your username: ";
                    getline(cin, _searchUsername);
                    cout << "\n Again Enter your Email: ";
                    getline(cin, _searchEmail);
                    if(_enterCtr++ == 2){
                        cout << "\nYou have enterd 3 times wrong input. Do again" << endl;
                        break;
                    }
            }    
    }
    file.close();
}

void temp::deleteAccountFun(){
    cout << "\nEnter your username to delete your account: ";
    getline(cin, _searchUsername);
    
    fstream tempFile;
    tempFile.open("temp.txt", ios::out | ios::app);
    file.open("logindata.txt", ios::in);

    getline(file, _username, '*');
    getline(file, _email, '*');
    getline(file, _password, '\n');

    while(!file.eof()){
        if(_searchUsername != _username){
            tempFile << _username << "*" << _email << "*" << _password << endl;
        }
        getline(file, _username, '*');
        getline(file, _email, '*');
        getline(file, _password, '\n');    
    }
    
    file.close();
    tempFile.close();
    
    remove("logindata.txt");
    rename("temp.txt", "logindata.txt");
    
    cout << "Account deleted successfully." << endl;
}
