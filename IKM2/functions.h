#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

wchar_t LastChar(wstring Word);

void StartBacktracking(vector<wstring>& Words, vector<int>& UsedAtStep, bool& AnswerFound);

void Backtracking(vector<wstring>& Words, vector<int>& UsedAtStep, wchar_t PrevChar, const int WordNumber, bool& AnswerFound);

wstring WordAtStep(vector<wstring>& Words, vector<int>& UsedAtStep, const int Step);

vector<wstring> SortWords(vector<wstring>& Words, vector<int>& UsedAtStep);