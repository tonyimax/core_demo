#include <iostream>
#include "../../core/cust_bash64.h"

int main() {
    std::cout << "base64 test !\n";
    wchar_t wc[128]={0};
	std::cout << "===test base64 encode===!\n";
    CCustBase64::Encode("Hello",5,wc,128);
	const size_t len = wcslen(wc) + 1;
	char* out=CCustBase64::w2c(wc);
	printf("===> 'Hello' encode to base64 is: '%s'\n\n",out);
	std::cout << "===test base64 encode===!\n";
	printf("===> base64 String '%s' after base64 decode is:",out);

	CCustBase64::Decode(wc,len,wc,128);
	printf("'%s'\n\n",CCustBase64::w2c(wc));

    return 0;
}