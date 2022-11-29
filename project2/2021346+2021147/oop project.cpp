#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <stdexcept>

using namespace std;




class teacher {
public:
    virtual int quiz1() = 0; //virtual functions for quizzes
    virtual int quiz2() = 0;


};

class student :public teacher {
    vector  <string> name; //vector to store student name
    vector  <int> score; //vector that stores student class
    vector <string> reg; //vector storing student reg number

    vector <int> v;
public:
    int s, b;

    //to store our data to a csv file called data.csv
    void InputToFile(int s)

    {

        //opening fie
        bool flag = false;
        fstream myfilein, myfileout;
        string sreg, sname, sscore;
        string  reg, name, score;
        cout << "Enter reg number:";
        cin >> reg;
        //taking data from user
        myfilein.open("data.csv", ios::in);
        while (getline(myfilein, sreg, ','))
        {
            getline(myfilein, sreg, ',');

            getline(myfilein, sname, ',');
            getline(myfilein, sscore, '\n');
            if (reg == sreg)
            {
                flag = true;  //method to avoid having two students with same reg number

            }
        }

        //checking
        myfilein.close();
        if (flag == true)
        {
            cout << "This regnumber already exists." << endl;
        }
        else
        {
            cin.ignore();
            cout << "Enter name:";
            getline(cin, name);

            myfileout.open("data.csv", ios::app);
            if (myfileout.is_open())
            {
                myfileout << reg << ',' << name << ',' << s;
                myfileout << "\n";
                myfileout.close();
            }
            cout << "Student record added successfully." << endl;
            cout << name << " " << reg << " has obtained " << s << " out of 4 in this quiz " << endl;
        }



    }



    //function of quiz 1
    int quiz1() {
        int a;
        static int i = 1;


        //questions and answers
        cout << "WELCOME TO QUIZ 1\n";
        cout << i << ". What is 5x15?\n";
        cout << "1.50\n2.60\n3.70\n4.75\n";
        cin >> a;
        //exception handling
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }

        if (a == 4) {
            ++s; //to keep count of the current score
        }
        v.push_back(a); //to store question number in a vector
        ++i;
        cout << i << ". What is 150/5?\n";
        cout << "1.25\n2.30\n3.35\n4.40\n";
        cin >> a;
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }
        if (a == 2) {
            ++s;
        }
        //using vectors
        v.push_back(a);
        i++;
        cout << i << ".What is 42 + | 4 | +| -4 | - 42\n";
        cout << "1.-42\n2.42\n3.-4\n4.4\n";
        cin >> a;
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }
        if (a == 4) {
            ++s;
        }
        v.push_back(a);
        cout << i << ". What is 1004 divided by 2?\n";
        cout << "1.500\n2.504\n3.502\n4.505\n";
        cin >> a;
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }
        if (a == 3) {
            ++s;
        }
        v.push_back(a);

        static int j = 0;
        score.push_back(s);
        cout << "\nYour score is " << score[j] << " out of 4\n";
        ++j; //to display score from the vector


        return s;
    }
    int quiz2() {
        int a;
        int s = 0;
        static int i = 1;
        cout << "WELCOME TO QUIZ 2\n";
        cout << i << ". What is 10x10?\n";
        cout << "1.100\n2.60\n3.70\n4.75\n";
        cin >> a;

        //questions and answers
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }
        if (a == 1) {
            ++s;
        }
        v.push_back(a);
        ++i;
        cout << i << ". What is 200/10?\n";
        cout << "1.25\n2.22\n3.30\n4.20\n";
        cin >> a;
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }

        if (a == 4) {
            ++s;
        }
        v.push_back(a);
        i++;
        cout << i << ".What is 42+8-20\n";
        cout << "1.35\n2.34\n3.32\n4.30\n";
        cin >> a;
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }
        if (a == 4) {
            ++s;
        }
        v.push_back(a);
        cout << i << ". What is 2000 divided by 2?\n";
        cout << "1.1001\n2.1000\n3.1002\n4.1005\n";
        cin >> a;
        if (a > 4) {
            throw invalid_argument("Invalid ");

        }
        if (a == 2) {
            ++s;
        }
        v.push_back(a);
        static int j = 0;
        score.push_back(s);
        cout << "\nYour score is " << score[j] << " out of 4\n";
        ++j;

        return s;
    }

    friend ostream& operator<<(ostream& cout, student& s) {
        cout << "Thanks for using ";
        return cout;
    }
};
int main()
{

    teacher* tptr;
    student s;
    int score = 0;
 //polymorphism
    tptr = &s;
    int a;
    char opt;
    do {

        //do while loop
        cout << "                                       WELCOME TO QUIZ SYSTEM\n";


        //asking user
        cout << "Do you want to attempt quiz 1 or quiz 2?\n";
        cin >> a;
        if (a == 1) {
            score = tptr->quiz1();

        }
        else if (a == 2) {
            score = tptr->quiz2();
        }
        else {
            cout << "Enter a valid number\n";
        }
        s.InputToFile(score);
        cout << "Do you want to attempt again?(y/n)\n";
        cin >> opt;
    } while ((a == 1 || a == 2) && opt == 'y');

    cout << s;
}