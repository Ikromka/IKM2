#include "functions.h"

void main() {
	vector<wstring> Words = { L"аб", L"де", L"ёа" , L"вг" , L"гд" , L"бв" , L"её" };
	vector<int> UsedAtStep(Words.size(), 0);
	bool AnswerFound = false;
	StartBacktracking(Words, UsedAtStep, AnswerFound);

}
