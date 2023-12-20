#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "Hanged.h"
using namespace std;

int main() {
    int diff;
    string word;
    string guess;
    int lives;
    cout << "Welcome to Hangman Game!" << endl;
    Sleep(1000);
    cout << "Game is loading.";
    Sleep(2000);
    cout << ".";
    Sleep(2000);
    cout << ".";
    Sleep(2000);
    cout << "." << endl;
    Sleep(2000);
    cout << "Which difficulty would you like to play in?" << endl;
    Sleep(1000);
    cout << "1. Easy(6-lives, 6-letters)" << endl;
    Sleep(1000);
    cout << "2. Medium(8-lives, 10-letters)" << endl;
    Sleep(1000);
    cout << "3. Hard(10-lives, 15-letters)" << endl;
    std::cout << "Enter 1, 2 or 3:" << std::endl;
    cin >> diff;
    Hanged h(diff);
    return 0;
}
