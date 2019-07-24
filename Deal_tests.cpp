//
//  Deal_tests.cpp
//  proto
//
//  Created by David McKinney on 7/24/19.
//  Copyright © 2019 David McKinney. All rights reserved.
//
#include "Deal.h"
#include "unit_test_framework.h"
#include <sstream>
#include <string>

using namespace std;

TEST(test_deal_empty_ctor) {
    
    Deal deal;
    string name = deal.get_name_of_deal();
    int discount = deal.get_discount();
    
    ASSERT_TRUE(name == "");
    ASSERT_TRUE(discount == 0);
}

TEST(test_deal_init_ctor) {
    
    Deal deal("first deal", 50);
    string name = deal.get_name_of_deal();
    int discount = deal.get_discount();
    
    ASSERT_TRUE(name == "first deal");
    ASSERT_TRUE(discount == 50);
}

TEST(test_deal_less_than_one) {
    Deal one("first", 10);
    Deal two("second", 20);
    
    ASSERT_TRUE(one < two);
}

TEST(test_deal_less_than_two) {
    Deal less("less is more", 2);
    Deal more("more", 1);
    
    ASSERT_TRUE(less < more);
}

TEST(test_deal_copy_ctor) {
    Deal first("first", 1);
    Deal second(first);
    
    ASSERT_TRUE(second.get_name_of_deal() == "first");
    ASSERT_TRUE(second.get_discount() == 1);
}

TEST(test_deal_equal) {
    Deal first("first day of class", 1);
    Deal second("second day of class", 2);
    
    second = first;
    
    ASSERT_TRUE(second.get_name_of_deal() == "first day of class");
    ASSERT_TRUE(second.get_discount() == 1);
}










TEST_MAIN()
