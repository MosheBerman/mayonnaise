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
#import <vector>


class Storekeeper {
    WidgetQueue *queue;
    int numberOfPromotionsRemaining;
    double promotionRate;
    
public:
    
    Storekeeper():numberOfPromotionsRemaining(0), promotionRate(0.0){
        queue = new WidgetQueue();
    };
    
    //  Getters and setters
    
    void setPromotionRate(double);
    int getNumberOfPromotions();
    void beginPromotion();
    
    //  Buy and sell widgets
    
    void receiveNumWidgetsAtPrice(int, double);
    void sellWidgets(int);

    //  Sale helper methods
    double quantityAvailableForDesiredQuantity(Widget, int);
    double priceForNWidgetsAtPricePerItem(int, double);
    
    //  Print methods
    void printOverstock();
};

#endif /* defined(____LinkedLists__Storekeeper__) */
