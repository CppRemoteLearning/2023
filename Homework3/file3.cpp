#include "Includes.h"

void show_questions3()
{
    vector<string> questions = vector<string>();

    questions.push_back("What are branches and what are they useful for?");
    questions.push_back("How do you change branch?");
    questions.push_back("What are pull requests and what are they useful for? ");
    questions.push_back("Why do you think we don't want you to be able to commit to your main branch?");

    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }
}

void show_answers3()
{
    vector<string> answers = vector<string>();
    answers.push_back("Branches are different versions of the same code. They are useful to work on different features at the same time.");
    answers.push_back("You can change branch with the command git checkout [branch name].");
    answers.push_back("Pull requests are requests to merge a branch into another. They are useful to review code before merging it into the main branch.");
    answers.push_back("Because we want to review my code before merging it into the main branch so as to not break the code for everyone else.");

    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
}

// int main()
// {
//     show_questions3();
//     show_answers3();
// }
