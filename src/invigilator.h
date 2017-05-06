#ifndef INVIGILATOR_H
#define INVIGILATOR_H
#include <string>
#include <memory>
#include <vector>
class invigilator;

typedef std::shared_ptr<invigilator> invigilator_ptr;

class invigilator{
  public:
    static invigilator_ptr get(std::string name);

    invigilator(std::ifstream infile);
    std::string get_name();
    std::vector<std::vector<std::string> >& get_schedule();
  private:
    static std::vector<invigilator_ptr> invigilators_;

    std::string name_;
    std::vector<std::vector<std::string> > schedule_; 
};
#endif
