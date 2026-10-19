#include "Keeper.h"
#include <fstream>

Keeper::Keeper() : size(0), capacity(2) {
    items = new Base*[capacity];
    std::cout << "[Keeper] Конструктор по умолчанию вызван.\n";
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    items = new Base*[capacity];
    for (int i = 0; i < size; ++i) {
        items[i] = other.items[i]->clone(); // Глубокое копирование
    }
    std::cout << "[Keeper] Конструктор копирования вызван.\n";
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
    std::cout << "[Keeper] Деструктор вызван. Память освобождена.\n";
}

Keeper& Keeper::operator=(const Keeper& other) {
    std::cout << "[Keeper] Оператор присваивания вызван.\n";
    if (this != &other) {
        for (int i = 0; i < size; ++i) delete items[i];
        delete[] items;

        size = other.size;
        capacity = other.capacity;
        items = new Base*[capacity];
        for (int i = 0; i < size; ++i) {
            items[i] = other.items[i]->clone();
        }
    }
    return *this;
}

void Keeper::resize(int newCapacity) {
    Base** newItems = new Base*[newCapacity];
    for (int i = 0; i < size; ++i) {
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

void Keeper::add(Base* item) {
    if (!item) throw KeeperException("Ошибка: попытка добавить нулевой указатель.");
    if (size == capacity) {
        resize(capacity * 2);
    }
    items[size++] = item;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) {
        throw KeeperException("Ошибка: индекс вне диапазона при удалении.");
    }
    delete items[index];
    for (int i = index; i < size - 1; ++i) {
        items[i] = items[i + 1];
    }
    size--;
}

void Keeper::editItem(int index) {
    if (index < 0 || index >= size) {
        throw KeeperException("Ошибка: индекс вне диапазона при редактировании.");
    }
    items[index]->edit();
}

void Keeper::printAll() const {
    if (size == 0) {
        std::cout << "Список пуст.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "Запись #" << i + 1 << ":\n";
        items[i]->print();
        std::cout << "-------------------\n";
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw KeeperException("Ошибка: не удалось открыть файл для записи: " + filename);
    }
    out << size << "\n";
    for (int i = 0; i < size; ++i) {
        items[i]->saveToFile(out);
    }
    out.close();
    std::cout << "Данные успешно сохранены в файл " << filename << "\n";
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw KeeperException("Ошибка: файл не найден или не может быть открыт: " + filename);
    }
    
    // Очищаем текущие данные
    for (int i = 0; i < size; ++i) delete items[i];
    size = 0;

    int count;
    in >> count;
    in.ignore(); 

    for (int i = 0; i < count; ++i) {
        std::string type;
        in >> type;
        if (type == "STUDENT") {
            Student* s = new Student();
            s->loadFromFile(in);
            add(s);
        } else if (type == "TEACHER") {
            Teacher* t = new Teacher();
            t->loadFromFile(in);
            add(t);
        } else if (type == "ADMIN") {
            Admin* a = new Admin();
            a->loadFromFile(in);
            add(a);
        }
    }
    in.close();
    std::cout << "Данные успешно загружены из файла " << filename << "\n";
}