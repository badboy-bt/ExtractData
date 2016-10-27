#pragma once

#include "ExtractBase.h"
#include "SearchBase.h"

class CExtract
{
public:
	CExtract();
	void SetClass();
	void SetSearchClass();
	static BOOL Mount(CArcFile* pclArc);
	static bool Decode(CArcFile* pclArc, bool convert);
	static BOOL Search(CArcFile* pclArc);
	void Close();

private:
	static std::vector<CExtractBase*> m_Class;
	static std::vector<CSearchBase*> m_SearchClass;
	static std::set<CExtractBase*> m_DecodeClass;
};
