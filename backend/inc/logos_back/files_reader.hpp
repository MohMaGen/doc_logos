#pragma once

#include <cstdint>
#include <memory>
#include <vector>


namespace doc {
    class Document {
        public:
            using data_type = std::shared_ptr<std::vector<uint8_t>>;


            Document() = delete;
            Document(data_type data) : data(data) {}

        private:
            data_type data;
    };
}
