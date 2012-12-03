//
//  Widget.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Widget.h"

Widget *Widget::first = NULL;
Widget *Widget::last = NULL;

//
//  Linked List
//

void Widget::enqueue(Widget *widget){
    if (last != NULL) {
        last->next = widget;
    }
    if (first == NULL) {
        first = widget; //  If the list was empty, set first widget
    }
    last = widget;
}

Widget* Widget::dequeue(){
    Widget *widget = first;
    
    if (widget != NULL) {
        first = widget->next;
    }
    
    if (widget == widget->last) {
        widget = last = NULL;
    }
    
    return widget;
}