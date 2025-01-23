#include "logger.h"

std::ofstream current_log_file;

void create_logger(const char* file_path) {
    if (current_log_file.is_open()) {
        current_log_file.close();
    }
    current_log_file.open(file_path, std::fstream::app);
    if (!current_log_file.is_open()) {
        throw std::runtime_error("Unable to open log file!");
    }
}

std::ofstream* get_current_logger() {
    return &current_log_file;
}

void close_logger() {
    if (current_log_file.is_open()) {
        current_log_file.close();
    }
}