#include<fstream>
using std::ifstream;
 using std::ofstream;
  using std::endl;
    using std::cerr;
  int main()
  {
   ifstream in;
   in.open("1.txt");
 in .close();
   ofstream out;
   out.open("2.txt")
   out.close();
   Sales_data total;
   if(read(in,total))
    {
      Sales_data treas;
      while(read(in,trans))
      {
        if(total.isbn()==trans.isbn())
          {
            total.combine(trans);
          }
          else{
          print(out,total)<<endl;
          total=trans;
          }
      }
      print(out,total)<<endl;
      
    } else{
      cerr<<"No data?!"<<endl;
  }
}