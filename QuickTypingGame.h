#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
using namespace std::chrono;

class QuickTypingGame
{
private:
    string player;
    string computer[20] =
        {
            "car", "play", "cow", "reda",
            "software", "kapsi", "gym", "apple",
            "nine", "cat", "dog", "pc",
            "organization", "lemon", "money", "sunny",
            "background", "beautiful", "emoji", "forrest"};

    int randomIndex()
    {
        return rand() % 20;
    }

public:
    void play()
    {
        srand(time(0));
        int attempts;
        int score = 0;

        cout << "Choose number of attempts (3, 5, 10, 20): ";
        cin >> attempts;

        // Validate input
        while (attempts != 3 && attempts != 5 && attempts != 10 && attempts != 20)
        {
            cout << "Invalid choice. Please enter 3, 5, 10, or 20: ";
            cin >> attempts;
        }

        cin.ignore();

        system("cls");
        cout << "                                                   =========================================" << endl;
        cout << "                                                     Type as fast and accurate as you can!" << endl;
        cout << "                                                   =========================================" << endl;

        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "                                                                    Get ready.." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        for (int i = 3; i >= 1; i--)
        {
            system("cls");
            cout <<"                                                                      "<<i<< endl
                 << "                                                                        _" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }

        auto start_time = steady_clock::now();

        for (int i = 1; i <= attempts; i++)
        {
            system("cls");
            int index = randomIndex();
            cout<< "                                                         Word " << i << " of " << attempts << ":" << endl;
            cout<<"                                                          ============================"<<endl<<endl;
            cout<<"                                                          "<<computer[index] << endl;
            cout<<"                                                          ============================" << endl
                 << endl;

            cout << "                                                        Type it here: ";
            getline(cin, player);

            if (player == computer[index])
            {
                cout << "                                                                    Correct!" << endl;
                score++;
            }
            else
            {
                cout << "                                                            Wrong! The correct word was: " << computer[index] << endl;
            }

            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        auto end_time = steady_clock::now();

        auto duration_ms = duration_cast<milliseconds>(end_time - start_time).count();
        double duration_sec = duration_ms / 1000.0;

        system("cls");
        cout << "                                                                     Game Over!" << endl;
        cout << "                                                           Your score: " << score << " out of " << attempts << endl;
        cout << "                                                           Total time: " << duration_sec << " seconds" << endl;
    }
};

