#include "noweb.h"

using namespace std;

NoWeb::NoWeb(HANDLE hProcess, char option) {
	switch (option) {
	case 'N':
		mem::NopEx((BYTE*)pointers::webTick(), 8, hProcess);
	break;
	
	case 'F':
		mem::PatchEx((BYTE*)pointers::webTick(), (BYTE*)"\xF3\x0F\x11\x89\x38\x02\x00\x00", 8, hProcess);
	break;
	}
}