#include <map>
#include <string>

class Histogram {
    private:
    std::map<char,int> data;

    public:
    Histogram(std::string& input)
    {

        for (auto c : input)
        {
            if (data.find(c) == data.end())
                data[c] = 1;
            else
                data[c]++;
        }
    };

    int count_of(char c)
    {
        if (data.find(c) == data.end())
            return 0;

        return data[c];
    }

    void print()
    {
        for (char c='A'; c <= 'z'; c++)
        {
            std::cout << "c: " << c << " " << count_of(c) << std::endl;
        }
    }
};
