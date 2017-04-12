#ifndef EXAM_H
#define EXAM_H
#include <string>
using namespace std;

class Exam{
  public:
    Exam();
    Exam(string name, string code, string classroom, int date, int time);
  private:
    string course_name_;
    string course_code_;
    string classroom_;
    int date_;
    int time_;
};
#endif
