#include "DatabaseManager.h"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& dbFile) {
    if (sqlite3_open(dbFile.c_str(), &db_) != SQLITE_OK) {
        std::cerr << "Failed to open database: " << dbFile << "\n";
        db_ = nullptr;
    }
}

DatabaseManager::~DatabaseManager() {
    if (db_) {
        sqlite3_close(db_);
    }
}

bool DatabaseManager::executeQuery(const std::string& query) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db_, query.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << (errMsg ? errMsg : "unknown") << "\n";
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
bool DatabaseManager::executePrepared(const std::string& query, const std::vector<std::string>& params) {
    sqlite3_stmt* stmt;
    
    // ✅ use this->db
    if (sqlite3_prepare_v2(this->db_, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "SQLite prepare error: " << sqlite3_errmsg(this->db_) << "\n";
        return false;
    }

    for (size_t i = 0; i < params.size(); ++i) {
        if (sqlite3_bind_text(stmt, static_cast<int>(i + 1), params[i].c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
            std::cerr << "SQLite bind error: " << sqlite3_errmsg(this->db_) << "\n";
            sqlite3_finalize(stmt);
            return false;
        }
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "SQLite step error: " << sqlite3_errmsg(this->db_) << "\n";
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
