#include "rect.h"
#include <string>

static int textY = 10;

rect::rect(point upPoint, point downPoint, color lineColor, color fillColor,
           bool isFilled)
    : shape(lineColor, fillColor, isFilled) {
  this->upPoint = new point{upPoint};
  this->downPoint = new point{downPoint};
  rNum++;
}

rect::rect() {
  this->upPoint = new point;
  this->downPoint = new point;
  rNum++;
}

rect::rect(const rect& r) : shape(r) {
  this->upPoint = new point{*(r.upPoint)};
  this->downPoint = new point{*(r.downPoint)};
  rNum++;
}

rect::~rect() {
  delete upPoint;
  delete downPoint;
  rNum--;
  std::string s1{"����ʣ��������" + std::to_string(rNum)};
  outtextxy(200, textY, s1.data());
  textY += 30;
}

rect::rect(point upPoint, point downPoint, color lineColor)
    : shape(lineColor, CYAN, false) {
  this->upPoint = new point{upPoint};
  this->downPoint = new point{downPoint};
  rNum++;
}
void rect::draw() {
  setcolor(getLineColor());
  if (getIsFilled()) {
    setfillcolor(getFillColor());
    bar(upPoint->getX(), upPoint->getY(), downPoint->getX(), downPoint->getY());
  }
  rectangle(upPoint->getX(), upPoint->getY(), downPoint->getX(),
              downPoint->getY());
}

void rect::setUpPoint(point upPoint) { *(this->upPoint) = upPoint; }

void rect::setDownPoint(point downPoint) { *(this->downPoint) = downPoint; }

point rect::getUpPoint() { return *upPoint; }

point rect::getDownPoint() { return *downPoint; }