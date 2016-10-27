#include "stdafx.h"
#include "BSFre.h"

/// Mount
///
/// @param pclArc Archive
///
bool CBSFre::Mount(CArcFile* pclArc)
{
	if (!pclArc->CheckExe(_T("BSF.exe")))
		return false;

	return CPaz::Mount(pclArc);
}

/// Decode
///
/// @param pclArc Archive
///
bool CBSFre::Decode(CArcFile* pclArc)
{
	if (!pclArc->CheckExe(_T("BSF.exe")))
		return false;

	return CPaz::Decode(pclArc);
}

/// Initialize mount key
///
/// @param pclArc Archive
///
void CBSFre::InitMountKey(CArcFile* pclArc)
{
	static const SKeyInfo astKeyInfo[] =
	{
		{ _T("scr"),    "\xCF\x1F\x01\x9B\xE4\x48\xDB\x6B\x3F\x0A\x64\x7B\xBA\x94\xE4\x87\x67\xDA\xF7\x36\xC4\xFC\x70\x8D\x6D\x32\x84\x47\x08\x06\x28\xDD" },
		{ _T("bg"),     "\x2E\x97\x37\xFD\x0F\xB1\x44\x26\x93\x63\xBA\x36\xB9\xF0\x24\xA0\xEC\xC0\x4A\x12\x1A\x21\xE9\x43\x46\x9C\xCF\xB0\x50\x84\x09\x02" },
		{ _T("st"),     "\xC4\xA6\xF5\xE3\x5A\xB4\xEC\xFF\xF8\x44\x45\xEB\xF0\x1D\x80\xC4\x38\x8A\x3B\x2D\x5E\x7A\xD4\x7F\xF8\x32\x5E\xE9\x56\x45\xB0\x33" },
		{ _T("sys"),    "\x23\x97\x59\xF5\xD0\x33\x28\xF5\x71\xA8\x14\x74\xDB\xAF\x3B\x25\xBE\xE4\xC9\x8F\x78\x4A\x67\xA0\x67\x52\x1F\x28\x73\x3B\x42\xFF" },
		{ _T("bgm"),    "\x9C\x75\x40\x99\x3A\xD4\x0F\xC9\xBD\x4A\xF2\x68\xB1\xF7\x5D\xB0\xAF\x3A\xB0\xFF\x13\x94\x97\xC6\x33\x16\xBF\x66\xC2\x1B\xA4\xB5" },
		{ _T("voice"),  "\x41\x0D\x47\xF7\x21\xF8\x76\xF9\x60\xA6\x6F\x1E\x6E\x0B\xA9\x16\xFC\xB7\x6F\x05\x98\x1C\x1A\xD0\xBD\x59\xAB\x59\x1A\x57\x7C\x66" },
		{ _T("se"),     "\xE3\xEA\xCD\xF8\xCE\xC4\xF1\xC6\x9B\xF8\xD7\xAD\xC9\xBD\xA6\xC6\x57\x45\x42\xE9\x31\x65\x65\x5F\x28\xB8\x12\x7A\x17\x24\x2F\xE1" },
		{ _T("mov"),    "\x13\x56\xEE\x41\x4C\x1B\xD8\x2E\x6E\x3B\x38\xED\x3D\xA1\x99\xEF\x31\x92\x28\xB2\xC7\xB3\xAD\xD1\x54\x8E\xE1\x00\x11\x74\xE4\xB5" }
	};

	SetKey(pclArc, astKeyInfo);
}

/// Initialize decode key
///
/// @param pclArc Archive
///
void CBSFre::InitDecodeKey(CArcFile* pclArc)
{
	static const SKeyInfo astKeyInfo[] =
	{
		{ _T("scr"),    "\xBC\xAB\x1F\xC6\x61\x18\xC3\x2D\x11\xC3\x48\xD7\x07\x36\x6D\x76\x5E\x84\xC8\xE7\xA1\xA2\xAF\x76\x02\xC6\x30\xFA\xFA\x76\xD0\x95" },
		{ _T("bg"),     "\x1E\x1F\xD8\xC2\xD7\xD9\xF6\x92\xCB\x39\xD7\xB3\xB3\xD0\xA5\x1E\x55\x2E\xFA\x1D\x76\x1D\x33\x6F\x6E\xDC\xBD\x44\x2D\x12\x40\xDB" },
		{ _T("st"),     "\x6A\x40\x43\x76\xC0\x6C\x2F\x71\x75\xCC\x4D\x29\xAE\x28\x9E\x8F\xCE\xBF\x34\x0A\xC2\x5F\xDE\x7C\xFA\x80\xDE\x1D\xCA\x19\x6A\xFC" },
		{ _T("sys"),    "\xFF\xF1\xBA\xD0\x54\x2B\x61\xEE\x9F\xCD\xB4\x16\x60\x08\xFB\xDE\x88\xF9\x30\x7C\x1C\xA1\x05\xA2\x94\xE2\xFF\x45\x9B\x35\x53\xEF" },
		{ _T("bgm"),    "\xFE\xD4\x5A\x7D\x8B\x2E\x41\xF0\x97\x4D\xD9\x17\xF1\xF9\x21\xE2\x03\x5C\x6A\x00\xDD\xDC\xBA\xA8\xEE\xF5\x4A\x37\x25\xCE\xBE\x68" },
		{ _T("voice"),  "\x45\x49\xFD\xEB\x1B\x50\x41\x1B\x6D\x1F\x46\x8B\x47\x45\x32\x2E\x7D\x2B\x1D\xE3\x1B\xCB\xD2\x13\x75\x6A\xAB\x33\xB1\x0F\x2F\xDD" },
		{ _T("se"),     "\x73\x72\x3F\x47\x7D\x2A\x96\xD6\xF1\xD3\x47\x8E\x0A\xF6\x12\x19\xF8\x68\x45\x33\xAE\xE6\xE1\x28\x5A\xB2\xCF\x35\x45\xE1\xE8\x84" },
		{ _T("mov"),    "\xE9\x31\x7D\x7F\xE8\x15\x32\x46\xB3\xBB\xE7\xFE\xA2\xD4\x65\xB9\x32\xD2\x9E\xBD\x2E\x68\x38\xEC\x8C\xFF\x20\xFB\xAB\xEE\xED\x51" }
	};

	SetKey(pclArc, astKeyInfo);
}
