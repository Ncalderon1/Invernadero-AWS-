#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "Pid_dht11"                         //change this
 
const char WIFI_SSID[] = "Dios";               //change this
const char WIFI_PASSWORD[] = "diosesfe";           //change this
const char AWS_IOT_ENDPOINT[] = "ae8e972qtcif6-ats.iot.us-east-2.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----

-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----

-----END CERTIFICATE-----

)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----

-----END RSA PRIVATE KEY-----

 
 
)KEY";
