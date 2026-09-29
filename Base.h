#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Base {
public:
    Base();
    Base(const Base& other);
    virtual ~Base();

    virtual void print() const = 0;
    virtual void readFromConsole() = 0;
    virtual void edit() = 0; // Изменение данных
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void loadFromFile(std::ifstream& in) = 0;
    virtual std::string getType() const = 0;
    virtual Base* clone() const = 0;

    Base& operator=(const Base& other);
};