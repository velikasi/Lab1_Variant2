#pragma once
#include "Base.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include <exception>

// Класс собственного исключения
class KeeperException : public std::exception {
    std::string message;
public:
    KeeperException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class Keeper {
private:
    Base** items; // Динамический массив указателей на базовый класс
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    Keeper& operator=(const Keeper& other);

    void add(Base* item);
    void remove(int index);
    void editItem(int index);
    void printAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    int getSize() const { return size; }
};