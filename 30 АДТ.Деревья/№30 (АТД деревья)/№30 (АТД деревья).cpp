#include "tree.h"
using namespace std;

Tree::Tree(string country) {
    this -> country = country;
    left = NULL;
    right = NULL;
    parent = NULL;
    cursor = false;
}

Tree::~Tree() {
    delete this -> left;
    delete this -> right;
}

int Tree::height(Tree* node)   {
    int level = 1;
    while (node -> left != NULL) {
        node = node -> left;
        level++;
    }
    return level;
}

Tree* Tree::balancedTree(int n)  {
    if (n == 0) { return NULL; } 
    Tree* tree = new Tree(V[ii]);
    ii++;
    tree -> addLeftTree(balancedTree(n / 2));
    tree -> addRightTree(balancedTree(n - n / 2 - 1));
    return tree;
}

void Tree::addLeftTree(Tree* tree) {
    if (tree != NULL) {
        tree -> parent = this;
        left = tree;
    }
}

void Tree::addRightTree(Tree* tree) {
    if (tree != NULL) {
        tree -> parent = this;
        right = tree;
    }
}

int Tree::getLevelUtil(Tree* node, string data, int level)  {
    if (node == NULL) { return 0; }
    if (node -> country == data) { return level; }

    int downlevel = getLevelUtil(node -> left, data, level + 1);
    if (downlevel != 0) { return downlevel; }

    downlevel = getLevelUtil(node -> right, data, level + 1);
    return downlevel;
}

void Tree::reorderSetCoords(Tree* tree, char dir) {                                                  
    if (tree != NULL) {
        int curLevel = getLevel(gc.tree, tree -> getCountry());
        if (tree -> parent == NULL) { tree -> b = 'К';
        } else if (tree -> left == NULL && tree -> right == NULL) { tree -> b = 'Л';
        } else { tree -> b = 'П'; }
           
        if (dir == '0') {
            tree -> x = gc.winW / 2;
            tree -> y = gc.winH - (gc.winH / gc.treeH / 2);
        } else if (dir == 'r') {
            // Левый
            tree -> x = tree -> parent -> x - gc.winW / pow(2, curLevel);

            if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1) { tree -> y = gc.winH / 2;
            } else { tree -> y = tree -> parent -> y - gc.winH / gc.treeH; }
                
        } else if (dir == 'l') {
            // Правый
            tree -> x = tree -> parent -> x + gc.winW / pow(2, curLevel);

            if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1) { tree -> y = gc.winH / 2;
            } else { tree -> y = tree -> parent -> y - gc.winH / gc.treeH; }
        }
        /*cout << tree->country << "(" << tree->b << ' ' << tree->x << ' ' << tree->y << ' ' << curLevel  << ' ' << dir<< ")" ;
        cout << gc.treeH << endl;*/
        reorderSetCoords(tree -> left, 'r'); //дерево рисуется зеркально
        reorderSetCoords(tree -> right, 'l'); //поэтому меняем узлы местами
    }
}

void Tree::reorderAtributes(Tree* tree)  {
    if (tree != NULL) {
        cout << "Информация в узле: " << setw(15) << tree -> country << endl;

        // Зеркально отображение
        if (tree -> left != NULL) { cout << "Правый потомок: " << setw(18) << tree->left->country << endl;
        } else { cout << "Правый потомок: " << setw(18) << "null" << endl; }
            
        if (tree -> right != NULL) { cout << "Левый потомок: " << setw(19) << tree -> right -> country << endl; 
        } else { cout << "Левый потомок: " << setw(19) << "null" << endl; }
            
        if (tree -> parent != NULL) { cout << "Родитель: " << setw(24) << tree -> parent -> country << endl;
        } else { cout << "Родитель: " << setw(24) << "null" << endl; }
            
        cout << "Тип узла: " << setw(24) << tree -> b << endl << "\n";
        reorderAtributes(tree->left);
        reorderAtributes(tree->right);
    }
}

