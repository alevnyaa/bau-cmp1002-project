#include "exam.h"

exam::exam(std::string course_name, 
    std::string classroom_name, 
    int day, 
    int starting_time,
    int student_number){
  course_name_ = course_name;
  classroom_name_ = classroom_name;
  day_ = day;
  starting_time_ = starting_time;
  student_number_ = student_number;
  return;
}

std::string exam::print(){
  std::string prnt_text = "";
  prnt_text += "Day: " + std::to_string((day_+1)) + "\n";
  prnt_text += "Course name: " + course_name_ + "\n";
  prnt_text += "Starting time: " + std::to_string((starting_time_*2+8)) + "\n";
  prnt_text += "Classroom name: " + classroom_name_ + "\n";
  prnt_text += "Number of students: " + std::to_string(student_number_) + "\n";
  return prnt_text;
}

//exam::operator std::string() const{
//  return "";
//}
