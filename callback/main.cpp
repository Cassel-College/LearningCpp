#include <iostream>
#include <functional>



void print(std::string info) 
{
    std::cout << info << std::endl;
}

int Callback_1()
{
    print("Hello, this is Callback_1 ");
    return 0;
}

int Handle(int (*Callback_function)())
{
    print("Entering Handle Function. ");
    Callback_function();
    print("Leaving Handle Function. ");
    return 0;
}


int function_has_parameter(int num)
{
    print("This function has one parameter.");
    print("num = " + std::to_string(num) + ".");
    return 0;
}



int handle_func(int num, int(*callback_function)(int))
{
    int return_code = 0;
    print("---------------------------------------");
    print("exec function");
    print("---------------------------------------");
    return_code = callback_function(num);
    print("---------------------------------------");
    return return_code;
}

typedef int (*CallbackFunction)(int);
int handle_func_use_typedef(int num, CallbackFunction callback_function)
{
    int return_code = 0;
    print("---------------------------------------");
    print("exec function");
    print("---------------------------------------");
    return_code = callback_function(num);
    print("---------------------------------------");
    return return_code;
}

typedef bool (* Func)(int, int);
bool handle_func_use_class_static_function(int num1, int num2, Func callback_function)
{
    bool return_code = false;
    print("---------------------------------------");
    print("exec function");
    print("---------------------------------------");
    return_code = callback_function(num1, num2);
    print("---------------------------------------");
    return return_code;
}

int func_used_in_class(int a, int b)
{
    print("This is function for number1 add number2.");
    print("number a = " + std::to_string(a));
    print("number b = " + std::to_string(b));
    print("return number was " + std::to_string(a + b));
    return a + b;
}

class Test
{
    public:
        Test()
        {
            print("create test!");
        }

        ~Test() 
        {
            print("Delete test.");
        }

        static bool check_num(int num_i, int num_ii)
        {
            print("Enter Test::check_num(int num_i, int num_ii) ...");
            bool key = false;
            print("num 1 = " + std::to_string(num_i) + ".");
            print("num 2 = " + std::to_string(num_ii) + ".");
            if (num_i == num_ii) {
                key == true;
                print("num1 == num2");
            } else{
                print("num1 != num2");
            } 
            return key;
        }

        void paly(int number1, int number2, bool(*callback_function)(int, int))
        {
            print("---------------------------------------");
            print("exec function in class's function");
            print("---------------------------------------");
            callback_function(number1, number2);
            print("---------------------------------------");
        }

        void paly001(int number1, int number2, int(*callback_function)(int, int))
        {
            print("---------------------------------------");
            print("exec function in class's function");
            print("---------------------------------------");
            callback_function(number1, number2);
            print("---------------------------------------");
        }

        void add_number(int number1, int number2)
        {
            print("Number 1 is:" + std::to_string(number1));
            print("Number 2 is:" + std::to_string(number2));
            print(std::to_string(number1) + " + " + std::to_string(number2) + " = " + std::to_string(number1 + number2) + ".");
        }

        void paly_function(int number1, int number2, std::function<void(int, int)> callback_funtion)
        {
            print("Exec function in paly_function(int number1, int number2, std::function<void(int, int)> callback_funtion)");
            callback_funtion(number1, number2);
            print("exec over!");
        }

        void paly_function_not_in_class(int number1, int number2, std::function<int(int, int)> callback_funtion)
        {
            print("Exec function in paly_function(int number1, int number2, std::function<int(int, int)> callback_funtion)");
            callback_funtion(number1, number2);
            print("exec over!");
        }
};


int main()
{
    print("Entering Main Function. ");
    Handle(Callback_1);
    print("Leaving Main Function. ");
    handle_func(5, function_has_parameter);
    handle_func_use_typedef(3, function_has_parameter);
    Test *test = new Test();
    handle_func_use_class_static_function(1, 2, Test::check_num);
    test->paly(2, 2, Test::check_num);
    test->paly001(2, 4, func_used_in_class);


    auto target_function_in_class = std::bind(&Test::add_number, test, std::placeholders::_2, std::placeholders::_1);
    target_function_in_class(12, 34);

    auto target_function = std::bind(func_used_in_class, std::placeholders::_1, std::placeholders::_2);
    auto number = target_function(12, 90);
    print(std::to_string(number));


    test->paly_function(55, 67, std::bind(&Test::add_number, test, std::placeholders::_1, std::placeholders::_2));
    test->paly_function_not_in_class(12, 66, std::bind(func_used_in_class, std::placeholders::_1, std::placeholders::_2));
    return 0;
}
