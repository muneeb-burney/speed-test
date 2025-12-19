#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;

void typingSpeedTest() 
{
    string sentences[3] = 
	{
        "Artificial intelligence is changing the future.",
        "Coding is the new language of creativity.",
        "Speed comes with practice and focus."
    };

    srand(time(0));
    string sentence = sentences[rand() % 3];
    string userInput;

    cout << "\nType this sentence:\n" << sentence << "\n\n";
    cout << "Press Enter to start...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    cout << "\nStart typing:\n";
    time_t start = time(0);
    getline(cin, userInput);
    time_t end = time(0);

    double timeTaken = difftime(end, start);
    if (timeTaken < 1) timeTaken = 1;

    int words = 1;
    for (char c : userInput) if (c == ' ') words++;

    double wpm = (words / timeTaken) * 60;

    int correct = 0;
    int len = sentence.size();
    for (int i = 0; i < len && i < userInput.size(); i++)
        if (sentence[i] == userInput[i]) correct++;

    double accuracy = (double)correct / len * 100;

    cout << "\nTime: " << timeTaken << " sec";
    cout << "\nWords: " << words;
    cout << "\nSpeed: " << wpm << " WPM";
    cout << "\nAccuracy: " << accuracy << "%";

    if (accuracy == 100) cout << "\nPerfect!";
    else if (accuracy >= 80) cout << "\nGood!";
    else cout << "\nKeep practicing!";
}

int main() 
{
    typingSpeedTest();
 
}
