//
//  Deal.h
//  proto
//
//  Created by David McKinney on 7/22/19.
//  Copyright © 2019 David McKinney. All rights reserved.
//
// Deal is an offer that be created by businesses and redeemed by customers

#include <stdio.h>
#include <string>
#include <map>
#include <vector>


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
    
    Deal(Deal &deal) {
        copy_deal(deal);
    }
    
    Deal& operator=(const Deal &deal_in) {
        if(this == &deal_in) {
            return *this;
        }
        else {
            copy_deal(deal_in);
            return *this;
        }
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
    
    void copy_deal(const Deal &deal_in) {
        deal.first = deal_in.get_name_of_deal();
        deal.second = deal_in.get_discount();
    }
    
    bool operator==(const Deal &deal_in) {
        if((get_name_of_deal() == deal_in.get_name_of_deal()) && (get_discount() == deal_in.get_discount()))
            return true;
        else
            return false;
    }
    
private:
    std::pair<std::string, int> deal;
};
