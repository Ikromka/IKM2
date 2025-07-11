#include "functions.h"

wchar_t LastChar(wstring Word) {
	const int n = Word.size();
	if (Word[n - 1] == L'ь' || Word[n - 1] == L'ъ' || Word[n - 1] == L'ы') {
		return Word[n - 2];
	}
	else {
		return Word[n - 1];
	}
}

void StartBacktracking(vector<wstring>& Words, vector<int>& UsedAtStep, bool& AnswerFound) {
	const int n = Words.size();
	for (int i = 0; i < n; i++) {
		UsedAtStep[i] = 1;
		Backtracking(Words, UsedAtStep, LastChar(Words[i]), 2, AnswerFound);
		UsedAtStep[i] = 0;
	}
}

void Backtracking(vector<wstring>& Words, vector<int>& UsedAtStep, wchar_t PrevChar, int WordNumber, bool& AnswerFound) {
	const int n = Words.size();
	if (AnswerFound) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (UsedAtStep[i] == 0 && Words[i][0] == PrevChar) {
			UsedAtStep[i] = WordNumber;
			if (WordNumber != n) {
				Backtracking(Words, UsedAtStep, LastChar(Words[i]), WordNumber + 1, AnswerFound);
			}
			else {
				if ( WordAtStep(Words, UsedAtStep, 1)[0] == LastChar(WordAtStep(Words, UsedAtStep, n))) {
					Words = SortWords(Words, UsedAtStep);
					AnswerFound = true;
					return;
				}
			}
			UsedAtStep[i] = 0;
		}
	}
}

wstring WordAtStep(vector<wstring>& Words, vector<int>& UsedAtStep, int Step) {
	const int n = Words.size();
	for (int i = 0; i < n; i++) {
		if (UsedAtStep[i] == Step) {
			return Words[i];
		}
	}
}

vector<wstring> SortWords(vector<wstring>& Words,vector<int>& UsedAtStep) {
	const int n = Words.size();
	vector<wstring> Result{};
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (UsedAtStep[j] == i) {
				Result.push_back(Words[j]);
			}
		}
	}
	return Result;
}