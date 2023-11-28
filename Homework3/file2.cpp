#include "Includes.h"

void show_questions2()
{
    vector<string> questions = vector<string>();

    questions.push_back("Why does git call itself distributed?");
    questions.push_back("What's the difference between git and svn?");
    questions.push_back("Let’s say you and a friend both have the same repository downloaded from github."
                        "Nobody else has the repository but you, your friend and github. "
                        "How many copies of the code exist right now?");

    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }
}

void show_answers2()
{
    vector<string> answers = vector<string>();
    answers.push_back("Because every developer has a copy of the repository on their machine.");
    answers.push_back("Git is distributed, svn is not.");
    answers.push_back("3 copies because github is distributed and both the developer and his friend have a copy.");

    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
}

// int main()
// {
//     show_questions2();
//     show_answers2();
// }
