#pragma once
#include "Base.h"

class Teacher : public Base {
private:
    std::string fullName;
    std::string* groups;   // Динамический массив групп
    int groupsCount;
    std::string* subjects; // Динамический массив предметов
    int subjectsCount;

    void freeMemory();
    void copyFrom(const Teacher& other);

public:
    Teacher();
    Teacher(std::string fullName, std::string* gr, int grCnt, std::string* sub, int subCnt);
    Teacher(const Teacher& other);
    ~Teacher();

    Teacher& operator=(const Teacher& other);

    void print() const override;
    void readFromConsole() override;
    void edit() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    std::string getType() const override;
    Base* clone() const override;
};