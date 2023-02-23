#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Student {
public:
  Student(int id, string name) : id(id), name(name) {}
  int id;
  string name;
};

void paly(std::shared_ptr<std::vector<std::shared_ptr<Student>>> students_ptr) {
    
    for (auto& s : *students_ptr) {
        cout << s->id << " " << s->name << endl;
        s->id = 1;
    }

}

void show(std::shared_ptr<std::vector<std::shared_ptr<Student>>> students_ptr) {

    for (auto s : *students_ptr) {
        cout << s->id << " " << s->name << endl;
    }
}

void demo(std::shared_ptr<std::vector<std::shared_ptr<Student>>> students_ptr) {

    std::string func_name = "demo";
    std::cout << "--------------------------" << func_name << "--------------------------" << std::endl;
    for (auto s : *students_ptr) {
        // cout << s->id << " " << s->name << endl;
        std::cout << "... " << (*s).id << std::endl;
    }
    std::cout << "--------------------------over--------------------------" << std::endl;
}

void test_const_core(Student *const student) {
    std::string func_name = "test_const_core";
    std::cout << "--------------------------" << func_name << "--------------------------" << std::endl;
    std::cout << "... " << student->id << std::endl;
    std::cout << "--------------------------over--------------------------" << std::endl;
}

void test_const(std::shared_ptr<std::vector<std::shared_ptr<Student>>> students_ptr) {
    std::string func_name = "test_const";
    std::cout << "--------------------------" << func_name << "--------------------------" << std::endl;
    for (auto s : *students_ptr) {
        test_const_core(s.get());
        std::cout << "... " << s->id << std::endl;
        break;
    }
    std::cout << "--------------------------over--------------------------" << std::endl;
}

int main() {
    
    std::shared_ptr<std::vector<std::shared_ptr<Student>>> students_ptr = 
        std::make_shared<std::vector<std::shared_ptr<Student>>>();

    students_ptr->push_back(shared_ptr<Student>(new Student(1, "Alice")));
    students_ptr->push_back(shared_ptr<Student>(new Student(2, "Bob")));
    students_ptr->push_back(make_shared<Student>(3, "Charlie"));
    students_ptr->push_back(make_shared<Student>(4, "David"));

    show(students_ptr);
    test_const(students_ptr);
    demo(students_ptr);
    paly(students_ptr);
    show(students_ptr);

    demo(students_ptr);
    return 0;
}