#include<iostream>
#include<string>

using namespace std;

struct Student
{
    char record;
};

class StudentGrade
{
private:
    
    Student lettergraden;
    
    double quiz, midterm, finalExam;
    double finalTotalGrade;

public:
    void set_guiz();
    void set_Midterm();
    void set_FinalExam();
    
    double getquiz();
    double getMidterm();
    double getFinalExam();
    
    double finalTotGrade();
    char lettergrade();
    char calcFinalLetterGrade();
};
void StudentGrade::set_guiz()
{
    int temp = 0;
    cout << "Enter quiz grades: ";
    for (int i = 0; i < 2; i++)
    {
        cin >>temp;
        quiz += temp;
    }
}
void StudentGrade::set_Midterm()
{
    cout << "Enter midterm grade: ";
    cin >> midterm;
}

void StudentGrade::set_FinalExam()
{
    cout << "Enter final grade: ";
    cin >> finalExam;
}

double StudentGrade::getMidterm() 
{ 
    return midterm;
}
double StudentGrade::getFinalExam()
{ 
    return finalExam; 
}
double StudentGrade::getquiz()
{ 
    return quiz; 
}
double StudentGrade::finalTotGrade()
{
    int temp_quiz,temp_midterm,temp_finalexam;
    temp_quiz = (quiz / 20) * 25;
    temp_midterm = (midterm / 100) * 25;
    temp_finalexam = (finalExam / 100) * 50;
    finalTotalGrade = temp_quiz + temp_midterm + temp_finalexam;
    return temp_quiz + temp_midterm + temp_finalexam;
}
char StudentGrade::calcFinalLetterGrade()
{
   
    if (finalTotalGrade >= 90)
        return 'A';
    else if (finalTotalGrade >= 80 && finalTotalGrade < 90)
        return 'B';
    else if (finalTotalGrade >= 70 && finalTotalGrade < 80)
        return 'C';
    else if (finalTotalGrade >= 60 && finalTotalGrade < 70)
        return 'D';
    else
        return 'F';
}
char StudentGrade::lettergrade()
{
     lettergraden.record = calcFinalLetterGrade();
     return lettergraden.record;
}

int main()
{

    StudentGrade student;
    student.set_guiz();
    student.set_Midterm();
    student.set_FinalExam();
    student.finalTotGrade();
    student.calcFinalLetterGrade();
    student.lettergrade();
    cout<<"letter grade: "<<student.lettergrade()<<endl;
    return 0;
}
