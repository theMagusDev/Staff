#include "../include/Exception.h"
#include "../include/Factory.h"
#include "../include/ProjectManager.h"
#include "../include/Tester.h"
#include "../include/TeamLeader.h"
#include "../include/SeniorManager.h"
#include "../include/Driver.h"
#include "../include/Cleaner.h"
#include <iostream>
#include <fstream>

Project* findProject(std::vector<Project*> projects, int id) {
    for (Project* project : projects) {
        if (project->getId() == id) {
            return project;
        }
    }

    return nullptr;
}

Position determinePosition(const std::string& strPosition) {
    if (strPosition == "UNINITIALIZED") {
        return Position::UNINITIALIZED;
    }
    if (strPosition == "TEAM_LEADER") {
        return Position::TEAM_LEADER;
    }
    if (strPosition == "PROGRAMMER") {
        return Position::PROGRAMMER;
    }
    if (strPosition == "TESTER") {
        return Position::TESTER;
    }
    if (strPosition == "PROJECT_MANAGER") {
        return Position::PROJECT_MANAGER;
    }
    if (strPosition == "SENIOR_MANAGER") {
        return Position::SENIOR_MANAGER;
    }
    if (strPosition == "DRIVER") {
        return Position::DRIVER;
    }
    if (strPosition == "CLEANER") {
        return Position::CLEANER;
    }
}

std::vector<Employee *> Factory::makeStaff() {
    std::ifstream projectsData("../bd/projects_info.txt");
    std::vector<Project*> projects;
    int projectID = 0;
    int numberOfEmployees = 0;
    int budget = 0;

    std::ifstream staffData("../bd/staff_info.txt");
    std::vector<Employee*> staff;
    std::string name;
    int id = 0;
    int workTime = 0;
    int salary = 0;
    Position position;
    std::string strPosition;
    int bonusField;

    if (!projectsData.is_open()) {
        throw FileIOException("Error while opening projects data");
    }
    if (!staffData.is_open()) {
        throw FileIOException("Error while opening staff data");
    }

    std::string buffer;
    while (!projectsData.eof()) {
        getline(projectsData, buffer);
        if (!buffer.empty()) {
            projectID = atoi(buffer.c_str());
            getline(projectsData, buffer);
            budget = atoi(buffer.c_str());
            numberOfEmployees = atoi(buffer.c_str());
            getline(projectsData, buffer);
            projects.push_back(
                new Project(projectID, budget, numberOfEmployees)
            );
        }
    }

    int hourlyRate = -1;
    int projectInvolvedID = -1;
    int numberOfProjects = -1;
    std::vector<Project*> seniorManagerProjects;
    while (!staffData.eof()) {
        getline(staffData, buffer);
        if (!buffer.empty()) {
            id = atoi(buffer.c_str());
            getline(staffData, name);
            getline(staffData, strPosition);
            getline(staffData, buffer);
            workTime = atoi(buffer.c_str());
            position = determinePosition(strPosition);
            switch (position) {
                case Position::UNINITIALIZED:
                    std::cerr << "Uninitialized position in employee "
                    << name << ", can not create abstract class instance"
                    << std::endl;
                    break;
                case Position::TEAM_LEADER:
                    getline(staffData, buffer);
                    hourlyRate = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    bonusField = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    projectInvolvedID = atoi(buffer.c_str());
                    staff.push_back(
                        new TeamLeader(
                                id,
                                name,
                                hourlyRate,
                                workTime,
                                findProject(projects, projectInvolvedID),
                                bonusField
                        )
                    );
                    break;
                case Position::PROGRAMMER:
                    getline(staffData, buffer);
                    hourlyRate = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    bonusField = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    projectInvolvedID = atoi(buffer.c_str());
                    staff.push_back(
                            new Programmer(
                                    id,
                                    name,
                                    hourlyRate,
                                    workTime,
                                    findProject(projects, projectInvolvedID),
                                    bonusField
                            )
                    );
                    break;
                case Position::TESTER:
                    getline(staffData, buffer);
                    hourlyRate = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    bonusField = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    projectInvolvedID = atoi(buffer.c_str());
                    staff.push_back(
                            new Tester(
                                    id,
                                    name,
                                    hourlyRate,
                                    workTime,
                                    findProject(projects, projectInvolvedID),
                                    bonusField
                            )
                    );
                    break;
                case Position::PROJECT_MANAGER:
                    getline(staffData, buffer);
                    projectInvolvedID = atoi(buffer.c_str());
                    staff.push_back(
                            new ProjectManager(
                                    id,
                                    name,
                                    workTime,
                                    *findProject(projects, projectInvolvedID))
                    );
                    break;
                case Position::SENIOR_MANAGER:
                    getline(staffData, buffer);
                    numberOfProjects = atoi(buffer.c_str());
                    for (int i = 0; i < numberOfEmployees; i++) {
                        getline(staffData, buffer);
                        projectInvolvedID = atoi(buffer.c_str());
                        seniorManagerProjects.push_back(findProject(projects, projectInvolvedID));
                    }
                    staff.push_back(
                            new SeniorManager(
                                    id,
                                    name,
                                    workTime,
                                    seniorManagerProjects)
                    );
                    seniorManagerProjects.clear();
                    break;
                case Position::DRIVER:
                    getline(staffData, buffer);
                    hourlyRate = atoi(buffer.c_str());
                    getline(staffData, buffer);
                    bonusField = atoi(buffer.c_str());
                    staff.push_back(
                            new Driver(
                                    id,
                                    name,
                                    hourlyRate,
                                    bonusField,
                                    workTime)
                    );
                    break;
                case Position::CLEANER:
                    getline(staffData, buffer);
                    hourlyRate = atoi(buffer.c_str());
                    staff.push_back(
                            new Cleaner(
                                    id,
                                    name,
                                    hourlyRate,
                                    workTime)
                    );
                    break;
            }
        }
    }

    return staff;
}
