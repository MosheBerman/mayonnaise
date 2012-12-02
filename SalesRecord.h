//
//  SalesRecord.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____LinkedLists__SalesRecord__
#define ____LinkedLists__SalesRecord__

#include <iostream>

enum kSalesRecordType {
    kSalesRecordTypeSale = 0,
    kSalesRecordTypeReciept = 1,
    kSalesRecordTypePromotion
    };

class SalesRecord {
    kSalesRecordType recordType;
    int quantity;
    int saleAmount;
    double pricePerWidget;
    
    //  Parser Methods

    kSalesRecordType recordTypeFromString(std::string);
    int quantityFromString(std::string);
    int saleAmountFromString(std::string);
    double priceFromString(std::string);
    
public:
    
    SalesRecord();
    SalesRecord(std::string record);
    
    //  Getters and setters
    
    kSalesRecordType getRecordType();
    void setRecordType(kSalesRecordType);
    
    int getQuantity();
    void setQuantity(int);
    
    int getSaleAmount();
    void setSaleAmount(int);
    
    double getPricePerWidget();
    void setPricePerWidget(int);
};

#endif /* defined(____LinkedLists__SalesRecord__) */
