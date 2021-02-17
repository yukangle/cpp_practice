#include <iostream>

#include "TextQuery.h"
#include "open_file.h"
#include "query.h"
#include "and_query.h"
#include "or_query.h"
#include "not_query.h"
#include "word_query.h"

using std::endl;
using std::cout;
using std::cerr;

int main(int argc, char **argv)
{
    ifstream infile;
    if (argc < 2 || !open_file(infile, argv[1])) {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }

    TextQuery tq;
    tq.read_file(infile);

    Query q = Query("fiery") & Query("bird") | Query("wind");

    q.eval(tq);
    q.display(cout);
    
    cout << endl;

    return 0;

}