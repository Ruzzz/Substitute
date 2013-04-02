#pragma once
// win 1251


#include "StringUtil.h"


TEST(StringUtilTest, wideToAnsiArray)
{
    std::vector<char> v;
    ASSERT_TRUE(StringUtil::wideToAnsiArray(v, L"test_����"));
    ASSERT_TRUE(std::equal(v.cbegin(), v.cend(), "test_����"));
}


TEST(StringUtilTest, prepareAnsi)
{
    std::vector<char> v;
    std::string s;

    ASSERT_TRUE(StringUtil::prepareAnsi(_T("test_����"), v));
    ASSERT_TRUE(StringUtil::prepareAnsi(_T("test2_����2"), s));

    ASSERT_TRUE(std::equal(v.cbegin(), v.cend(), "test_����"));
    ASSERT_TRUE(s == "test2_����2");
}
