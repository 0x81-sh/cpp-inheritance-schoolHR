#pragma once
#include <string>
#include <sstream>

class Map;

// The types the map can contain
union MapTypes {
    std::string *str;
    Map *map;
};

// An entry of the map, with the type specified (as unions do not store which type they contain)
struct MapEntry {
    short typeId;
    MapTypes content;
};

// Map for an actual, proper implementation of JSON, not some string concatenation madness
// Actually works like a JSON object should, and can be nested as deep as needed without any problems in output
// Operates on a principle of key-value pairs

class Map {
    private:
        MapEntry *values;
        std::string *keys;
        int length;

        void incrementSize();
        std::string stringify(int indent) const;

        //don't allow assigning
        Map& operator=(const Map &that);
    public:
        Map();
        Map(const Map &ref);
        ~Map();

        void addElement(const std::string& key, const std::string &content);
        void addElement(const std::string &key, const Map &content);
        std::string toJSON() const;
};

