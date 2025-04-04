#include <iostream>

using namespace std;

class oops
{
public:
  string topic;
  int no_of_topics;

  oops(){};

   oops(oops& t)
  {
    topic = t.topic;
    no_of_topics= t.no_of_topics + 5;
    
  }
};

int
main()
{
  oops oop1;
  oop1.topic = "Objec- Programming Language";
  oop1.no_of_topics = 10;
  cout << "Topic: " << oop1.topic << endl;
  cout << "Number of Topics: " << oop1.no_of_topics << endl;

  oops oop2(oop1);
  cout << "Topic: " << oop2.topic << endl;
  cout << "Number of Topics: " << oop2.no_of_topics << endl;

  
  return 0;
}