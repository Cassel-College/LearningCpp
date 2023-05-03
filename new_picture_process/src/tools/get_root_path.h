#include<iostream>
#include<string>

class RootPath {
    
public:
    static std::string getRootPath();

    void setRootPath(const std::string& fileName);

private:

    std::string rootPath = "/Users/pengliu/Code/LearningCpp/new_picture_process/";

};