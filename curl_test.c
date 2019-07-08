#include <curl/curl.h>
#include <string.h>


static int curl_test_writer (char *data, size_t size, size_t nmemb, void *buffer) {
	if (buffer == NULL) {
		return 0;
	}

	else {
		size_t actual_size = size * nmemb;
		memcpy(buffer, data, actual_size);
		return actual_size;
	}
}


CURLcode curl_test (char url[]) {
	CURL *curl = curl_easy_init();
	CURLcode result;

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

		static char errorBuffer[CURL_ERROR_SIZE];
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_test_writer);
		char buffer[1000000];
		memset(buffer, '\0', sizeof(buffer));
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

		result = curl_easy_perform(curl);

		if (result == CURLE_OK) {
			printf("RESULT: %s\n", buffer);
		}
		
		else {
			printf("ERROR: %s\n", errorBuffer);
		}
	}

	curl_easy_cleanup(curl);

	return result;
}

int main (int argc, char *argv[]) {
	curl_test(argv[1]);
	return 0;
}
