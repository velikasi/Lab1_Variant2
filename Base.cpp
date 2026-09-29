#include "Base.h"

Base::Base() {
    std::cout << "[Base] Конструктор по умолчанию вызван.\n";
}

Base::Base(const Base& other) {
    std::cout << "[Base] Конструктор копирования вызван.\n";
}

Base::~Base() {
    std::cout << "[Base] Виртуальный деструктор вызван.\n";
}

Base& Base::operator=(const Base& other) {
    std::cout << "[Base] Оператор присваивания вызван.\n";
    return *this;
}