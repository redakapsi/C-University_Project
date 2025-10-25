    #include <iostream>
    #include <string>
    #include <ctime>
    #include <cstdlib>
    #include <chrono>
    #include <thread>
    using namespace std;

    class RacingCar
    {
    private:
        int playerp;
        int computerp;
        const int finishline = 80;
        string car[3] = {
            "   ____",
            "_/ - -  \\__",
            "-0---0----))))->"};

    public:
        RacingCar() : playerp(0), computerp(0) {}
        void gamemode()

        {   system("cls");

                 int d;
                 system("cls"); // clear screen

                 cout << "\n\n";
                 cout << "                                                ==========================================\n";
                 cout << "                                                ||        WELCOME TO RACING GAME        ||\n";
                 cout << "                                                ==========================================\n";
                 cout << "                                                       ---------- 80m RACE ----------\n";
                 cout << "\n";
                 cout << "                                                ------------------------------------------\n";
                 cout << "                                                 Choose difficulty level [1, 2, or 3]:\n";
                 cout << "                                                ------------------------------------------\n\n";

                 cout << "                                                          1. HARD MODE\n\n";
                 cout << "                                                          2. MEDIUM MODE\n\n";
                 cout << "                                                          3. EASY MODE\n\n";
                 cout << "                                                Type your choice here => ";cin>>d;

                 if (d == 1)
                     computerp += rand() % 3 + 1;
                 else if (d == 2)
                     computerp += rand() % 1 + 1;
                 else
                     computerp = 0;
        }

        void play()
        {
            srand(time(0));

            gamemode();
            while (playerp < finishline && computerp < finishline)
            {
                
                system("cls"); 

                
                cout << "Player:\n--------\n";
                for (int i = 0; i < 3; i++)
                    cout << string(playerp, ' ') << car[i] << endl;
                
                cout << "                                                                               |final" << endl;
                cout << "                                                                               |final" << endl;
                cout << "                                                                               |final" << endl;
                cout << "                                                                               |final" << endl;
                cout << "                                                                               |final" << endl;
                cout << "                                                                               |final" << endl;
                cout << "Computer:\n----------\n";
                for (int i = 0; i < 3; i++)
                    cout << string(computerp, ' ') << car[i] << endl;

                cout << "\nPress Enter to accelerate...";
                cin.ignore();

                
                int pstep = rand() % 4 + 1;
                int cstep = rand() % 4 + 1;
                playerp += pstep;
                computerp += cstep;

                if (playerp > finishline)
                    playerp = finishline;
                if (computerp > finishline)
                    computerp = finishline;
            }

            
            system("cls");
            cout << "=============\nFinal Result:\n=============\n";
            if (playerp >= finishline && computerp >= finishline)
                cout << "It's a tie!\n";
            else if (playerp >= finishline)
                cout << "You won the race!\n";
            else
                cout << "The computer won the race!\n";
        }
    };

    // int main()
    // {
    //     srand(time(0)); 
    //     char choice;

    //     do
    //     {
    //         RacingCar game;
    //         game.play();

    //         cout << "\nDo you want to play again? (y/anything[exit]): ";
    //         cin >> choice;
    //         cin.ignore(); 
    //     } while (choice == 'y' || choice == 'Y');

    //     cout << "You have exited the racing game!\n";
    //     return 0;
    // }
