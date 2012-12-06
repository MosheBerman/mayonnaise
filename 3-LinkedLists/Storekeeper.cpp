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
    std::cout << "Stocking " << numberOfWidgets << " at $" << price << " per unit." << std::endl;
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
    
    std::cout << "\n--- Sale ---" << std::endl;
    
    //
    //  While we have widgets to sell, let's try and sell them.
    //
    
    while (numberOfWidgetsToSell > 0) {
        
        //
        //  Read out the quantity and the price
        //
        
        
        if (empty(queue)) {
            
            std::cout << "The remaining " << numberOfWidgetsToSell << " widgets are not available." << std::endl;
            break;
        }
        
        int quantity = queue->front->quantity;
        double price = queue->front->price;
        
        //
        //  There's enough to sell.
        //
        
        if (quantity > numberOfWidgetsToSell) {
            
            //
            //  Sell...
            //
            
            numberOfWidgetsSold += numberOfWidgetsToSell;
            queue->front->quantity -= numberOfWidgetsToSell;
            numberOfWidgetsToSell = 0;
            
            //
            //  Calculate price
            //
            
            totalPrice += (price * 1.3 * (double)numberOfWidgetsSold);

        }
        
        //
        //  There are widgets, but not enough
        //
        
        else if(quantity > 0){
            
            //
            //  Sell...
            //
            
            numberOfWidgetsSold += quantity;
            queue->front->quantity -= numberOfWidgetsToSell;
            numberOfWidgetsToSell -= quantity;
            
            //
            //  Calculate price
            //
            
            totalPrice += (price * 1.3 * (double)numberOfWidgetsSold);
            
            //
            //  remove the now empty item from the queue
            //
            
            remove(queue);
        }
        
        std::cout << "Sold " << numberOfWidgetsSold;
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << " at $" << price * 1.3 << " per unit.";
        std::cout << std::endl;
        
        numberOfWidgetsSold = 0;
    }
    
    
    std::cout << "\t\t" << "Total Sales: $";
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << totalPrice << "\n" << std::endl;
    
    totalPrice = 0;
    
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