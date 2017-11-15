#pragma once
#include "../General/Styles.hpp"
#include "../IDisplayable.h"

//������� ����� ��� ��������� ���������
//�� ���� ����������
//����  �����, ��� � ��������� �� �������������
//����� �� ��� �����
class GUIBox : public IDisplayable
{
private:
	//����������� ����� � ��������� ����� ������� � styles.h
	GUIStyle *gstyle;
	TextStyle *tstyle;
	//������� sfml ������
	Sprite sprite;
	//������� ����� (����� ������� ��������� �� ���� ����� ��� ����� ��������)
	//���� �� ������� ����� - �������� �� �����
	Sprite frames[4];
	//����� (���)
	Text text;
	//���� ��� �����, ������� ��� ����������, �� �� ����� ��� ��������
	friend class GUILayer;
protected:
	//����������� ������������, ��� � � IDisplayable
	GUIBox(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
public:
	//�� �� ������� ��� � � IDisplayable
	//��� ���������� ����� �� �� �����������, ���� ������������ - �������� ������� ������������� ������ � ������
	//���� �� ������ ��� �������� ���� - ������� � �� ��� �������, �� ��� ���� �����
	void Draw() override;
	void SetPosition(float x, float y) override;
	void SetPosition(Vector2f position_) override;
	void SetSize(float width, float height) override;
	void SetSize(Vector2f size_) override;
	//������� ������ � ������
	virtual void SetText(char *text);
	virtual void SetGStyle(GUIStyle *gstyle);
	virtual void SetTStyle(TextStyle *tstyle);
	//�������� ������
	//���� ��� ��������� ������� ��� ��������� �������� ���-�� ������ ��������� - ����������� � ����������� ��� �������
	//� ���� ����� - ���� �����������, �� � ������ �������� �� ������������ ������, ����� ���� ���
	virtual void Recalc();
};
