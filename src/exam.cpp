#include "exam.h"

exam::exam(std::string course_name, 
    std::string classroom_name, 
    int day, 
    int starting_time,
    int student_number){
  course_name_ = course_name;
  for(auto & c: course_name_) c = toupper(c);
  classroom_name_ = classroom_name;
  for(auto & c: classroom_name_) c = toupper(c);
  day_ = day;
  starting_time_ = starting_time;
  student_number_ = student_number;
  return;
}

std::string exam::print(){
  std::string prnt_text = "";
  std::string day_str;
  if(day_ == 0){
    day_str = "Monday"; 
  }else if(day_ == 1){
    day_str = "Tuesday"; 
  }else if(day_ == 2){
    day_str = "Wednesday"; 
  }else if(day_ == 3){
    day_str = "Thursday"; 
  }else if(day_ == 4){
    day_str = "Friday"; 
  }else if(day_ == 5){
    day_str = "Saturday"; 
  }else if(day_ == 6){
    day_str = "Sunday"; 
  }   
  prnt_text += "Day: " + day_str + "\n";
  prnt_text += "Course name: " + course_name_ + "\n";
  prnt_text += "Starting time: " + std::to_string((starting_time_*2+8)) + ":30" + "\n";
  prnt_text += "Classroom name: " + classroom_name_ + "\n";
  prnt_text += "Number of students: " + std::to_string(student_number_) + "\n";
  return prnt_text;
}

//exam::operator std::string() const{
//  return "";
//}
