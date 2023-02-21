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

int main() {
    
    std::shared_ptr<std::vector<std::shared_ptr<Student>>> students_ptr = 
        std::make_shared<std::vector<std::shared_ptr<Student>>>();

    students_ptr->push_back(shared_ptr<Student>(new Student(1, "Alice")));
    students_ptr->push_back(shared_ptr<Student>(new Student(2, "Bob")));
    students_ptr->push_back(make_shared<Student>(3, "Charlie"));
    students_ptr->push_back(make_shared<Student>(4, "David"));

    show(students_ptr);
    paly(students_ptr);
    show(students_ptr);
    return 0;
}

int main1() {
    // 创建一个vector<shared_ptr<Student>>
    std::vector<std::shared_ptr<Student>> students;

    // 使用构造函数初始化shared_ptr对象，并添加到vector中
    students.push_back(shared_ptr<Student>(new Student(1, "Alice")));
    students.push_back(shared_ptr<Student>(new Student(2, "Bob")));

    // 使用make_shared函数初始化shared_ptr对象，并添加到vector中
    students.push_back(make_shared<Student>(3, "Charlie"));
    students.push_back(make_shared<Student>(4, "David"));

    // 遍历vector并打印每个学生的信息
    for (auto& s : students) {
        cout << s->id << " " << s->name << endl;
    }

    return 0;
}
