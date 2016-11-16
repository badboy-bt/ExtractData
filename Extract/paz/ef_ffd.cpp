#include "stdafx.h"
#include "ef_ffd.h"

bool Cef_ffd::Mount(CArcFile* archive)
{
	if (!archive->CheckExe(_T("ef_ffd.exe")))
		return false;

	return CPaz::Mount(archive);
}

bool Cef_ffd::Decode(CArcFile* archive)
{
	if (!archive->CheckExe(_T("ef_ffd.exe")))
		return false;

	return CPaz::Decode(archive);
}

void Cef_ffd::InitMountKey(CArcFile* archive)
{
	static const SKeyInfo key_info[] =
	{
		{ _T("scr"),    "\x9C\xD4\x50\x29\x8F\x0A\x0B\x33\x9F\x85\xE8\xD8\xAE\x59\x72\x03\x42\x21\x5A\x25\x78\x1E\x0D\x6B\x79\xE4\xAC\xD1\x22\x55\x22\xF0" },
		{ _T("bg"),     "\xAF\xA7\x0C\x31\x21\x35\x49\x28\x1C\xDB\xDF\xE8\x05\xA4\xFE\xF1\x1C\x7E\xE0\x9E\x4F\xB8\x40\xAA\x8C\x16\x36\xB6\x4C\x26\x24\x6A" },
		{ _T("st"),     "\x1D\xA8\x8B\x0B\xE7\xC0\x70\x3A\xAD\xB0\x26\xA2\x88\xE8\x30\x4B\xA1\x16\x00\x64\xE7\x0D\x51\x2F\x3C\x2D\xDE\xDB\xE7\x20\x37\x10" },
		{ _T("sys"),    "\xF6\xA3\x6B\xE0\x6A\x0E\x57\xE9\xD4\x7E\x4B\x5E\x31\x36\xCD\xC0\xC3\x15\x37\x01\xA9\xDF\xF4\xD8\xEB\x03\x13\xF5\xCC\xB7\xFF\xEF" },
		{ _T("bgm"),    "\x0C\x21\x09\x97\xF5\x45\x93\x74\xD3\x83\x9B\x34\xB9\x62\x5A\xBE\x32\x67\xC3\xBC\xBE\xB3\x9F\x45\xBA\x34\x03\x7C\x95\x1E\xE3\xD8" },
		{ _T("voice"),  "\xF1\x70\x82\xD7\x8F\x47\x7A\xDB\xAB\xB8\x25\xFB\x99\x00\x1E\x76\x61\xB6\xA1\x9B\x10\xCB\x87\xD5\x8B\x1C\x9A\xA8\x9B\x49\x08\x5B" },
		{ _T("se"),     "\xF6\x9B\xB5\x07\x04\xB7\x22\xDD\x1D\xDA\xB5\x4A\x0C\x64\x1D\xD7\x81\x6F\x90\x67\x49\x2C\xA3\xA8\xFF\xD7\x86\x71\xF9\xEB\x54\xC6" },
		{ _T("mov"),    "\x2D\x6D\x3E\x50\xDB\xF9\x5F\xF9\xAC\x64\xD9\x7A\x0B\xA1\x1E\x91\x83\xBC\x0B\xA7\xD2\x99\xA7\x9E\x78\x3F\x35\x8D\x87\x77\x6B\x2A" }
	};

	SetKey(archive, key_info);
}

void Cef_ffd::InitDecodeKey(CArcFile* archive)
{
	static const SKeyInfo key_info[] =
	{
		{ _T("scr"),    "\x67\x71\x7C\x99\x60\x31\xC8\x70\x98\x91\xDF\xA1\x4E\x8A\xA5\x12\x19\x8A\x52\xA2\xD4\x94\x09\x55\x17\xF0\xD5\x75\xDF\x22\xB3\x55" },
		{ _T("bg"),     "\x35\xF4\x8B\x89\x9B\x42\xB1\x40\xE2\x5D\xD3\x97\x51\xB4\xF8\x8B\xB4\x84\x60\x60\x3A\x63\xFF\x2E\xBE\x46\x52\x60\x5A\xDF\x53\xD8" },
		{ _T("st"),     "\xEA\x00\x49\x87\x55\xCF\x30\x29\x4E\x84\x84\xF4\x4B\x70\x1D\xEB\x86\x16\xF5\xA9\xAC\x08\x7E\x48\x0E\x5D\x5A\x45\x12\x60\x2F\x02" },
		{ _T("sys"),    "\x96\x61\x53\xBC\x19\x3D\x1C\xAC\x5B\x81\x7F\x0F\x37\xD4\xD9\xE2\x81\x6A\x8D\x03\x94\x47\x3B\x82\x69\x0F\x5B\xDC\xE1\x1B\xEC\xE1" },
		{ _T("bgm"),    "\x0B\xA3\x08\x0E\x30\xAE\x08\x06\x4C\x8F\x11\x00\xCF\xB2\xB2\xDF\x55\x6C\x66\xB8\x1C\xA3\xAC\x7C\xF1\xF8\x82\x9C\x5F\x41\xF1\x47" },
		{ _T("voice"),  "\xDB\x11\x84\x26\xA3\x06\x4C\x38\x22\xAB\x48\x9D\x8B\x9E\xED\x11\x75\xC9\x7D\xCD\x2D\x60\x07\x96\x85\x74\xBD\xBD\xE7\xC8\x64\xC2" },
		{ _T("se"),     "\x57\xB7\xA6\x6B\x3C\xE9\xFB\x01\x9E\x8F\xF2\x80\xA5\xEB\x90\x69\x12\xEB\x90\x0A\x70\x82\x41\xEF\xCA\x9F\xB9\x36\x92\x61\x28\xA1" },
		{ _T("mov"),    "\x91\x60\x0A\x03\x84\xBA\xED\xE1\x42\xB7\x9C\xFE\x17\xAE\x5F\x94\x1D\xFD\x1C\xF8\x4F\xCB\x0F\x66\x1E\x53\xE3\xC0\x3A\x81\xE4\xF5" }
	};

	SetKey(archive, key_info);
}
