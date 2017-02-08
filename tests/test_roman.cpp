#include <roman/roman.h>

#include <gtest/gtest.h>

#include <stdexcept>

TEST(ArabicToRomanTest, ZeroThrowsDomainError) {
    EXPECT_THROW(arabic_to_roman(0), std::domain_error);
}

TEST(ArabicToRomanTest, FourThousandThrowsDomainError) {
    EXPECT_THROW(arabic_to_roman(4000), std::domain_error);
}

TEST(ArabicToRomanTest, Ones) {
    std::vector<std::pair<int, std::string>> const pairs = {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"}
    };
    for (auto const & p : pairs) {
        EXPECT_EQ(arabic_to_roman(p.first), p.second);
    }
}

TEST(ArabicToRomanTest, Tens) {
    std::vector<std::pair<int, std::string>> const pairs = {
        {10, "X"},
        {20, "XX"},
        {30, "XXX"},
        {40, "XL"},
        {50, "L"},
        {60, "LX"},
        {70, "LXX"},
        {80, "LXXX"},
        {90, "XC"},
    };
    for (auto const & p : pairs) {
        EXPECT_EQ(arabic_to_roman(p.first), p.second);
    }
}

TEST(ArabicToRomanTest, TensAndOnes) {
    EXPECT_EQ(arabic_to_roman(99), "XCIX");
}

TEST(ArabicToRomanTest, Hundreds) {
    std::vector<std::pair<int, std::string>> const pairs = {
        {100, "C"},
        {200, "CC"},
        {300, "CCC"},
        {400, "CD"},
        {500, "D"},
        {600, "DC"},
        {700, "DCC"},
        {800, "DCCC"},
        {900, "CM"},
    };
    for (auto const & p : pairs) {
        EXPECT_EQ(arabic_to_roman(p.first), p.second);
    }
}