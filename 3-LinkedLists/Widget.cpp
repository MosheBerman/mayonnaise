//
//  Widget.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Widget.h"

//
//  Allocates and returns a fresh widget
//

WidgetPointer createWidget(){
    WidgetPointer p;
    p = (WidgetPointer)malloc(sizeof(struct Widget));
    return (p);
}

//
//  Free up the memory consumed by a given node
//

void freeNode(WidgetPointer p){
    free(p);
}

//
//  Checks if the queue is empty
//

bool empty(struct WidgetQueue *pointerQueue){
    return pointerQueue->front == NULL;
}

//
//  Insert a given price and quantity into the queue
//

void insert(struct WidgetQueue *pointerQueue, int quantity, double price){
    
    WidgetPointer pointer;
    
    pointer = createWidget();
    
    pointer->price = price;
    pointer->quantity = quantity;
    pointer->next = NULL;
    
    if (pointerQueue->rear == NULL) {
        pointerQueue->front = pointer;
    }
    else{
        (pointerQueue->rear)->next = pointer;
    }
    
    pointerQueue->rear = pointer;
    
    
}


//
//  Remove the first item from the queue
//  and returns its value
//

Widget remove(struct WidgetQueue *queue){
    
    WidgetPointer pointer;
    Widget widget;
    
    if (empty(queue)) {
        
    }
    
    pointer = queue->front;
    widget.price = pointer->price;
    widget.quantity = pointer->quantity;
    
    queue->front = pointer->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    freeNode(pointer);
    return widget;
}
