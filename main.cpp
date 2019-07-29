//Author: David McKinney
//Created: July 16, 2019
//Modified: July 16, 2019
//Purpose: Allows a user to create either a business or consumer profile. If business, a
//user can offer a deal. If consumer, user can utilize a deal made available by a business

//#include "user.h"

#include "user.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>


int main(int argc, char **argv) {
    Game game;
    
    
    timeval t1;
    gettimeofday(&t1, NULL);
    
    srand(unsigned(t1.tv_usec * t1.tv_sec));
    
    std::string filename = std::string(argv[1]);
    
    User *first_user = User_factory("davy", "qwerty", "Business");
   
    
    first_user->create_deal_with_stream(filename);
    
    std::ostringstream name;
    name << first_user->all_deals();
    
    
    std::cout << name.str();
    
   
    
    name.str("");
    

    game.get_business_users()->push_back(first_user);
    
    name << *(game.get_business_users());
    
    std::cout << name.str();
    
    
    /*
    User *second_user = User_factory("jack", "munster", "Business");
    second_user->create_deal_with_stream(filename);
    
    name << second_user->all_deals();
    
    
    std::cout << name.str();
    
    
    //User *first_consumer = User_factory("customer", "0320uhgewf8", "Consumer");
    
    delete second_user;
    */
    
    
    
    delete first_user;
    
    
    
    return 0;
}
