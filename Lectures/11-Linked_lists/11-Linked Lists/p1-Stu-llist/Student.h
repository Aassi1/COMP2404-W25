#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    Student(string, string="Hey you!", string="basket-weaving", float=0.0f);
    ~Student();
    void print() const;
    bool lessThan(const Student&) const;
    bool matches(const string& name) const;

  private:
    const string number;
    string name;
    string majorPgm;
    float  gpa;
};

#endif
