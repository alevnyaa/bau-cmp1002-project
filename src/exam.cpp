#include "exam.h"
using namespace std;

exam::exam(){
  return;
}

exam::exam(string name, string code, string classroom, int date, int time){
  course_name_ = name;
  course_code_ = code;
  classroom_ = classroom;
  date_ = date;
  time_ = time;
  return;
}

exam::operator std::string() const{
  return "";
}
