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

class User {
    
public:
    //EFFECTS returns user's username
    virtual const std::string & get_username() const = 0;
    
    //EFFECT return user's password
    virtual const std::string & get_password() const = 0;
    
    //EFFECT return valid deals a user has created or redeemed
    virtual void show_my_deals() = 0;
    
    virtual void remove_deal(std::string name) = 0;
    
    
};

User * User_factory(const std::string &username, const std::string &password, const std::string &profile_type);
    

#endif
