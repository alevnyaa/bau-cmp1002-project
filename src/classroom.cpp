#include <iostream>
#include <fstream>
#include "classroom.h"

std::vector<std::shared_ptr<classroom>> classroom::classrooms_ = std::vector<std::shared_ptr<classroom> >();
std::array<std::array<std::string, LESSON_NUM>, DAY_NUM> schedule_;
std::vector<exam> exams_ = std::vector<exam>();

classroom::classroom(std::ifstream& infile){
  infile.unsetf(std::ios_base::skipws);

  std::queue<char> file;
  char ch;
  while(infile >> ch){
    if(!isspace(ch) || ch == '\n'){
      file.push(ch); 
    }
  }
  infile.close();

  std::string classroom_name = "";
  for(int i=0; i<4; i++){
    classroom_name += file.front();
    file.pop();
  }
  classroom_name_ = classroom_name;

  for(int i=0; i<8; i++){
    file.pop();
  }

  std::string capacity_str = "";
  
  while(file.front() != '\n'){
    if(!isspace(file.front())){
      capacity_str += file.front();
      file.pop();
    }
  }
  file.pop();

  capacity_ = stoi(capacity_str);

  for(auto day : schedule_){
    for(std::string hour : day){
      hour = "Empty";
    }
  }

  if(DEBUG) {
    std::cout << "DEBUG: Dumping queue before schedule for " << classroom_name_ << std::endl;
    std::queue<char> filecopy = file;
    while(!filecopy.empty()){
      std::cout << filecopy.front();
      filecopy.pop();
    }
    std::cout << std::endl;
  }
  while(!file.empty()){
    int schedule_day;
    schedule_day = file.front();
    file.pop();

    while(!file.empty() && file.front() != '\n'){
      int schedule_hour = file.front();
      file.pop();
      schedule_[schedule_day][schedule_hour] = "Full";
    }
  }

  if(DEBUG) std::cout << "DEBUG: Successfully set schedule for " << classroom_name_ << std::endl;

  classrooms_.push_back(std::shared_ptr<classroom>(this));
}

bool classroom::exists(std::string classroom_name){
//  for(auto cr: classroom::classrooms_){
//    if((*cr).classroom_name == classroom_name){
//      return true;
//    }
//  }
  return true;
}

//todo
classroom& classroom::get(std::string classroom_name){
  return *classrooms_[0];
}

const std::vector<std::shared_ptr<classroom> >& classroom::get_all(){
  return classrooms_;
}

//todo
classroom& classroom::get_free(std::string time, std::string day, int student_number){
  for(auto classroom : classrooms_){
  }
  return *classrooms_[0]; 
}

std::string classroom::print_free_classrooms_for_starting_time_and_day(std::string starting_time, std::string day){
  return "";
}

std::string classroom::print_free_times_for_classroom_and_day(std::string classroom_name, std::string day){
  return "";
}

std::string classroom::print_free_days_for_classroom_and_starting_time(std::string classroom_name, std::string starting_time){
  return "";
}

std::string classroom::get_name(){
  return classroom_name_;
}

std::string classroom::print_schedule(){
  std::string prnt_txt = "\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun";
  int cur_hour = 8;
  for(auto time : schedule_){
    prnt_txt += std::to_string(cur_hour) + ":30-" + std::to_string(cur_hour+2) + ":20";
    for(std::string event : time){
      prnt_txt += "\t" + event;
    }
  }
  return "";
}
