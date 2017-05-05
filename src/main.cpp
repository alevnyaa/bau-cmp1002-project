#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <boost/filesystem.hpp>
#include "userinput.h"
#include "exam.h"
#include "classroom.h"

std::string display_menu(){
  std::string menu = "";
  menu += "1. Create Exam\n";
  menu += "2. Show schedule for classroom\n";
  menu += "3. List available classrooms for time and day\n";
  menu += "4. List available hours for classroom at day\n";
  menu += "5. List available days for classroom at starting time\n";
  menu += "0. Exit\n";
  return menu;
}

int initialize_classrooms(char* path_str){
  boost::filesystem::path p(path_str);
  //files of lines of queues of chars
  //vector of vector of queue of char
  if(exists(p)){
    if(is_directory(p)){
      for(boost::filesystem::directory_entry& dir_entry : boost::filesystem::directory_iterator(p)){
        std::string full_path = path_str + dir_entry.path().filename().string();
        std::ifstream infile(full_path);
        if(infile){
          classroom* new_cr = new classroom(infile);
        }else{
          std::cout << "Not file?" << std::endl;
          return 1;
        }
      }
    }else{
      std::cout << "Path not a directory" << std::endl;
    }
  }else{
    std::cout << "Classroom files are missing!" << std::endl;
    return 1;
  }
  return 0;
}

void create_exam(){
  std::string course_name = userinput::course_name::get();
  std::string day = userinput::day::get();
  std::string time = userinput::starting_time::get();
  std::cout << "Please enter number of students: ";
  int student_number;
  std::cin >> student_number;

  std::string classroom_name = classroom::get_free(day, time, student_number);
  exam new_exam(course_name, classroom_name, day, time, student_number);
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
  if(!initialize_classrooms(argv[1])){
    std::cout << "Can't find classroom setup texts in \"files/\" directory to initialize classrooms" << std::endl;
    std::cout << "Terminating..." << std::endl;
    return 1; 
  };
  bool exit = false;
  while(!exit){
    std::cout << display_menu();
    std::cout << "Waiting for input: ";
    int choice = userinput::get_int();
    switch(choice){
      case 1:{
        create_exam();
      }break;
      case 2:{
        std::string classroom_name = userinput::classroom_name::get();
        if(classroom::exists(classroom_name)){
          //classroom::get(classroom_name).print_schedule();
        }else{
          std::cout << "There is no such classroom" << std::endl;
        }
      }break;
      case 3:{
        std::string starting_time = userinput::starting_time::get();
        std::string day = userinput::day::get();
        classroom::print_free_classrooms_for_starting_time_and_day(starting_time, day);
      }break;
      case 4:{
        std::string classroom_name = userinput::classroom_name::get();
        std::string day = userinput::day::get();
        classroom::print_free_times_for_classroom_and_day(classroom_name, day);
      }break;
      case 5:{
        std::string classroom_name = userinput::classroom_name::get();
        std::string starting_time = userinput::starting_time::get();
        classroom::print_free_days_for_classroom_and_starting_time(classroom_name, starting_time);
      }break;
      case 0:{
        exit = true;
      }break;
      default: 
        std::cout << "Your input does not match any operation" << std::endl;
    }
  }
}
