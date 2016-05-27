#ifndef LEARNSTL_H
#define LEARNSTL_H

#include <string>

class LearnStl
{
public:
    LearnStl(const std::string str);
    ~LearnStl();
    static int m_nLearnIndex;

    void test_istream_iterator();
    void test_boost_array();
    void test_boost_format();
    void test_boost_shared_ptr();
    void test_boost_any();
    void test_boost_assign();
    void test_boost_lambda();
private:
    void declare(const std::string content);
    const std::string m_strName;
};

#endif // LEARNSTL_H
