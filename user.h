#ifndef USER_H
#define USER_H
//  user.h
//  proto
//
//  Created by David McKinney on 7/16/19.
//  Copyright © 2019 David McKinney. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <sstream>


class Deal {
    
    
public:
    Deal() {
        deal.first = "";
        deal.second = 0;
    }
    Deal(std::string name_in, int discount) {
        deal.first = name_in;
        deal.second = discount;
    }
    
    bool operator<(const Deal &deal1) const {
        return get_name_of_deal() < deal1.get_name_of_deal();
    }
    
    
    std::string get_name_of_deal() const {
        return deal.first;
    }
    
    int get_discount() const {
        return deal.second;
    }
    
    std::pair<std::string, int> get_deal() {
        return deal;
    }
    
    
private:
    std::pair<std::string, int> deal;
};





class User {
    
public:
    //EFFECTS returns user's username
    virtual const std::string & get_username() const = 0;
    
    //EFFECT return user's password
    virtual const std::string & get_password() const = 0;
    
    //EFFECT return valid deals a user has created or redeemeed
    
    virtual std::map<Deal,int> all_deals() = 0;
    
    virtual void create_deal() = 0;
    
    void add_deal(std::string, int);
    //virtual void remove_deal(Deal &deal) = 0;
    
    virtual ~User() { };
};


User * User_factory(const std::string &username, const std::string &password,
    const std::string &profile_type);


std::ostream &operator<<(std::ostream & os, const std::map<Deal, int> &all_deals);

#endif
