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
	virtual void Draw() override;
	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width, float height) override;
	virtual void SetSize(Vector2f size_) override;
	//������� ������ � ������
	virtual void SetText(char *text);
	virtual void SetGStyle(GUIStyle *gstyle);
	virtual void SetTStyle(TextStyle *tstyle);

	//������ ���������� ����������� �������!!!
	void handleEvent(const sf::Event& event) override
	{
	//������� ���� �� ������ ����� ������ ����
	if (event.type == sf::Event::MouseButtonPressed)
	{
	std::cout << "Mouse button pressed" << std::endl;
	//�������, ���� �� ��� ����� ������
	if (event.mouseButton.button == sf::Mouse::Left)
	{
	std::cout << "It was LEFT button" << std::endl;
	std::cout << "mouse x: " << event.mouseButton.x << std::endl;
	std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	//� ���� ������ �� ���� �������, ������� ��������� "Pressed element!"
	if (sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
	std::cout << "Pressed element!" << std::endl;
	}
	std::cout << std::endl;
	}
	};

	//�������� ������
	//���� ��� ��������� ������� ��� ��������� �������� ���-�� ������ ��������� - ����������� � ����������� ��� �������
	//� ���� ����� - ���� �����������, �� � ������ �������� �� ������������ ������, ����� ���� ���
	virtual void Recalc();
};
