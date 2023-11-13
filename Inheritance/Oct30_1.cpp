#include <iostream>
#include <vector>
using namespace std;

class Question
{
public:
    Question();
    void set_text(string question_text);
    void set_answer(string correct_response);
    bool check_answer(string response) const;
    void display() const;
private:
    string text;
    string answer;
};

Question::Question() {
    this->text = "";
    this->answer = "";
}

void Question::set_text(string value) { this->text = value; }

void Question::set_answer(string value) { this->answer = answer; }

bool Question::check_answer(string response) const { return (response == this->answer); }

void Question::display() const
{
    cout << "Question: " << this->text << endl;
    cout << "Answer: " << this->answer << endl;
}

class ChoiceQuestion : public Question
{
public:
    void add_choice(string choice, bool correct);
    void display() const;
private:
    vector<string> choices;
    vector<bool> trueFalse;
};

void ChoiceQuestion::add_choice(string choice, bool correct)
{
    this->choices.push_back(choice);
    this->trueFalse.push_back(correct);
}

void ChoiceQuestion::display() const
{
    Question::display();
    for (unsigned int i = 0; i < choices.size(); i++) {
        cout << i + 1 << ": " << choices.at(i) << " " << (!trueFalse.at(i) ? "False" : "True") << endl;
    }
}

class MultipleChoiceQuestion : public ChoiceQuestion
{
public:

private:

};

class FillInQuestion : public Question
{
public:

private:

};


class NumericalQuestion : public Question
{
public:

private:

};

class FreeResponseQuestion : public Question
{
public:
    void response(string input);
private:
    bool trueFalse;
};

void FreeResponseQuestion::response(string input) {
    cout << "True" << endl;
}

int main()
{
    ChoiceQuestion cq;
    FreeResponseQuestion frq;
    string input;

    cq.set_text("In which country was the inventor of C++ born?");
    cq.add_choice("Australia", false);
    cq.add_choice("San Francisco", false);
    cq.add_choice("Denmark", true);
    cq.display();
    string response = "San Francisco";
    bool result = cq.check_answer(response);
    if (!result)
    {
        cout << "False" << endl;
    } else
    {
        cout << "True" << endl;
    }

    frq.set_text("Is computer science important?");
    frq.display();
    getline(cin, input);
    frq.response(input);

    return 0;
}
