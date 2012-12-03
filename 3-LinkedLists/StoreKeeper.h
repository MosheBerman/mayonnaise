//
//  Storekeeper.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____LinkedLists__Storekeeper__
#define ____LinkedLists__Storekeeper__

#include <iostream>
#include "Widget.h"
#import "Sale.h"
#import <vector>


class Storekeeper {
    Widget* widgets;
    int numberOfPromotionsRemaining;
    double promotionRate;
    
    //  Pass along an previous batches so we can recurse
    void sellNumberOfWidgets(int numberOfWidgetsToSell, std::vector<Sale>& soldBatches);
    
public:
    
    Storekeeper():numberOfPromotionsRemaining(0), promotionRate(0.0){};
    
    //  Getters and setters
    
    void setPromotionRate(double);
    int getNumberOfPromotions();
    void beginPromotion();
    
    //  Buy and sell widgets
    
    void receiveNumWidgetsAtWidgetsAtPrice(int, double);
    void sellWidgets(int);

    //  Sale helper methods
    double quantityAvailableForDesiredQuantity(Widget*, int);
    double priceForNWidgetsAtPricePerItem(int, double);
    
    //  Print methods
    void printSales(std::vector<Sale> &sales, int);
    void printOverstock();
};

#endif /* defined(____LinkedLists__Storekeeper__) */
