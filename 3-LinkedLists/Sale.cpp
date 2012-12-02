//
//  Sale.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Sale.h"

//  Getters

int Sale::getQuantity(){
    return quantity;
}

double Sale::getPricePerUnit(){
    return pricePerUnit;
}

// Net total of the sale

double Sale::revenue(){
    return (double)getQuantity() * getPricePerUnit();
}