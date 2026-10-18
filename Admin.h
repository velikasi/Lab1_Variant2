#pragma once
#include "Base.h"

class Admin : public Base {
private:
    std::string fullName;
    std::string position;
    std::string phone;
    std::string responsibility;

public:
    Admin();
    Admin(std::string fullName, std::string pos, std::string phone, std::string resp);
    Admin(const Admin& other);
    ~Admin();

    void print() const override;
    void readFromConsole() override;
    void edit() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    std::string getType() const override;
    Base* clone() const override;
};