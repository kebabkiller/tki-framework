#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include <iterator>
#include <fstream>
#include <streambuf>
#include "histogram.h"

void process(std::string& data)
{
    Histogram hs(data);

    hs.print();
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cin >> std::noskipws;
        std::istream_iterator<char> it(std::cin);
        std::istream_iterator<char> end;
        std::string results(it, end);

        process(results);
    }
    if (argc == 2)
    {
        std::ifstream f(argv[1]);
        if (f.is_open() == false)
        {
            std::cerr << "File not found or privileges are not sufficient." << std::endl;
            return 1;
        }

        std::string results((std::istreambuf_iterator<char>(f)),  std::istreambuf_iterator<char>());
        process(results);
    }

    return 0;
}
