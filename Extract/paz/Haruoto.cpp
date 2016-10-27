#include "stdafx.h"
#include "Haruoto.h"

/// Mount
///
/// @param pclArc Archive
///
bool CHaruoto::Mount(CArcFile* pclArc)
{
	if (!pclArc->CheckExe(_T("haruoto.exe")))
		return false;

	return CPaz::Mount(pclArc);
}

/// Decode
///
/// @param pclArc Archive
///
bool CHaruoto::Decode(CArcFile* pclArc)
{
	if (!pclArc->CheckExe(_T("haruoto.exe")))
		return false;

	return CPaz::Decode(pclArc);
}

/// Initialize Mount Key
///
/// @param pclArc Archive
///
void CHaruoto::InitMountKey(CArcFile* pclArc)
{
	static const SKeyInfo astKeyInfo[] =
	{
		{ _T("scr"),    "\x6A\xE9\x0C\x8F\xCF\x05\x91\x36\xFC\xD7\xD5\x02\x92\xE7\xEB\xAA\x9D\x85\x95\xD7\x4B\x93\xE1\x56\x6E\x10\x80\xFC\xB1\x63\xE9\x57" },
		{ _T("bg"),     "\x3E\x63\xB9\x37\xC9\x3F\x6F\xF9\x97\x5C\x3F\xD2\xF7\x41\x47\x55\x5E\xF9\x15\xC9\x29\xE2\x41\x55\x13\x35\xCB\xEB\x77\x58\x34\xF5" },
		{ _T("st"),     "\xAD\x0D\xD7\x8E\xBA\x94\xFB\xB5\x45\xA9\x52\xA7\x49\xCF\x07\xD2\xAA\xCD\x74\x19\xED\x7C\xBD\xFE\xBC\x52\x2E\x90\x1C\xB1\x54\x15" },
		{ _T("sys"),    "\x77\xA6\x25\x52\x61\xC5\xF3\x2B\xC6\x7E\xCE\x42\x4B\x51\xED\xE1\x40\xC1\x75\x86\x58\x22\x17\x11\x27\x27\x6A\xAA\x5F\x2E\x08\x76" },
		{ _T("bgm"),    "\x5B\xF0\x64\x43\x7F\x91\x18\x1B\xD9\x9B\x73\x63\xBC\x87\xB7\x41\xE1\x94\xD6\xD1\x2A\x93\x0D\x4D\x16\x74\x3F\xFB\x02\x8F\x12\xD9" },
		{ _T("voice"),  "\x1B\xA9\x54\x23\xD4\xBA\x2A\x45\x3F\xC0\x00\xCA\x5B\x30\x26\xB4\x4D\x07\x58\xBA\x22\x91\x60\x73\x46\xF8\x6D\x41\xC2\x93\x30\xFE" },
		{ _T("se"),     "\x75\x91\xB5\xB0\x20\xFE\xE9\x68\xB8\xAC\x37\x36\xE9\x0D\xF9\xF8\x44\xDA\xBB\x01\x02\xDA\xD0\x43\x7A\x75\xB3\x3D\x62\xFB\x23\xA4" },
		{ _T("mov"),    "\x2A\x6A\x46\xAB\x22\x1E\x14\x45\x04\x20\xD6\x68\x26\xDE\xF2\xCE\x86\xCC\xBF\x65\x88\x2F\x1C\x7C\x70\xA9\xD2\xAE\xA1\x87\xAA\x8C" }
	};

	SetKey( pclArc, astKeyInfo );
}

/// Initialize Decode Key
///
/// @param pclArc Archive
///
void CHaruoto::InitDecodeKey(CArcFile* pclArc)
{
	static const SKeyInfo astKeyInfo[] =
	{
		{ _T("scr"),    "\x9D\x6C\x31\x1A\x49\x4A\xA6\x44\xE3\xEC\x31\x15\xE3\x5A\x68\xB1\x08\xBF\x75\x91\x19\x3D\xA9\xAC\x5C\x6F\xDE\x69\xD5\xBD\x90\x42"},
		{ _T("bg"),     "\x46\xE6\x5E\xC1\xC7\x7A\x24\xAC\x10\x3E\xB8\x10\x46\x36\xBF\xED\x96\x4B\x2C\x59\xF2\x19\xDF\xA8\x8B\x79\xFD\x5B\x12\xCC\x0D\xC9"},
		{ _T("st"),     "\x6B\xEF\xDC\x76\x1B\x25\x2E\x6D\x2F\xB7\xC7\x70\x78\xA6\x5A\x5B\x8F\x97\xA5\xE0\x92\xA1\x13\xAE\x9D\xDA\x15\x62\x0E\x9F\x40\x31"},
		{ _T("sys"),    "\xCA\x49\x6B\xF9\x05\x0B\x84\x48\x01\x18\x1F\xF6\x3A\x6A\xF9\xBB\xB3\x62\x9D\xE4\xB8\x95\x02\x7D\x52\x53\xE5\x40\x89\xF6\xE6\x3B"},
		{ _T("bgm"),    "\x24\xB2\xCA\x09\x47\xEE\xE8\xFD\x46\x20\x81\x62\x49\x41\x5E\xCC\xC2\x6D\xD7\x26\x25\xB4\x6F\xD7\x6A\xA3\x2F\xB3\x42\x91\xC2\xA7"},
		{ _T("voice"),  "\x38\xEB\xBA\x67\x9F\x8C\x18\x4B\xBE\x91\xAA\x73\x68\xEC\x47\x50\x7B\x78\x12\x66\x99\xC0\x18\x7A\xA4\x8C\xB1\x7C\xFA\x2F\x93\x35"},
		{ _T("se"),     "\xC8\xB4\xFB\xD3\xCE\xA6\xD5\xF4\x28\x29\x5D\xEA\x55\x2B\x75\x05\x9F\x43\x0D\x63\xD4\x77\xBE\x26\xC1\xCC\x2C\x5B\x71\x91\x18\xA4"},
		{ _T("mov"),    "\xC8\xB4\xFB\xD3\xCE\xA6\xD5\xF4\x28\x29\x5D\xEA\x55\x2B\x75\x05\x9F\x43\x0D\x63\xD4\x77\xBE\x26\xC1\xCC\x2C\x5B\x71\x91\x18\xA4"}
	};

	SetKey(pclArc, astKeyInfo);
}
