#include "../DSys.h"

int main() {

	std::string path = "src/_test/file.txt";
	Reader reader1(ReaderType::_FILE, path);

	//Writer writer1(reader1.getText());
	//writer1.Write();

	std::unordered_map<std::string, std::regex> RegexFilters;
	RegexFilters["DELAY"] = std::regex("\\$(\\s+|\\S+)?\\(S[0-9]+\\)");
	RegexFilters["NEWLINE"] = std::regex("\\\\n");
	std::string text = reader1.getText();
	while (true)
	{
		for (int i = 0; i < text.length(); i++)
		{
			for (auto rf : RegexFilters)
			{
				if (std::regex_search(text.substr(i), m, rf.second))
				{
					switch (rf.first)
					{
						case "DELAY":
							break;
						case "NEWLINE":
							break;
						default:
							_OUTPUT_ERROR_INVALID_REGEX(rf.first);
					}
				}
			}
		}
	}

	while (true);
}