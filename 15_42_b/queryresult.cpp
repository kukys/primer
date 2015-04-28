#include "queryresult.h"
std::ostream&
operator <<(std::ostream &os, const QueryResult &qr)
{
                static int i =0;
    int min,max;
    std::cout<<"input the mix lineNo"<<std::endl;
    std::cin>>min;
    std::cout<<"input the max lineNo"<<std::endl;
    std::cin>>max;
    //! print each line in which the word appears
    for ( auto &index : *qr.sp_lines)
    {
        if(index+1>=min&&index+1<=max)
        {
            i+=1;
            os << "\t(line " << index + 1 << ") ";
            const StrBlobPtr wp(qr.file, index);
            os << wp.deref() << "\n";
        }
        else
            continue;
    }
    if(i)
    {
        os << qr.sought << " occurs " << i << " "
        << "times"   <<  "\n";
   }
   else
   {
    os<<"NO Data";
   }
    return os;

}
