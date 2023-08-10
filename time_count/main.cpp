
// #include <iostream>
// #include <chrono>
// #include <ctime>
// #include <unistd.h>

// int main() {
//     // Get the current time using std::chrono::system_clock::now ()
//     auto now = std::chrono::system_clock::now ();
//     // Convert the current time to a time_t object
//     std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);


//     sleep(2);
//     auto now1 = std::chrono::system_clock::now ();
//     std::time_t now_time_t1 = std::chrono::system_clock::to_time_t(now1);


//     // Calculate the difference in seconds
//     double diff_seconds = std::difftime(now_time_t1, now_time_t);

//     // Print the difference in seconds
//     std::cout << "The difference is " << diff_seconds << " seconds." << std::endl;

//     // Convert the current time to a string
//     char* now_str = std::ctime(&now_time_t);

//     // Print the current time
//     std::cout << "The current time is: " << now_str << std::endl;

//     return 0;
// }

#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>


// int main() {
//     auto now = std::chrono::system_clock::now();
//     auto now_c = std::chrono::system_clock::to_time_t(now);
//     std::tm* now_tm = std::localtime(&now_c);;
//     std::stringstream ss;
//     ss << std::put_time(now_tm, "%Y%m%d%H%M%S");
//     std::string s = ss.str();
//     std::cout << s << std::endl;
//     // std::cout << std::put_time(now_tm, "%Y%m%d%H%M%S") << '\n';
//     return 0;
// }


std::string GetNowDateTime() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);
    std::stringstream ss;
    ss << std::put_time(now_tm, "%Y%m%d%H%M%S");
    std::string s = ss.str();
    return s;
}

int GetDiffSeconds(std::string old_time, std::string now_time) {
    std::tm tm = {};
    std::istringstream ss(old_time);
    ss >> std::get_time(&tm, "%Y%m%d%H%M%S");
    auto timestamp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto now = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - timestamp);
    std::cout << "时间差为 " << diff.count() << " 秒" << std::endl;
    return 0;
}

int main() {
    std::string old_time = "";
    if (old_time == "") {
        old_time = "20230526185552";
    }
    std::string new_time = GetNowDateTime();

    GetDiffSeconds(old_time, new_time);
}


// int main() {
//     std::tm tm = {};
//     std::string old_time = "20230526185552";
//     std::istringstream ss(old_time);
//     ss >> std::get_time(&tm, "%Y%m%d%H%M%S");
//     auto timestamp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
//     auto now = std::chrono::system_clock::now();
//     auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - timestamp);
//     std::cout << "时间差为 " << diff.count() << " 秒" << std::endl;
//     return 0;
// }





