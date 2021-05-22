#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "demogData.h"
#include "psData.h"
#include "parse.h"
#include "visitorCombine.h"
#include "statTool.h"
#include "visitor.h"

#include "visitorCombineState.h"
#include "visitorCombineCounty.h"
#include "visitorCombineKey.h"


using namespace std;
//README: This is a paired lab. The memebers are Jiayang Zhao and Ziyue Wang.
int main() {
    vector<shared_ptr<regionData>> pileOfData;

    read_csv(pileOfData, "police_shootings_cleaned.csv", POLICE);
    read_csv(pileOfData, "county_demographics.csv", DEMOG);

    visitorCombineState a;
    statTool::createStateData(pileOfData, a);

    a.printAllCombo(&demogData::getBAupCount, &psCombo::getNumMentalI);

 
    return 0;
}

