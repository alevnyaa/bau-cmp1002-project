#ifndef EXAM_H
#define EXAM_H
#include <string>

class exam{
  public:
    exam(std::string course_name, 
        std::string classroom_name, 
        std::string day, 
        std::string starting_time,
        int student_number);
    //operator std::string() const;
  private:
    std::string course_name_;
    std::string classroom_name_;
    std::string day_;
    std::string starting_time_;
    int student_number_;
};
#endif
