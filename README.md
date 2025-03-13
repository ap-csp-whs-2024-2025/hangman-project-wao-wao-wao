[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=18659693)
# hangman-mini-project

## To compile code
All code must be compiled before you can run it.  To compile means that you are converting your C++ code into a language that the computer can understand (e.g., binary).  To compile C++ code, run the following command in a terminal:
```
g++ fileName.cpp -o outFileName
```
This tells the C++ compiler to compile your file named `fileName.cpp`, and output it (`-o`) as a file named `outFileName`.

## To run code
After you have compiled the code, run your output file by running
```
./outFileName
```

## Compile and Run Example
Suppose I have a file named `classwork.cpp`.  I compile and run the file by doing
```
g++ classwork.cpp -o output
./output
```
# List Helper Procedures
Mr. Vu has provided you with custom procedures that work specifically with C++ vectors, and are similar to the AP CSP style list procedures.  You are free to use them in your program.

|Procedure|Description|
|---|---|
|`void display(vec)`|Takes a vector as parameter, and displays it to the screen in a nice format.|
|`void append(vec, val)`|Appends `val` into the vector `vec`.|
|`void insert(vec, ind, val)`|Inserts `val` into the index `ind` of the vector `vec`.  The elements previously at index `ind` and after are shifted over to the right.  The size of the vector increases by 1.|
|`void remove(vec, ind)`|Removes the element at `ind` of the vector `vec`.  Elements after the element at `ind` are shifted over to the left.  The size of the vector is decreased by 1.|
|`int length(vec)`|Returns the number of elements in the vector.|

# Instructions - Wordle Clone
Do the following in the file named `hangman.cpp`.

You will create a simpler version of the Hangman game.  Players are tasked with correctly guessing an eight-letter word.  The program should display the a hint formatted in the following way after each guess:
* An "_" if the letter is not in the word.
* The letter itself if the letter is in the word.

If you wish, you can also print out an actual hangman person after each guess.  See [this link](https://cplusplus.com/forum/beginner/221193/) for an example of what you could print.

For example, if the word is `"education"`:
|Guess|Hint|
|---|---|
|`"d"`|`["_", "d", "_", "_", "_", "_", "_", "_", "_"]`|
|`"e"`|`["e", "d", "_", "_", "_", "_", "_", "_", "_"]`|
|`"a"`|`["e", "d", "_", "_", "a", "_", "_", "_", "_"]`|

## Program Requirements
* Computer should get a random word from the `wordList` to use as the secret word.
* User should be prompted to guess a letter.
* The user should be presented with either a hint if the letter is correct, or a message (or image) if the letter is not present in the word.
* The user should then be prompted for whether or not they want to guess the word.
    * If they answer `"y"`, then they can try and guess the word.
    * If they answer `"n"`, then they are prompted again to guess another letter.
* As long as the user still has lives (the man has not been hanged yet) and if the word has not yet been guessed, then the game will play.
* After the user finally guesses the word, or if they run out of lives, then the game ends.

Starter code has been provided for you.  You are free to use it, or solve the problem in a different way.  In the starter code, you can complete the program by writing this procedure, and doing the following other things.
*  Note that the `hint` variable is globally accessible to the entire program.
*  `bool getHint(std::string secret, char guessLetter)` - This procedure takes in the secret word and the user guess, and updates the `hint` variable, which is globally accessible to the entire program.  If the `guessLetter` was present in the `secret`, then return `true` at the end of the procedure.  Otherwise, return `false` to indicate that the guess was incorrect.
*  Add functionality to ask the user if they want to guess the whole word.
*  Feel free to print the actual hangman person.

**Note and Hint:** To get a single character from a `std::string`, use the brackets `[]`.  For example, if you had a `std::string` variable named `secret`, then you can get the letter at index 3 by doing `secret[4]`.

## Extension
Create a list (`std::vector`) of `std::string` values and add the user guesses (letters only), so that you can display to the user what letters they have already guessed.  You can also give the user a message if they reuse a letter they have already guessed.
