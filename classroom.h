#ifndef CLASSROOM_H 
#define CLASSROOM_H
class A { int a; };
#include <string>
#include exam.h
using namespace std;

class Classroom{
  public:
    Classroom();
    Classroom(string name, int capacity, int full_times[], size_t size);
    DisplaySchedule();
  private:
    string class_name_;

    vector<Exam> exams_;
};
#endif
