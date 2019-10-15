#include <graphics.h>
#include "rect.h"
#include "tria.h"
#include "Circle.h"
#include "controlEge.h"


int main() {
  //��ʼ����ͼ������(�ɴ���������ڴ�С��Ĭ��640*480)
  controlEge* a = new controlEge{};

  // ��ɫ��֧�ֽ���: �գ�Ĭ�Ϻ�ɫ������д��ɫ����RED����RGB��������255��165��97����16����RGB��������0xc0ffee��

  // Բ���࣬����Ϊ��Բ�ģ��뾶��������ɫ�����ɫ���Ƿ���䣨�����������ɲ�������Ϊ����䣩
  Circle* c1 = new Circle{point(369, 180), 50, color(GREEN), color(0xffc125), true};
  Circle* c2 = new Circle{point(80, 250), 30, color(254, 26, 89), color(154, 36, 98), false};
  Circle* c3 = new Circle{point(125, 179), 88, color(0xffec8b), color(), false};
  // ����Բ��
  c1->draw();
  c2->draw();
  c3->draw();
  // �����࣬����Ϊ�����϶��㣬���¶��㣬������ɫ�����ɫ���Ƿ���䣨�����������ɲ�������Ϊ����䣩
  rect* r1 = new rect{point(250, 360), point(340, 460), color(0xffc1c1), color(MAGENTA),
          true};
  rect* r2 = new rect{point(356, 214), point(456, 388), color(132, 189, 233), color(CYAN),
          false};
  // ���ƾ���
  r1->draw();
  r2->draw();
  // �������࣬����Ϊ����һ�����㣬�ڶ������㣬���������㣬������ɫ�����ɫ���Ƿ���䣨�����������ɲ�������Ϊ����䣩
  tria* t1 = new tria{point(450, 100), point(600, 200),point(500,300), color(CYAN), color(0xffc1c1), true};
  t1->draw();
  // �������
  delete c1;
  c1 = nullptr;
  delete c2;
  c2 = nullptr;
  delete c3;
  c3 = nullptr;
  delete r1;
  r1 = nullptr;
  delete r2;
  r2 = nullptr;
  delete t1;
  t1 = nullptr;
  // ��ͣ
  getch();
  // ɾ����ͼ������
  delete a;
  a = nullptr;
  return 0;
}