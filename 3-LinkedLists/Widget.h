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
    Widget():price(0), quantity(0){
        next =  NULL;
        previous = NULL;
        first = this;
        last = first;
    };
    
    Widget(double _price,int _quantity):price(_price), quantity(_quantity){
        first = this;
        last = first;
    };
    
    //  Getters and setters
    
    int getQuantity();
    void setQuantity(int);
    
    double getPrice();

    //  Linked List
    
    Widget *next;
    Widget *previous;
    
    static Widget *first;
    static Widget *last;
};

//
//  Linked List
//

void makeNode(Widget *widget, double price, int quantity){
    Widget *w = new Widget(price, quantity);
    w->previous = widget->last;
    w->previous->next = w;
    widget->last = w;
}

Widget* freeNode(Widget *widget){
    Widget *w = widget->first;
    
    if (w != NULL) {
        w->first = w->next;
    }
    
    return w;
}

#endif /* defined(____LinkedLists__Widget__) */
