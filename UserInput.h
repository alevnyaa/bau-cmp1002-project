#ifndef USERINPUT_H
#define USERINPUT_H
#include <string>
#include <iostream>

namespace UserInput{
  std::string GetInterval();
  bool TryParseInterval(std::string interval);
  std::string GetClassName();
  bool TryParseClassName(std::string class_name);
  std::string GetDay();
  bool TryParseDay(std::string day);
  std::string GetTime();
  bool TryParseTime(std::string time);
  std::string GetCourseName();
  bool TryParseCourseName(std::string course_name);
  int GetInt();
}
#endif
