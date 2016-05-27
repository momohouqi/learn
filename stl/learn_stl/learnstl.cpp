#include "learnstl.h"
#include <iostream> // std::cout
#include <iterator> // std::istream_iterator
#include <boost/array.hpp> // boost::array
#include <algorithm> // for_each
#include <boost/format.hpp> // boost::format
#include <boost/shared_ptr.hpp> // boost::format
#include <vector>
#include <boost/any.hpp>
#include <list> // std::list
#include <boost/assign/std/vector.hpp> // for operator +=
#include <map>
#include <deque>
#include <boost/foreach.hpp>
#include <boost/lambda/lambda.hpp>

int LearnStl::m_nLearnIndex = 0;
LearnStl::LearnStl(const std::string str): m_strName(str)
{
    ++m_nLearnIndex;
    std::cout << boost::format("%1% born. instance%2%") % m_strName % m_nLearnIndex << std::endl;
}

LearnStl::~LearnStl()
{
    --m_nLearnIndex;
    std::cout << boost::format("%2% leave. instance%1%") % m_nLearnIndex % m_strName << std::endl;
}

void LearnStl::declare(const std::string content)
{
    std::cout << std::endl;
    std::cout << "===" << content << "===" << std::endl;
}

void LearnStl::test_istream_iterator()
{
    declare("istream_iterator");
    std::cout << "input 2 values:";
    std::istream_iterator<double> itend;
    //std::cout << "after define itend" << std::endl;
    // This will wait user to input for the first construction time.
    std::istream_iterator<double> itinput(std::cin);
    //std::cout << "after define itinput" << std::endl;

    double value0, value1;
    if(itinput != itend){
       value0 = *itinput;
    }
    //std::cout << "after value=*itinput" << std::endl;
    // This will wait user to input for the 2 time when increase the istream_iterator.
    ++itinput;
    //std::cout << "after ++itinput" << std::endl;
    if(itinput != itend){
       value1 = *itinput;
    }
    std::cout << value0 << "*" << value1 << "=" << value0 * value1 <<std::endl;
}

typedef std::pair<std::string, std::string> StrPair;
struct MyPrintObject{

    template <typename T>
    void operator()(T e) {std::cout << e << "-";}

    void operator()(StrPair &e)
    {
        std::cout << e.first << "-" << e.second << ",";
    }

    void operator()(boost::any& e)
    {
        // When use boost::any_cast<int*>(&e), it allways return null, even input a int.
        if(e.type() == typeid(int))
            std::cout << boost::format("%1%") % boost::any_cast<const int>(e);
        else if(boost::any_cast<const char*>(&e))
            std::cout << boost::format("%1%") % boost::any_cast<const char*>(e);
        else
            std::cout << "any_cast error" << ",";
    }
};

void LearnStl::test_boost_array()
{
    declare("boost::array--for_each__function object");
    boost::array<int, 10> ba = {0,1,2};
    std::for_each(ba.begin(), ba.end(), MyPrintObject());
}

void LearnStl::test_boost_format()
{
    declare("boost::format");
    std::cout << "boost::format(\"%2% Hello %1% %2% %3%\") % \"will\" %\"chen\" % 123:" << std::endl;
    std::cout << boost::format("%2% Hello %1% %2% %3%") % "will" %"chen" % 123;
}

void LearnStl::test_boost_shared_ptr()
{
    declare("boost::shared_ptr");
    typedef boost::shared_ptr<LearnStl> TypeSharePtrLearn;
    std::vector<TypeSharePtrLearn> vectorObjs;
    vectorObjs.push_back(TypeSharePtrLearn(new LearnStl("Lily")));
    vectorObjs.push_back(TypeSharePtrLearn(new LearnStl("Will")));
    vectorObjs.push_back(TypeSharePtrLearn(new LearnStl("Jack")));
    declare("boost::shared_ptr ends");
}

void LearnStl::test_boost_any()
{
    declare("boost::any");
    std::list<boost::any> many;
    many.push_back((int)123);
    many.push_back("Hello");
    std::for_each(many.begin(), many.end(), MyPrintObject());
}


void LearnStl::test_boost_assign()
{
    declare("boost's assigen operation");

    std::vector<int> vector_values;
    using namespace boost::assign;// It is for the following line is valid.
    vector_values += 1,2,3;

    std::map<std::string, int> months;
    insert(months)
            ("january", 31)("february", 28);

    std::deque<StrPair> pairQue;
    push_front(pairQue)("Hello", "ni hao")("Welcome", "huan ying");
    // !!!The function object here should take StrPari type as a parameter, not the deque's iterator!!!
    std::for_each(pairQue.begin(), pairQue.end(), MyPrintObject());

    declare("Using BOOST_FOREACH");
    BOOST_FOREACH(StrPair &e, pairQue)
    {
        std::cout << e.first << "-" << e.second << ",";
    }
}

void LearnStl::test_boost_lambda()
{
    declare("boost::lambda");
    //using namespace boost::lambda;
    std::list<int> myList(10);
    //std::for_each(myList.begin(), myList.end(), _1=1);
    std::for_each(myList.begin(), myList.end(), boost::lambda::_1=1);
    //std::for_each(myList.begin(), myList.end(), std::cout << _1 << ",");
    std::for_each(myList.begin(), myList.end(), std::cout << boost::lambda::_1 << ",");
}
