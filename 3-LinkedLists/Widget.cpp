//
//  Widget.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 12/2/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include "Widget.h"

Widget *Widget::first;
Widget *Widget::last;

int Widget::getQuantity(){
    return quantity;
}

void Widget::setQuantity(int _quantity){
    if(_quantity >=0){
        quantity = _quantity;
    }
}

double Widget::getPrice(){
    return price;
}