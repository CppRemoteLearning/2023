#include "Includes.h"

void show_questions1()
{
    vector<string> questions = vector<string>();

    questions.push_back("When does it make sense to start vi with sudo (e.g. 'sudo vi [file])?");
    questions.push_back("What alternative is there to an IDE?");
    questions.push_back("What are the advantages and disadvantages of using an IDE vs another solution?");
    questions.push_back("What's the best IDE and why?");

    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }
}

void show_answers1()
{
    vector<string> answers = vector<string>();
    answers.push_back("When you want to edit a file that you don't have write permissions to.");
    answers.push_back("A text editor.");
    answers.push_back("IDEs are usually more user friendly and have more features,"
                      "but they are also slower and more resource intensive.");
    answers.push_back("The best IDE is the one you know how to use :) "
                      "for me is important to be use few resources and be responsive and intuitive. That's why I use VSCode.");

    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
}

int main()
{
    show_questions1();
    show_answers1();
    show_questions2();
    show_answers2();
    show_questions3();
    show_answers3();
}
