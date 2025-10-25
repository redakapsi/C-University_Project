#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <limits>
#include <cstdlib>
using namespace std;
using namespace chrono;
#include "RacingCar.h"
#include "QuickTypingGame.h"
#include "RSP.h"
#include "GuessingGame.h"
#include "login.h"

class GameHistory
{
public:
    map<string, int> playCount;
    map<string, double> totalTime;

    void recordPlay(const string &game, double seconds)
    {
        playCount[game]++;
        totalTime[game] += seconds;
    }

    void showHistory()
    {
        cout << "\n======= Game History =======\n";
        for (const auto &entry : playCount)
        {
            cout << "Game: " << entry.first
                 << " | Played: " << entry.second
                 << " times | Time: " << totalTime[entry.first] << " seconds\n";
        }
        cout << "============================\n";
    }

};

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    string name,passwod,password2;
    GameHistory history;
    Login Login;
    int choice2;
    bool logged = true;
    bool logout = true;
    while (logout)
    {
    
    
    while (logged)
    {
        system("cls");
    cout<<"                                                             1. Sing up"<<endl<<endl;
    cout<<"                                                             2. Sing in"<<endl<<endl;
   cout <<"                                                             3. Play as Guest" << endl<< endl;
    cout<<"                                                             4. Exit"<<endl<<endl;    
    cout<<"Enter [1], [2], [3], [4]: ";
    cin>>choice2;
   
    
    
    while(choice2!=1&&choice2!=2&&choice2!=3&&choice2!=4)
    {

        system("cls");
        cout<<"Invalid input"<<endl;
        cout << "                                                             1. Sing up" << endl
             << endl;
        cout << "                                                             2. Sing in" << endl
             << endl;
        cout << "                                                             3. Play as Guest" << endl
             << endl;
        cout << "                                                             4. Exit" << endl
             << endl;

        cout << "Enter [1], [2], [3], [4]: ";
        cin >> choice2;
    }
    
    switch (choice2)
    {
        case 1:
        {
            Login.singup();
            break;
        }
        case 2:
        {
            system("cls");
            Login.singin();
            if(Login.islogged())
                logged = false;
            break;
        }
        case 3:
            logged = false;
            break;
             
        case 4:
            return 0;
            break;

    default:
        cout<<"Invalid data"<<endl;
        break;
    }
    
    }







    int choice;
    do
    {
        cout << "\n                                                         ========== Game Menu ==========\n";
        cout << "                                                           1. Racing Car\n";
        cout << "                                                           2. Quick Typing\n";
        cout << "                                                           3. Rock Paper Scissors\n";
        cout << "                                                           4. Guessing Game\n";
        cout << "                                                           5. View Game History\n";
        cout << "                                                           6. Exit\n";
        cout << "                                                           7. Log out"<<endl;
        cout << "                                                           ===============================\n";
        cout <<"                                                            Enter your choice: ";
        cin >> choice;
        clearInput();

        auto start = high_resolution_clock::now();

        switch (choice)
        {
        case 1:
        {
            RacingCar game;
            game.play();
            history.recordPlay("Racing Car", duration_cast<seconds>(high_resolution_clock::now() - start).count());
            break;
        }
        case 2:
        {
            QuickTypingGame game;
            game.play();
            history.recordPlay("Quick Typing", duration_cast<seconds>(high_resolution_clock::now() - start).count());
            break;
        }
        case 3:
        {
            RSP game;
            game.play();
            
            history.recordPlay("Rock Paper Scissors", duration_cast<seconds>(high_resolution_clock::now() - start).count());
            break;
        }
        case 4:
        {
            geussinggame game;
            game.play();
            history.recordPlay("Guessing Game", duration_cast<seconds>(high_resolution_clock::now() - start).count());
            break;
        }
        case 5:
            history.showHistory();
            break;
        case 6:
        {
            cout << "Goodbye, " << name << "! See you next time.\n";
            logout = false;
            break;
        }
        case 7:
        {
            Login.logout();
            logged = true;
            break;
        }
        default:
            system("cls");
            cout << "Invalid choice. Try again.\n";
        }

    } while (!logged);
    }
    return 0;
}
