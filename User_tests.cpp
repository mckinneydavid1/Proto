//
//  User_tests.cpp
//  proto
//
//  Created by David McKinney on 7/16/19.
//  Copyright © 2019 David McKinney. All rights reserved.
//

#include "unit_test_framework.h"
#include <string>
#include <fstream>
#include <iostream>
#include "user.h"

using namespace std;


// This case tests the business class constructor and get_username func
TEST(test_business_get_username) {
    User *first_user(User_factory("davy", "qwerty", "Business"));
    
    string username = first_user->get_username();
    
    ASSERT_TRUE(username == "davy");
    
    delete first_user;
}

// This tests the get_username func
TEST(test_business_get_password) {
    User *first_user = User_factory("davy", "eghewghwof8344", "Business");
    
    string password = first_user->get_password();
    
    ASSERT_TRUE(password == "eghewghwof8344");
    
    delete first_user;
}

// This is a basic test to check the create deal function
TEST(test_business_create_deal) {
    User *first_user = User_factory("davy", "qwerty", "Business");
    
    first_user->create_deal();
    
    std::ostringstream name;
    name << first_user->all_deals();
    
    ASSERT_EQUAL(name.str(), "50% off: 50\n");
    delete first_user;
}


// This is a basic test to check the add_deal func
TEST(test_business_add_deal) {
    User *first_user = User_factory("davy", "qwerty", "Business");
    
    first_user->create_deal();
    
    first_user->create_deal();
    
    std::ostringstream all;
    all << first_user->all_deals();
    
    
    ASSERT_EQUAL(all.str(), "50% off: 50\n");
    
    delete first_user;
}



TEST_MAIN()
