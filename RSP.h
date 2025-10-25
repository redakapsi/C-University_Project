#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class RSP
{
public:
    void play()
    {
        int scorep = 0;
        int scorec = 0;
        string Pchoice;
        int computer;

        cout << "=============================================================\n";
        cout << "               ROCK  |  PAPER  |  SCISSORS\n";
        cout << "=============================================================\n";
        cout << "Welcome to the Rock, Paper, and Scissors game!\n";
        cout << "You'll play against the computer.\n";
        cout << "=============================================================\n";

        srand(time(0));

        do
        {
            system("cls"); 

            cout << "\n-------------------------------------------------------------\n";
            cout << "                      NEW ROUND\n";
            cout << "-------------------------------------------------------------\n";

            computer = rand() % 3;
            string Cmove = (computer == 0) ? "paper" : (computer == 1) ? "rock"
                                                                       : "scissors";

            while (true)
            {
                cout << "\nEnter your choice (paper, rock, scissors), or type (exit): ";
                cin >> Pchoice;

                for (char &c : Pchoice)
                    c = tolower(c);

                if (Pchoice == "rock" || Pchoice == "paper" || Pchoice == "scissors" || Pchoice == "exit")
                    break;
                else
                    cout << "\n[!] Invalid input! Try again.\n";
            }

            if (Pchoice == "exit")
                break;

            cout << "\n---------------------------------------------\n";
            cout << "Computer's choice: [ " << Cmove << " ]\n";
            cout << "---------------------------------------------\n";

            if (Cmove == Pchoice)
            {
                cout << "Result: It's a tie!\n";
            }
            else if (Pchoice == "rock" && Cmove == "scissors" ||
                     Pchoice == "scissors" && Cmove == "paper" ||
                     Pchoice == "paper" && Cmove == "rock")
            {
                cout << "Result: You win this round!\n";
                scorep++;
            }
            else
            {
                cout << "Result: You lose this round.\n";
                scorec++;
            }

            cout << "\n---------------- CURRENT SCORE ----------------\n";
            cout << "Computer: " << scorec << "   |   You: " << scorep << endl;
            cout << "----------------------------------------------\n";

            cout << "\nPress Enter to continue to the next round...";
            cin.ignore(); 
            cin.get();    

        } while (Pchoice != "exit");

        system("cls");

        cout << "\n=============================================================\n";
        cout << "                       FINAL RESULT\n";
        cout << "=============================================================\n";
        cout << "Computer's score: " << scorec << endl;
        cout << "Your score:       " << scorep << endl;
        cout << "-------------------------------------------------------------\n";

        if (scorec > scorep)
            cout << "The computer has beaten you! Be strong!\n";
        else if (scorec < scorep)
            cout << "You've beaten the computer! Be proud, you're strong!\n";
        else
            cout << "It's a tie! You survived, be careful next game!\n";

        cout << "\nYou've exited the RPS game. We had a nice time together!\n";
        cout << "Hope we can play again soon.\n";
        cout << "=============================================================\n";
    }
};
