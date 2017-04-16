#include "Exam.h"
using namespace std;

Exam::Exam(){
  return;
}

Exam::Exam(string name, string code, string classroom, int date, int time){
  course_name_ = name;
  course_code_ = code;
  classroom_ = classroom;
  date_ = date;
  time_ = time;
  return;
}

Exam::operator std::string() const{
  return "";
}
