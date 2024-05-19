#include "../include/Factory.h"
#include "../include/Project.h"
#include <iostream>
#include <fstream>

std::vector<Employee *> Factory::makeStaff() {
    std::ifstream projectsData("projects_info.txt");
    std::vector<Project*> projects;

}

/*
std::vector<Employee *> Factory_Staff::make_staff() {
    std::ifstream data_Projects("projects_info.txt");
    std::vector<Project *> projects;
    int project_Id = 0;
    int number_of_employees = 0;
    int budget = 0;

    std::ifstream data_Staff("staff_info.txt");
    std::string name;
    int id = 0;
    int work_time = 0;
    int salary = 0;
    std::string posVal;
    if (!data_Staff.is_open()) {
        throw "no open dataS";
    }
    if (!data_Projects.is_open()) {
        throw "no open dataP";
    }
    std::string templ;
    while (!data_Projects.eof()) {
        getline(data_Projects, templ);
        if (!templ.empty()) {
            project_Id = atoi(templ.c_str());
            getline(data_Projects, templ);
            budget = atoi(templ.c_str());
            getline(data_Projects, templ);
            number_of_employees = atoi(templ.c_str());
            projects.push_back(new Project(project_Id, budget,
                                           number_of_employees));
        }
    }

    std::vector<Employee *> staff;
    std::cout << std::endl;
    while (!data_Staff.eof()) {
        getline(data_Staff, templ);
        if (!templ.empty()) {
            id = atoi(templ.c_str());
            getline(data_Staff, name);
            getline(data_Staff, templ);
            work_time = atoi(templ.c_str());
            getline(data_Staff, templ);
            salary = atoi(templ.c_str());
            getline(data_Staff, posVal);
            getline(data_Staff, templ);
            project_Id = atoi(templ.c_str());
            staff.push_back(
                    make_employee(id, name, work_time, salary, posVal,
                                  project_Id, projects));
        }
    }
    return staff;
}
 */