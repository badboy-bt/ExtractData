#pragma once

class CAxl final : public CExtractBase
{
public:
	bool Mount(CArcFile* pclArc) override;
	bool Decode(CArcFile* pclArc) override;

private:
	void InitMountKey(LPVOID deckey);
	bool CreateKey(LPBYTE key, LPINT key_len, LPBYTE pIndex, DWORD index_size);
	bool DecryptIndex(LPBYTE pIndex, DWORD index_size, QWORD arcSize);

	BYTE m_deckey[32] = {};
	DWORD m_len = 0;
};
