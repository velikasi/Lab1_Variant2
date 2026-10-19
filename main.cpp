#include <iostream>
#include "Keeper.h"
#include <limits>
#include <windows.h>


int main() 
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    Keeper university;
    int choice;
    std::string filename = "university_data.txt";

    do {
        std::cout << "\n=== МЕНЮ ВУЗА ===\n"
                  << "1. Добавить Студента\n"
                  << "2. Добавить Преподавателя\n"
                  << "3. Добавить Админ. персонал\n"
                  << "4. Вывести все данные\n"
                  << "5. Редактировать запись\n"
                  << "6. Удалить запись\n"
                  << "7. Сохранить в файл\n"
                  << "8. Загрузить из файла\n"
                  << "0. Выход\n"
                  << "Ваш выбор: ";
        
        if (!(std::cin >> choice)) {

            std::cout << "Ошибка ввода. Введите число.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    Student* s = new Student();
                    s->readFromConsole();
                    university.add(s);
                    break;
                }
                case 2: {
                    Teacher* t = new Teacher();
                    t->readFromConsole();
                    university.add(t);
                    break;
                }
                case 3: {
                    Admin* a = new Admin();
                    a->readFromConsole();
                    university.add(a);
                    break;
                }
                case 4: {
                    university.printAll();
                    break;
                }
                case 5: {
                    int index;
                    std::cout << "Введите номер записи для редактирования (от 1 до " << university.getSize() << "): ";
                    std::cin >> index;
                    university.editItem(index - 1);
                    std::cout << "Запись изменена.\n";
                    break;
                }
                case 6: {
                    int index;
                    std::cout << "Введите номер записи для удаления (от 1 до " << university.getSize() << "): ";
                    std::cin >> index;
                    university.remove(index - 1);
                    std::cout << "Запись удалена.\n";
                    break;
                }
                case 7: {
                    university.saveToFile(filename);
                    break;
                }
                case 8: {
                    university.loadFromFile(filename);
                    break;
                }
                case 0: {
                    std::cout << "Завершение работы программы...\n";
                    break;
                }
                default: {
                    std::cout << "Неверный пункт меню. Попробуйте снова.\n";
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Исключение: " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}