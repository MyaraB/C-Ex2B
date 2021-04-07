#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel
{
    class Board
    {
    private:
        unsigned int totalRows;
        unsigned int totalColms;
        unsigned int minRow;
        unsigned int minColm;
        vector<vector<char>> board;
        void adjustSize(unsigned int row, unsigned int col, unsigned int length, Direction direction);

    public:
        Board();
        void post(unsigned int row, unsigned int col, ariel::Direction direction, std::string content);
        std::string read(unsigned int row, unsigned int col, ariel::Direction direction, unsigned int length);
        void show();
    };
}