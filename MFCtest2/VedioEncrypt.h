#pragma once
class VedioEncrypt
{
public:
	VedioEncrypt();
	~VedioEncrypt();

	int EDncryptFile(CString in_txt, CString out_txt, int do_encrypt);
};

