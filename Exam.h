#ifndef EXAM_H
#define EXAM_H
#include <string>

class Exam{
  public:
    Exam();
    Exam(std::string name, std::string code, std::string classroom, int date, int time);
    operator std::string() const;
  private:
    std::string course_name_;
    std::string course_code_;
    std::string classroom_;
    int date_;
    int time_;
};
#endif
