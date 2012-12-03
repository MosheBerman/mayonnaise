//
//  Storekeeper.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Storekeeper.h"
#include <numeric>
#include <algorithm>
#include <iomanip>

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
    std::cout << "\nThe next two customers will receive a " << promotionRate << "% discount. \n" << std::endl;
}

void Storekeeper::receiveNumWidgetsAtPrice(int numberOfWidgets, double price){
    
    insert(queue, numberOfWidgets, price);
    std::cout << "Stocking " << numberOfWidgets << " at $" << price << " each." << std::endl;
}

//
//  This public method wraps the sales method
//  so that it can keep an internal vector
//  around for recursion purposes.
//

void Storekeeper::sellWidgets(int numberOfWidgetsToSell){

    //
    //  Count how many widgets we sold
    //  and the total revenue.
    //
    
    int numberOfWidgetsSold = 0;
    double totalPrice = 0.0;
    
    //
    //  While we have widgets to sell, let's try and sell them.
    //
    
    while (numberOfWidgetsToSell > 0) {
        
        //
        //  If there's nothing to sell, we need to break the loop.
        //
        
        if (empty(queue)) {
            
            std::cout << "remainder of " << numberOfWidgetsToSell << " Widgets not available." << std::endl;
            break;
        }
        
        int quantity = (queue->front)->quantity;
        double price = (queue->front)->price;
        
        //
        //  If there's enough stock, sell it.
        //
        
        if (quantity >= numberOfWidgetsToSell) {
            
            //
            //  First, let's remove the items
            //  from the queue.
            //
            
            (queue->front)->quantity -= numberOfWidgetsToSell;
            
            //
            //  Let's also count them.
            //
            
            numberOfWidgetsSold += numberOfWidgetsToSell;
            numberOfWidgetsToSell -= numberOfWidgetsSold;
            
            //
            //  Now we want to get the total price
            //
            
            totalPrice += (price * 1.3 * (double)numberOfWidgetsSold);
            
            //
            //  If applicable, calculate promotional price.
            //
            
            if (numberOfPromotionsRemaining > 0) {
                totalPrice = (promotionRate/100) * totalPrice;
            }
            
            //
            //  Print out a message
            //
            
            std::cout << "Sold " << quantity << " at $" << price <<std::endl;
        }
        
        //
        //  If we're short on supply, move on to the next batch.
        //  Remove the front node and continue.
        //
        
        else{
            
            remove(queue);
            
            continue;
            
        }
        
    }
    
    std::cout << "\t\t" << "Total Sales: $" << totalPrice << "\n" << std::endl;
    
    /*
    //
    //  If there are more widgets, pull them off of the Storekeeper.
    //
    
    Widget* nextBatchOfWidgets = remove(queue);
    
    printSales(soldBatches, numberOfWidgetsToSell);
    return;

    
    //
    //  Get the price per widget for this batch
    //
    
    double pricePerItem = nextBatchOfWidgets.price;
    double quantityAvailable = quantityAvailableForDesiredQuantity(nextBatchOfWidgets, numberOfWidgetsToSell);
    
    //  Hang on to the sale until we're finished
    Sale sale = Sale(quantityAvailable, pricePerItem);
    soldBatches.push_back(sale);
    
    //
    //  If we're not selling all of the widgets from this
    //  batch, then try the next batch of widgets.
    //
    
    if (quantityAvailable < numberOfWidgetsToSell) {
        
        //
        //  If there are more Widgets in another batch,
        //  then we want to sell those too.
        //
        
        widgets = widgets->dequeue();
        
        sellNumberOfWidgets(numberOfWidgetsToSell, soldBatches);
        

    }
    
    //
    //  Otherwise, print the sales and the unfilled portion of the order
    //
    
    else{
        printSales(soldBatches, numberOfWidgetsToSell);
    }
    */
    
    
    
}

//
//  Check the current batch for widgets.
//  If there's enough, take those and subtract them.
//

double Storekeeper::quantityAvailableForDesiredQuantity(Widget batch, int numberOfWidgetsToSell) {
    
    double quantityAvailable = batch.quantity;
    
    if (quantityAvailable >= numberOfWidgetsToSell) {
        quantityAvailable = numberOfWidgetsToSell;
        //  Update the quantity
        batch.quantity = quantityAvailable - numberOfWidgetsToSell;
    }
    
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

void Storekeeper::printOverstock(){
    
    if (empty(queue)) {
        return;
    }
    
    std::cout << "\nOverstock:\n\n";
    
    while (!empty(queue)) {
        Widget overstock = remove(queue);
        std::cout << overstock.quantity << " remain at $";
        std::cout << overstock.price << std::endl;
    
    }
}