//
// Created by hvoid on 10/18/18.
//

#ifndef ID3_ID_3_TOOL_HPP
#define ID3_ID_3_TOOL_HPP

#include "utils.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <boost/algorithm/string.hpp>


/**
 * ID3 Algorithm procedure:
 * 1)calculate entrophy for result variable
 *
 */



class ID3Tool {
private:

    //this is to store data as it is in the file
    vector<vector<string>> dataTable;
    //contain all attr name except Day
    vector<string> attrName;
    //map each attr to all unique values
    map<string, set<string>> attrValMap;
    int TOTAL_DATA_SIZE = 0;
    double ALL_ATTR_ENTROPHY = 0;


    //This function is to read data as a string table
    void read_data_file(string filePath, vector<vector<string>> &dataOut);
    vector<double> compute_entrophy(string targetAttr, bool isResultEn);
    double compute_information_gain(vector<double> entrophy)

public:

    //read in data and init attr and its value
    ID3Tool(string dataPath);

    //calculate entrophy and GINI and decide attr oder of tree splitting
    vector<string> get_split_order();


};


#endif //ID3_ID_3_TOOL_HPP
