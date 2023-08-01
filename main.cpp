#include <iostream>

#include "menu.h"

bool test1();
bool test2();
bool subMenu();

int main()
{
    menu("MAIN MENU",
         {
            {"Test 1", test1},
            {"Test 2", test2},
            {"SubMenu", subMenu},
         });
    return 0;
}

// ---

bool test1()
{
    std::cout << "test 1" << std::endl;
    return true;
}

bool test2()
{
    std::cout << "test two" << std::endl;
    return false;
}

bool test3();
bool test4();

bool subMenu()
{
    return menu("SubMenu",
                {
                    {"Test 3", test3},
                    {"Test 4", test4},
                });
}

bool test3()
{
    std::cout << "test さん" << std::endl;
    return true;
}

bool test4()
{
    std::cout << "test 四" << std::endl;
    return false;
}
