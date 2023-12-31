#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "temperaturehumidite"                         //change this
 
const char WIFI_SSID[] = "NEUSTA";               //change this
const char WIFI_PASSWORD[] = "NEUSTA@Eisenhower2022!";           //change this
const char AWS_IOT_ENDPOINT[] = "a13loltpsesfzp-ats.iot.eu-north-1.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAMsWTv/kSh+VYbz1X7uaAbJYehp4MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzExMjExNDAz
MjhaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDYmV8lCJ7/S+Dj520a
5LLyF+d7vdS/1QOchXbhuvKb/5xaVGtYWwhY8LYP6Wc5jXcfuCc4gw5bTL20aAG0
rFoNCwM6stUG4+X5LCyB46/qFm5Qkb0qSKf567FZuwV39JhGDQ9y0f+6Oni0M4jO
p0eOwl0RUBUKVOtTps05PkTjJ9chOyttZpbKXaVSE4zwMKYpVa78Zp/WvU0c1NRr
yrHuC+b4QIS5bmckUlodS5nhS3vfuphFgjvPfme6QeAC/YLRBGq4KqnouFVnDUxl
HvEfWH7NDQmOZeKaTDnGpiFu8aiV1kEve2Q0ObgP6MAjKAEOLEKCNYB/LFSk4gwG
CI3HAgMBAAGjYDBeMB8GA1UdIwQYMBaAFECLJBMRRrcRwjJqebK42nTae1noMB0G
A1UdDgQWBBR/sgoOoHwO+ERXKMs4pYr4mZpYmzAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAdjre7/yofAPJzdB41YG5Hc8p
/0hqzOn4329DtSEpx8OTfufByGTvsR8SVCEc4CG7q0gTAt7LqtdzXczN7zMfwnwj
77X56wDjq1KT3Q4NnreHSQuF1ZQPYBjUD4e5ARD0hRutzYyVoBnr3v+wi1a6CiBT
m6UuNAZqUON+9wXmsiQvYHUvMvKlWQzh0eFgmtXI3bKx4YWI1/CzamAG5SJ02L6I
0RNnH/RSrhMXXJMKTIT+10r0Lv8hC61OQqDu+UpgB5QB8k2PjQIi3G6zPIiEWJ5M
7/qJpy1/KesobYeZglxnI1l25cieWVzaV7jen5v95D04Gdjj6xasHiZ7HixJEA==
-----END CERTIFICATE-----
 
 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA2JlfJQie/0vg4+dtGuSy8hfne73Uv9UDnIV24brym/+cWlRr
WFsIWPC2D+lnOY13H7gnOIMOW0y9tGgBtKxaDQsDOrLVBuPl+SwsgeOv6hZuUJG9
Kkin+euxWbsFd/SYRg0PctH/ujp4tDOIzqdHjsJdEVAVClTrU6bNOT5E4yfXITsr
bWaWyl2lUhOM8DCmKVWu/Gaf1r1NHNTUa8qx7gvm+ECEuW5nJFJaHUuZ4Ut737qY
RYI7z35nukHgAv2C0QRquCqp6LhVZw1MZR7xH1h+zQ0JjmXimkw5xqYhbvGoldZB
L3tkNDm4D+jAIygBDixCgjWAfyxUpOIMBgiNxwIDAQABAoIBAGXmQcy6cZLJr9OI
XNv6G/WpKU4d0KkvHbPVVkh8GwcpCfW1IYs/yH2PQRfbRqTc2N4jVNBRV7+8KsNk
6uiE7RiVxb8nwvCq5taC4a154JjQVLWy2ru50szRBW6hfcEhYUITguERyq1iNMcS
N5qBODkBV6d9dWiW6t8/6ey0TtROXCo1khO7WNWjOzxOqziznvXZZkzbzk2dWRHz
kcxOx5EUNULva8skcPOSAXAln3tCIp7rl78uorlcYYlO6/u3PAameJUqwoubYsTv
T580EocSeVOoPyipgTjR6WnDhnbghJiVOlMIOKno+Yzd8ujuJShHRKRICAmkpOH9
Chk1ewECgYEA9p57ha6K/TN3y8TW1BfIttUUDsXyCuKpRd63cB64fcVcnFtwYSaX
hJ5TRLl4Z+nal0IkWN3XHneGQfG5gfztzc/6q1QIZqt0irJ6DpNwOTOwk+388dtl
eEXueqf9fBFTK9YLdWmDw2oNnk/6IC0aUtYVkD8TeYMjzpBGCOp1+98CgYEA4NaP
2kbIoY1dihyhwfNiSqaNpb2Lmtp5eCuLOg5ckSeGMD/Hpa2KQ2/JPPYIeICHGK8B
RMMl++6gpHlZ04G3kFr0w4ux8PPzCHo8uA1vEcRKhXTnSNiGpMOI52iuW0hOJrhn
ZptNN/RFlDAgk/KXMfOze9TDViYKh1qa2VdbqxkCgYEAw/fpda/d2BfG0NAIWZ7Q
qqAlARxAGnBETDYPE/QFbEOhNMngQgK1kfdxeYHb8M6+GUXAtjEJ2Lbno40eePFw
UgQ7T1tGFbeWswPhw6VbHsk5PkN1pQZO2kTPnP3Sin0F1yaOEm2W+3hRfARXYKwW
Z86gce/9XKhdkq3ISRtuR4cCgYBzVV0BaSHtzShYeot3hDO9e2ZZyLteOgfpXtzS
cR+GzjGFepIdKMIuCZ+/B64cskGapdsOvNQ1QZliBWXQm0/gWugHjxc+NMVMaffP
qgR5pqlbgDZMJdYbmroVips19Acy0ZEpDy0zMLioZW+wtNZeJ1bAhMmW3Xi1KgMY
zjkVsQKBgQC/CT7YvaAhiH4NfD4eznrsofKs1ZJUlIpFSH4gFviub7J8ifPYsc1X
XvkaVJJfkFzY/zZNriC4OlLrXMtqMHnRC6k0SSkT5gmIrSt0P9EDWRdd8rPCfoDT
dByG9Se8r1BmfTaFfs55wCzQ1Z9K5KN3ZgXC8nUc14F3QPGeD7MR1A==
-----END RSA PRIVATE KEY-----
 
 
)KEY";