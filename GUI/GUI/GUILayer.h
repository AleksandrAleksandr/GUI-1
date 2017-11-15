#pragma once
#include <memory>
#include <vector>
#include <string>
#include "GUIButton.h"

//�� ���� Layout, ����� ������������ �������� ���������� 
//��� �������� ��������� ���� ��� ����, ������� � ������ � visual studio
class GUILayer : IDrawable
{
private:
	//������� ��������� �� ���� ����
	//���������� ����� ��� ����� ���������!
	std::vector<std::shared_ptr<GUIBox>> boxes;
	std::vector<std::shared_ptr<GUIButton>> buttons;
	//��������� �� ���� �� ������� ��������� ��� ����
	RenderWindow* window;
public:
	//������������, �� �������� �� ���� ����, ������ ����������� ��� ���� � �������
	//���� ��� ������ ��� ��������� ����������� (0,0) � (����������, ����������)
	//��������� ���� ��������� ��� ����� ���� �� �������� :)
	GUILayer(RenderWindow &Swindow, Vector2f, Vector2f);
	void SetWindow(RenderWindow &Swindow);//�������� �� ���� �� ����������� � �� ���������� ���� �����

	//�������� ������!
	//�� ��������� ������� � ��������� ���������� ���������� shared_ptr<���������������> (�������, �� ����� ���� �������� ����, ���������� ����� �� ������� ���������)
	//��� ���������� ������������:
	//���������� ����� ������ (���� �� 1) ��� ����� ���������
	//�� ������ ��������� �������, ��������� ��� � ������� (������� ����) � ���������� shared_ptr �� ���� (��� ��� ������������ �������� � handler.cpp)
	//������� ���������� ��� � GUILayer.cpp, ��� �� �������, �� ��� ������ ���������� (�������� �� �����)
	std::shared_ptr<GUIBox> CreateBox(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

	std::shared_ptr<GUIButton> CreateButton(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());

	//��� ����� ������������� ��� ���������� �������� � ����������, �������������� ��� ���������� ����� ����� ���������
	//�� ���� ��������� � ���� ����� (���� � GUILayer.cpp)
	void Draw() override;
};