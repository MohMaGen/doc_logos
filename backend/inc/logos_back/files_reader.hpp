#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <variant>
#include <vector>

namespace doc {

    class Document { 
        public:
            using data_type = std::vector<uint8_t>;
            using path_type = std::string;
            using data_pointer_type = std::atomic<std::shared_ptr<data_type>>;
    
            Document() = delete;
            Document(path_type path_to_file) : data(path_to_file) {}
            Document(data_type data) : data(data) {}

            void open() noexcept(false);

            [[nodiscard("Return value is not used")]]
            std::optional<const data_type &> get_data() const noexcept;

            [[nodiscard("Return value is not used")]]
            std::optional<data_pointer_type> get_data_pointer() const noexcept;
    
            ~Document();
    
        private:
            std::variant<data_type, path_type> data;
    };

    
}