//
//  Widget.h
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____LinkedLists__Widget__
#define ____LinkedLists__Widget__

#include <iostream>

class Widget {
    double price;
    int quantity;
public:
    Widget():price(0), quantity(0){};
    Widget(double _price,int _quantity):price(_price), quantity(_quantity){};
    
    //  Getters & setters
    
    int getQuantity();
    double getPrice();
};

#endif /* defined(____LinkedLists__Widget__) */
