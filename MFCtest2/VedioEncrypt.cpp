#include "stdafx.h"
#include "VedioEncrypt.h"
#include <openssl\evp.h>
#include <string>

using namespace std;

VedioEncrypt::VedioEncrypt()
{
}


VedioEncrypt::~VedioEncrypt()
{
}

int VedioEncrypt::EDncryptFile(CString in_txt, CString out_txt, int do_encrypt) {
	FILE* in;
	FILE* out;
	errno_t err_in, err_out;
	string in_string, out_string;
	in_string = in_txt.GetString();
	out_string = out_txt.GetString();
	const char* in_char = in_string.c_str();
	const char* out_char = out_string.c_str();
	err_in = fopen_s(&in, in_char, "a+b");
	err_out = fopen_s(&out, out_char, "a+b");

	/* Allow enough space in output buffer for additional block */
	unsigned char inbuf[1024], outbuf[1024 + EVP_MAX_BLOCK_LENGTH];
	int inlen, outlen;
	EVP_CIPHER_CTX *ctx;
	/* Bogus key and IV: we'd normally set these from
	* another source.
	*/
	unsigned char key[] = "0123456789abcdeF";
	unsigned char iv[] = "1234567887654321";

	/* Don't set key or IV right away; we want to check lengths */
	ctx = EVP_CIPHER_CTX_new();
	EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, NULL, NULL, do_encrypt);
	OPENSSL_assert(EVP_CIPHER_CTX_key_length(ctx) == 16);
	OPENSSL_assert(EVP_CIPHER_CTX_iv_length(ctx) == 16);

	/* Now we can set key and IV */
	EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, do_encrypt);

	while (1)
	{
		inlen = fread_s(inbuf, 1024 + EVP_MAX_BLOCK_LENGTH, 1, 1024, in);
		if (inlen <= 0) break;
		if (!EVP_CipherUpdate(ctx, outbuf, &outlen, inbuf, inlen))
		{
			/* Error */
			EVP_CIPHER_CTX_free(ctx);
			return 0;
		}
		fwrite(outbuf, 1, outlen, out);
	}
	if (!EVP_CipherFinal_ex(ctx, outbuf, &outlen))
	{
		/* Error */
		EVP_CIPHER_CTX_free(ctx);
		return 0;
	}
	fwrite(outbuf, 1, outlen, out);

	EVP_CIPHER_CTX_free(ctx);
	
	fclose(in);
	fclose(out);

	return 1;
}
