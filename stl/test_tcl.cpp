#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <boost/any.hpp>


void test_any()
{
    typedef std::vector<boost::any> Many;
    Many box;
    box.push_back(12);
    box.push_back("Hello");

    for(Many::const_iterator it(box.begin()); it != box.end(); ++it){
        std::cout << it->type().name() << ":" << std::endl;
    }
}
int main(int argc, char* argv[])
{
    std::vector<std::string> vectorStrs;
    typedef std::map<std::string, int> MapStringIntType;

    MapStringIntType mapWordCount;

    for(int i = 0; i< argc; ++i){
        vectorStrs.push_back(argv[i]);
        mapWordCount[argv[i]]++;
    }

    for(MapStringIntType::const_iterator it(mapWordCount.begin());
            it != mapWordCount.end();
            ++it){
        std::cout << it->first << ":" << it->second <<std::endl;
    }
    std::cout << "test boost::any" << std::endl;
    test_any();
}
