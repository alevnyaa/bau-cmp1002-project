#include <iostream>
#include <fstream>
#include "classroom.h"

std::vector<std::shared_ptr<classroom>> classroom::classrooms_ = std::vector<std::shared_ptr<classroom> >();

classroom::classroom(std::ifstream& infile){
  infile.unsetf(std::ios_base::skipws);

  std::queue<char> file;
  std::string line;
  while(std::getline(infile, line)){
    for(int i=0; i<line.length(); i++){
      if(!isspace(line[i])){
        file.push(line[i]); 
      }
    }
    file.push('N');
  }
  file.push('E');
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
  
  while(file.front() != 'N'){
    if(!isspace(file.front())){
      capacity_str += file.front();
      file.pop();
    }
  }

  capacity_ = stoi(capacity_str);

  file.pop();
  file.pop();

  for(int i=0; i<LESSON_NUM; i++){
    for(int j=0; j<DAY_NUM; j++){
      schedule_[i][j] = "Empty";
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
  while(file.front() != 'E'){
    char schedule_day = file.front();
    int s_d = schedule_day - '0';
    file.pop();

    while(file.front() != 'N'){
      char schedule_hour = file.front();
      int s_h = schedule_hour - '0';
      file.pop();
      schedule_[s_h-1][s_d-1] = "Full";
      if(DEBUG) std::cout << "DEBUG: This element should be Full: " << s_h-1 << "/" << s_d-1 << "=" << schedule_hour << "/" << schedule_day << ": " << schedule_[s_h-1][s_d-1] << std::endl;
      if(DEBUG) std::cout << "DEBUG: Front character is " << file.front() << std::endl;
    }
    if(file.front() == 'N'){
      file.pop();
    }
  }

  if(DEBUG) std::cout << "DEBUG: Successfully set schedule for " << classroom_name_ << std::endl;

  if(DEBUG){
    std::cout << "DEBUG: Dumping schedule_" << std::endl;
    for(int i=0; i<LESSON_NUM; i++){
      for(int j=0; j<DAY_NUM; j++){
        std::cout << "Entry " << i << "/"  << j << " : " << schedule_[i][j] << std::endl;
      }
    }
  }

  classrooms_.push_back(std::shared_ptr<classroom>(this));
}

bool classroom::exists(std::string classroom_name){
  for(auto cr: classroom::classrooms_){
    if(cr->get_name() == classroom_name){
      return true;
    }
  }
  return false;
}

//todo
classroom& classroom::get(std::string classroom_name){
  for(auto cr : classrooms_){
    if(cr->get_name() == classroom_name){
      if(DEBUG) std::cout << "DEBUG: Gave class " << cr->get_name() << std::endl;
      if(DEBUG) std::cout << cr->print_schedule() << std::endl;
      return *cr;
    }
  }
  std::cout << "Couldn't find classroom. Terminating..." << std::endl;
  throw 20;
}

const std::vector<std::shared_ptr<classroom> >& classroom::get_all(){
  return classrooms_;
}

//todo
classroom& classroom::get_free(std::string time, std::string day, int student_number){
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
  if(DEBUG) std::cout << "DEBUG: Got name " << classroom_name_ << std::endl;
  return classroom_name_;
}

std::string classroom::print_schedule(){
  std::string prnt_txt = "\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n";
  int cur_hour = 8;
  for(int i=0; i<LESSON_NUM; i++){
    prnt_txt += std::to_string(cur_hour) + ":30-" + std::to_string(cur_hour+2) + ":20";
    cur_hour += 2;
    for(int j=0; j<DAY_NUM; j++){
      if(DEBUG) std::cout << "DEBUG: Current schedule entry " << i << "/" << j << " is "  << schedule_[j][i] << std::endl;
      prnt_txt += '\t' + schedule_[i][j];
    }
    prnt_txt += '\n';
  }
  std::cout << prnt_txt;
  return prnt_txt;
}
