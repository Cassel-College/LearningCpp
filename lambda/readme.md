[外部变量访问方式说明符] (参数) mutable noexcept/throw() -> 返回值类型
{
   函数体;
};


外部变量格式	功能
[]	空方括号表示当前 lambda 匿名函数中不导入任何外部变量。
[=]	只有一个 = 等号，表示以值传递的方式导入所有外部变量；
[&]	只有一个 & 符号，表示以引用传递的方式导入所有外部变量；
[val1,val2,...]	表示以值传递的方式导入 val1、val2 等指定的外部变量，同时多个变量之间没有先后次序；
[&val1,&val2,...]	表示以引用传递的方式导入 val1、val2等指定的外部变量，多个变量之间没有前后次序；
[val,&val2,...]	以上 2 种方式还可以混合使用，变量之间没有前后次序。
[=,&val1,...]	表示除 val1 以引用传递的方式导入外，其它外部变量都以值传递的方式导入。
[this]	表示以值传递的方式导入当前的 this 指针。