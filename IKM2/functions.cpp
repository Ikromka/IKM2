#include "functions.h"

wchar_t LastChar(wstring Word) {
	const int n = Word.size();
	if (Word[n - 1] == L'ü' || Word[n - 1] != L'ú' || Word[n - 1] != L'û') {
		return Word[n - 2];
	}
	else {
		return Word[n - 1];
	}
}

void Backtracking(const vector<wstring>& Words, vector<bool>& WasUsed, wchar_t PrevChar) {
	const int n = Words.size();
	int WordsUsed = 0;
	for (int i = 0; i < n; i++) {
		if (WasUsed[i]) {
			WordsUsed++;
		}
		else if (Words[i][0] == PrevChar) {
			WasUsed[i] = true;
			Backtracking(Words, WasUsed, LastChar(Words[i]));
			WasUsed[i] = false;
		}
	}
	
}