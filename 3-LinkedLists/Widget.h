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

/*
    This file defines two structs for us to
    work with.
 
    Widget contains a price and a quantity.
    WidgetQueue implements a queue.
 
    Also defined here are the queue methods.
 
*/

struct Widget {
    
    //Info fields
    double price;
    int quantity;
    
    //List fields
    struct Widget *next;
};

typedef struct Widget *WidgetPointer;

struct WidgetQueue {
    WidgetPointer front, rear;
};

/*
 
 The queue methods are defined here.
 
 */

//
//  Allocates and returns a fresh widget
//

WidgetPointer createWidget();

//
//  Free up the memory consumed by a given node
//

void freeNode(WidgetPointer p);

//
//  Checks if the queue is empty
//

bool empty(struct WidgetQueue *pointerQueue);

//
//  Insert a given price and quantity into the queue
//

void insert(struct WidgetQueue *pointerQueue, int quantity, double price);

//
//  Remove the first item from the queue
//  and returns its value
//

Widget remove(struct WidgetQueue *queue);

#endif /* defined(____LinkedLists__Widget__) */
