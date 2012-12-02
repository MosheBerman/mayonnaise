//
//  SalesRecord.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Record.h"
#include <sstream>

SalesRecord::SalesRecord(){
    recordType = kSalesRecordTypeSale;
    quantity = 0;
    saleAmount = 0;
    pricePerWidget = 0;
}

SalesRecord::SalesRecord(std::string record){
    recordType = recordTypeFromString(record);
    quantity = quantityFromString(record);
    saleAmount = saleAmountFromString(record);
    pricePerWidget = priceFromString(record);
}

/* Getters and Setters */

kSalesRecordType SalesRecord::getRecordType(){
    return recordType;
}

void SalesRecord::setRecordType(kSalesRecordType _recordType){
    recordType = _recordType;
}

int SalesRecord::getQuantity(){
    return quantity;
}

void SalesRecord::setQuantity(int _quantity){
    quantity = _quantity;   //  Allow negatives for refunds
}

int SalesRecord::getSaleAmount(){
    return saleAmount;
}

void SalesRecord::setSaleAmount(int _saleAmount){
    if (_saleAmount >= 0) { //  Can't have negative percentages for sales
        saleAmount = _saleAmount;
    }
}

double SalesRecord::getPricePerWidget(){
    return pricePerWidget;
}

void SalesRecord::setPricePerWidget(int _pricePerWidget){
    if(_pricePerWidget >= 0){
        pricePerWidget = _pricePerWidget;
    }
}


/* Parser methods */

kSalesRecordType SalesRecord::recordTypeFromString(std::string record){
    
    char c = record[0];
    
    if (c == 'S') {
        return kSalesRecordTypeSale;
    }
    else if(c == 'R'){
        return kSalesRecordTypeReciept;
    }
    
    return kSalesRecordTypePromotion;   //  Assume that we have valid
                                        //  input and that we will have
                                        //  processed the other two kinds
                                        //  of records.
}

int SalesRecord::quantityFromString(std::string record){

    std::istringstream recordStream(record);
    
    char c;
    int quantity;
    
    recordStream >> c;  //Read in and summarily discard the first character
    recordStream >> quantity;
    
    return quantity;
}

int SalesRecord::saleAmountFromString(std::string record){

    std::istringstream recordStream(record);
    
    char c;
    int quantity;
    
    recordStream >> c;  //Read in and summarily discard the first character
    recordStream >> quantity;
    
    return quantity;
}

double SalesRecord::priceFromString(std::string record){
    std::istringstream recordStream(record);
    
    char c;
    int quantity;
    double price;
    
    recordStream >> c;  //Read in and summarily discard the first character
    recordStream >> quantity;
    recordStream >> price;
    
    return price;
    
}