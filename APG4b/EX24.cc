//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

// �ȉ��ɁA24���ԕ\�L�̎��v�\���� Clock ���`����

// Clock�\���̂̃����o�ϐ�������
//   int hour    ���Ԃ�\�� (0~23�̒l���Ƃ�)
//   int minute  ����\��   (0~59�̒l���Ƃ�)
//   int second  �b��\��   (0~59�̒l���Ƃ�)

struct Clock{
	int hour;
	int minute;
	int second;

// �����o�֐� set �̒�`������
//   �֐���: set
//   ����: int h, int m, int s (���ꂼ�ꎞ�A���A�b��\��)
//   �Ԃ�l: �Ȃ�
//   �֐��̐���:
//     ���E���E�b��\��3�̈������󂯎��A
//     ���ꂼ��A�����o�ϐ� hour, minute, second �ɑ������

	void set(int h, int m, int s){
		hour = h;
		minute = m;
		second = s;
	}

// �����o�֐� to_str �̒�`������
//   �֐���: to_str
//   ����: �Ȃ�
//   �Ԃ�l: string�^
//   �֐��̎d�l:
//     �����o�ϐ����\�������̕������Ԃ�
//     �����̕�����͎��̃t�H�[�}�b�g
//     "HH:MM:SS"
//     HH�AMM�ASS�͂��ꂼ�ꎞ�ԁA���A�b��2���ŕ\����������

	string to_str(){
		string ret;
		if(hour < 10) ret += '0';
		ret += to_string(hour);
		ret += ':';

		if(minute < 10) ret += '0';
		ret += to_string(minute);
		ret += ':';

		if(second < 10) ret += '0';
		ret += to_string(second);

		return ret;
	}
// �����o�֐� shift �̒�`������
//   �֐���: shift
//   ����: int diff_second
//   �Ԃ�l: �Ȃ�
//   �֐��̎d�l:
//     diff_second �b���������o�ϐ����\��������ύX����(�������A���t�₤�邤�b�͍l���Ȃ�)
//     diff_second �̒l�����̏ꍇ�A������߂�
//     diff_second �̒l�����̏ꍇ�A������i�߂�
//     diff_second �̒l�� -86400 ~ 86400 �͈̔͂���Ƃ肤��
	void shift(int diff_second){
		int total_sec;
		total_sec = hour * 3600 + minute * 60 + second;
		total_sec += diff_second;
		if(total_sec < 0){
			total_sec = 24 * 3600 + total_sec;
		}

		second = total_sec % 60;
		total_sec /= 60;

		minute = total_sec % 60;
		hour = total_sec / 60;
		if(hour == 24) hour = 0;
	}

};
// -------------------
// ���������͕ύX���Ȃ�
// -------------------

int main() {
  // ���͂��󂯎��
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock�\���̂̃I�u�W�F�N�g��錾
  Clock clock;

  // set�֐����Ăяo���Ď�����ݒ肷��
  clock.set(hour, minute, second);

  // �������o��
  cout << clock.to_str() << endl;

  // ���v��i�߂�(�߂�)
  clock.shift(diff_second);

  // �ύX��̎������o��
  cout << clock.to_str() << endl;
}
