#include "Student.h"
#include <stdexcept>

Student::Student() : course(1), averageGrade(0.0) {
    std::cout << "[Student] Конструктор по умолчанию вызван.\n";
}

Student::Student(std::string fullName, std::string group, std::string spec, int course, double grade)
    : fullName(fullName), group(group), specialty(spec), course(course), averageGrade(grade) {
    std::cout << "[Student] Конструктор с параметрами вызван.\n";
}

Student::Student(const Student& other) : Base(other), fullName(other.fullName), group(other.group),
                                         specialty(other.specialty), course(other.course), averageGrade(other.averageGrade) {
    std::cout << "[Student] Конструктор копирования вызван.\n";
}

Student::~Student() {
    std::cout << "[Student] Деструктор вызван.\n";
}

void Student::setCourse(int c) {
    if (c < 1 || c > 6) throw std::invalid_argument("Курс должен быть от 1 до 6.");
    course = c;
}

void Student::setAverageGrade(double g) {
    if (g < 0.0 || g > 5.0) throw std::invalid_argument("Средний балл должен быть от 0.0 до 5.0.");
    averageGrade = g;
}

void Student::print() const {
    std::cout << "--- Студент ---\n"
              << "ФИО: " << fullName << "\n"
              << "Группа: " << group << "\n"
              << "Специальность: " << specialty << "\n"
              << "Курс: " << course << "\n"
              << "Средний балл: " << averageGrade << "\n";
}

void Student::readFromConsole() {
    std::cin.ignore();
    std::cout << "Введите ФИО студента: "; std::getline(std::cin, fullName);
    std::cout << "Введите группу: "; std::cin >> group;
    std::cin.ignore();
    std::cout << "Введите специальность: "; std::getline(std::cin, specialty);
    std::cout << "Введите курс: "; std::cin >> course;
    std::cout << "Введите средний балл: "; std::cin >> averageGrade;
}

void Student::edit() {
    std::cout << "Редактирование данных Студента:\n";
    readFromConsole();
}

void Student::saveToFile(std::ofstream& out) const {
    out << "STUDENT\n" << fullName << "\n" << group << "\n" << specialty << "\n" << course << "\n" << averageGrade << "\n";
}

void Student::loadFromFile(std::ifstream& in) {
    in >> fullName >> group >> specialty >> course >> averageGrade;
}

std::string Student::getType() const { return "STUDENT"; }
Base* Student::clone() const { return new Student(*this); }