void drawButton1()  {
    if (gc.b1_state == 1) { glColor3f(0.486f, 0.988f, 0.0f);
    } else { glColor3f(0.902f, 0.902f, 0.980f); }
        
    glBegin(GL_QUADS);
    glVertex2i(0, gc.winH);
    glVertex2i(0, gc.winH - gc.winH / 18);
    glVertex2i(gc.winW / 16, gc.winH - gc.winH / 18);
    glVertex2i(gc.winW / 16, gc.winH);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, gc.winH);
    glVertex2i(0, gc.winH - gc.winH / 18);
    glVertex2i(gc.winW / 16, gc.winH - gc.winH / 18);
    glVertex2i(gc.winW / 16, gc.winH);
    glEnd();

    string button = "Add";
    glRasterPos2i(2, gc.winH - 12);
    for (int i = 0; i < button.length(); i++) { glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]); }

    // Установим другие координаты для мыши, тк другая система координат
    gc.b1_x = gc.winW / 16;  
    gc.b1_y = gc.winH / 18; 
}

void drawButton2()  {
    if (gc.b2_state == 1) { glColor3f(1.0f, 0.388f, 0.278f);
    } else { glColor3f(0.902f, 0.902f, 0.980f); }
        
    glBegin(GL_QUADS);
    glVertex2i(0, gc.winH - (3 / 2) * gc.b1_y);
    glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b1_y));
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, gc.winH - (3 / 2) * gc.b1_y);
    glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b1_y));
    glEnd();

    string button = "Delete";
    glRasterPos2i(2, gc.winH - (3 / 2) * gc.b1_y - 12);
    for (int i = 0; i < button.length(); i++) { glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]); }

    // Установим другие координаты для мыши, тк другая система координат
    gc.b2_x = gc.winW / 16; 
    gc.b2_y = gc.winH / 18 + (3 / 2) * gc.b1_y;

}

void drawButton3()  {
    if (gc.b3_state == 1) { glColor3f(0.0f, 0.749f, 1.0f);
    } else { glColor3f(0.902f, 0.902f, 0.980f); }
        
    glBegin(GL_QUADS);
    glVertex2i(0, gc.winH - (3 / 2) * gc.b2_y);
    glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b2_y));
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, gc.winH - (3 / 2) * gc.b2_y);
    glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b2_y));
    glEnd();

    string but31 = "Info";
    string but32 = "in console";
    glRasterPos2i(2, gc.winH - (3 / 2) * gc.b2_y - 12);
    for (int i = 0; i < but31.length(); i++) { glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, but31[i]); }
    glRasterPos2i(2, gc.winH - (3 / 2) * gc.b2_y - 24);
    for (int i = 0; i < but32.length(); i++) { glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, but32[i]); }

    // Установим другие координаты для мыши, тк другая система координат
    gc.b3_x = gc.winW / 16;
    gc.b3_y = gc.winH / 18 + (3 / 2) * gc.b2_y;
}

