#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_endpoint.h"



v1beta1_endpoint_t *v1beta1_endpoint_create(
    list_t *addresses,
    v1beta1_endpoint_conditions_t *conditions,
    v1beta1_endpoint_hints_t *hints,
    char *hostname,
    char *node_name,
    v1_object_reference_t *target_ref,
    list_t* topology
    ) {
    v1beta1_endpoint_t *v1beta1_endpoint_local_var = malloc(sizeof(v1beta1_endpoint_t));
    if (!v1beta1_endpoint_local_var) {
        return NULL;
    }
    v1beta1_endpoint_local_var->addresses = addresses;
    v1beta1_endpoint_local_var->conditions = conditions;
    v1beta1_endpoint_local_var->hints = hints;
    v1beta1_endpoint_local_var->hostname = hostname;
    v1beta1_endpoint_local_var->node_name = node_name;
    v1beta1_endpoint_local_var->target_ref = target_ref;
    v1beta1_endpoint_local_var->topology = topology;

    return v1beta1_endpoint_local_var;
}


void v1beta1_endpoint_free(v1beta1_endpoint_t *v1beta1_endpoint) {
    if(NULL == v1beta1_endpoint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_endpoint->addresses) {
        list_ForEach(listEntry, v1beta1_endpoint->addresses) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_endpoint->addresses);
        v1beta1_endpoint->addresses = NULL;
    }
    if (v1beta1_endpoint->conditions) {
        v1beta1_endpoint_conditions_free(v1beta1_endpoint->conditions);
        v1beta1_endpoint->conditions = NULL;
    }
    if (v1beta1_endpoint->hints) {
        v1beta1_endpoint_hints_free(v1beta1_endpoint->hints);
        v1beta1_endpoint->hints = NULL;
    }
    if (v1beta1_endpoint->hostname) {
        free(v1beta1_endpoint->hostname);
        v1beta1_endpoint->hostname = NULL;
    }
    if (v1beta1_endpoint->node_name) {
        free(v1beta1_endpoint->node_name);
        v1beta1_endpoint->node_name = NULL;
    }
    if (v1beta1_endpoint->target_ref) {
        v1_object_reference_free(v1beta1_endpoint->target_ref);
        v1beta1_endpoint->target_ref = NULL;
    }
    if (v1beta1_endpoint->topology) {
        list_ForEach(listEntry, v1beta1_endpoint->topology) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_endpoint->topology);
        v1beta1_endpoint->topology = NULL;
    }
    free(v1beta1_endpoint);
}

