#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // int num[4] = {4, 2, 3, 1};

    std::vector<int> num = {4, 3, 2, 1};

    //对 a 数组中的元素进行排序

    auto func = [=](int x, int y) -> bool { return x < y; };

    sort(num.begin(), num.end(), func);
    for(int n : num){
        cout << n << " ";
    }
    return 0;
}