#Just a simple curl test program on c
Sends GET-request for given URL and prints the response (raw data) via terminal.

#Usage (in UNIX terminal):
gcc curl_test.c -lcurl -o curl_test && ./curl_test <...your url...> && unlink curl_test

#Example:
gcc curl_test.c -lcurl -o curl_test && ./curl_test https://google.com && unlink curl_test
