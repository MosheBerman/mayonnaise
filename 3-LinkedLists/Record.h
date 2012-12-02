//
//  Record.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____LinkedLists__Record__
#define ____LinkedLists__Record__

#include <iostream>

enum kRecordType {
    kRecordTypeSale = 0,
    kRecordTypeReciept = 1,
    kRecordTypePromotion
    };

class Record {
    kRecordType recordType;
    int quantity;
    int saleAmount;
    double pricePerWidget;
    
    //  Parser Methods

    kRecordType recordTypeFromString(std::string);
    int quantityFromString(std::string);
    int saleAmountFromString(std::string);
    double priceFromString(std::string);
    
public:
    
    Record();
    Record(std::string record);
    
    //  Getters and setters
    
    kRecordType getRecordType();
    void setRecordType(kRecordType);
    
    int getQuantity();
    void setQuantity(int);
    
    int getSaleAmount();
    void setSaleAmount(int);
    
    double getPricePerWidget();
    void setPricePerWidget(int);
};

#endif /* defined(____LinkedLists__Record__) */
