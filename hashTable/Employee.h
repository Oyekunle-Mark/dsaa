//
// Created by Oyekunle Oloyede on 18/10/2020.
//

#ifndef DSAA_EMPLOYEE_H
#define DSAA_EMPLOYEE_H

#include <string>
#include <utility>

class Employee {
public:
    explicit Employee(std::string name, double salary, std::size_t seniority)
            : name{std::move(name)}, salary{salary}, seniority{seniority} {}

    const std::string &getName() const {
        return name;
    }

    bool operator==(const Employee &rhs) const {
        return getName() == rhs.getName();
    }

    bool operator!=(const Employee &rhs) const {
        return !(*this == rhs);
    }

private:
    std::string name;
    double salary;
    std::size_t seniority;
};


#endif //DSAA_EMPLOYEE_H
