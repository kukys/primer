class StrBlob
{
  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlod();
    StrBlod(std::initializer_list<std::string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //���ӻ�ɾ��Ԫ��
    
  void push_back(const std::string &t){data->pusn_back(t);}
  void pop_back();
  
  const std::string & front();
    
  const std::string & back();
    
  private:
    std::shared_ptr<std::vector<str::string>> data;
      
    void check(size_type i,const std::string &msg) const; 
}
 void StrBlob::check(size_type i,const string &msg) const
  {
    if(i>=data->size())
      {
        throw out_of_range(msg);
      }
  }
  const std::string & StrBlob::front()
    {
      check(0,"front on empty StrBlob");
      return data->front();
    }
  const string & StrBlob::back()
    {
      check(0,"back on empty StrBlob");
      return data->back();
    }
  const string & StrBlob::pop_back()
    {
      check(0,"pop_back on empty StrBlob");
      return data->pop_back();
    }
      