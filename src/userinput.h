#ifndef USERINPUT_H
#define USERINPUT_H
#include <string>
#include <iostream>
namespace userinput{
  namespace starting_time{
    int get();
    bool try_parse(std::string starting_time);
  };

  namespace classroom_name{
    std::string get();
    bool try_parse(std::string classroom_name);
  };

  namespace day{
    int get();
    bool try_parse(std::string day);
  };

  namespace course_name{
    std::string get();
    bool try_parse(std::string course_name);
  };

  int get_int();
}
#endif
