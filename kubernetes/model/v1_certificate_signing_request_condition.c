#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_certificate_signing_request_condition.h"



v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_create(
    char *last_transition_time,
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_local_var = malloc(sizeof(v1_certificate_signing_request_condition_t));
    if (!v1_certificate_signing_request_condition_local_var) {
        return NULL;
    }
    v1_certificate_signing_request_condition_local_var->last_transition_time = last_transition_time;
    v1_certificate_signing_request_condition_local_var->last_update_time = last_update_time;
    v1_certificate_signing_request_condition_local_var->message = message;
    v1_certificate_signing_request_condition_local_var->reason = reason;
    v1_certificate_signing_request_condition_local_var->status = status;
    v1_certificate_signing_request_condition_local_var->type = type;

    return v1_certificate_signing_request_condition_local_var;
}


void v1_certificate_signing_request_condition_free(v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition) {
    if(NULL == v1_certificate_signing_request_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_certificate_signing_request_condition->last_transition_time) {
        free(v1_certificate_signing_request_condition->last_transition_time);
        v1_certificate_signing_request_condition->last_transition_time = NULL;
    }
    if (v1_certificate_signing_request_condition->last_update_time) {
        free(v1_certificate_signing_request_condition->last_update_time);
        v1_certificate_signing_request_condition->last_update_time = NULL;
    }
    if (v1_certificate_signing_request_condition->message) {
        free(v1_certificate_signing_request_condition->message);
        v1_certificate_signing_request_condition->message = NULL;
    }
    if (v1_certificate_signing_request_condition->reason) {
        free(v1_certificate_signing_request_condition->reason);
        v1_certificate_signing_request_condition->reason = NULL;
    }
    if (v1_certificate_signing_request_condition->status) {
        free(v1_certificate_signing_request_condition->status);
        v1_certificate_signing_request_condition->status = NULL;
    }
    if (v1_certificate_signing_request_condition->type) {
        free(v1_certificate_signing_request_condition->type);
        v1_certificate_signing_request_condition->type = NULL;
    }
    free(v1_certificate_signing_request_condition);
}

cJSON *v1_certificate_signing_request_condition_convertToJSON(v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_certificate_signing_request_condition->last_transition_time
    if(v1_certificate_signing_request_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_certificate_signing_request_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_certificate_signing_request_condition->last_update_time
    if(v1_certificate_signing_request_condition->last_update_time) {
    if(cJSON_AddStringToObject(item, "lastUpdateTime", v1_certificate_signing_request_condition->last_update_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_certificate_signing_request_condition->message
    if(v1_certificate_signing_request_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_certificate_signing_request_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_certificate_signing_request_condition->reason
    if(v1_certificate_signing_request_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_certificate_signing_request_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_certificate_signing_request_condition->status
    if (!v1_certificate_signing_request_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_certificate_signing_request_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_certificate_signing_request_condition->type
    if (!v1_certificate_signing_request_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_certificate_signing_request_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_parseFromJSON(cJSON *v1_certificate_signing_request_conditionJSON){

    v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_local_var = NULL;

    // v1_certificate_signing_request_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_certificate_signing_request_condition->last_update_time
    cJSON *last_update_time = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_conditionJSON, "lastUpdateTime");
    if (last_update_time) { 
    if(!cJSON_IsString(last_update_time))
    {
    goto end; //DateTime
    }
    }

    // v1_certificate_signing_request_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_certificate_signing_request_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_certificate_signing_request_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_certificate_signing_request_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_certificate_signing_request_condition_local_var = v1_certificate_signing_request_condition_create (
        last_transition_time ? strdup(last_transition_time->valuestring) : NULL,
        last_update_time ? strdup(last_update_time->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_certificate_signing_request_condition_local_var;
end:
    return NULL;

}
