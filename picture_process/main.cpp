#include <iostream>
#include <fstream>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <cstdlib> 
#include <string>
#include <map>
#include <algorithm>
#include <memory>

#include "src/cases/cases_001/running_001.h"
#include "src/cases/cases_002/running_002.h"
#include "src/cases/cases_003/running_003.h"
#include "src/cases/cases_004/running_004.h"
#include "src/cases/cases_005/running_005.h"
#include "src/cases/cases_006/running_006.h"
#include "src/cases/cases_007/running_007.h"
#include "src/cases/cases_008/running_008.h"
#include "src/cases/cases_009/running_009.h"
#include "src/cases/cases_010/running_010.h"

using namespace std;

void ShowInfo(const std::string &info) {
    std::cout << info << std::endl;
}

void __inline__ ShowUserInformation(const std::vector<std::string> &infos) {
    for (auto item : infos) {
        ShowInfo(item);
    }
}

std::string get_root_path() {
    return "/Users/pengliu/Code/LearningCpp/new_picture_process";
}

std::string get_path(const std::string &path_name) {
    std::string path = "";
    std::map<std::string, std::string> myMap;
    myMap.insert(std::make_pair("welcome_sweet_system", "/config/welcome_sweet_system.txt"));
    myMap.insert(std::make_pair("user_interface", "/config/user_interface.txt"));
    myMap.insert(std::make_pair("shutdown_system", "/config/shutdown_system.txt"));
    myMap.insert(std::make_pair("clean_terminal", "/config/clean_terminal.txt"));
    myMap.insert(std::make_pair("user_input", "/config/user_input.txt"));
    myMap.insert(std::make_pair("function_run_over", "/config/function_run_over.txt"));
    myMap.insert(std::make_pair("line", "/config/line.txt"));
    myMap.insert(std::make_pair("inner_line", "/config/inner_line.txt"));
    myMap.insert(std::make_pair("not_dev", "/config/not_dev.txt"));
    myMap.insert(std::make_pair("no_task", "/config/homework/no_task.txt"));
    myMap.insert(std::make_pair("task_001", "/config/homework/task_001.txt"));
    myMap.insert(std::make_pair("task_002", "/config/homework/task_002.txt"));
    myMap.insert(std::make_pair("task_003", "/config/homework/task_003.txt"));
    myMap.insert(std::make_pair("task_004", "/config/homework/task_004.txt"));
    myMap.insert(std::make_pair("task_005", "/config/homework/task_005.txt"));
    myMap.insert(std::make_pair("task_006", "/config/homework/task_006.txt"));
    myMap.insert(std::make_pair("task_007", "/config/homework/task_007.txt"));
    myMap.insert(std::make_pair("task_008", "/config/homework/task_008.txt"));
    myMap.insert(std::make_pair("task_009", "/config/homework/task_009.txt"));
    myMap.insert(std::make_pair("task_010", "/config/homework/task_010.txt"));
    myMap.insert(std::make_pair("task_qqq", "/config/homework/task_qqq.txt"));
    myMap.insert(std::make_pair("split_red_picture", "/config/info/split_red_picture.txt"));
    myMap.insert(std::make_pair("split_green_picture", "/config/info/split_green_picture.txt"));
    myMap.insert(std::make_pair("split_blue_picture", "/config/info/split_blue_picture.txt"));
    if (myMap.count(path_name) == 0) {
        std::cout << "Element with key " << path_name << " not found\n";
    } else {
        path = get_root_path() + "/" + myMap.find(path_name)->second;
    }
    return path;
}

