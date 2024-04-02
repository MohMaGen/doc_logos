#include <logos_back/files_reader.hpp>
#include <fstream>
#include <iostream>
#include <optional>




namespace doc {

    void Document::open() noexcept(false) {
        if (std::holds_alternative<Document::data_type>(this->data)) { 
            throw std::runtime_error("Document is already open");
        }

        auto path = std::get<Document::path_type>(this->data);

        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Can't open file at path: " + path);
        }

        std::vector<uint_8> data (std::istreambuf_iterator<char>(file), {});
        this->data = std::move(data);
        
        file.close();
    }

    std::optional<const Document::data_type &> Document::get_data() const noexcept {
        if (std::holds_alternative<Document::data_type>(this->data)) { 
            return std::get<Document::data_type>(this->data);
        } else {
            return std::nullopt;    
        } 
    }

    std::optional<Document::data_pointer_type> Document::get_data_pointer() const noexcept {
        if (std::holds_alternative<Document::path_type>(this->data)) {
            return std::get<Document::path_type>(this->data);
        } else {
            return std::nullopt;
        } 
    }

    Document::~Document() {}
}