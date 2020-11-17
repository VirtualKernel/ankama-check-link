#include <Windows.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "hmac/md5.h"
#include "hmac/hmac.h"

std::string to_hex(const std::string& s, bool upper_case = true)
{
	std::ostringstream ret;

	for (std::string::size_type i = 0; i < s.length(); ++i)
		ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << static_cast<uint32_t>(s[i]);

	return ret.str();
}

std::string ankama_check_link(std::string url)
{
	std::string click_account = "69";
	std::string from_account = "69";
	std::string click_name = "VirtualKernel";
	std::string from_name = "VirtualKernel";
	std::string game = "1";
	std::string server = "1337";

	std::string hmac_string = hmac<MD5>(url + click_account + from_account + click_name + from_name + game + server, ">:fIZ?vfU0sDM_9j");

	std::string wat;

	// pls dont judge, kty
	// was gonna say quick and dirty, it definitely is dirty but not quick.
	wat.append("{");
	wat.append("\"url\"").append(":").append("\"").append(url).append("\"").append(",");
	wat.append("\"click_account\"").append(":").append(click_account).append(",");
	wat.append("\"from_account\"").append(":").append(from_account).append(",");
	wat.append("\"click_name\"").append(":").append("\"").append(click_name).append("\"").append(",");
	wat.append("\"from_name\"").append(":").append("\"").append(from_name).append("\"").append(",");
	wat.append("\"game\"").append(":").append(game).append(",");
	wat.append("\"server\"").append(":").append(server).append(",");
	wat.append("\"hmac\"").append(":").append("\"").append(hmac_string).append("\"");
	wat.append("}");

	return "https://go.ankama.com/en/check?s=" + to_hex(wat);
}

int main()
{
	std::string url;
	std::cin >> url;
	std::cout << ankama_check_link(url) << std::endl;
}