std::vector<std::string> read_config_file(const std::string &file_path) {
    std::ifstream file(file_path);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

void init() {
    ShowUserInformation(read_config_file(get_path("user_interface")));
}


std::string get_task_name(const std::string &input_id) {
    std::string task_name  = "";
    if (input_id == "1") {
        task_name = "task_001";
    } else if (input_id == "2") {
        task_name = "task_002";
    } else if (input_id == "3") {
        task_name = "task_003";
    } else if (input_id == "4") {
        task_name = "task_004";
    } else if (input_id == "5") {
        task_name = "task_005";
    } else if (input_id == "6") {
        task_name = "task_006";
    } else if (input_id == "7") {
        task_name = "task_007";
    } else if (input_id == "8") {
        task_name = "task_008";
    } else if (input_id == "9") {
        task_name = "task_009";
    } else if (input_id == "10") {
        task_name = "task_010";
    } else if (input_id == "0") {
        task_name = "task_000";
    } else if (input_id == "q") {
        task_name = "task_qqq";
    } 
    return task_name;
}

void ShowTaskInfo(const std::string &func_id) {
    ShowUserInformation(read_config_file(get_path("line")));
    ShowUserInformation(read_config_file(get_path(get_task_name(func_id))));
    ShowUserInformation(read_config_file(get_path("line")));
}

int ExecTesk(const std::string &func_id) {
    ShowTaskInfo(func_id);
    if (func_id == "1") {
        std::shared_ptr<Exec001> execution_001 = std::make_shared<Exec001>();
	    execution_001->run();
    } else if (func_id == "2") {
        std::shared_ptr<Exec002> execution_002 = std::make_shared<Exec002>();
	    execution_002->run();
    } else if (func_id == "3") {
        std::shared_ptr<Exec003> execution_003 = std::make_shared<Exec003>();
	    execution_003->run();
    } else if (func_id == "4") {
        std::shared_ptr<Exec004> execution_004 = std::make_shared<Exec004>();
	    execution_004->run();
    } else if (func_id == "5") {
        std::shared_ptr<Exec005> execution_005 = std::make_shared<Exec005>();
	    execution_005->run();
    } else if (func_id == "6") {
        std::shared_ptr<Exec006> execution_006 = std::make_shared<Exec006>();
	    execution_006->run();
    } else if (func_id == "7") {
        std::shared_ptr<Exec007> execution_007 = std::make_shared<Exec007>();
	    execution_007->run();
    } else if (func_id == "8") {
        std::shared_ptr<Exec008> execution_008 = std::make_shared<Exec008>();
	    execution_008->run();
    } else if (func_id == "9") {
        std::shared_ptr<Exec009> execution_009 = std::make_shared<Exec009>();
	    execution_009->run();
    } else if (func_id == "10") {
        std::shared_ptr<Exec010> execution_010 = std::make_shared<Exec010>();
	    execution_010->run();
    } else if (func_id == "0") {
		std::shared_ptr<Exec001> execution_001 = std::make_shared<Exec001>();
        execution_001->run();
        std::shared_ptr<Exec002> execution_002 = std::make_shared<Exec002>();
        execution_002->run();
        std::shared_ptr<Exec003> execution_003 = std::make_shared<Exec003>();
        execution_003->run();
        std::shared_ptr<Exec004> execution_004 = std::make_shared<Exec004>();
        execution_004->run();
        std::shared_ptr<Exec005> execution_005 = std::make_shared<Exec005>();
        execution_005->run();
        std::shared_ptr<Exec006> execution_006 = std::make_shared<Exec006>();
        execution_006->run();
        std::shared_ptr<Exec007> execution_007 = std::make_shared<Exec007>();
        execution_007->run();
        std::shared_ptr<Exec008> execution_008 = std::make_shared<Exec008>();
        execution_008->run();
        std::shared_ptr<Exec009> execution_009 = std::make_shared<Exec009>();
        execution_009->run();
        std::shared_ptr<Exec010> execution_010 = std::make_shared<Exec010>();
        execution_010->run();
    } else if (func_id == "q") {
        return 0;
    }
    ShowUserInformation(read_config_file(get_path("function_run_over")));
    return 1;
}


void SweetSystem() {
    ShowUserInformation(read_config_file(get_path("welcome_sweet_system")));
    std::string has_next_command = "y";
    transform(has_next_command.begin(),has_next_command.end(),has_next_command.begin(),::toupper);
    while(has_next_command == "Y" || has_next_command == "YES") {
        ShowUserInformation(read_config_file(get_path("user_interface")));
        ShowUserInformation(read_config_file(get_path("user_input")));
        std::string func_id = "1";
        std::cin >> func_id;
        std::string task_name = get_task_name(func_id);
        if (task_name == "") {
            ShowUserInformation(read_config_file(get_path("no_task")));
            continue;
        }
        int r = ExecTesk(func_id);
        if (r == 0) {
            return;
        }
        std::cin >> has_next_command;
        transform(has_next_command.begin(),has_next_command.end(),has_next_command.begin(),::toupper);
        if (has_next_command == "Y" || has_next_command == "YES") {
            ShowUserInformation(read_config_file(get_path("clean_terminal")));
        }
    }
    ShowUserInformation(read_config_file(get_path("shutdown_system")));
}


int main()
{
    SweetSystem();
}