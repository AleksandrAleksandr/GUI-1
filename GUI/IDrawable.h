#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

//�������� ���������� �� ������ ����������� �� ����� ������
//�� ���� ����������� �� IDisplayable ���� ��� ����������
//� �� GUIElement ���� ��� ��������� �������
//��������� ��. GUIElement.h
class IDrawable abstract
{
public:
	//�������/������� ������� � �������. ���� ���� �� �������� ������ ���� ���������.
	//������� ������������ GUILayer � ������� ��������� �������, � �� ����!
	//��� ������� ���������� ��. GUIlayer,h
	virtual void SetPosition(float x, float y);
	virtual void SetPosition(Vector2f position_);
	virtual void SetSize(float width, float height);
	virtual void SetSize(Vector2f size_);
	Vector2f GetSize();
	Vector2f GetPosition();
	//������� ���������
	//������ ������� ���������� ������ �������������� �� �� ������
	//�� ������� - � ���� ������� �� ������ ������������ ���� Sprite � RenderWindow
	//��� ������� ���������� ��. IDisplayable.h
	virtual void Draw() = 0;
	//������������, ������� ������� (x,y)
	//����� ������ (������, ������)
	IDrawable(float, float, float, float);
	IDrawable(Vector2f, float, float);
	IDrawable(float, float, Vector2f);
	IDrawable(Vector2f, Vector2f);
	~IDrawable();
protected:
	//������ � �������
	Vector2f size;
	Vector2f position;
};

