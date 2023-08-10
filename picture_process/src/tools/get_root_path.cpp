#include "get_root_path.h"

std::string RootPath::getRootPath() {
    return "/Users/pengliu/Code/LearningCpp/new_picture_process/";
}

void RootPath::setRootPath(const std::string& fileName) {
    this->rootPath = fileName;
}