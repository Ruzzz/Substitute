#pragma once


#include "HexUtil.h"


TEST(HexUtilTest, charValue)
{
    HexUtil::Byte t[256];
    memset(t, 255, ARRAY_SIZE(t));
    for (char i = '0'; i <= '9'; ++i)
        t[i] = i - '0';
    for (char i = 'A'; i <= 'F'; ++i)
        t[i] = i - 'A' + 10;
    for (char i = 'a'; i <= 'f'; ++i)
        t[i] = i - 'a' + 10;

    HexUtil::Byte b;
    for (int i = 0; i < 256; ++i)
    {
        if (t[i] != 0xFF)
        {
            ASSERT_TRUE(HexUtil::charValue((char)i, b));
            ASSERT_EQ(t[i], b);
        }
        else
            ASSERT_FALSE(HexUtil::charValue((char)i, b));
    }
}


TEST(HexUtilTest, toUInt)
{
    // 1 - < limit
    // 2 - < limit and invalid characters
    // 3 - = limit and invalid characters
    // 4 - = limit
    // 5 - > limit
    char *strs[] =           { "0", "1_", "12_", "AA", "FFFF" };
    unsigned int counts[] =  {  1,   1,    2,     2,    2 };
    HexUtil::Byte values[] = {  0,   1,    0x12,  0xAA, 0xFF };

    int len = ARRAY_SIZE(strs);
    for (int i = 0; i < len; ++i)
    {
        std::string s(strs[i]);
        std::vector<char> v(s.begin(), s.end());
        HexUtil::Byte b;

        ASSERT_EQ(counts[i], HexUtil::toUInt(v.begin(), v.end(), b, 2));
        ASSERT_EQ(values[i], b);
    }
}
