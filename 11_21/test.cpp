/*
�ٶ�word_count��һ��string��size_t��map,word��һ��string,��������ѭ��������
*/
while(cin>>word)
{
  ++word_count.insert({word,0}).first->second;
}
//���11_20