/**
 * 
 **/

#include <string>
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

std::string strip_query_key(const std::string & s, const std::string & key)
{
    // Find query begin '?' character.
    size_t question_mark = s.find('?');

    // Return a copy of the original string
    // if there is no query.
    if ( question_mark == std::string::npos )
    {
        return std::string{s};
    }

    // Copy string the begining of the string
    // until but not the '?'.
    std::string output{s, 0, question_mark};

    uint8_t count = 0;                  // Query counter.
    size_t  begin = question_mark + 1;  // Begin start pointing to next char after '?'.
    size_t  end   = begin;              // End of the query.
    std::string k{key};                 // Key '=' terminated.
    k += '=';

    do {
        // Find the end of this query.
        end = s.find('&', begin);
        if ( end == std::string::npos )
        {
            end = s.length();
        }

        // Append query if it is not the one to be stripped.
        if ( s.find(k, begin) != begin )
        {
            // Add '?' before the 1st query and '&' to next ones.
            output += (count++ == 0) ? '?' : '&';

            // Append query.
            output.append(s, begin, end - begin);
        }

        // Step to the next query.
        begin = end + 1;

    } while (end < s.length());

    return output;
}

int main (int argc, char ** argv)
{
    const std::string key{"sessionType"};

    // no query
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001"};
        std::string output = strip_query_key(input, key);
        assert(input == output);
    }

    // only session type query
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?sessionType=LIVE"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001");
    }

    // no session type substring case
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?channelId=4678"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(input == output);
    }

    // LIVE session type
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?channelId=4678&sessionType=LIVE"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?channelId=4678");
    }
    
    // RECORD session type
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?channelId=4678&sessionType=RECORD"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?channelId=4678");
    }

    // Strip channelId
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?channelId=4678&sessionType=RECORD"};
        std::string output = strip_query_key(input, "channelId");
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?sessionType=RECORD");
    }

    // session type is the only query
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?sessionType=LIVE"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001");
    }

    // session type not the last query
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?sessionType=RECORD&channelId=4678"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?channelId=4678");
    }

    // 2 sesion type queries
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?sessionType=RECORD&channelId=4678&sessionType=RECORD"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?channelId=4678");
    }

    // 2 other queries
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?sessionType=RECORD&channelId=4678&key=VALUE"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?channelId=4678&key=VALUE");
    }

    // malformed query - no '?'
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001&sessionType=RECORD&channelId=4678"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001&sessionType=RECORD&channelId=4678");
    }

    // marformed query - no key following '?'
    {
        const std::string input{"so+wyvsa://239.232.0.72:5001?"};
        std::string output = strip_query_key(input, key);
        //cout << "output " << output << endl;
        assert(output == "so+wyvsa://239.232.0.72:5001?");
    }

    return 0;
}
