#include "exam.h"
using namespace std;

exam::exam(string course_name, 
    string classroom_name, 
    string day, 
    string starting_time,
    int student_number){
  course_name_ = course_name;
  classroom_name_ = classroom_name;
  day_ = day;
  starting_time_ = starting_time;
  student_number_ = student_number;
  return;
}

//exam::operator std::string() const{
//  return "";
//}
