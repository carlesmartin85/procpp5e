import <iostream>;

namespace mycode
{
    void foo()
    {
        std::cout << "Call from inside namespace mycode" << std::endl;
    }
}

void foo()
{
    std::cout << "Call from outside namespace mycode" << std::endl;
}

//using mycode::foo;

int main()
{
    mycode::foo();
    foo();
}