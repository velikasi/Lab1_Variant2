#include "Teacher.h"
#include <stdexcept>

Teacher::Teacher() : groups(nullptr), groupsCount(0), subjects(nullptr), subjectsCount(0) {
    std::cout << "[Teacher] Конструктор по умолчанию вызван.\n";
}

Teacher::Teacher(std::string fullName, std::string* gr, int grCnt, std::string* sub, int subCnt)
    : fullName(fullName), groupsCount(grCnt), subjectsCount(subCnt) {
    std::cout << "[Teacher] Конструктор с параметрами вызван.\n";
    groups = new std::string[groupsCount];
    for (int i = 0; i < groupsCount; ++i) groups[i] = gr[i];
    subjects = new std::string[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) subjects[i] = sub[i];
}

Teacher::Teacher(const Teacher& other) : Base(other), fullName(other.fullName), groupsCount(other.groupsCount), subjectsCount(other.subjectsCount) {
    std::cout << "[Teacher] Конструктор копирования вызван.\n";
    copyFrom(other);
}

Teacher::~Teacher() {
    freeMemory();
    std::cout << "[Teacher] Деструктор вызван.\n";
}

Teacher& Teacher::operator=(const Teacher& other) {
    std::cout << "[Teacher] Оператор присваивания вызван.\n";
    if (this != &other) {
        Base::operator=(other);
        freeMemory();
        fullName = other.fullName;
        groupsCount = other.groupsCount;
        subjectsCount = other.subjectsCount;
        copyFrom(other);
    }
    return *this;
}

void Teacher::freeMemory() {
    delete[] groups;
    delete[] subjects;
    groups = nullptr;
    subjects = nullptr;
}

void Teacher::copyFrom(const Teacher& other) {
    groups = new std::string[groupsCount];
    for (int i = 0; i < groupsCount; ++i) groups[i] = other.groups[i];
    
    subjects = new std::string[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) subjects[i] = other.subjects[i];
}

void Teacher::print() const {
    std::cout << "--- Преподаватель ---\n"
              << "ФИО: " << fullName << "\n"
              << "Группы: ";
    for (int i = 0; i < groupsCount; ++i) std::cout << groups[i] << " ";
    std::cout << "\nПредметы: ";
    for (int i = 0; i < subjectsCount; ++i) std::cout << subjects[i] << " ";
    std::cout << "\n";
}

void Teacher::readFromConsole() {
    std::cin.ignore();
    std::cout << "Введите ФИО преподавателя: "; std::getline(std::cin, fullName);
    
    std::cout << "Введите количество групп: "; std::cin >> groupsCount;
    if (groupsCount < 0) throw std::invalid_argument("Количество групп не может быть отрицательным.");
    freeMemory(); 
    groups = new std::string[groupsCount];
    for (int i = 0; i < groupsCount; ++i) {
        std::cout << "Введите группу " << i + 1 << ": "; std::cin >> groups[i];
    }

    std::cout << "Введите количество предметов: "; std::cin >> subjectsCount;
    if (subjectsCount < 0) throw std::invalid_argument("Количество предметов не может быть отрицательным.");
    subjects = new std::string[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) {
        std::cout << "Введите предмет " << i + 1 << ": "; std::cin >> subjects[i];
    }
}

void Teacher::edit() {
    std::cout << "Редактирование данных Преподавателя:\n";
    readFromConsole();
}

void Teacher::saveToFile(std::ofstream& out) const {
    out << "TEACHER\n" << fullName << "\n" << groupsCount << "\n";
    for (int i = 0; i < groupsCount; ++i) out << groups[i] << "\n";
    out << subjectsCount << "\n";
    for (int i = 0; i < subjectsCount; ++i) out << subjects[i] << "\n";
}

void Teacher::loadFromFile(std::ifstream& in) {
    in >> fullName >> groupsCount;
    freeMemory();
    groups = new std::string[groupsCount];
    for (int i = 0; i < groupsCount; ++i) in >> groups[i];
    
    in >> subjectsCount;
    subjects = new std::string[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) in >> subjects[i];
}

std::string Teacher::getType() const { return "TEACHER"; }
Base* Teacher::clone() const { return new Teacher(*this); }