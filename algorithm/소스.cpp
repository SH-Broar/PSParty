#include<stdio.h>
#include<iostream>
#include<Windows.h>

using namespace std;
void Draw()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("=========================================\n");
        printf("|   |   |   |   |   |   |   |   |   |   |\n");
    }
    printf("=========================================\n");
}
void BlackMove()
{

}
void WhiteMove()
{

}
struct point
{
    int x;
    int y;
};
int main()
{
    string MoveWord = "";
    Draw();

    while (MoveWord != "Q" && MoveWord != "q")
    {
        printf("\n\n����Ű WASD, IJKL, 'Q,q'�� ����\n\n");
        cin >> MoveWord;
        switch (MoveWord[0])
        {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 's':
        case 'S':
        case 'd':
        case 'D':
            system("cls");
            Draw();
            BlackMove();
            break;
        case 'i':
        case 'I':
        case 'j':
        case 'J':
        case 'k':
        case 'K':
        case 'l':
        case 'L':
            system("cls");
            Draw();
            WhiteMove();
            break;
        case 'Q':
        case 'q':
            system("cls");
            Draw();
            printf("\n\n���α׷��� �����մϴ�.\n\n");
            break;
        default:
            system("cls");
            Draw();
            printf("�������� �ʴ� ��ɾ� �Դϴ�.");
            break;
        }
    }
}