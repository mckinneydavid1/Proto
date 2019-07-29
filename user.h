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
#include <fstream>

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
    
    //EFFECTS compares deals based on name of deal. Returns true if "this" deal name is
    // less than rhs deal name
    bool operator<(const Deal &rhs) const {
        return get_name_of_deal() < rhs.get_name_of_deal();
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
    virtual const std::string get_username() const = 0;
    
    //EFFECT return user's password
    virtual const std::string get_password() const = 0;
    
    //EFFECT return valid deals a user has created or redeemeed
    std::map<Deal,int> all_deals() const;
    
    //MODIFIES deals in a user's map of deals and associated barcodes
    //EFFECT return valid deals a user has created or redeemed
    std::map<Deal,int> *all_deals_change();
    
    //MODIFIES user's map of deals and associated barcodes
    //EFFECT allows user to create a deal via command line input
    virtual void create_deal() = 0;
    
    //MODIFIES user's map of deals and associated barcodes
    //EFFECT allows user to create a deal via a file stream
    virtual void create_deal_with_stream(std::string filename) = 0;
    
    //MODIFIES user's map of deals and associated barcodes
    //EFFECTS allows a consumer to add a single deal to their map of deals from a given
    //business
    //virtual void add_single_deal(std::map<Deal, int> deal_and_barcode);
    //void add_deal(std::string, int);
    //virtual void remove_deal(Deal &deal) = 0;
    
    virtual ~User() { };
    
    
    
private:
    //std::string username;
    //std::string password;
    //std::string profile_type;
    std::map<Deal, int> my_Deals;
};





// Business class derived from User
class Business : public User {
    
public:
    Business(std::string username_in, std::string password_in, std::string profile_type_in);
    
    const std::string get_username() const;
    
    const std::string get_password() const;
    
    void create_deal();
    
    void create_deal_with_stream(std::string filename);
    
    //EFFECTS adds a deal to a user's map of deals and associated barcodes if it DOES
    // NOT already exist
    void add_deal(std::string, int);
    
    
    //MODIFIES user's map of deals
    //EFFECTS removes a single element from a user's map of deals and associated barcodes
    void remove_deal(Deal &deal);
    
    
    
private:
    std::string username;
    std::string password;
    std::string profile_type;
    std::string deal_name;
    int deal_discount = 0;
    int barcode = 0;
    Deal deal;
    
};



// Consumer class derived from User
class Consumer : public User {
    
public:
    Consumer(std::string username_in, std::string password_in, std::string profile_type_in);
    
    const std::string get_username() const;
    
    const std::string get_password() const;
    
    void create_deal();
    
    void create_deal_with_stream(std::string filename);
    
    //void add_single_deal(std::map<Deal, int> deal_and_barcode);
    
    
private:
    std::string username;
    std::string password;
    std::string profile_type;
};



class Game {
    
public:
    
    Game() {
        business_users.clear();
    }
    
    //EFFECTS returns all the business in given session
    std::vector<User*> *get_business_users() {
        return &business_users;
    }
    
    
private:
    
    std::vector<User*> business_users;
    
};



User * User_factory(const std::string &username, const std::string &password,
    const std::string &profile_type);


std::ostream &operator<<(std::ostream & os, const std::map<Deal, int> &all_deals);

std::ostream &operator<<(std::ostream & os, const std::vector<User*> all_businesses);

#endif
