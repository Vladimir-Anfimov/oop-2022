#include "Canvas.h"
#include <stdio.h>
#include <cmath>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->matrix = new char*[height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int R2 = ray * ray;
    for (int xvar=0; xvar < this->height; xvar++)
        for (int yvar=0; yvar < this->width; yvar++) {
            int D = pow(xvar - x, 2) + pow(yvar - y, 2);
            if (D >= R2 - ray/2 && D <= R2 + ray/2)
                this->SetPoint(xvar, yvar, ch);
        }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    int R2 = ray * ray;
    for (int xvar = 0; xvar < this->height; xvar++)
        for (int yvar = 0; yvar < this->width; yvar++) {
            int D = pow(xvar - x, 2) + pow(yvar - y, 2);
            if (D <= R2 + ray/2)
                this->SetPoint(xvar, yvar, ch);
        }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int x = top; x<=bottom; x++)
        for (int y = left; y<=right;y++) {
            if (x == top || x == bottom || y == left || y == right)
                this->SetPoint(x, y, ch);
        }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int x = top; x <= bottom; x++)
        for (int y = left; y <= right; y++) {
                this->SetPoint(x, y, ch);
        }
}
void Canvas::SetPoint(int x, int y, char ch) {
    this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int D  = 2 * dy - dx;
    int y  = y1;

    for (int x=x1;x<=x2;x++) {
        this->SetPoint(x, y, ch);
        if (D > 0) {
            y++;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
    }
}
