//
//  Record.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Record.h"
#include <sstream>

Record::Record(){
    recordType = kRecordTypeSale;
    quantity = 0;
    saleAmount = 0;
    pricePerWidget = 0;
}

Record::Record(std::string record){
    recordType = recordTypeFromString(record);
    quantity = quantityFromString(record);
    saleAmount = saleAmountFromString(record);
    pricePerWidget = priceFromString(record);
}

/* Getters and Setters */

kRecordType Record::getRecordType(){
    return recordType;
}

void Record::setRecordType(kRecordType _recordType){
    recordType = _recordType;
}

int Record::getQuantity(){
    return quantity;
}

void Record::setQuantity(int _quantity){
    quantity = _quantity;   //  Allow negatives for refunds
}

int Record::getSaleAmount(){
    return saleAmount;
}

void Record::setSaleAmount(int _saleAmount){
    if (_saleAmount >= 0) { //  Can't have negative percentages for sales
        saleAmount = _saleAmount;
    }
}

double Record::getPricePerWidget(){
    return pricePerWidget;
}

void Record::setPricePerWidget(int _pricePerWidget){
    if(_pricePerWidget >= 0){
        pricePerWidget = _pricePerWidget;
    }
}


/* Parser methods */

kRecordType Record::recordTypeFromString(std::string record){
    
    char c = record[0];
    
    if (c == 'S') {
        return kRecordTypeSale;
    }
    else if(c == 'R'){
        return kRecordTypeReciept;
    }
    
    return kRecordTypePromotion;   //  Assume that we have valid
                                        //  input and that we will have
                                        //  processed the other two kinds
                                        //  of records.
}

int Record::quantityFromString(std::string record){

    std::istringstream recordStream(record);
    
    char c;
    int quantity;
    
    recordStream >> c;  //Read in and summarily discard the first character
    recordStream >> quantity;
    
    return quantity;
}

int Record::saleAmountFromString(std::string record){

    //
    //   Clean out the percent sign
    //
    
    size_t locationOfPercent = record.find('%');
    
    if (locationOfPercent != std::string::npos) {
        record.replace(locationOfPercent, locationOfPercent+1, "");
    }
    
    std::istringstream recordStream(record);
    
    char c;
    int quantity;
    
    recordStream >> c;  //Read in and summarily discard the first character
    recordStream >> quantity;
    
    return quantity;
}

double Record::priceFromString(std::string record){
    std::istringstream recordStream(record);
    
    char c;
    int quantity;
    double price;
    
    recordStream >> c;  //Read in and summarily discard the first character
    recordStream >> quantity;
    recordStream >> price;
    
    return price;
    
}