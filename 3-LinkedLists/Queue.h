//
//  Queue.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____LinkedLists__Queue__
#define ____LinkedLists__Queue__

#include <iostream>
#include <queue>
#include "Widget.h"

class Queue {
    std::deque<Widget> widgets;
    int numberOfPromotionsRemaining;
    double promotionRate;
public:
    
    Queue():numberOfPromotionsRemaining(0), promotionRate(0.0){};
    
    //  Getters and setters
    
    void setPromotionRate(double);
    int getNumberOfPromotions();
    void beginPromotion();
    
    //  Buy and sell widgets
    
    void receiveNumWidgetsAtWidgetsAtPrice(int, double);
    void sellNumberOfWidgets(int, double);  //  Pass a price along so we can recurse

    //  Sale helper methods
    double quantityAvailableForDesiredQuantity(Widget, int);
    double priceForNWidgetsAtPricePerItem(int, double);
};

#endif /* defined(____LinkedLists__Queue__) */
