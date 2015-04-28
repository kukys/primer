#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "notquery.h"

int main()
{
    std::ifstream file("E:/mingw/project/15_39/test.txt");

    TextQuery tQuery(file);

	  Query q = Query("hair")|Query("Alice");

    std::cout << q.eval(tQuery);

	std::cin.get();
    return 0;
}
