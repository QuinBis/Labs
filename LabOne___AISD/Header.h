#pragma once


int** CreatingMatric(int rows); // �������� ������������ �������
void RemovingMatric(int** matric, int cols); // ������������ ������ �� �������.
void OutputMatric(int** matr, int rows, int cols); // ����� ��������� �������.
void OutputArray(int* array, int cols); // ����� ��������� �������.
void CopyArray(int* array_from, int * array_to, int size); // ���������� �������� �� ������� A � ������ B
void RundNumMatric(int** matr, int rows); // ��������� ������� � ���������� ���������� � ���������
void InputMatric(int ** matric, int cols); // ���� ������� � ����������
void RemovingArray(int* array, int cols); // ������������ ������ �� ������������� �������
int* CreatingArray(int cols); // �������� ������������� �������
int Factorial(int num); // ���������� ���������� �� ����� num

