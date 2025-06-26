#pragma once
#include <string>
#include <vector>
#include <sqlite3.h>

class DatabaseManager {
public:
    DatabaseManager(const std::string& dbFile);
    ~DatabaseManager();

    bool executeQuery(const std::string& query);

    
bool executePrepared(const std::string& query, const std::vector<std::string>& params);

private:
    sqlite3* db_;
};
