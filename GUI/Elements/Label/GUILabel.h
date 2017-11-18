#pragma once
#include "../../GUI/GUIBox.h"
class GUILabel : public GUIBox
{
private:
    friend class GUILayer;
    Text text; /*!< ����� */ 
    Texture *iconT; /*!< �������� ������ */ 
    Sprite *icon; /*!< ������, ������� ����� ���������� */ 

protected:
    //! �����������
    /*!
    ������� ��������� label
    */
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

    //! �����������
    /*!
    ������� ��������� label
    */
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

    //! �����������
    /*!
    ������� label, ��������� �� ����� ������, ���� ����� ����� ������ �������.
    ���� ����� �����, �� ������� label, ���������� ������ � �����
    \param renderWindow_ ����, � ������� ������
    */
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);
    
    //! �����������
    /*!
    ������� label, ��������� �� ����� ������, ���� ����� ����� ������ �������.
    ���� ����� �����, �� ������� label, ���������� ������ � �����
    \param renderWindow_ ����, � ������� ������
    */
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);
    
    //! �������������� ������� Draw
    virtual void Draw() override;

    //! �������������� ������� Recalc
    virtual void Recalc() override;
};

