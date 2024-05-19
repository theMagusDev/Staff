#include <iostream>
#include "../include/Factory.h"
#include "../include/ProjectManager.h"
#include "../include/Tester.h"
#include "../include/TeamLeader.h"
#include "../include/SeniorManager.h"
#include "../include/Driver.h"
#include "../include/Cleaner.h"

int main() {
    std::vector<Employee*> staff = Factory::makeStaff();


    return 0;
}

