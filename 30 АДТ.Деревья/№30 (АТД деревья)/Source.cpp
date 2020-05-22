#include <glut.h>
#include "tree.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
int winW = 1600;
int winH = 720;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	glutInit(&argc, argv);
	cout << "======================================================" << endl;
	cout << "[Add] добавляет элемент в дерево, если такового нет," << endl;
	cout << "если он есть, то удалит его из дерева." << endl;
	cout << "[Delete] удаляет заданный элемент из дерева, он существует." << endl;
	cout << "[info in console] выводит всю информацию об элементах в консоль." << endl;
	cout << "Изначально рисуется сбалансированное дерево размером 7." << endl;
	cout << "======================================================" << endl;
	
	drawTree(winW, winH, 5, 7);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(winW, winH);
	glutCreateWindow("Tree (+ и - в консоли)");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mouseClick);
	glutMainLoop();
}