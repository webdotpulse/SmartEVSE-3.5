/*
;    Project: Smart EVSE v3
;
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
 */

#ifndef __EVSE_NETWORK

#define __EVSE_NETWORK

#include "main.h" //so SENSORBOX_VERSION is read in Sensorbox
#include "mongoose.h"
#include <ArduinoJson.h>

#define FREE(x) free(x); x = NULL;

// wrapper so hasParam and getParam still work
class webServerRequest {
private:
    struct mg_http_message *hm_internal;
    String _value;
    char temp[4096];     // allow CA cert to be sent 

public:
    void setMessage(struct mg_http_message *hm);
    bool hasParam(const char *param);
    webServerRequest* getParam(const char *param); // Return pointer to self
    const String& value(); // Return the string value
};

extern bool shouldReboot;
extern void network_loop(void);
extern String APhostname;
extern webServerRequest* request;
extern struct mg_mgr mgr;
extern uint8_t WIFImode;
extern char *downloadUrl;
extern uint32_t serialnr;
extern void RunFirmwareUpdate(void);
extern void WiFiSetup(void);
extern void handleWIFImode(void);
extern bool getLatestVersion(String owner_repo, String asset_name, char *version);
#ifndef SENSORBOX_VERSION
extern std::pair<int8_t, std::array<std::int16_t, 3>> getMainsFromHomeWizardP1();
extern String homeWizardHost;
#endif

#define FW_DOWNLOAD_PATH "http://smartevse-3.s3.eu-west-2.amazonaws.com"

#define OWNER_FACT "SmartEVSE"
#define REPO_FACT "SmartEVSE-3"
#define OWNER_COMM "dingo35"
#define REPO_COMM "SmartEVSE-3.5"

#endif
