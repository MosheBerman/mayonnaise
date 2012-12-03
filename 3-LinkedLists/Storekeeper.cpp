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
    Widget *widget = new Widget(numberOfWidgets, price);
    widgets->enqueue(widget);
}

//
//  This public method wraps the sales method
//  so that it can keep an internal vector
//  around for recursion purposes.
//

void Storekeeper::sellWidgets(int numberOfWidgets){
    
    std::vector<Sale> sales;
    sellNumberOfWidgets(numberOfWidgets, sales);
}

//
//  This method sells widgets from the widgets tree recursively
//

void Storekeeper::sellNumberOfWidgets(int numberOfWidgetsToSell, std::vector<Sale>& soldBatches){
    
    //
    //  Keep track of batches of sales
    //
    
    std::vector<Sale> sales;
    
    //
    //  If there are more widgets, pull them off of the Storekeeper.
    //
    
    Widget *nextBatchOfWidgets = widgets;
    
    //
    //  Get the price per widget for this batch
    //
    
    double pricePerItem = nextBatchOfWidgets->price;
    double quantityAvailable = quantityAvailableForDesiredQuantity(nextBatchOfWidgets, numberOfWidgetsToSell);
    
    //  Hang on to the sale until we're finished
    Sale sale = Sale(quantityAvailable, pricePerItem);
    soldBatches.push_back(sale);
    
    //
    //  If we're not selling all of the widgets from this
    //  batch, then try the next batch of widgets.
    //
    
    if (quantityAvailable < numberOfWidgetsToSell && widgets->next != NULL) {
        
        //
        //  If there are more Widgets in another batch,
        //  then we want to sell those too.
        //
        
        widgets->dequeue();
        
        sellNumberOfWidgets(numberOfWidgetsToSell, soldBatches);

    }
    
    //
    //  Otherwise, print the sales and the unfilled portion of the order
    //
    
    else{
        printSales(sales, numberOfWidgetsToSell);
    }
}

//
//  Check the current batch for widgets.
//  If there's enough, take those and subtract them.
//

double Storekeeper::quantityAvailableForDesiredQuantity(Widget *batch, int numberOfWidgetsToSell) {
    
    if (batch == NULL) {
        return 0;
    }
    
    double quantityAvailable = batch->quantity;
    
    if (quantityAvailable >= numberOfWidgetsToSell) {
        quantityAvailable = numberOfWidgetsToSell;
        //  Update the quantity
        batch->quantity = quantityAvailable - numberOfWidgetsToSell;
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

//
//  Takes a sum and a sale,
//  adds the sale to the sum,
//  and returns the new sum.
//

int sum(int sum, Sale sale){
    return sum += sale.getQuantity();
}

//
//  Prints a given sale 
//

void printSale(Sale sale){
    
    std::cout << "Sold \t" << sale.getQuantity() << " at \t" << sale.getPricePerUnit() << " each." << std::endl;
    
}

//
//  Use an iterator to count and
//  print out the number of sold
//  widget units.
//

void Storekeeper::printSales(std::vector<Sale> &sales, int remainder){
    
    int itemsSold = std::accumulate(sales.begin(), sales.end(), 0, sum);
    
    std::cout << itemsSold << " items sold." << std::endl;
    
    std::for_each(sales.begin(), sales.end(), printSale);
    
    if (remainder > 0) {
        std::cout << "remainder " << remainder << " Widgets unavailable." << std::endl;
    }
}

void Storekeeper::printOverstock(){
    
    Widget *overstock = widgets->dequeue();
    
    if (overstock != NULL) {
        std::cout << "\n\n\nOverstock:\n\n";
    }
    
    while (overstock != NULL) {
        std::cout << overstock->quantity << " remain at ";
        std::cout << overstock -> price << std::endl;
    }
}