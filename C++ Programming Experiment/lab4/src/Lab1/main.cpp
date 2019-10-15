#include <graphics.h>
#include "rect.h"
#include "tria.h"
#include "Circle.h"
#include "controlEge.h"
#include "ege_stream.h"

int main() {
  controlEge a{ 960,600 };
  setfont(28,10, "΢���ź�");
  EgeStream::BasicEgeStream cout(550,60,30);
  using std::endl;
  // Բ�ģ��뾶��������ɫ�����ɫ���Ƿ����
  shape* s[5];
  s[0] = new Circle{ point(269, 200), 50, color(GREEN), color(BLUE), true };
  s[1] = new Circle{ point(80, 120), 30, color(254, 26, 89), color(154, 36, 98), false };
  s[2] = new rect{ point(250, 360), point(340, 460), color(154, 98, 253), color(MAGENTA),
          true };
  s[3] = new tria{ point(356, 214), point(520, 215), point(456, 388),color(132, 189, 233), color(CYAN),
          true};
  s[4] = new Circle;
  s[0]->draw();
  s[1]->draw();
  s[2]->draw();
  s[3]->draw();
  *(s[4]) = *(s[1]);
  cout << cout.purple << "���Ƴ����ĺ�ɫ����ԲԲ�����ꣿ" << endl;
  cout << "(" << (*(s[4]))[0] << "," << (*(s[4]))[1] << ")"<<endl;
  cout << cout.purple << "���Ƴ����ĺ�ɫ����Բ��ԭ���������" << endl;
  cout << cout.pink << std::boolalpha << ((*(s[1])) == (*(s[4]))) << endl;
  cout << cout.purple << "��ɫ��ʵ��Բ > ��ɫ�Ŀ���Բ��" <<endl;
  cout << cout.pink << std::boolalpha << ((*(s[0])) > (* (s[1]))) << endl;
  cout << cout.purple << "��ɫ��ʵ��Բ < ��ɫ���Σ�" << endl;
  cout << cout.orange << "Բ�����" << (*(s[0])).getArea() << "  ���������" << (*(s[2])).getArea() << endl;
  cout << cout.pink << std::boolalpha << ((*(s[0])) < (* (s[2]))) << endl;
  cout << cout.purple << "��ɫ���� > ��ɫ�����Σ�" << endl;
  cout << cout.orange << "���������"<<(*(s[2])).getArea() << "  �����������" << (*(s[3])).getArea() << endl;
  cout << cout.pink << std::boolalpha << ((*(s[2])) > (*(s[3]))) << endl;
  cout << cout.purple << "�±�Խ����ԣ����(*(s[4]))[8]" << endl;
  try {
    cout << (*(s[4]))[8] << endl;
  }
  catch (std::out_of_range& e) {
    cout << cout.red << "Exception: " << e.what() << endl;
  }
  for (int i = 0; i < 5;i++)delete s[i];
  for (; 1;)getch();

  return 0;
}