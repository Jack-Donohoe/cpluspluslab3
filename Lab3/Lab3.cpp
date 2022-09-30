#include <iostream>
#include <string>
using namespace std;

// Testing For loops

/*int main()
{
    string ghosts[4] = {"Blinky","Inky","Pinky","Clyde"};
    string ans = "";
    bool found = false;

    cout << "Please enter the name of a ghost: ";
    cin >> ans;

    for (string ghost : ghosts) {
        if (ghost == ans) {
            cout << "Your guess was correct";
            found = true;
        }
    }

    if (found == false) {
        cout << "Your guess was incorrect";
    }

    return 0;
}*/

// Ghost Guessing code

/*int main()
{
    cout << "Counting forward: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
    }

    cout << "\nCounting backward: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << 9 - i << " ";
    }

    cout << "\nCounting by fives: " << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i * 5 << " ";
    }

    cout << "\nCounting with null statements: " << endl;
    int count = 0;
    for (; count < 10;) {
        cout << count << " ";
        count++;
    }

    cout << "\nCounting with nested for loops: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << i << "," << j << " ";
        }
    }

    return 0;
}*/


// String Tester
// Demonstrates string objects

/*int main() {
    string word1 = "Game";
    string word2("Over");
    string word3(3, '!');
    string phrase = word1 + " " + word2 + word3;

    cout << "The phrase is: " << phrase << "\n\n";
    cout << "The phrase has " << phrase.size() << " characters in it.\n\n";
    cout << "The character at position 0 is: " << phrase[0] << "\n\n";
    cout << "Changing the character at position 0.\n";

    phrase[0] = 'L';
    cout << "The phrase is now: " << phrase << "\n\n";

    for (unsigned int i = 0; i < phrase.size(); ++i) {
        cout << "Character at position " << i << " is: " << phrase[i] << endl;
    }

    cout << "\nThe sequence 'Over' begins at location ";
    cout << phrase.find("Over") << endl;

    if (phrase.find("Mario") == string::npos) {
        cout << "'Mario' is not in the phrase.\n\n";
    }

    phrase.erase(4, 5);
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase(4);
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase();
    cout << "The phrase is now: " << phrase << endl;

    if (phrase.empty()) {
        cout << "\nThe phrase is no more.\n";
    }

    return 0;
}*/

// Hero's Inventory
// Demonstrates arrays

/*int main()
{
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS];

    int numItems = 0;
    inventory[numItems++] = "sword";
    inventory[numItems++] = "armour";
    inventory[numItems++] = "shield";

    cout << "The value of numitems is now: " << numItems << endl;

    cout << "Your items:\n";
    for (int i = 0; i < numItems; ++i)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    for (int i = 0; i < numItems; ++i)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "\nYou find a healing potion.";
    if (numItems < MAX_ITEMS)
    {
        inventory[numItems++] = "healing potion";
    }
    else
    {
        cout << "You have too many items and can't carry another.";
    }
    cout << "\nYour items:\n";


    for (string i : inventory)  // For-each loop.  Note that this will iterate MAX_ITEMS times
    {
        cout << i << endl;
    }

    return 0;
}*/

// Tic-Tac-Toe Board
// Demonstrates multidimensional arrays

/*int main() {
    const int ROWS = 3;
    const int COLUMNS = 3;
    char board[ROWS][COLUMNS] = {
        {'O', 'X', 'O'},
        {' ', 'X', 'X'},
        {'X', 'O', 'O'} };

    cout << "Here's the tic-tac-toe board:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << "\n'X' moves to the empty location.\n\n";
    board[1][0] = 'X';
    cout << "Now the tic-tac-toe board is:\n";

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "\n'X' wins!" << endl;

    return 0;

}*/


// Word Jumble
// The classic word jumble game where the player can ask for a hint

int main() {

    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"laboured", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];  // word to guess
    string theHint = WORDS[choice][HINT];  // hint for word
    string jumble = theWord;  // jumbled version of word

    int length = jumble.size();
    for (int i = 0; i < length; ++i) {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble;
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit")) {

        if (guess == "hint") {
            cout << theHint;
        }
        else {
            cout << "Sorry, that's not it.";
        }

        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    if (guess == theWord) {
        cout << "\nThat's it!  You guessed it!\n";
    }

    cout << "\nThanks for playing.\n";

    return 0;
}
