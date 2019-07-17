
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


class Business : public User {
public:
    Business(std::string username_in, std::string password_in)
    : username(username_in), password(password_in) { }
    
    const std::string & get_username() const {
        return username;
    }
    
    const std::string & get_password() const {
        return password;
    }
    
    void show_my_deals() {
        for(auto deals : my_Deals) {
            std::cout << deals.first << ": " << deals.second << "\n";
        }
    }
    
    //EFFECTS user enters the details of the offer they would like to create
    void create_deal() {
        std::cout << "Please enter the name of the deal you would like to create: \n";
        std::cin >> deal_name;
        std::cout << "\n";
        
        std::cout << "Please enter the details of the offer: \n";
        std::cin >> deal_offer;
        std::cout << "\n";
    }
    
    //EFFECTS adds deal to deals created by user
    void add_deal(std::string name, std::string offer) {
        my_Deals.emplace(name, offer);
    }
    
    //EFFECTS removes a deal after it is no longer valid as deemed by user
    void remove_deal(std::string name) {
        my_Deals.erase(name);
    }
    
private:
    std::string username;
    std::string password;
    std::string deal_name;
    std::string deal_offer;
    std::map<std::string, std::string> my_Deals;
    
};



class Consumer : public User {
public:
    Consumer(std::string username_in, std::string password_in)
    : username(username_in), password(password_in) { }
    
    const std::string & get_username() const {
        return username;
    }
    
    const std::string & get_password() const {
        return password;
    }
    
    
    void show_my_deals() {
        for(auto deals : my_Deals) {
            std::cout << deals.first << ": " << deals.second << "\n";
        }
    }
    
    //EFFECTS removes a deal after it is no longer valid as deemed by business
    void remove_deal(std::string name) {
        my_Deals.erase(name);
    }
    
    
private:
    std::string username;
    std::string password;
    std::map<std::string, std::string> my_Deals;
    
};


User * User_factory(const std::string &username, const std::string &password, const std::string &profile_type) {
    
    if(profile_type == "Business") {
        return new Business(username, password);
    }
    
    if(profile_type == "Consumer") {
        return new Consumer(username, password);
    }
    
    assert(false);
    return nullptr;
}

