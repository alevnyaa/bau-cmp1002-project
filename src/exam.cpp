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

string exam::print(){
  string prnt_text = "";
  prnt_text += "Day: " + day_ + "\n";
  prnt_text += "Course name: " + course_name_ + "\n";
  prnt_text += "Starting time: " + starting_time_ + "\n";
  prnt_text += "Classroom name: " + classroom_name_ + "\n";
  prnt_text += "Number of students: " + to_string(student_number_) + "\n";
  return prnt_text;
}

//exam::operator std::string() const{
//  return "";
//}
