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
public:
    Widget():price(0), quantity(0){
        next =  NULL;
        if (first == NULL) {
            first = this;
        }
        last = first;
    };
    
    Widget(double _price,int _quantity):price(_price), quantity(_quantity){
        next = NULL;
        if (first == NULL) {
            first = this;
        }
        last = first;
    };
    
    double price;
    int quantity;
    
    //  Linked List
    
    Widget *next;
    
    static Widget *first;
    static Widget *last;
    
    void enqueue(Widget *widget);
    Widget* dequeue();
};



#endif /* defined(____LinkedLists__Widget__) */
