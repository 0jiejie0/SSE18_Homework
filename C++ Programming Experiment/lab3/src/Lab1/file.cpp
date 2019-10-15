#include "file.h"

void error(int line = 0, int errorCode = 0) {
  static int textY = 5;
  setcolor(0xff0000);
  std::string s1{};
  if (line >= 0) s1 += "��" + std::to_string(line + 1) + "�� ";
  switch (errorCode) {
  case 1:
    s1 += "ȱ�ٲ���";
    break;
  case 2:
    s1 += "�Ƿ�ͼ�δ���";
    break;
  case 3:
    s1 += "�ļ�������";
    break;
  }
  outtextxy(5, textY, s1.data());
  textY += 25;
}

int readFile(const std::filesystem::path& p) {
  std::ifstream in(p);
  if (in.fail()) return 1;
  int i = 1, whereN[100] = { 0 };
  // ��¼���л��з����ڵ��ļ�λ�ú�
  while (!in.eof()) if (in.get() == '\n') whereN[i++] = in.tellg();
  int maxI = i;
  in.close();
  in.open(p);
  // ���Ի�ͼ 3n��Ϊͼ�δ���  3n+1��Ϊ�������Բ���  3n+2��Ϊ��ɫ���Բ���
  for (i = 0; !in.eof() && i < maxI; i += 3) {
    int data[11] = { 0 };
    //��ȡͼ������
    in.seekg(whereN[i], std::ios_base::beg);
    in >> data[0];
    if ((data[0] < 1) || (data[0] > 3)) {
      error(i, 2);
      continue;
    }
    //��ȡ���β���
    in.seekg(whereN[i + 1], std::ios_base::beg);
    switch (data[0]) {
    case 1:  //Բ��
      in >> data[1] >> data[2] >> data[3];
      break;
    case 2:  //������
      in >> data[1] >> data[2] >> data[3] >> data[4] >> data[5] >> data[6];
      break;
    case 3:  //����
      in >> data[1] >> data[2] >> data[3] >> data[4];
      break;
    }
    if (in.tellg() > whereN[i + 2]) {
      error(i + 1, 1);
      continue;
    }
    // ��ȡ��ɫ���Ƿ����
    in.seekg(whereN[i + 2], std::ios_base::beg);
    in >> data[7] >> data[8] >> data[9] >> data[10];
    if ((in.tellg() > whereN[i + 3]) && !in.eof()) {
      error(i + 2, 1);
      //continue;
    }
    //��ͼ
    switch (data[0]) {
    case 1:  //Բ��
      Circle{ point(data[1], data[2]), data[3], color{data[7], data[8], data[9]} ,
                 color{data[7], data[8], data[9]},static_cast<bool>(data[10]) }.draw();
      break;
    case 2:  //������
      tria{ point(data[1], data[2]), point(data[3], data[4]),
               point(data[5], data[6]), color{data[7], data[8], data[9]},
          color{data[7], data[8], data[9]}, static_cast<bool>(data[10]) }
      .draw();
      break;
    case 3:  //����
      rect{
          point(data[1], data[2]), point(data[3], data[4]),
               color{data[7], data[8], data[9]},
               color{data[7], data[8], data[9]}, static_cast<bool>(data[10]) }
      .draw();
      break;
    }
  }
  return 0;
}

int newShape(char* s) {
  std::stringstream in;
  in << s;
  if (in.fail()) return 1;
  int i = 1, whereN[100] = { 0 };
  // ��¼���л�=�з����ڵ��ļ�λ�ú�
  for (int j = 0; s[j]; j++) {
    if (s[j] == '\n') whereN[i++] = j;
  }
  int maxI = i;
  in << s;
  // ���Ի�ͼ 3n��Ϊͼ�δ���  3n+1��Ϊ�������Բ���  3n+2��Ϊ��ɫ���Բ���
  for (i = 0; !in.eof() && i < maxI; i += 3) {
    int data[11] = { 0 };
    //��ȡͼ������
    in.seekg(whereN[i], std::ios_base::beg);
    in >> data[0];
    if ((data[0] < 1) || (data[0] > 3)) {
      error(i, 2);
      continue;
    }
    //��ȡ���β���
    in.seekg(whereN[i + 1], std::ios_base::beg);
    switch (data[0]) {
    case 1:  //Բ��
      in >> data[1] >> data[2] >> data[3];
      break;
    case 2:  //������
      in >> data[1] >> data[2] >> data[3] >> data[4] >> data[5] >> data[6];
      break;
    case 3:  //����
      in >> data[1] >> data[2] >> data[3] >> data[4];
      break;
    }
    if (in.tellg() > whereN[i + 2]) {
      error(i + 1, 1);
      continue;
    }
    // ��ȡ��ɫ���Ƿ����
    in.seekg(whereN[i + 2], std::ios_base::beg);
    in >> data[7] >> data[8] >> data[9] >> data[10];
    /*if ((in.tellg() > whereN[i + 3]) && !in.eof()) {
      error(i + 2, 1);
      // continue;
    }*/
    //��ͼ
    switch (data[0]) {
    case 1:  //Բ��
      Circle{ point(data[1], data[2]), data[3],
             color{data[7], data[8], data[9]},
             color{data[7], data[8], data[9]}, static_cast<bool>(data[10]) }
      .draw();
      break;
    case 2:  //������
      tria{ point(data[1], data[2]),          point(data[3], data[4]),
           point(data[5], data[6]),          color{data[7], data[8], data[9]},
           color{data[7], data[8], data[9]}, static_cast<bool>(data[10]) }
      .draw();
      break;
    case 3:  //����
      rect{ point(data[1], data[2]), point(data[3], data[4]),
           color{data[7], data[8], data[9]}, color{data[7], data[8], data[9]},
           static_cast<bool>(data[10]) }
      .draw();
      break;
    }
  }
  return 0;
}

void save(const std::filesystem::path & p, std::string & str) {
  std::ofstream out(p);
  str.erase(str.end() - 1);//ɾ������һ�����з�
  out << str;
}
