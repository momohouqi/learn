#include <iostream>
#include "learnstl.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    LearnStl learn("First");
    learn.test_istream_iterator();
    learn.test_boost_array();
    learn.test_boost_format();
    learn.test_boost_shared_ptr();
    learn.test_boost_any();
    learn.test_boost_assign();
    learn.test_boost_lambda();
    std::cout << "Main done" << std::endl;
    return 0;
}

