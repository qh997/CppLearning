#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//const int RAND_RANGE(101);

class Puzzle
{
  public:
    Puzzle()
    {
        srand(time(NULL));
        answer = rand() % 101;
    }
    int guess(const int value)
    {
        return value == answer ? 0
             : value <  answer ? 1
             :                   2;
    }

  private:
    int answer;
};

int main()
{
    string user_name;
    cout << "Please enter your name: ";
    cin >> user_name;
    cout << "\nHello, " << user_name
         << " let's play the game."
         << endl;

    bool usr_continue(true);
    while (usr_continue)
    {
        Puzzle pz;

        while (true)
        {
            int user_guess;
            cout << "Please guess the unkonw number: ";
            if (!(cin >> user_guess))
                break;

            bool won(false);
            switch (pz.guess(user_guess))
            {
                case 0:
                    cout << "Congratulation!" << endl;
                    won = true;
                    break;

                case 1:
                    cout << "Too low." << endl;
                    break;

                case 2:
                    cout << "Too high." << endl;
                    break;

                default:
                    break;
            }

            if (won)
                break;
        }

        usr_continue = false;
    }
}
