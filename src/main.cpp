#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <boost/filesystem.hpp>
#include "userinput.h"
#include "exam.h"
#include "classroom.h"
#include "constants.h"

std::string display_menu(){
  std::string menu;
  menu += "1. Create Exam\n";
  menu += "2. Show schedule for classroom\n";
  menu += "3. List available classrooms for time and day\n";
  menu += "4. List available hours for classroom at day\n";
  menu += "5. List available days for classroom at starting time\n";
  menu += "9. Print this help menu again\n";
  menu += "0. Exit\n";
  return menu;
}

int initialize_classrooms(char* path_str){
  char* path_str_classrooms = path_str;
  path_str_classrooms += "classrooms/";
  boost::filesystem::path p(path_str_classrooms);
  //files of lines of queues of chars
  //vector of vector of queue of char
  if(exists(p)){
    if(is_directory(p)){
      for(boost::filesystem::directory_entry& dir_entry : boost::filesystem::directory_iterator(p)){
        std::string full_path = path_str;
        full_path += dir_entry.path().filename().string();
        std::ifstream infile(full_path);
        if(infile){
          if(DEBUG) std::cout << "DEBUG: Currently making " << dir_entry.path().filename().string() << std::endl;
          classroom* new_cr = new classroom(infile);
        }else{
          std::cout << "Not file?" << std::endl;
          return 1;
        }
      }
      if(DEBUG) std::cout << "DEBUG: Initialize class for ended" << std::endl;
    }else{
      std::cout << "Path not a directory" << std::endl;
    }
  }else{
    std::cout << "Classroom files are missing!" << std::endl;
    return 1;
  }
  if(DEBUG) std::cout << "DEBUG: Initialized classes." << std::endl;
  return 0;
}

void create_exam(){
  std::string course_name = userinput::course_name::get();
  int day = userinput::day::get();
  int time = userinput::starting_time::get();
  std::cout << "Please enter number of students\n>>";
  int student_number;
  std::cin >> student_number;

  classroom_ptr free_cr = classroom::get_free(day, time, student_number);
  exam new_exam(course_name, free_cr->get_name(), day, time, student_number);
  std::ofstream out("exam.txt");
  out << new_exam.print();
  out.close();
  std::cout << "Exam created! See exam.txt" << std::endl;
}

int main(int argc, char* argv[]){
  if(argc < 2){
    std::cout << "Usage: exameditor directory-of-classroom-files" << std::endl;
    return 1;
  }
  if(initialize_classrooms(argv[1])){
    std::cout << "Error during classroom initialization" << std::endl;
    std::cout << "Terminating..." << std::endl;
    return 1; 
  };
  bool exit = false;
  std::cout << display_menu();
  while(!exit){
    std::cout << ">>";
    int choice = userinput::get_int();
    switch(choice){
      case 1:{
        create_exam();
      }break;
      case 2:{
        std::string classroom_name = userinput::classroom_name::get();
        std::cout << classroom::get(classroom_name)->print_schedule();
      }break;
      case 3:{
        int starting_time = userinput::starting_time::get();
        int day = userinput::day::get();
        std::cout << classroom::print_free_classrooms_for_starting_time_and_day(starting_time, day);
      }break;
      case 4:{
        std::string classroom_name = userinput::classroom_name::get();
        int day = userinput::day::get();
        std::cout << classroom::print_free_times_for_classroom_and_day(classroom_name, day);
      }break;
      case 5:{
        std::string classroom_name = userinput::classroom_name::get();
        int starting_time = userinput::starting_time::get();
        std::cout << classroom::print_free_days_for_classroom_and_starting_time(classroom_name, starting_time);
      }break;
      case 9:{
        std::cout << display_menu();
      }break;
      case 0:{
        exit = true;
      }break;
      default: 
        std::cout << "Your input does not match any operation" << std::endl;
    }
  }
}