void drawCircle(int x, int y) {
    glColor3f(1.0, 1.0, 1.0);
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y1 = gc.R * cos(theta) + y;
        x1 = gc.R * sin(theta) + x;;
        glVertex2f(x1, y1);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    float x2, y2;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y2 = gc.R * cos(theta) + y;
        x2 = gc.R * sin(theta) + x;;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawBorderedCircle(int x, int y)  {
    glColor3f(0.0, 0.0, 0.0);
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y1 = gc.R * cos(theta) + y;
        x1 = gc.R * sin(theta) + x;;
        glVertex2f(x1, y1);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    float x2, y2;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y2 = gc.R * cos(theta) + y;
        x2 = gc.R * sin(theta) + x;;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawLine(int x0, int y0, int x1, int y1)  {
    glColor3f(0.0f, 0.0f, 0.804f);
    glBegin(GL_LINES);
    glVertex2i(x0, y0);
    glVertex2i(x1, y1);
    glEnd();
}

Tree* checkCircle(Tree* node, int x, int y)  {
    if (pow(x - node -> getX(), 2) + pow(y - node -> getY(), 2) <= pow(gc.R, 2)) { return node; }
    Tree* temp = NULL;
    if (node -> getLeft() != NULL) { temp = checkCircle(node->getLeft(), x, y); }
    if (temp != NULL) { return temp; }
    if (node->getRight() != NULL) { temp = checkCircle(node -> getRight(), x, y); }
    return temp;
}

Tree* Tree::getNode(int x, int y)  {
    Tree* node = this;
    node = checkCircle(node, x, y);
    return node;
}

void display()  {
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, gc.winW, 0, gc.winH); // Ставим начало координат в левый нижний угол
    glViewport(0, 0, gc.winW, gc.winH);
    glClearColor(0.941, 0.973, 1.000, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Tree* tree = gc.tree;
    int R = 3 * (gc.winH / gc.treeH) / 4;   //высчитываем нужный радиус
    gc.R = (R / 2) / (gc.winH / gc.winW + 1) - gc.shift;
    tree -> reorderSetCoords(tree, '0'); //проставляем координаты
    queue<Tree*> Q; //очередь для записи DATA
    Tree* current = NULL;; //текущий элемент

    Q.push(tree);
    int x0, y0, x1, y1;

    drawButton1();  //отрисовка кнопок
    drawButton2();
    drawButton3();

    while (!Q.empty()) {
        tree = Q.front();   //1 элемент очереди
        Q.pop();
        x0 = tree -> getX();  //получаем его координаты
        y0 = tree -> getY();
       
        if (tree -> getLeft()) {
            current = tree -> getLeft();
            Q.push(current);    //записываем в очередь
            x1 = current -> getX();   //и получаем его координаты
            y1 = current -> getY();
            drawLine(x0, y0, x1, y1);   //отрисовка соед. линии
        }
        if (tree->getRight()) {
            current = tree->getRight();
            Q.push(current);
            x1 = current -> getX();
            y1 = current -> getY();
            drawLine(x1, y1, x0, y0);
        }

        drawCircle(x0, y0);	
        drawText(tree -> getCountry(), x0, y0, false);   

        //если курсор в зоне круга
        if (tree -> getCursor()) {
            drawBorderedCircle(x0, y0); //рисуем другой круг
            drawText(tree->getCountry(), x0, y0, true);//и текст
            tree -> drawAtribute();   //и пишем его тип и значение под кнопками
            tree -> setCursor(false);
        }
    }
    glutSwapBuffers();
}

void Tree::drawAtribute() {
    if (gc.winH > 200) {
        glColor3f(0.0f, 0.0f, 0.0f);
        GLvoid* font_style = GLUT_BITMAP_HELVETICA_18;
        int newX = 2;
        int newY = gc.winH - gc.b3_y - 10;
        int ka = 18;
        string temp;
        string fullB;
        if (this -> b == 'К') { fullB = "Root";
        } else if (this -> b == 'П') { fullB = "Node";
        } else if (this -> b == 'Л') { fullB = "Leaf"; }
           
        string fullNode = this->country + '[' + fullB + ']';
        glRasterPos2i(newX, newY - ka);
        for (int i = 0; i < fullNode.length(); i++) { glutBitmapCharacter(font_style, fullNode[i]); }
    }
}

void mouseMove(int x, int y)  {
    Tree* node = gc.tree -> getNode(x, gc.winH - y);

    if (node != NULL) { node->setCursor(true); }

    // Если входит в одну из кнопок
    if (x <= gc.b1_x and y <= gc.b1_y) { gc.b1_state = 1;
    } else { gc.b1_state = 0; }
        
    if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y) { gc.b2_state = 1;  
    } else { gc.b2_state = 0; }

    if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y) { gc.b3_state = 1; 
    } else { gc.b3_state = 0; }
        
    glutPostRedisplay(); // Перерисовка
}

void mouseClick(int button, int state, int x, int y)  {
    // Кнопка + // - // 
    if (x <= gc.b1_x and y <= gc.b1_y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            ii = 0;
            drawTree(gc.winW, gc.winH, 10, 1);
        }
    }
    if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            if (gc.nodes == 1) { 
                cout << "\nYou can't delete root!\n";   //корень удалить нельзя
            } else {
                string dt;
                ii = 0;
                cout << "\nDelete: ";
                getline(cin, dt);

                //ищем заданный ключ
                for (vector<string>::iterator i = V.begin(); i != V.end(); i++)  {
                    if (dt == *i) {
                        vector<string>::iterator j = i;
                        V.erase(j); //и удаляем его
                        gc.nodes--;
                        break;
                    }
                }
                drawTree(gc.winW, gc.winH, 10, 0); //перерисовываем дерево
                cout << "Элемент удалён." << endl;
            }
        }
    }
    if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y)  {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            gc.tree->reorderAtributes(gc.tree); //печать атрибутов
        }
    }
}

