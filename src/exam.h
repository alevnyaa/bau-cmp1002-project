#ifndef EXAM_H
#define EXAM_H
#include <string>

class exam{
  public:
    exam(std::string course_name, 
        std::string classroom_name, 
        int day, 
        int starting_time,
        int student_number);
    std::string print();
    //operator std::string() const;
  private:
    std::string course_name_;
    std::string classroom_name_;
    int day_;
    int starting_time_;
    int student_number_;
};
#endif
