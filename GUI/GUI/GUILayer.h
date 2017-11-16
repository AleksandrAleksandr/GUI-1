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
	//� CreateElement() ������� ��� ����� ��������� ���������� share_ptr �� ���� �������� � ���� ������
	//����� ��� ������� - elementType
	//����� � CreateElementType()
	//� ����� ������ 
	//elements.push_back(���_shared_ptr_�� ��� �������);
	//return ���_shared_ptr_�� ��� �������;
	std::vector<std::shared_ptr<IDisplayable>> elements;
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
	std::shared_ptr<GUIBox> CreateBox(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

	std::shared_ptr<GUIButton> CreateButton(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());

	//��� ����� ������������� ��� ���������� �������� � ����������, ������� ��� �� ����
	void Draw() override;
};