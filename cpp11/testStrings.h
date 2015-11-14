#include <string>
#include <locale>
#include <codecvt>

// Convert the arguments string to ut8
// Usage: outputstring = toUTF8(input_string)
template <typename T>
std::string toUTF8(const std::basic_string<T, std::char_traits<T>, std::allocator<T>>& str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<T>, T> conv;
    return conv.to_bytes(str);
}

template <typename T>
std::string toUTF8(const T * pstr)
{
    std::wstring_convert<std::codecvt_utf8_utf16<T>, T> conv;
    return conv.to_bytes(pstr);
}


// Build the output string from a UTF8 one. 
// Usage: outputstring = fromUTF8<outputtype>(utf8string)
template <typename T>
std::basic_string<T, std::char_traits<T>, std::allocator<T>> fromUTF8(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<T>, T> conv;
    return conv.from_bytes(str);
}


void testString()
{
	std::u16string str16 = u"test"; // u"" is for 16bit characters string
	const char16_t * pstr16 = str16.c_str();
	
	std::u32string str32 = U"test"; // U "" is for 32bit characters string
	const char32_t * pstr32 = str32.c_str();
	
	std::string str1 = toUTF8(str16);
	const char * pstr = str1.c_str();
	
	std::string str2 = toUTF8(pstr32);
	
	std::u16string str3 =  fromUTF8<char16_t>(str1);
	
	std::string str4 = toUTF8(str32);
	pstr = str4.c_str();
	
	str16 = fromUTF8<char16_t>(pstr);
}   

