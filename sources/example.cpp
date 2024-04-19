
#include <iostream>

#include "example.h"


std::string dummy_function()
{
    std::string tmp_string = "Hello from ";
    tmp_string.append(__FUNCTION__);

    return tmp_string;
}
