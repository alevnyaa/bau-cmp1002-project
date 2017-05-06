#include <iostream>
#include <fstream>
#include <queue>
#include "invigilator.h"
#include "constants.h"

void stoq(std::queue<char>& q, std::string s){
  std::queue<char> empty;
  std::swap(q, empty);
  for(char ch : s){
    if(!isspace(ch)){
      q.push(ch);
    }
  }
}

invigilator::invigilator(std::ifstream infile){
  std::string line;
  std::queue<char> q;
  std::getline(infile, line);
  stoq(q, line);

  while(!q.empty()){
    name_ += q.front();
    q.pop();
  }

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

  invigilators_.push_back(invigilator_ptr(this));
}

std::string invigilator::get_name(){
  return name_;
}

std::vector<std::vector<std::string> >& invigilator::get_schedule(){
  return schedule_;
}

invigilator_ptr invigilator::get(std::string name){
  for(auto iv : invigilators_){
    if(iv->get_name() == name){
      if(DEBUG) std::cout << "DEBUG: Got class: " << iv->get_name() << std::endl;
      return iv;
    }
  }
  std::cout << "Couldn't find invigilator. Terminating..." << std::endl;
  throw 3;
}
