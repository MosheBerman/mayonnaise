//
//  Storekeeper.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Storekeeper.h"
#include <numeric>

void Storekeeper::setPromotionRate(double _promotionRate){
    //  A negative "promotion" rate
    // could mean a temporary markup.
    promotionRate = _promotionRate;
}

int Storekeeper::getNumberOfPromotions(){
    return numberOfPromotionsRemaining;
}

void Storekeeper::beginPromotion(){
    numberOfPromotionsRemaining = 2;
}

void Storekeeper::receiveNumWidgetsAtWidgetsAtPrice(int numberOfWidgets, double price){
    Widget widget = Widget(numberOfWidgets, price);
    widgets.push_back(widget);
}

void Storekeeper::sellNumberOfWidgets(int numberOfWidgetsToSell, std::vector<Sale>& soldBatches){
    
    //
    //  If there are no widgets left, print out
    //  the message mentioned in the spec, and return.
    //
    
    if (widgets.empty() || numberOfWidgetsToSell == 0) {
        
        
        std::cout << "remainder " << numberOfWidgetsToSell << " not available." << std::endl;
        return;
    }
    
    //
    //  Keep track of batches of sales
    //
    
    std::vector<Sale> sales;
    
    //
    //  If there are more widgets, pull them off of the Storekeeper.
    //
    
    Widget nextBatchOfWidgets = widgets.front();
    
    //
    //  Get the price per widget for this batch
    //
    
    double pricePerItem = nextBatchOfWidgets.getPrice();
    double quantityAvailable = quantityAvailableForDesiredQuantity(nextBatchOfWidgets, numberOfWidgetsToSell);
    
    //
    Sale sale = Sale(quantityAvailable, pricePerItem);
    
}

//
//  Check the current batch for widgets.
//  If there's enough, take those and subtract them,
//  otherwise, 
//

double Storekeeper::quantityAvailableForDesiredQuantity(Widget batch, int numberOfWidgetsToSell) {
    
    double quantityAvailable = batch.getQuantity();
    
    if (quantityAvailable >= numberOfWidgetsToSell) {
        quantityAvailable = numberOfWidgetsToSell;
    }
    
    //
    //  If we're using all of the widgets,
    //  there's no more in the batch, so pop it.
    //
    
    else{
        widgets.pop_front();
    }
    
    //  Update the quantity
    batch.setQuantity(quantityAvailable - numberOfWidgetsToSell);
    
    return quantityAvailable;
}

//
//  Calculate the price of the batch...
//

double Storekeeper::priceForNWidgetsAtPricePerItem(int n, double pricePerItem){
    
    double priceOfBatch = pricePerItem * n;
    priceOfBatch *= 1.3;   //  Apply the 30 percent markup
    
    //  ... apply the promotion if applicable.
    
    if (numberOfPromotionsRemaining > 0) {
        priceOfBatch *= 1-(promotionRate/100);
        numberOfPromotionsRemaining--;
    }
    
    return priceOfBatch;
}

int sum(int sum, Sale sale){
    return sum += sale.getQuantity();
}

void Storekeeper::printSales(std::vector<Sale> &sales){
    
    int itemsSold = std::accumulate(sales.begin(), sales.end(), 0, sum);


    
}

void sum(){
    
}