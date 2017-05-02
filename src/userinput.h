#ifndef USERINPUT_H
#define USERINPUT_H
#include <string>
#include <iostream>
namespace userinput{
  namespace starting_time{
    std::string get();
    bool parse();
    bool try_parse();
  };

  namespace classroom_name{
    std::string get();
    bool parse();
    bool try_parse();
  };

  namespace day{
    std::string get();
    bool parse();
    bool try_parse();
  };

  namespace course_name{
    std::string get();
    bool parse();
    bool try_parse();
  };

  int get_int();
}
#endif
