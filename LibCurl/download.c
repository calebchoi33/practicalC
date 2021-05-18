
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *response;
    size_t size;
} gMemory;

int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow){
    if(dltotal > 0){
        fprintf(stderr, "Downloaded %ld of %ld bytes\n", dlnow, dltotal);
    } else{
        fprintf(stderr, "Downloaded %ld bytes\n", dlnow);
    }
    return 0;
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, gMemory *userdata){
    userdata->response = realloc(userdata->response, (userdata->size +(size*nmemb)+1));
    memcpy(&(userdata->response[userdata->size]), ptr, size*nmemb+1);
    userdata->size +=size*nmemb;
    return size*nmemb;
}

int main(int argc, char *argv[]){
    if(argc <= 1){
        fprintf(stderr, "Link not found\n");
        return 1;
    }
    gMemory userdata = {.response=calloc(1,sizeof(char)), .size= 0};
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, progress_callback);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L); 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &userdata);
    CURLcode code = curl_easy_perform(curl);
    if(code != 0){
        fprintf(stderr, "Error\n");
    }
    printf("%s\n", userdata.response);
    curl_easy_cleanup(curl);
    free(userdata.response);
}
