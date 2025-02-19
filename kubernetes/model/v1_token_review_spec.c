#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_review_spec.h"



v1_token_review_spec_t *v1_token_review_spec_create(
    list_t *audiences,
    char *token
    ) {
    v1_token_review_spec_t *v1_token_review_spec_local_var = malloc(sizeof(v1_token_review_spec_t));
    if (!v1_token_review_spec_local_var) {
        return NULL;
    }
    v1_token_review_spec_local_var->audiences = audiences;
    v1_token_review_spec_local_var->token = token;

    return v1_token_review_spec_local_var;
}


void v1_token_review_spec_free(v1_token_review_spec_t *v1_token_review_spec) {
    if(NULL == v1_token_review_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_review_spec->audiences) {
        list_ForEach(listEntry, v1_token_review_spec->audiences) {
            free(listEntry->data);
        }
        list_freeList(v1_token_review_spec->audiences);
        v1_token_review_spec->audiences = NULL;
    }
    if (v1_token_review_spec->token) {
        free(v1_token_review_spec->token);
        v1_token_review_spec->token = NULL;
    }
    free(v1_token_review_spec);
}

cJSON *v1_token_review_spec_convertToJSON(v1_token_review_spec_t *v1_token_review_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_token_review_spec->audiences
    if(v1_token_review_spec->audiences) {
    cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
    if(audiences == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_review_spec->audiences) {
    if(cJSON_AddStringToObject(audiences, "", (char*)audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_token_review_spec->token
    if(v1_token_review_spec->token) {
    if(cJSON_AddStringToObject(item, "token", v1_token_review_spec->token) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_token_review_spec_t *v1_token_review_spec_parseFromJSON(cJSON *v1_token_review_specJSON){

    v1_token_review_spec_t *v1_token_review_spec_local_var = NULL;

    // define the local list for v1_token_review_spec->audiences
    list_t *audiencesList = NULL;

    // v1_token_review_spec->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1_token_review_specJSON, "audiences");
    if (audiences) { 
    cJSON *audiences_local = NULL;
    if(!cJSON_IsArray(audiences)) {
        goto end;//primitive container
    }
    audiencesList = list_createList();

    cJSON_ArrayForEach(audiences_local, audiences)
    {
        if(!cJSON_IsString(audiences_local))
        {
            goto end;
        }
        list_addElement(audiencesList , strdup(audiences_local->valuestring));
    }
    }

    // v1_token_review_spec->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(v1_token_review_specJSON, "token");
    if (token) { 
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }
    }


    v1_token_review_spec_local_var = v1_token_review_spec_create (
        audiences ? audiencesList : NULL,
        token ? strdup(token->valuestring) : NULL
        );

    return v1_token_review_spec_local_var;
end:
    if (audiencesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, audiencesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(audiencesList);
        audiencesList = NULL;
    }
    return NULL;

}
