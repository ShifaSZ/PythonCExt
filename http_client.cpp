/*
 * http_client.cpp
 *
 *  Created on: Jul 9, 2018
 *      Author: accuser
 */
#include <cpprest/filestream.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>

using namespace std;
using namespace web;
using namespace utility;
using namespace http;

#define BUF_SIZE 10000

extern "C"{

char * http_get_data(){
    char *buf = (char *)malloc(BUF_SIZE+1);
    if (NULL == buf)
        return NULL;
    
	utility::string_t address = U("https://stu3.test.pyrohealth.net/fhir/Patient/7d13c1e8-b603-4ec6-98cc-b4af32fdd5d4");
	utility::string_t content_type = U("application/json");

	http::uri uri = http::uri(address);

	web::http::client::http_client client(uri);

    http_request req(methods::GET);
    req.headers().add(U("Accept"), U("application/fhir+json"));

	http_response response;
    
    try {
		response = client.request(req).get();
    }
    catch (const std::exception &e)
    {
        snprintf(buf, BUF_SIZE, "Error exception:%s\n", e.what());
		return buf;
    }
    
	http::status_code status_c = response.status_code();

	if (status_c != 200)
	{
        snprintf(buf, BUF_SIZE, "Response error\n");
		return buf;
	}
    snprintf(buf, BUF_SIZE, "Response: %s", response.extract_string(true).get().c_str());
	return buf;
}

}