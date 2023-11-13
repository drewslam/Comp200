#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question
{
public:
    void set_text(string value);
    void set_answer(string value);
    bool check_answer(string response) const;
    void display() const;
private:
    string text;
    string answer;

};

void Question::set_text(string value) {
    text = value;
}
void Question::set_answer(string value) {
    answer = value;
}
bool Question::check_answer(string response) const {
    return response == answer;
}
void Question::display() const {
    cout << text << endl;
}

class ChoiceQuestion : public Question
{
public:
    void add_choice(string choice, bool correct);
    void displayChoice() const;
private:
    vector <string> choiceList;
};

void ChoiceQuestion::add_choice(string choice, bool correct) {
    choiceList.push_back(choice);
    if (correct)
    {
        int choice_index = choiceList.size();
        string choice_string = to_string(choice_index);
        set_answer(choice_string);
    }
}
void ChoiceQuestion::displayChoice() const {
    for (int i = 0; i < choiceList.size(); i++) {
        cout << i + 1 << ". " << choiceList.at(i) << endl;
    }
}
/*class FillInQuestion : public Question {
    public:
        void fillIn(string input);
};

void FillInQuestion::fillIn(string input) {
    return input == answer;
}*/

class FreeResponseQuestion : public Question {
    public:
        bool checkanswer(string choice);
};

bool FreeResponseQuestion::checkanswer(string choice) {
    if (choice == "True") {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    ChoiceQuestion cq;
    Question fq;
    Question nq;
    FreeResponseQuestion frq;


    cq.set_text("In which country was the inventor of C++ born?");
    cq.add_choice("Australia", false);
    cq.add_choice("China", true);
    cq.add_choice("Japan", false);
    cq.display();
    cq.displayChoice();
    string response;
    cin >> response;
    bool result = cq.check_answer(response);
    if (result) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Wrong" << endl;
    }

    fq.set_answer("China");
    fq.set_text("The country the inventor of C++ was born in is ___");
    fq.display();
    string input;
    cin >> input;
    bool answer = fq.check_answer(input);
    if (answer) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Wrong" << endl;
    }

    nq.set_answer("4");
    nq.set_text("What is 2 + 2 equal?");
    nq.display();
    string num;
    cin >> num;
    bool answer2 = nq.check_answer(num);
    if (answer2) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Wrong" << endl;
    }

    frq.set_text("Is computer science important?");
    frq.display();
    string response2;
    cin.ignore();
    getline(cin, response2);
    cout << "True or False" << endl;
    string check;
    bool answer3;
    cin >> check;
    answer3 = frq.checkanswer(check);
    if (answer3) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Wrong" << endl;
    }

    return 0;
}
