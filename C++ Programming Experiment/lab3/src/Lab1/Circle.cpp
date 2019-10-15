#include "Circle.h"

Circle::~Circle() { 
  delete centerPoint;
  cNum--; 
}

Circle::Circle() { 
  this->centerPoint = new point;
  cNum++; 
};

Circle::Circle(const Circle& c) :shape(c){
  this->centerPoint = new point{*(c.centerPoint)};
  cNum++;
}

Circle::Circle(point centerPoint, int r, color lineColor, color fillColor,
       bool isFilled)
    : shape(lineColor, fillColor, isFilled), r(r) {
  this->centerPoint = new point{centerPoint};
  cNum++;
}

Circle::Circle(point centerPoint, int r, color lineColor)
    : shape(lineColor, CYAN, false), r(r){
  this->centerPoint = new point{centerPoint};
  cNum++;
}

void Circle::draw() {
    setcolor(getLineColor());
    if (getIsFilled()) {
      setfillcolor(getFillColor());
      fillellipse(centerPoint->getX(), centerPoint->getY(), r, r);
    } else
    circle(centerPoint->getX(), centerPoint->getY(), r); 
  }


void Circle::setR(int r) {
    Circle::r = r;
  }

void Circle::setCenterPoint(point centerPoint) {
  *(this->centerPoint) = centerPoint;
  }

int Circle::getR() { return r; }

point Circle::getCenterPoint() { return *centerPoint; }
