#pragma once

#define _OUTPUT_ERROR_PATH(x) std::cout << x << " -> INCORRECT PATH!"
#define _OUTPUT_ERROR_EMPTY_TEXT(x) std::cout << "EMPTY TEXT!"
#define _OUTPUT_ERROR_INVALID_REGEX(x) std::cout << x << " IS AN INVALID REGEX!"
#define _OUTPUT_WRITE(x) std::cout << x

#define BIT(x) (1<<x)

enum WriterDelay
{
	_FASTEST = 0,
	_FASTER,
	_FAST,
	_NORMAL,
	_SLOW,
	_SLOWER,
	_SLOWEST
};

enum ReaderType
{
	_FILE = 0, _TEXT
};