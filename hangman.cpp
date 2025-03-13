/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<std::string> hint(8, "_"); // Hint is globally available

bool getHint(std::string secret, char guessLetter)
{
    bool found = false;
    for (size_t i = 0; i < secret.length(); i++)
    {
        if (secret[i] == guessLetter)
        {
            hint[i] = std::string(1, guessLetter);
            found = true;
        }
    }
    return found;
}

void displayHangman(int lives)
{
    std::cout << "Lives left: " << lives << "\n";
}

int main()
{
    srand(time(0));
    std::vector<std::string> wordList = {
        "education", "solution", "mountain", "platinum",
        "alphabet", "necklace", "elevator", "diamonds",
        "fragrant", "velocity", "graduate", "nebraska",
        "tropical", "evidence", "involved", "shopping",
        "baseball", "kangaroo", "horrible", "animals"};
    
    std::string answer = wordList[rand() % wordList.size()];
    char letterGuess;
    std::string wordGuess;
    int lives = 10;
    std::vector<char> guessedLetters;

    std::cout << "Welcome to Hangman!\n";

    while (lives > 0 && hint != std::vector<std::string>(answer.length(), "_"))
    {
        std::cout << "\nEnter your guess: ";
        std::cin >> letterGuess;

        if (std::find(guessedLetters.begin(), guessedLetters.end(), letterGuess) != guessedLetters.end())
        {
            std::cout << "You already guessed that letter. Try again.\n";
            continue;
        }
        guessedLetters.push_back(letterGuess);
        
        if (!getHint(answer, letterGuess))
        {
            lives--;
        }

        display(hint);
        displayHangman(lives);

        if (hint == std::vector<std::string>(answer.begin(), answer.end()))
        {
            std::cout << "Congratulations! You guessed the word: " << answer << "\n";
            return 0;
        }
        
        std::cout << "Would you like to guess the word (y/n)? ";
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y')
        {
            std::cout << "Enter your word guess: ";
            std::cin >> wordGuess;
            if (wordGuess == answer)
            {
                std::cout << "Congratulations! You guessed the word: " << answer << "\n";
                return 0;
            }
            else
            {
                std::cout << "Wrong guess! You lose a life.\n";
                lives--;
            }
        }
    }
    
    std::cout << "Game over! The correct word was: " << answer << "\n";
    return 0;
}
