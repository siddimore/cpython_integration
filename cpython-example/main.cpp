#include <Python.h>
#include <iostream>
#include <fstream>
#include <sstream>

std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char *argv[]) {
    Py_Initialize();

    try {
        std::string code = read_file("script.py");

        std::cout << "Running embedded Python script...\n";
        PyRun_SimpleString(code.c_str());
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    Py_Finalize();
    return 0;
}