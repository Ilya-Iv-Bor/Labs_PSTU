#include <glut.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

class Tree {
private:
	string country;
	Tree* left;
	Tree* right;
	Tree* parent;
	char b;
	int x;
	int y;
	bool cursor;
public:
	Tree(string);
	~Tree();
	static Tree* balancedTree(int n); // Создание дерева
	void addLeftTree(Tree* tree); // Добавление левого поддерева
	void addRightTree(Tree* tree); // Добавление правого поддерева
	int height(Tree*); // Получение высоты ид. баланс. дерева
	void reorderSetCoords(Tree* tree, char dir); //расстановка координат и типов узлов на основе //размеров окна
	void reorderAtributes(Tree* tree); //печать всех атрибутов
	void drawAtribute(); //отрисовка типа и значения узла под кнопками

	int getX() { return this->x; }
	int getY() { return this->y; }
	char getB() { return this->b; }
	Tree* getLeft() { return this->left; }
	Tree* getRight() { return this->right; }
	string getCountry() { return this->country; }
	Tree* getParent() { return this->parent; }
	bool getCursor() { return this->cursor; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setB(char b) { this->b = b; }
	void setLeft(Tree* left) { this->left = left; }
	void setRight(Tree* right) { this->right = right; }
	void setCountry(string country) { this->country = country; }
	void setParent(Tree* parent) { this->parent = parent; }
	void setCursor(bool c) { cursor = c; }

	int getLevelUtil(Tree* node, string data, int level); //получение текущего уровня узла (высоты)
	int getLevel(Tree* node, string data) { return getLevelUtil(node, data, 1); };
	Tree* getNode(int x, int y); // Получание узла
};

struct SGlutContextStruct {
	Tree* tree;
	int winW, winH, treeH, treeW, shift, R;
	int b1_x, b1_y, b1_state = 0; //коорды кнопки и состояие при наведении мыши
	int b2_x, b2_y, b2_state = 0;
	int b3_x, b3_y, b3_state = 0;
	int nodes = 0;
};

static SGlutContextStruct gc;
static vector<string> V; //элементы дерева
static int ii = 0; //счетчик

Tree* checkCircle(Tree* node, int x, int y);
void drawTree(int window_width, int window_height, int shift, int n);
void display(); //функция отображения
void drawCircle(int x, int y); //рисуем круг в заданных координатах
void drawBorderedCircle(int x, int y); //круг если мышь в зоне узла
Tree* checkCircle(Tree* node, int x, int y); //проверяем входит ли мышь в зону круга
void reshape(int, int); //решейп
void drawButton1(); //кнопка +
void drawButton2(); //кнопка -
void drawButton3(); //кнопка вывода атрибутов в консоль
void drawText(string data, int x0, int y0, bool state); //отрисовка текста на узлах
void drawLine(int x1, int y1, int x2, int y2); //соединяющие линии
void mouseMove(int x, int y); //функция отслеживания движения мыши
void mouseClick(int button, int state, int x, int y); //отслеживание нажатий
