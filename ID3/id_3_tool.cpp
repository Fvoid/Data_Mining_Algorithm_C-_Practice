//
// Created by hvoid on 10/18/18.
//

#include "id_3_tool.hpp"

ID3Tool::ID3Tool(string dataPath) {
    read_data_file(dataPath, this->dataTable);

    //extract all attribute name except Day
    for(int i = 1; i < dataTable[0].size(); i++){
        this->attrName.push_back(dataTable[0][i]);
    }

    //extract values for each attr
    //i is the col
    //j is row
    for(int i = 1; i < dataTable[0].size(); i++){
        string attr_tmp = dataTable[0][i];
        set<string> attr_val_tmp;
        for(int j = 1; j < TOTAL_DATA_SIZE; j++){
            attr_val_tmp.insert(dataTable[j][i]);
        }
        attrValMap.insert(pair<string, set<string>>(attr_tmp, attr_val_tmp));
    }

}

vector<double> ID3Tool::compute_entrophy(string targetAttr, bool isResultEn) {
    int totalVal = attrValMap[targetAttr].size();
    map<string, int> attrValCount;
    int targetCol = 0;

    //find target row
    for(int i = 1; i < dataTable[0].size(); ++i){
        if(dataTable[0][i] == targetAttr){
            targetCol = i;
            break;
        }
    }

    //initialize attr value count
    //create attr count map
    for(auto x : attrValMap[targetAttr]){
        attrValCount.insert(pair<string, int>(x, 0));
    }

    if(isResultEn){
        for(int i = 1; i < TOTAL_DATA_SIZE; ++i){
            attrValCount[dataTable[i][targetCol]]++;
        }
    }else{

    }


    //calculate entrophy
    map<string, int>::iterator it = attrValCount;

}


void ID3Tool::read_data_file(string filePath, vector<vector<string>> &dataOut) {
    string tmpLine = "";
    ifstream dataStream(filePath);

    if(!dataStream){
        cerr << "Unable to Open File.\n";
    }

    while(getline(dataStream, tmpLine)){
        vector<string> tmp;
        boost::algorithm::split(tmp, tmpLine, boost::is_any_of(" "));
        dataOut.push_back(tmp);
    }
    //minus the attr row
    this->TOTAL_DATA_SIZE = dataOut.size() - 1;
}