cJSON *v1beta1_endpoint_convertToJSON(v1beta1_endpoint_t *v1beta1_endpoint) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_endpoint->addresses
    if (!v1beta1_endpoint->addresses) {
        goto fail;
    }
    cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
    if(addresses == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, v1beta1_endpoint->addresses) {
    if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1beta1_endpoint->conditions
    if(v1beta1_endpoint->conditions) {
    cJSON *conditions_local_JSON = v1beta1_endpoint_conditions_convertToJSON(v1beta1_endpoint->conditions);
    if(conditions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conditions", conditions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_endpoint->hints
    if(v1beta1_endpoint->hints) {
    cJSON *hints_local_JSON = v1beta1_endpoint_hints_convertToJSON(v1beta1_endpoint->hints);
    if(hints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hints", hints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_endpoint->hostname
    if(v1beta1_endpoint->hostname) {
    if(cJSON_AddStringToObject(item, "hostname", v1beta1_endpoint->hostname) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_endpoint->node_name
    if(v1beta1_endpoint->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1beta1_endpoint->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_endpoint->target_ref
    if(v1beta1_endpoint->target_ref) {
    cJSON *target_ref_local_JSON = v1_object_reference_convertToJSON(v1beta1_endpoint->target_ref);
    if(target_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetRef", target_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_endpoint->topology
    if(v1beta1_endpoint->topology) {
    cJSON *topology = cJSON_AddObjectToObject(item, "topology");
    if(topology == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = topology;
    listEntry_t *topologyListEntry;
    if (v1beta1_endpoint->topology) {
    list_ForEach(topologyListEntry, v1beta1_endpoint->topology) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)topologyListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_endpoint_t *v1beta1_endpoint_parseFromJSON(cJSON *v1beta1_endpointJSON){

    v1beta1_endpoint_t *v1beta1_endpoint_local_var = NULL;

    // define the local list for v1beta1_endpoint->addresses
    list_t *addressesList = NULL;

    // define the local variable for v1beta1_endpoint->conditions
    v1beta1_endpoint_conditions_t *conditions_local_nonprim = NULL;

    // define the local variable for v1beta1_endpoint->hints
    v1beta1_endpoint_hints_t *hints_local_nonprim = NULL;

    // define the local variable for v1beta1_endpoint->target_ref
    v1_object_reference_t *target_ref_local_nonprim = NULL;

    // define the local map for v1beta1_endpoint->topology
    list_t *topologyList = NULL;

    // v1beta1_endpoint->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "addresses");
    if (!addresses) {
        goto end;
    }

    
    cJSON *addresses_local = NULL;
    if(!cJSON_IsArray(addresses)) {
        goto end;//primitive container
    }
    addressesList = list_createList();

    cJSON_ArrayForEach(addresses_local, addresses)
    {
        if(!cJSON_IsString(addresses_local))
        {
            goto end;
        }
        list_addElement(addressesList , strdup(addresses_local->valuestring));
    }

    // v1beta1_endpoint->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "conditions");
    if (conditions) { 
    conditions_local_nonprim = v1beta1_endpoint_conditions_parseFromJSON(conditions); //nonprimitive
    }

    // v1beta1_endpoint->hints
    cJSON *hints = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "hints");
    if (hints) { 
    hints_local_nonprim = v1beta1_endpoint_hints_parseFromJSON(hints); //nonprimitive
    }

    // v1beta1_endpoint->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1beta1_endpoint->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "nodeName");
    if (node_name) { 
    if(!cJSON_IsString(node_name))
    {
    goto end; //String
    }
    }

    // v1beta1_endpoint->target_ref
    cJSON *target_ref = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "targetRef");
    if (target_ref) { 
    target_ref_local_nonprim = v1_object_reference_parseFromJSON(target_ref); //nonprimitive
    }

    // v1beta1_endpoint->topology
    cJSON *topology = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "topology");
    if (topology) { 
    cJSON *topology_local_map = NULL;
    if(!cJSON_IsObject(topology) && !cJSON_IsNull(topology))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(topology))
    {
        topologyList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(topology_local_map, topology)
        {
            cJSON *localMapObject = topology_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(topologyList , localMapKeyPair);
        }
    }
    }


    v1beta1_endpoint_local_var = v1beta1_endpoint_create (
        addressesList,
        conditions ? conditions_local_nonprim : NULL,
        hints ? hints_local_nonprim : NULL,
        hostname ? strdup(hostname->valuestring) : NULL,
        node_name ? strdup(node_name->valuestring) : NULL,
        target_ref ? target_ref_local_nonprim : NULL,
        topology ? topologyList : NULL
        );

    return v1beta1_endpoint_local_var;
end:
    if (addressesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, addressesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(addressesList);
        addressesList = NULL;
    }
    if (conditions_local_nonprim) {
        v1beta1_endpoint_conditions_free(conditions_local_nonprim);
        conditions_local_nonprim = NULL;
    }
    if (hints_local_nonprim) {
        v1beta1_endpoint_hints_free(hints_local_nonprim);
        hints_local_nonprim = NULL;
    }
    if (target_ref_local_nonprim) {
        v1_object_reference_free(target_ref_local_nonprim);
        target_ref_local_nonprim = NULL;
    }
    if (topologyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, topologyList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(topologyList);
        topologyList = NULL;
    }
    return NULL;

}
