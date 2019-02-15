#include "../DSys.h"

int main() {

	std::string text = "texterino_text";
	Reader reader1(ReaderType::_TEXT, text);
	std::cout << reader1.getText() << "\n"
		<< reader1.getPath() << "\n"
		<< reader1.getRType() << "\n\n";

	std::string path = "src/_test/file.txt";
	Reader reader2(ReaderType::_FILE, path);
	std::cout << reader2.getText() << "\n"
		<< reader2.getPath() << "\n"
		<< reader2.getRType() << "\n";

	while (true);
}