void reshape(int w, int h) {
    gc.winW = w;
    gc.winH = h;
    glViewport(0, 0, (GLsizei)gc.winW, (GLsizei)gc.winH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)gc.winW, 0, (GLdouble)gc.winH);
    glutPostRedisplay();
}

void drawText(string data, int x0, int y0, bool state) {
    if (gc.winH < 375 or gc.winW < 375) { return; }

    GLvoid* font_style;
    int counter = 0;
    vector<string> v;
    string temp;
    int strX;
    int strY = 12;

    //если мышь в зоне кнопки
    if (state == true) {
        font_style = GLUT_BITMAP_9_BY_15;
        glColor3f(1.0f, 1.00f, 1.0f);
        strX = 9;
    } else {
        glColor3f(0.0f, 0.0f, 0.0f);
        font_style = GLUT_BITMAP_8_BY_13;
        strX = 8;
    }

    //если несколько слов делим строку
    for (int i = 0; i < data.length() + 1; i++) {
        temp += data[i];
        if (data[i] == ' ' or data[i] == '\0') {
            counter++;
            v.push_back(temp);
            temp = "";
        }
    }
    int y = y0 + ((strY * counter / 2)) - 5; // первоначальный отступ по Y вверх

    //кол-во слов
    for (int i = 0; i < v.size(); i++) {
        int ka = v[i].length() / 2;    //отступ влево
        glRasterPos2i(x0 - ka * strX, y - (strY * i)); //ставим координаты
        for (int j = 0; j < v[i].length(); j++) { glutBitmapCharacter(font_style, v[i][j]); }
    }
}

void drawTree(int window_width, int window_height, int shift, int n) {
    static bool start = false;
    for (int i = 0; i < n; i++) {
        bool yes = false;
        string dt;
        cout << gc.nodes + 1 << " элемент: ";
        getline(cin, dt);

        for (int i = 0; i < V.size(); i++)
            if (dt == V[i]) { yes = true; } 
        if (!yes) {
            V.push_back(dt);
            gc.nodes++;
        } else {
            if (!start) {
                cout << "Ошибка!" << endl;
                n++;
            } else {
				if (gc.nodes == 1) {
					cout << "\nYou can't delete root!\n";   //корень удалить нельзя
                } else {
                    //ищем заданный ключ
                    for (vector<string>::iterator i = V.begin(); i != V.end(); i++) {
                        if (dt == *i) {
                            vector<string>::iterator j = i;
                            V.erase(j); //и удаляем его
                            gc.nodes--;
                            break;
                        }
                    }
                    cout << "Заданный элемент найден в дереве. Элемент удалён." << endl;
                }
            }
			
        }
        
    }
    Tree* tree = Tree::balancedTree(gc.nodes);
    gc.tree = tree;
    gc.winW = window_width;
    gc.winH = window_height;
    gc.shift = shift;
    gc.treeH = tree->height(tree);
    gc.treeW = pow(2, gc.treeH - 1); //макс. ширина дерева
    tree->reorderSetCoords(tree, '0'); //ставим координаты
    glViewport(0, 0, gc.winW, gc.winH);
    start = true;
}

//void drawError()
// {
//     glColor3f(0.0f, 0.0f, 0.0f);
//     GLvoid* font_style = GLUT_BITMAP_HELVETICA_18;
//     int newX = 2;
//     int newY = gc.winH - gc.b3_y - 10;
//     int ka = 18;
//     string temp = "Error!";
//     glRasterPos2i(newX, newY - ka);
//     for (int i = 0; i < temp.length(); i++)
//         glutBitmapCharacter(font_style, temp[i]);
//     glutPostRedisplay();
// }

