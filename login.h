#ifndef LOGIN_H
#define LOGIN_H


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct User
{
    string username;
    string password;

};
class Login{
    protected:
        int count = 0;
        string  currentuser = "";
        User users[100];
    public:
        Login()
        {
            count = 0;
            currentuser = "";
        };
        void singup()
        {
            string name, password, password2;
            system("cls");

            cout << "Enter your name: ";
            cin >> name;

            cout << "Enter a password: ";
            cin >> password;
            cout << "Repeat your password: ";
            cin >> password2;

            while (password != password2)
            {
                system("cls");
                cout << "Passwords don't match!\n";
                cout << "Enter a password: ";
                cin >> password;
                cout << "Repeat your password: ";
                cin >> password2;
            }

            bool exists = false;
            for (int i = 0; i < count; i++)
            {
                if (users[i].username == name)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "This account already exists!\n";
            }
            else
            {
                users[count].username = name;
                users[count].password = password;
                count++;
                cout << "Sign Up Successfully!\n";
            }
            system("pause");
        };
        void singin()
        {
            system("cls");
            string user, password;
            if (count == 0)
            {
                cout << "No accounts yet. Please sign up first.\n";
                system("pause");
                system("cls");
                return;
            }
            system("cls");
            cout << "Enter your username: ";
            cin >> user;
            cout << "Enter your password: ";
            cin >> password;

            for (int i = 0; i < count; i++)
            {
                if (users[i].username == user && users[i].password == password)
                {
                    cout << "Welcome Back " << user << endl;
                    currentuser = user;
                    return;
                }
            }
            cout << "No account found named: [" << user << "]" << endl;

            system("pause");
            system("cls");
        };
        void logout()
        {
            if (!islogged())
            {
                cout << "you are not logged in" << endl;
            }
            else
            {
                cout << "Goodbye, " << currentuser << "!\n";
                currentuser = "";
            }
            system("pause");
        };
        bool islogged()
        {
            return currentuser != "";
        };
        string currentname()
        {
            return currentuser;
        };

};
#endif  // LOGIN_H
 