//
//  main.cpp
//  3-LinkedLists
//
//  Created by Moshe Berman on 11/28/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//
//  This is the third of six assignments in Professor Lowenthal's Data Structures class.
//

#include <iostream>
#include <fstream>

#include "FileIO.h"

#include "Record.h"
#include "StoreKeeper.h"
#include "Widget.h"

int main(int argc, const char * argv[])
{
    
    //
    //  Set up the file
    //

    ifstream records;
    std::string fileName = "Input.txt";
    
    if(!openInputStream(records, fileName)){
        std::cout << "Couldn't open " << fileName << std::endl;
        throw runtime_error("Couldn't open " + fileName);
    }
    
    //
    //  A line buffer
    //
    
    std::string line;
    
    //
    //  Skip the first two lines, since
    //  they contain unusable data and
    //  whitespace.
    //
    
    getline(records, line);
    getline(records, line);

    //
    //  Create a storekeeper instance
    //  to process sales as we go.
    //
    
    Storekeeper *shop = new Storekeeper();
    
    //
    //  Process the input files.
    //
    
    while (getline(records, line)) {
        
        Record r = Record(line);
        
        if (r.getRecordType() == kRecordTypePromotion) {
            shop->setPromotionRate(r.getSaleAmount());
            shop->beginPromotion();
        }
        else if(r.getRecordType() == kRecordTypeSale){
            shop->sellWidgets(r.getQuantity());
        }
        else if(r.getRecordType() == kRecordTypeReciept){
            shop->receiveNumWidgetsAtPrice(r.getQuantity(), r.getPricePerWidget());
        }
    }
    
    shop->printOverstock();
    
    return 0;
}
