//
//  Sale.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____LinkedLists__Sale__
#define ____LinkedLists__Sale__

#include <iostream>

class Sale {
    int quantity;
    double pricePerUnit;
public:
    Sale():quantity(0), pricePerUnit(0.0){};
    Sale(int _quantity, double _pricePerUnit):quantity(_quantity), pricePerUnit(_pricePerUnit){};
    
    //  Getters
    
    int getQuantity();
    double getPricePerUnit();
    
    // Net total of the sale
    
    double revenue();
};

#endif /* defined(____LinkedLists__Sale__) */
