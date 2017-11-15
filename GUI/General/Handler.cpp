#include "Headers.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//����. ������ fun part
void main() 
{
	//������ �������� ����� gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.frameWid = 5;

	//������ �������� ����� ������
	static TextStyle tst;
	tst.font.loadFromFile("alte-haas-grotesk.regular.ttf");
	tst.color.r = tst.color.g = tst.color.b = 10;
	tst.fontSize = 22;
	tst.align = 'c';
	
	//�������� ���� � ���� ��� �� ��� (������ ���� ����������, ���� ���� �����������, �� ��� � �� ������ ���� ����)
	WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
	GUILayer layer(main.window, Vector2f(0,0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	//��� ������

	//������ �������� ������ "�������" � ���������� �������, ���������� 0,0 � �������� 300,400 �� ��������� ���� ����
	std::shared_ptr<GUIBox> box = layer.CreateBox(0, 0, 300, 400, "omegaLUL", &tst, &gst);

	//���� ������ ������ ����������, ��� � ����� ��� ������
	while (main.window.isOpen())
	{
		main.window.clear();
		Event event;
		while (main.window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				main.window.close();
		}
		layer.Draw();
		main.window.display();
	}
}