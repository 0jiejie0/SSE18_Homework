#include <graphics.h>
#include "rect.h"
#include "Circle.h"
#include "controlEge.h"


int main() {
  controlEge a;
  // Բ�ģ��뾶��������ɫ�����ɫ���Ƿ����
  Circle c1{point(269, 200), 50, color(GREEN), color(BLUE), true};
  Circle c2{point(80, 120), 30, color(254, 26, 89), color(154, 36, 98), false};
  c1.draw();
  c2.draw();
  // ���϶��㣬���¶��㣬������ɫ�����ɫ���Ƿ����
  rect r1{point(250, 360), point(340, 460), color(154, 98, 253), color(MAGENTA),
          true};
  rect r2{point(356, 214), point(456, 388), color(132, 189, 233), color(CYAN),
          false};
  r1.draw();
  r2.draw();
  getch();

  return 0;
}