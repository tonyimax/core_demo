#include <iostream>
#include "../../core/cust_bash64.h"

#include "httplib.h"


int main() {
    std::cout << "base64 test !\n";
	constexpr char str[]="https://blog.csdn.net/fittec";
	int len=128;
    wchar_t wc[len]={0};
	std::cout << "===test base64 encode===!\n";
    CCustBase64::Encode(str,strlen(str),wc,len);
	const size_t wlen = wcslen(wc) + 1;
	char* out=w2c(wc);
	printf("===> '%s' encode to base64 is: '%s'\n\n",str,out);
	std::cout << "===test base64 encode===!\n";
	printf("===> base64 String '%s' after base64 decode is:",out);

	CCustBase64::Decode(wc,wlen,wc,len);
	printf("'%s'\n\n",w2c(wc));

	// HTTP
	httplib::Client cli("http://qifu-api.baidubce.com");
	auto res = cli.Get("/ip/geo/v1/district?ip=147.185.133.190");
	res->status;
	res->body;
    printf("%s",res->body.c_str());
    return 0;
}