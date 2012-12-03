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
#include <Storekeeper>
#include "Widget.h"
#import "Sale.h"


class Storekeeper {
    std::deque<Widget> widgets;
    int numberOfPromotionsRemaining;
    double promotionRate;
public:
    
    Storekeeper():numberOfPromotionsRemaining(0), promotionRate(0.0){};
    
    //  Getters and setters
    
    void setPromotionRate(double);
    int getNumberOfPromotions();
    void beginPromotion();
    
    //  Buy and sell widgets
    
    void receiveNumWidgetsAtWidgetsAtPrice(int, double);
    void sellNumberOfWidgets(int numberOfWidgetsToSell, std::vector<Sale>& soldBatches);   //  Pass along an previous batches so we can recurse

    //  Sale helper methods
    double quantityAvailableForDesiredQuantity(Widget, int);
    double priceForNWidgetsAtPricePerItem(int, double);
    void printSales(std::vector<Sale> &sales);
};

#endif /* defined(____LinkedLists__Storekeeper__) */