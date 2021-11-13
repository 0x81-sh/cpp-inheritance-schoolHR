#include "Map.h"

void Map::incrementSize() {
    std::string *tempStr = new std::string[length + 1];
    MapEntry *tempEntries = new MapEntry[length + 1];

    for (int i = 0; i < length; i++) {
        tempStr[i] = keys[i];
        tempEntries[i] = values[i];
    }

    length++;

    delete[] keys;
    delete[] values;

    values = tempEntries;
    keys = tempStr;
}

std::string Map::stringify(int indent) const {
    std::string spacer;
    for (int i = 0; i < indent; i++) {
        spacer += "  ";
    }

    std::ostringstream x;
    x << "{\n";

    // concatenate the values of each key, if needed, use recursion to go through children
    for (int i = 0; i < length; i++) {
        x << spacer << "  " << "\"" << keys[i] << "\": ";

        if (values[i].typeId == 0) {
            x << *values[i].content.str;
        } else if (values[i].typeId == 1) {
            x << values[i].content.map->stringify(indent + 1);
        }

        if (i + 1 != length) x << ",";
        x << "\n";
    }

    x << spacer << "}";
    return x.str();
}

Map::Map() {
    values = new struct MapEntry[0];
    keys = new std::string[0];
    length = 0;
}

Map::Map(const Map &ref) {
    length = ref.length;
    values = new struct MapEntry[length];
    keys = new std::string[length];

    // copy the arrays, and also create copies of the data pointers to avoid two references to one element
    for (int i = 0; i < length; i++) {
        keys[i] = std::string(ref.keys[i]);
        values[i].typeId = ref.values[i].typeId;

        if (values[i].typeId == 0) {
            values[i].content.str = new std::string(*ref.values[i].content.str);
        } else if (values[i].typeId == 1) {
            values[i].content.map = new Map(*ref.values[i].content.map);
        }
    }
}

Map::~Map() {
    delete[] keys;

    // delete the actual data pointers of each element
    for (int i = 0; i < length; i++) {
        if (values[i].typeId == 0) {
            delete values[i].content.str;
        } else if (values[i].typeId == 1) {
            delete values[i].content.map;
        }

    }
    delete[] values;
}

void Map::addElement(const std::string &key, const std::string &content) {
    incrementSize();

    keys[length - 1] = key;
    values[length - 1].typeId = 0;
    values[length - 1].content.str = new std::string(content);
}

void Map::addElement(const std::string &key, const Map &content) {
    incrementSize();

    keys[length - 1] = key;
    values[length - 1].typeId = 1;
    values[length - 1].content.map = new Map(content);
}

std::string Map::toJSON() const {
    return stringify(0);
}
