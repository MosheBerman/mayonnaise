//
//  Sale.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

/*

 This class represents a *part* of
 a sale of widgets, since different
 pieces of stock have varying prices.
 
 Each batch of widgets that is sold
 is put into a "Sale" instance and 
 then read out at the end of the 
 sellNumberOfWidgets() function in
 the Queue class.
 
 */

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
