#include <iostream>
#include <string>
#include <conio.h>
#include <random>
#include <vector>
using namespace std;

class Hanged
{
private:
    string word;
    string guess;
    int lives;
    vector<string> words_e = {"GRUMPY", "FJORDS", "VEXING", "WOMBAT", "QUILTS"},
    words_m = {"MICROSOFT", "ABDUCTION", "MONASTERY", "JUXTAPOSED", "RELIANTLY"},
    words_h = {"ENTREPRENEURSHIP", "PHOTOSYNTHESIS", "TELECOMMUNICATION", "UNFORGETTABLE", "ACCOMPLISHMENT"};
    /**
     * This function implements the easy level of the Hangman game.
     * It generates a random word from a list of words and prompts the user to guess the letters of the word.
     * The user has a limited number of lives to guess the word.
     * If the user guesses the word correctly, they win. Otherwise, they lose.
     * @return void
     */
    void easy() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 4);
        word = words_e[dis(gen)];
        guess = string(word.length(), '_ ');
        cout << "You have " << lives << " lives." << endl;
        cout << "The word is " << word.length() << " letters long." << endl;
        while (lives > 0)
        {
            cout << "Guess a letter: ";
            string c;
            cin >> c;
            transform(c.begin(), c.end(), c.begin(), ::toupper);
            if (word.find(c) != string::npos)
            {
                cout << "Correct!" << endl;
                char letter = c[0];
                int pos = -1;
                while ((pos = word.find(letter, pos + 1)) != string::npos)
                {
                    guess[pos * 2] = letter;
                }
                cout << guess << endl;
                if (guess == word)
                {
                    cout << "You win!" << endl;
                    break;
                }
            }
            else
            {
                cout << "Wrong!" << endl;
                lives--;
                cout << "You have " << lives << " lives left." << endl;
                if (lives == 0)
                {
                    cout << "You lose!" << endl;
                    cout << "The word was " << word << endl;
                    cout << "Press any key to exit...";
                    getch();
                    exit(0);
                }
            }
        }
    }
    /**
     * Executes the medium difficulty level of the Hangman game.
     * Generates a random word from the medium word list and prompts the user to guess letters.
     * Updates the game state based on the user's input and provides feedback.
     * Ends the game when the user wins or loses.
     */
    void med() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 4);
        word = words_m[dis(gen)];
        guess = string(word.length(), '_ ');
        cout << "You have " << lives << " lives." << endl;
        cout << "The word is " << word.length() << " letters long." << endl;
        while (lives > 0)
        {
            cout << "Guess a letter: ";
            string c;
            cin >> c;
            transform(c.begin(), c.end(), c.begin(), ::toupper);
            if (word.find(c) != string::npos)
            {

                cout << "Correct!" << endl;
                int pos = -1;
                while ((pos = word.find(c[0], pos + 1)) != string::npos)
                {
                    guess[pos * 2] = c[0];
                }
                cout << guess << endl;
                if (guess == word)
                {
                    cout << "You win!" << endl;
                    break;
                }
            }
            else
            {
                cout << "Wrong!" << endl;
                lives--;
                cout << "You have " << lives << " lives left." << endl;
                if (lives == 0)
                {
                    cout << "You lose!" << endl;
                    cout << "The word was " << word << endl;
                    cout << "Press any key to exit...";
                    getch();
                    exit(0);
                }
            }
        }
    }
    void hard() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 4);
        word = words_h[dis(gen)];
        guess = string(word.length(), '_ ');
        cout << "You have " << lives << " lives." << endl;
        cout << "The word is " << word.length() << " letters long." << endl;
        while (lives > 0)
        {
            cout << "Guess a letter: ";
            string c;
            cin >> c;
            transform(c.begin(), c.end(), c.begin(), ::toupper);
            if (word.find(c) != string::npos)
            {

                cout << "Correct!" << endl;
                char c_char = c[0];
                int pos = -1;
                while ((pos = word.find(c_char, pos + 1)) != string::npos)
                {
                    guess[pos * 2] = c_char;
                }
                cout << guess << endl;
                if (guess == word)
                {
                    cout << "You win!" << endl;
                    break;
                }
            }
            else
            {
                cout << "Wrong!" << endl;
                lives--;
                cout << "You have " << lives << " lives left." << endl;
                if (lives == 0)
                {
                    cout << "You lose!" << endl;
                    cout << "The word was " << word << endl;
                    cout << "Press any key to exit...";
                    getch();
                    exit(0);
                }
            }
        }
    }
public:
    Hanged(int d) {
        if (d == 1)
        {
            lives = 6;
            easy();
        }
        else if (d == 2)
        {
            lives = 8;
            med();
        }
        else if (d == 3)
        {
            lives = 10;
            hard();
        }
        else
        {
            cout << "Invalid input" << endl;
            cout << "Press any key to exit..." << endl;
            getch();
            exit(0);
        }
    }
    ~Hanged() {}
};