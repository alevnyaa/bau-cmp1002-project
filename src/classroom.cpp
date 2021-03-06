#include <algorithm>
#include <iostream>
#include <limits>
#include <fstream>
#include "classroom.h"

//is this necessary?
std::vector<classroom_ptr> classroom::classrooms_ = std::vector<classroom_ptr>();

void stoq(std::queue<char>& q, std::string s){
  std::queue<char> empty;
  std::swap(q, empty);
  for(char ch : s){
    if(!isspace(ch)){
      q.push(ch);
    }
  }
}


classroom::classroom(std::ifstream& infile){
  std::string line;
  std::queue<char> q;
  std::getline(infile, line);
  stoq(q, line);

  while(q.front() != 'C' && !q.empty()){
    classroom_name_ += q.front();
    q.pop();
  }

  for(int i=0; i<8; i++){
    q.pop();
  }
  
  std::string capacity_str;

  while(!q.empty()) {
    capacity_str += q.front();
    q.pop();
  }
  
  capacity_ = stoi(capacity_str);

  for(int i=0; i<LESSON_NUM; i++){
    schedule_.push_back(std::vector<std::string>(DAY_NUM, "Empty"));
  }

  std::getline(infile, line);
  while(infile){
    std::getline(infile, line);
    stoq(q, line);
    if(!q.empty()){
      char hour_ch = q.front();
      int hour = hour_ch - '0';
      q.pop();
      while(!q.empty()){
        char day_ch = q.front();
        int day = day_ch - '0';
        q.pop();
        schedule_[day-1][hour-1] = "Full";
      }
    }
  }

  infile.close();

  classrooms_.push_back(classroom_ptr(this));
}

bool classroom::exists(std::string classroom_name){
  for(auto cr: classrooms_){
    if(cr->get_name() == classroom_name){
      return true;
    }
  }
  return false;
}

classroom_ptr classroom::get(std::string classroom_name){
  for(auto cr : classrooms_){
    if(cr->get_name() == classroom_name){
      if(DEBUG) std::cout << "DEBUG: Got class: " << cr->get_name() << std::endl;
      return cr;
    }
  }
  std::cout << "Couldn't find classroom. Terminating..." << std::endl;
  throw 3;
}

const std::vector<classroom_ptr>& classroom::get_all(){
  return classrooms_;
}

//todo TODO don't throw error?
classroom_ptr classroom::get_free(int time, int day, int student_number){
  int lowest_capacity = std::numeric_limits<int>::max();
  classroom_ptr best_class;
  for(auto cr : classrooms_){
    int capacity = cr->get_capacity();
    if(capacity >= student_number 
        && capacity < lowest_capacity
        && cr->get_schedule().at(day).at(time) == "Empty"){
      best_class = cr;
      lowest_capacity = cr->get_capacity();
    }
  }
  if(best_class){
    return best_class; 
  }else{
    std::cout << "Couldn't find free classroom. Terminating..." << std::endl;
    throw 20;
  }
}

std::string classroom::print_free_classrooms_for_starting_time_and_day(int starting_time, int day){
  std::vector<std::string> cr_names;
  for(auto cr : classrooms_){
    if(cr->get_schedule().at(starting_time).at(day) == "Empty"){
      cr_names.push_back(cr->get_name());
    }
  }

  if(DEBUG) std::cout << "DEBUG: Sorting names" << std::endl;
  std::sort(cr_names.begin(), cr_names.end());

  std::string prnt_txt;
  for(auto cr_name : cr_names){
    prnt_txt += cr_name + "\n";
  }
  return prnt_txt;
}

std::string classroom::print_free_times_for_classroom_and_day(std::string classroom_name, int day){
  if(DEBUG) std::cout << "DEBUG: Creating prnt_txt" << std::endl;
  std::string prnt_txt;
  classroom_ptr cr = get(classroom_name);
  for(int i=0; i<LESSON_NUM; i++){
    if(DEBUG) std::cout << "DEBUG: Accessing class " << i << "/" << day << std::endl;
    if(cr->get_schedule().at(i).at(day) == "Empty"){
      prnt_txt += std::to_string(i * 2 + 8) + ":30" + "\n"; 
    }
  }
  return prnt_txt;
}

std::string classroom::print_free_days_for_classroom_and_starting_time(std::string classroom_name, int starting_time){
  std::string prnt_txt;
  classroom_ptr cr = get(classroom_name);
  for(int i=0; i<DAY_NUM; i++){
    if(cr->get_schedule().at(starting_time).at(i) == "Empty"){
      prnt_txt += std::to_string(i + 1) + "\n"; 
    }
  }
  return prnt_txt;
}

std::string classroom::get_name(){
  return classroom_name_;
}

int classroom::get_capacity(){
  return capacity_;
}

std::vector<std::vector<std::string> >& classroom::get_schedule(){
  return schedule_;
}

std::string classroom::print_schedule(){
  std::string prnt_txt = "\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n";
  int cur_hour = 8;
  for(std::vector<std::string> time : schedule_){
    prnt_txt += std::to_string(cur_hour) + ":30-" + std::to_string(cur_hour+2) + ":20";
    cur_hour += 2;
    for(std::string target : time){
      prnt_txt += "\t" + target;
    }
    prnt_txt += "\n";
  }
  return prnt_txt;
}
