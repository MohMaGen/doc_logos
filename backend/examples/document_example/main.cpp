#include <logos_back/files_reader.hpp>

int main() {
    std::strin name;
    std::cout << "Enter file name: " << std::endl;
    std::cin >> name;
    
    doc::Document document(name);

    std::cout << "Opening file..." << std::endl;
    
    if (auto file = document.get_data()) {
        std::cout << "File opened" << "\n";
         << "File size: " << file->size() << "\n";
         << "File content: " << "\n";
        
        for (auto byte : *file) {
            std::cout << std::hex << byte; 
        }
        
        std::cout << std::endl;
    } else {
        std::cout << "Can't read file" << std::endl; 
    }
    
    return 0;
}