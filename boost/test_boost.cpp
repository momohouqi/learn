#include <iostream>
#include <boost/array.hpp>
#include <boost/any.hpp>
#include <vector>


void test_any()
{
    std::cout << "====Test boost::any" << std::endl;
    typedef std::vector<boost::any> Many;
    Many box;
    box.push_back(12);
    box.push_back("Hello");

    for(Many::const_iterator it(box.begin()); it != box.end(); ++it){
        std::cout << it->type().name() << ":" << std::endl;
    }
}

void test_array()
{
    std::cout << "====Test boost::array" << std::endl;
    boost::array<int, 10> ai = {1,2,3};
    for(size_t i = 0; i < ai.size(); ++i){
        std::cout << ai[i] << std::endl;
    }
}
int main(int argc, char* argv[])
{
    test_array();
    test_any();
    return 0;
}
