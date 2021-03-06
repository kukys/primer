#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "e:\mingw\project\7\Sales_Data.h"     // Sales_data class.

inline bool 
compareIsbn(const Sales_Data &sd1, const Sales_Data &sd2)
{
    return sd1.isbn().size() < sd2.isbn().size();
}

int main()
{
    Sales_Data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_Data> v{d1, d2, d3, d4, d5};

    //! @note   the elements the iterators pointing to
    //!         must match the parameters of the predicate.
    std::sort(v.begin(), v.end(), compareIsbn);

    for(const auto &element : v)
        std::cout << element.isbn() << " ";
    std::cout << std::endl;

    return 0;
  }