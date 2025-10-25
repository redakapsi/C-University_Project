#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class geussinggame
{
private:
    int number;
    int attemps;

public:
    geussinggame()
    {
        srand(time(0));
        number = rand() % 15 + 1;
        attemps = 0;
    }
    void play()
    {
        system("cls");
        int guess;
        cout << "--------------------------------------" << endl;
        cout << "Welcome to the guessing game !" << endl;
        cout << "--------------------------------------" << endl;
        cout << "-> we have selected a number betwen(0-15),what is it?" << endl;
        do
        {
            cout << "enter your guess: ";
            cin >> guess;
            attemps++;
            if (guess > number)
            {
                system("cls");

                cout << ".............................................................." << endl;
                cout << "it's a litle bit higher! try lower and trust your sensens :)" << endl;
                cout << ".............................................................." << endl;
            }
            else if (guess < number)
            {
                system("cls");

                cout << ".............................................................." << endl;
                cout << "it's a litle bit lower! try higher and trust your senses :]" << endl;
                cout << ".............................................................." << endl;
            }
            else
            {
                if (attemps == 1 || attemps <= 5)
                {
                    system("cls");

                    cout << "wow you've guessed it in " << attemps << " attemps {:0 incridible!}" << endl;
                }
                else
                {
                    system("cls");

                    cout << "congrats you've guessed it in " << attemps << " attemps!" << endl;
                }
            }

        } while (guess != number);
    }
    
};
// int main()
// {
//     geussinggame game;
//     game.play();
//     return 0;
// }