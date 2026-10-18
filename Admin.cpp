#include "Admin.h"

Admin::Admin() {
    std::cout << "[Admin] Конструктор по умолчанию вызван.\n";
}

Admin::Admin(std::string fullName, std::string pos, std::string phone, std::string resp)
    : fullName(fullName), position(pos), phone(phone), responsibility(resp) {
    std::cout << "[Admin] Конструктор с параметрами вызван.\n";
}

Admin::Admin(const Admin& other) : Base(other), fullName(other.fullName), position(other.position),
                                   phone(other.phone), responsibility(other.responsibility) {
    std::cout << "[Admin] Конструктор копирования вызван.\n";
}

Admin::~Admin() {
    std::cout << "[Admin] Деструктор вызван.\n";
}

void Admin::print() const {
    std::cout << "--- Админ. персонал ---\n"
              << "ФИО: " << fullName << "\n"
              << "Должность: " << position << "\n"
              << "Телефон: " << phone << "\n"
              << "Область ответственности: " << responsibility << "\n";
}

void Admin::readFromConsole() {
    std::cin.ignore();
    std::cout << "Введите ФИО: "; std::getline(std::cin, fullName);
    std::cout << "Введите должность: "; std::getline(std::cin, position);
    std::cout << "Введите телефон: "; std::cin >> phone;
    std::cin.ignore();
    std::cout << "Введите область ответственности: "; std::getline(std::cin, responsibility);
}

void Admin::edit() {
    std::cout << "Редактирование данных Админ. персонала:\n";
    readFromConsole();
}

void Admin::saveToFile(std::ofstream& out) const {
    out << "ADMIN\n" << fullName << "\n" << position << "\n" << phone << "\n" << responsibility << "\n";
}

void Admin::loadFromFile(std::ifstream& in) {
    in >> fullName >> position >> phone >> responsibility;
}

std::string Admin::getType() const { return "ADMIN"; }
Base* Admin::clone() const { return new Admin(*this); }