#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flex_volume_source.h"



v1_flex_volume_source_t *v1_flex_volume_source_create(
    char *driver,
    char *fs_type,
    list_t* options,
    int read_only,
    v1_local_object_reference_t *secret_ref
    ) {
    v1_flex_volume_source_t *v1_flex_volume_source_local_var = malloc(sizeof(v1_flex_volume_source_t));
    if (!v1_flex_volume_source_local_var) {
        return NULL;
    }
    v1_flex_volume_source_local_var->driver = driver;
    v1_flex_volume_source_local_var->fs_type = fs_type;
    v1_flex_volume_source_local_var->options = options;
    v1_flex_volume_source_local_var->read_only = read_only;
    v1_flex_volume_source_local_var->secret_ref = secret_ref;

    return v1_flex_volume_source_local_var;
}


void v1_flex_volume_source_free(v1_flex_volume_source_t *v1_flex_volume_source) {
    if(NULL == v1_flex_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_flex_volume_source->driver) {
        free(v1_flex_volume_source->driver);
        v1_flex_volume_source->driver = NULL;
    }
    if (v1_flex_volume_source->fs_type) {
        free(v1_flex_volume_source->fs_type);
        v1_flex_volume_source->fs_type = NULL;
    }
    if (v1_flex_volume_source->options) {
        list_ForEach(listEntry, v1_flex_volume_source->options) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_flex_volume_source->options);
        v1_flex_volume_source->options = NULL;
    }
    if (v1_flex_volume_source->secret_ref) {
        v1_local_object_reference_free(v1_flex_volume_source->secret_ref);
        v1_flex_volume_source->secret_ref = NULL;
    }
    free(v1_flex_volume_source);
}

cJSON *v1_flex_volume_source_convertToJSON(v1_flex_volume_source_t *v1_flex_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_flex_volume_source->driver
    if (!v1_flex_volume_source->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1_flex_volume_source->driver) == NULL) {
    goto fail; //String
    }


    // v1_flex_volume_source->fs_type
    if(v1_flex_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_flex_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_flex_volume_source->options
    if(v1_flex_volume_source->options) {
    cJSON *options = cJSON_AddObjectToObject(item, "options");
    if(options == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = options;
    listEntry_t *optionsListEntry;
    if (v1_flex_volume_source->options) {
    list_ForEach(optionsListEntry, v1_flex_volume_source->options) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)optionsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_flex_volume_source->read_only
    if(v1_flex_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_flex_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_flex_volume_source->secret_ref
    if(v1_flex_volume_source->secret_ref) {
    cJSON *secret_ref_local_JSON = v1_local_object_reference_convertToJSON(v1_flex_volume_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_flex_volume_source_t *v1_flex_volume_source_parseFromJSON(cJSON *v1_flex_volume_sourceJSON){

    v1_flex_volume_source_t *v1_flex_volume_source_local_var = NULL;

    // define the local map for v1_flex_volume_source->options
    list_t *optionsList = NULL;

    // define the local variable for v1_flex_volume_source->secret_ref
    v1_local_object_reference_t *secret_ref_local_nonprim = NULL;

    // v1_flex_volume_source->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_flex_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!cJSON_IsString(fs_type))
    {
    goto end; //String
    }
    }

    // v1_flex_volume_source->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "options");
    if (options) { 
    cJSON *options_local_map = NULL;
    if(!cJSON_IsObject(options) && !cJSON_IsNull(options))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(options))
    {
        optionsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(options_local_map, options)
        {
            cJSON *localMapObject = options_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(optionsList , localMapKeyPair);
        }
    }
    }

    // v1_flex_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_flex_volume_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "secretRef");
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_local_object_reference_parseFromJSON(secret_ref); //nonprimitive
    }


    v1_flex_volume_source_local_var = v1_flex_volume_source_create (
        strdup(driver->valuestring),
        fs_type ? strdup(fs_type->valuestring) : NULL,
        options ? optionsList : NULL,
        read_only ? read_only->valueint : 0,
        secret_ref ? secret_ref_local_nonprim : NULL
        );

    return v1_flex_volume_source_local_var;
end:
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(optionsList);
        optionsList = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_local_object_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
