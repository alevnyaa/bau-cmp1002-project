#ifndef USERINPUT_H
#define USERINPUT_H
#include <string>
#include <iostream>
namespace userinput{
  std::string get_starting_time();
  bool try_parse_starting_time(std::string starting_time);
  std::string get_class_name();
  bool try_parse_class_name(std::string class_name);
  std::string get_day();
  bool try_parse_day(std::string day);
  std::string get_time();
  bool try_parse_time(std::string time);
  std::string get_course_name();
  bool try_parse_course_name(std::string course_name);
  int get_int();
}
#endif
