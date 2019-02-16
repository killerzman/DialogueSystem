#include "../DSys.h"

int main() {

	std::string path = "src/_test/file.txt";
	Reader reader1(ReaderType::_FILE, path);

	Parser parser1(reader1.getText());

	while (true);
}