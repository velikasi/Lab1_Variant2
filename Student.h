#pragma once
#include "Base.h"

class Student : public Base {
private:
    std::string fullName;
    std::string group;
    std::string specialty;
    int course;
    double averageGrade;

public:
    Student();
    Student(std::string fullName, std::string group, std::string spec, int course, double grade);
    Student(const Student& other);
    ~Student();

    void print() const override;
    void readFromConsole() override;
    void edit() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    std::string getType() const override;
    Base* clone() const override;

    void setCourse(int c);
    void setAverageGrade(double g);
};