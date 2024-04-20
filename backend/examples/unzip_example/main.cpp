#include <iomanip>
#include <iostream>
#include <string>
#include <zip.h>
#include <pugixml.hpp>




std::string repeat(std::string str, const std::size_t n)
{
    if (n == 0) {
        str.clear();
        str.shrink_to_fit();
        return str;
    } else if (n == 1 || str.empty()) {
        return str;
    }
    const auto period = str.size();
    if (period == 1) {
        str.append(n - 1, str.front());
        return str;
    }
    str.reserve(period * n);
    std::size_t m {2};
    for (; m < n; m *= 2) str += str;
    str.append(str.c_str(), (n - (m / 2)) * period);
    return str;
}

struct Printer: public pugi::xml_tree_walker {
    struct Config {
        size_t indent_size = 3;
        std::string indent_sign { " " };
    };

    size_t indent_size = 3;
    std::string indent_sign { " " };

    Printer(Config cfg) : indent_size(cfg.indent_size), indent_sign(cfg.indent_sign) {}

    virtual bool for_each(pugi::xml_node &node) override {
        std::cout << repeat(indent_sign, this->depth() * indent_size) <<
            "[ " << node.name() << " ]";

        if (*node.value() != '\0') {
            std::cout << " «" << node.value() << "»";
        }

        if (node.attributes_begin() != node.attributes_end()) {
            std::cout << " ( ";

            for (auto attr : node.attributes()) {
                std::cout << attr.name() << " => " << std::quoted(attr.value()) << " ";
            }

            std::cout << " )";
        }

        std::cout << "\n";

        return true;
    }
};


auto main(void) -> int {
    std::string file_name;
    std::cin >> file_name;
    
    int err = 0;
    zip *z = zip_open(file_name.c_str(), 0, &err);

    //Search for the file of given name
    const char *name = "word/document.xml";
    struct zip_stat st;
    zip_stat_init(&st);
    zip_stat(z, name, 0, &st);

    //Alloc memory for its uncompressed contents
    std::string contents (st.size, '\0');

    //Read the compressed file
    zip_file *f = zip_fopen(z, name, 0);
    zip_fread(f, contents.data(), st.size);
    zip_fclose(f);

    //And close the archive
    zip_close(z);
    
    std::cout << contents << "\n\n" << std::endl;

    std::cout << std::endl;
    
    pugi::xml_document doc;
    if (!doc.load_string(contents.c_str())) {
        return -1;
    }

    std::cout << doc.name() << " " << doc.value() << std::endl;

    Printer printer ({.indent_size = 2, .indent_sign = "•"});
    doc.traverse(printer);

    return 0;
}
