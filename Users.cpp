
//  Users.cpp
//  proto
//
//  Created by David McKinney on 7/16/19.
//  Copyright © 2019 David McKinney. All rights reserved.
//
//  Business is a user with business profile

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "user.h"
//#include "Deal.h"
#include <cmath>
#include <sstream>


// User implementation
std::map<Deal,int> User::all_deals() const {
    return my_Deals;
}

std::map<Deal,int> *User::all_deals_change() {
    return &my_Deals;
}
/*
 
 
 

 
 */

// Business implementation
Business::Business(std::string username_in, std::string password_in, std::string profile_type_in)
: username(username_in), password(password_in), profile_type(profile_type_in) { }



const std::string Business::get_username() const {
    return username;
}

const std::string Business::get_password() const {
    return password;
}



void Business::create_deal() {
    std::istringstream is;
    
    std::cout << "Please enter the name of the deal you would like to create: \n";
    getline(std::cin, deal_name);
    std::cout << "\n";
    
    std::cout << "Please enter the percentage discount offered to the customer: \n";
    std::cin >> deal_discount;
    std::cout << "\n";
    
    barcode = rand();
    
    add_deal(deal_name, deal_discount);
}




void Business::add_deal(std::string name, int offer) {
    deal = Deal(deal_name, deal_discount);
    all_deals_change()->emplace(deal, barcode);
}


void Business::remove_deal(Deal &deal) {
    std::map<Deal, int>::iterator it = all_deals().find(deal);
    all_deals_change()->erase(it);
}

/*
 

*/



// User implementation
Consumer::Consumer(std::string username_in, std::string password_in, std::string profile_type_in)
: username(username_in), password(password_in), profile_type(profile_type_in) { }

const std::string Consumer::get_username() const {
    return username;
}

const std::string Consumer::get_password() const {
    return password;
}

void Consumer::create_deal() {
    std::cout << "Sorry consumers cannot create deals, only redeem them.\n";
}

User * User_factory(const std::string &username, const std::string &password, const std::string &profile_type) {
    
    if(profile_type == "Business") {
        return new Business(username, password, profile_type);
    }
    
    if(profile_type == "Consumer") {
        return new Consumer(username, password, profile_type);
    }
    
    assert(false);
    return nullptr;
}

std::ostream &operator<<(std::ostream & os, const std::map<Deal, int> &all_deals) {
    for(auto &deals : all_deals) {
        os << deals.first.get_name_of_deal() << ": " << deals.first.get_discount() << "\n";
    }
    return os;
}




/*
class Business : public User {
public:
    Business(std::string username_in, std::string password_in, std::string profile_type_in)
    : username(username_in), password(password_in), profile_type(profile_type_in) { }
    
    const std::string & get_username() const {
        return username;
    }
    
    const std::string & get_password() const {
        return password;
    }
    
    
    //EFFECTS user enters the details of the offer they would like to create
    void create_deal() {
        std::istringstream is;
        
        std::cout << "Please enter the name of the deal you would like to create: \n";
        getline(std::cin, deal_name);
        std::cout << "\n";
        
        std::cout << "Please enter the percentage discount offered to the customer: \n";
        std::cin >> deal_discount;
        std::cout << "\n";
        
        barcode = rand();
        
        add_deal(deal_name, deal_discount);
    }
    
    
    //EFFECTS adds deal to deals created by user
    void add_deal(std::string name, int offer) {
        deal = Deal(deal_name, deal_discount);
        my_Deals.emplace(deal, barcode);
    }
    
    //EFFECTS removes a deal after it is no longer valid as deemed by user
    void remove_deal(Deal &deal) {
        std::map<Deal, int>::iterator it = my_Deals.find(deal);
        my_Deals.erase(it);
    }
    
    std::map<Deal,int> all_deals()  {
        return my_Deals;
    }
    
private:
    std::string username;
    std::string password;
    std::string deal_name;
    std::string profile_type;
    int deal_discount = 0;
    int barcode = 0;
    Deal deal;
    std::map<Deal, int> my_Deals;
    
};



class Consumer : public User {
public:
    Consumer(std::string username_in, std::string password_in, std::string profile_type_in)
    : username(username_in), password(password_in), profile_type(profile_type_in) { }
    
    const std::string & get_username() const {
        return username;
    }
    
    const std::string & get_password() const {
        return password;
    }
    
    std::map<Deal,int> all_deals()  {
        return my_Deals;
    }
    
    void create_deal() {
        ;
    }
    
    //EFFECTS removes a deal after it is no longer valid as deemed by business
    void remove_deal(Deal &deal) {
        std::map<Deal, int>::iterator it = my_Deals.find(deal);
        my_Deals.erase(it);
    }
    
    
private:
    std::string username;
    std::string password;
    std::string profile_type;
    std::map<Deal, int> my_Deals;
    
};

*/


