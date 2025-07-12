int (*MessageBoxExt)(unsigned int, const char16_t *, const char16_t *);
 
std::u16string convertToUtf16(const std::string &utf8str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.from_bytes(utf8str);
}
*(uintptr_t *)&MessageBoxExt = UE4 + 0x7377958;


if (MessageBoxExt(1, (char16_t *)xxx3.c_str(), (char16_t *)f2.c_str()) == 1)
    {  
        MessageBoxExt(0, (char16_t *)xxx2.c_str(), (char16_t *)f2.c_str());
    }
    else
    {
		 
        MessageBoxExt(0, (char16_t *)xxx1.c_str(), (char16_t *)f2.c_str());
		}
    }
	
    return 0;    
}


KAUSHIK