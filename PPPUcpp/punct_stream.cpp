#include "punct_stream.h"

using namespace std;

Punct_stream &Punct_stream::operator>>(string &s)
{
    while (!(buffer >> s))
    {
        if (buffer.bad() || !source.good())
            return *this;
        buffer.clear();

        string line;
        getline(source, line);

        for (int i = 0; i < line.size(); ++i)
            if (is_whitespace(line[i]))
                line[i] = ' ';
            else if (!sensitive)
                line[i] = tolower(line[i]);

        buffer.str(line);
    }

    return *this;
}

bool Punct_stream::is_whitespace(char c)
{
    for (int i = 0; i < white.size(); ++i)
        if (c == white[i])
            return true;

    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}
