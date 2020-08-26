#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My638reverphrase
{
	TEST_CLASS(My638reverphrase)
	{
	public:
		void reverseInPlace(std::string& input, size_t start, size_t end) {
			for (; start < end; ++start, --end)
			{
				char tmp = input[start];
				input[start] = input[end];
				input[end] = tmp;
			}
		}
		std::string reverseWord(std::string input) {
			size_t end = input.size() - 1;
			reverseInPlace(input, 0, end);
			return input;
		}

		std::string reversePhrase(std::string input) {
			input = reverseWord(input);
			size_t start = 0, end = 0;
			for (size_t i = 0; i < input.size(); ++i)
			{
				if (input[i] == ' ') {
					end = i - 1;
					reverseInPlace(input, start, end);
					start = i + 1;
				}
			}

			end = input.size() - 1;
			reverseInPlace(input, start, end);

			return input;
		}

		TEST_METHOD(reverseWord)
		{
			Assert::AreEqual(reverseWord("a").c_str(), "a");
			Assert::AreEqual(reverseWord("ab").c_str(), "ba");
			Assert::AreEqual(reverseWord("abc").c_str(), "cba");
			Assert::AreEqual(reverseWord("abcd").c_str(), "dcba");
			Assert::AreEqual(reverseWord("abcde").c_str(), "edcba");
		}

		TEST_METHOD(reversePhrase)
		{
			Assert::AreEqual(reverseWord("a b").c_str(), "b a");
			Assert::AreEqual("cd a", reversePhrase("a cd").c_str());
			Assert::AreEqual("cd ab", reversePhrase("ab cd").c_str());
			Assert::AreEqual("here world hello", reversePhrase("hello world here").c_str());
		}
	};
}
